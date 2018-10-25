#undef UNICODE
#undef _UNICODE
#include<Windows.h>
#include"resource.h"
int main(void)
{
	DWORD dwTmp;
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "smiling...", 10, &dwTmp, NULL);
	HBITMAP hBm = LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HDC hCompDC = CreateCompatibleDC(hDC);
	SelectObject(hCompDC, hBm);
	BITMAP bm;
	GetObject(hBm, sizeof(bm), &bm);
	Sleep(100);
	BitBlt(hDC, 100, 100, bm.bmWidth, bm.bmHeight, hCompDC, 0, 0, SRCPAINT);
	DeleteDC(hCompDC);
	Sleep(2100);
	ReleaseDC(hWnd, hDC);
	DeleteObject(hBm);
	return 0;
}