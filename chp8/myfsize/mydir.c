#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* ------------------------------------------------------------------ */
/*  Our own DIR and dirent types — mimic POSIX but backed by Win32     */
/* ------------------------------------------------------------------ */

/* Mirrors POSIX dirent — only d_name is needed by callers */
typedef struct {
    char d_name[MAX_PATH];
} mydirent;

/* Mirrors POSIX DIR — holds Win32 search state */
typedef struct {
    HANDLE          hFind;          /* Win32 search handle              */
    WIN32_FIND_DATA findData;       /* current entry from FindNextFile  */
    int             firstRead;      /* flag: first entry already loaded */
    mydirent        entry;          /* returned by myreaddir()          */
} MYDIR;

/* ------------------------------------------------------------------ */
MYDIR* myopendir(const char* dirname)
{
    MYDIR* dp;
    char   searchPath[MAX_PATH];
    DWORD  attr;

    if (!dirname || !*dirname)
    {
        errno = EINVAL;
        return NULL;
    }

    /* Verify the path exists and is a directory */
    attr = GetFileAttributesA(dirname);
    if (attr == INVALID_FILE_ATTRIBUTES)
    {
        fprintf(stderr, "myopendir: can't access %s (error %lu)\n",
            dirname, GetLastError());
        return NULL;
    }
    if (!(attr & FILE_ATTRIBUTE_DIRECTORY))
    {
        fprintf(stderr, "myopendir: %s is not a directory\n", dirname);
        return NULL;
    }

    dp = (MYDIR*)malloc(sizeof(MYDIR));
    if (!dp)
        return NULL;

    /* Build search pattern "dirname\*" */
    snprintf(searchPath, MAX_PATH, "%s\\*", dirname);

    /* FindFirstFile loads the first entry immediately */
    dp->hFind = FindFirstFileA(searchPath, &dp->findData);
    if (dp->hFind == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "myopendir: can't open %s (error %lu)\n",
            dirname, GetLastError());
        free(dp);
        return NULL;
    }

    dp->firstRead = 1;      /* first entry already sitting in findData */
    return dp;
}

/* ------------------------------------------------------------------ */
mydirent* myreaddir(MYDIR* dp)
{
    if (!dp || dp->hFind == INVALID_HANDLE_VALUE)
        return NULL;

    for (;;)
    {
        if (dp->firstRead)
        {
            /* Consume the entry loaded by FindFirstFile */
            dp->firstRead = 0;
        }
        else
        {
            /* Advance to the next entry */
            if (!FindNextFileA(dp->hFind, &dp->findData))
                return NULL;    /* no more entries */
        }

        /* Skip "." and ".." — mirrors POSIX inode-0 skip */
        if ((strcmp(dp->findData.cFileName, ".") == 0) ||
            (strcmp(dp->findData.cFileName, "..") == 0))
            continue;

        /* Copy filename into the returned entry */
        strncpy(dp->entry.d_name, dp->findData.cFileName, MAX_PATH - 1);
        dp->entry.d_name[MAX_PATH - 1] = '\0';
        return &dp->entry;
    }
}

/* ------------------------------------------------------------------ */
void myclosedir(MYDIR* dp)
{
    if (dp)
    {
        if (dp->hFind != INVALID_HANDLE_VALUE)
            FindClose(dp->hFind);
        free(dp);
    }
}
