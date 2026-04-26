#include <windows.h>
/* ... */
#include "dlgitems.h"
#include "calculator.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK createDlgBox(HINSTANCE hinst, HWND hparent, UINT msg, WPARAM wparam, LPARAM lparam)
{
    return(DialogBox(hinst, "CALC", hparent, (DLGPROC)DlgProc));
}

BOOL CALLBACK DlgProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT displayDlgBox(HINSTANCE, HWND, LPSTR);
    /* ... */
    HWND hwndOwner;
    RECT rc, rcDlg, rcOwner;
    
    switch(msg)
    {
    case WM_INITDIALOG:
        // Get owner of wind. & dlgbox. rects.
        if((hwndOwner = GetParent(hwndDlg)) == NULL) hwndOwner = GetDesktopWindow();
        
        GetWindowRect(hwndOwner, &rcOwner);
        GetWindowRect(hwndDlg, &rcDlg);
        CopyRect(&rc, &rcOwner);
        
        // Offset the owner and dialog box rectangles so that right and bottom 
        // values represent the width and height, and then offset the owner again 
        // to discard space taken up by the dialog box.
        OffsetRect(&rcDlg, -rcDlg.left, -rcDlg.top);
        OffsetRect(&rc, -rc.left, -rc.top);
        OffsetRect(&rc, -rcDlg.right, -rcDlg.bottom);
        
        // The new position is the sum of half the remaining space and the owner's 
        // original position.
        SetWindowPos(hwndDlg, HWND_TOP, rcOwner.left + (rc.right / 2), rcOwner.top + (rc.bottom / 2), 0, 0, SWP_NOSIZE);
        /*
        if(GetDlgCtrlID((HWND)wParam) != ID_EXPR) // edit
        {
            SetFocus(GetDlgItem(hwndDlg, ID_EXPR));
            return(FALSE);
        }
        */
        displayDlgBox(NULL, hwndOwner, "Expr:");
        return(TRUE);

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {   
        case IDOK:
            MessageBox(hwndDlg, TEXT(itoa(calculate(), NULL, 10)), TEXT("Answer"), MB_OK | MB_ICONINFORMATION);
            PostMessage(hwndDlg, WM_COMMAND, IDCANCEL, lParam);
            break;

        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return(TRUE);

        default:
            break;
        }   
        break;

    }

    return(FALSE);
}

LPWORD lpwAlign(LPWORD lpIn)
{
    ULONG ul;

    ul = (ULONG)lpIn;
    ul++;
    ul >>= 1;
    ul <<= 1;

    return((LPWORD)ul);
}

LRESULT displayDlgBox(HINSTANCE hinst, HWND hwndOwner, LPSTR lpszMsg)
{
    HGLOBAL hgbl;
    LPDLGTEMPLATE lpdt;
    LPDLGITEMTEMPLATE lpdit;
    LPWORD lpw;
    LPWSTR lpwsz;
    LRESULT ret;
    int nchar;
    
    hgbl = GlobalAlloc(GMEM_ZEROINIT, 1024);
    if(!hgbl) return(-1);
    
    lpdt = (LPDLGTEMPLATE)GlobalLock(hgbl);
    
    // Define a dlgbox.
    lpdt->style = WS_BORDER | WS_SYSMENU | DS_MODALFRAME | WS_CAPTION;
    lpdt->cdit = 1; // No. of controls
    lpdt->x = 10; lpdt->y = 10;
    lpdt->cx = 100; lpdt->cy = 100;
    
    lpw = (LPWORD)(lpdt + 1);
    *lpw++ = 0;                 // No menu
    *lpw++ = 0;                 // Predefined dlgbox. class (by default)
    
    lpwsz = (LPWSTR)lpw;
    nchar = 1 + MultiByteToWideChar(CP_ACP, 0, "CalC", -1, lpwsz, 50);
    lpw += nchar;
    
    // Define an OK button
    lpw = lpwAlign(lpw);    // Align DLGITEMTEMPLATE on DWORD boundary
    lpdit = (LPDLGITEMTEMPLATE)malloc(1 * sizeof(lpw));
    lpdit->x = 10; lpdit->y = 70;
    lpdit->cx = 80; lpdit->cy = 20;
    lpdit->id = IDOK;               // OK button identifier
    lpdit->style = WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON;
    
    lpw = (LPWORD)(lpdit + 1);
    *lpw++ = 0xFFFF;
    *lpw++ = 0x0080;            // Button class
    
    lpwsz = (LPWSTR)lpw;
    nchar = 1 + MultiByteToWideChar(CP_ACP, 0, "OK", -1, lpwsz, 50);
    lpw += nchar;
    *lpw++ = 0;     // No creation data
    
    // Define a static text control
    lpw = lpwAlign(lpw);            // Align DLGITEMTEMPLATE on DWORD boundary
    lpdit = (LPDLGITEMTEMPLATE)realloc(lpdit, sizeof(lpw));
    lpdit->x = 10; lpdit->y = 10;
    lpdit->cx = 40; lpdit->cy = 20;
    lpdit->id = ID_EXPR;    // Text identifier
    lpdit->style = WS_CHILD | WS_VISIBLE | SS_LEFT;
    
    lpw = (LPWORD)(lpdit + 1);
    *lpw++ = 0xFFFF;
    *lpw++ = 0x0082;            // static class
    
    for(lpwsz = (LPWSTR)lpw; *lpwsz++ = (WCHAR)*lpszMsg++; );
    lpw = (LPWORD)lpwsz;
    *lpw++ = 0;         // No creation data
    
    GlobalUnlock(hgbl);
    ret = DialogBoxIndirect(hinst, (LPDLGTEMPLATE)hgbl, hwndOwner, (DLGPROC)DlgProc);
    GlobalFree(hgbl);
    return(ret);
}
