#ifndef MYFSIZE_H
#define MYFSIZE_H

#include <windows.h>
#include <sys/stat.h>   /* _stat, _S_IFDIR, _S_IFMT  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* ------------------------------------------------------------------ */
/*  Our own DIR and dirent — must be defined BEFORE any function decls */
/* ------------------------------------------------------------------ */

typedef struct {
    char d_name[MAX_PATH];
} mydirent;

typedef struct {
    HANDLE          hFind;
    WIN32_FIND_DATA findData;
    int             firstRead;
    mydirent        entry;
} MYDIR;

/* ------------------------------------------------------------------ */
/*  Function declarations                                               */
/* ------------------------------------------------------------------ */

MYDIR*    myopendir(const char* dirname);
mydirent* myreaddir(MYDIR* dp);
void      myclosedir(MYDIR* dp);
void      mydirwalk(char* dirname, void (*fsize)(char*));
void      fsize(char* name);

#endif /* MYFSIZE_H */
