#include "myfsize.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

/* Apply fsize() to all files in dir — Windows version */
void mydirwalk(char* dirname, void (*fsize)(char*))
{
    HANDLE          hFind;
    WIN32_FIND_DATA findData;
    char            searchPath[MAX_PATH];
    char            fullPath[MAX_PATH];

    /* Build the search pattern: "dirname\*" */
    snprintf(searchPath, MAX_PATH, "%s\\*", dirname);

    hFind = FindFirstFile(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "dirwalk: can't open %s (error %lu)\n",
            dirname, GetLastError());
        return;
    }

    do
    {
        /* Skip self (".") and parent ("..") entries */
        if ((strcmp(findData.cFileName, ".") == 0) ||
            (strcmp(findData.cFileName, "..") == 0))
            continue;

        /* Build the full path */
        snprintf(fullPath, MAX_PATH, "%s\\%s", dirname, findData.cFileName);

        /* Call the function pointer (e.g. fsize) */
        (*fsize)(fullPath);

    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
}
