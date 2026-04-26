#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define OPEN_MAX  20
#define PERMS     (_S_IREAD | _S_IWRITE)

/* Our own flags — no longer relying on CRT internals */
#define MY_READ   0x01
#define MY_WRITE  0x02
#define MY_APPEND 0x04

/* Our own FILE-like struct — replaces _iob */
typedef struct {
    int  fd;        /* underlying OS file descriptor   */
    int  flag;      /* MY_READ / MY_WRITE / MY_APPEND  */
    char* base;     /* buffer base (unused here)        */
    int  cnt;       /* chars left in buffer (unused)    */
} MYFILE;

/* Our own file table — replaces _iob[]  */
static MYFILE _myiob[OPEN_MAX];

/* ------------------------------------------------------------------ */
MYFILE* myfopen(const char* name, const char* mode)
{
    int    fd = -1;
    MYFILE* fp = NULL;

    /* Find a free slot */
    for (int i = 0; i < OPEN_MAX; i++) {
        if ((_myiob[i].flag & (MY_READ | MY_WRITE)) == 0) {
            fp = &_myiob[i];
            break;
        }
    }
    if (!fp)            /* no free slots */
        return NULL;

    switch (*mode)
    {
    case 'r':
        /* Open read-only; create if missing */
        fd = _open(name, _O_RDONLY | _O_BINARY, 0);
        if (fd == -1)
            fd = _creat(name, PERMS);
        break;

    case 'w':
        /* Create / truncate for writing */
        fd = _open(name, _O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY, PERMS);
        break;

    case '+':
        /* Open for read+write, create if missing */
        fd = _open(name, _O_RDWR | _O_CREAT | _O_BINARY, PERMS);
        break;

    case 'a':
        /* Append: open or create, then seek to end */
        fd = _open(name, _O_WRONLY | _O_BINARY, 0);
        if (fd == -1)
            fd = _creat(name, PERMS);
        if (fd != -1)
            _lseek(fd, 0L, SEEK_END);
        break;

    default:
        return NULL;
    }

    if (fd == -1)
        return NULL;

    /* Fill in the slot */
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? MY_READ : MY_WRITE;

    return fp;
}

/* ------------------------------------------------------------------ */
int myfclose(MYFILE* file)
{
    if (!file)
        return -1;

    int rc = _close(file->fd);

    /* Clear the slot so it can be reused */
    memset(file, 0, sizeof(MYFILE));
    return rc;
}
