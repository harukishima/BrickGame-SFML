#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "BrickGame.h"

using namespace std;

char map[25][70];

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width,

		height, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,

		Cursor_an_Pos);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void GiaoDien()
{
	textcolor(12);
	gotoxy(77, 4); cout << "^.^!";
	textcolor(7);
	textcolor(11);
	gotoxy(77, 6); cout << "Phim mui ten LEN: di len.";
	gotoxy(77, 7); cout << "Phim mui ten XUONG: di xuong.";
	gotoxy(77, 8); cout << "Phim mui ten TRAI: sang trai.";
	gotoxy(77, 9); cout << "Phim mui ten PHAI: sang phai.";
	gotoxy(77, 10); cout << "P: tam dung.";
	gotoxy(77, 11); cout << "Enter: tiep tuc.";
	gotoxy(77, 12); cout << "Q: thoat.";
	textcolor(7);
}


void VeKhung()
{
	for (int i = 0; i < 25; i++)
	{
		map[i][0] = ' ';
		map[i][1] = ' ';
		map[i][69] = ' ';
		map[i][68] = ' ';
	}
	for (int j = 0; j < 70; j++)
	{
		map[0][j] = ' ';
		map[24][j] = ' ';
		map[3][j] = '-';
	}
}

void VeTrung(int x, int y)
{
	map[x][y] = 'o';
}

void XoaTrung(int x, int y)
{
	map[x][y] = ' ';
}

void InGiaoDien()
{
	cout << "\n\n";
	for (int i = 0; i < 25; i++)
	{
		cout << "   ";
		for (int j = 0; j < 70; j++)
		{
			if (i == 0 || i == 24 || j == 0 || j == 1 || j == 68 || j == 69)
			{
				textcolor(119);
				cout << map[i][j];
				textcolor(7);
			}
			else if (map[i][j] == ':')
			{
				textcolor(85);
				cout << map[i][j];
				textcolor(7);
			}
			else if (map[i][j] == '-')
			{
				textcolor(14);
				cout << map[i][j];
				textcolor(7);
			}
			else if (map[i][j] == 'o')
			{
				textcolor(12);
				cout << map[i][j];
				textcolor(7);
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}


void VeKhay(int x, int y)
{
	map[x][y] = ':';
	map[x][y - 1] = ':';
	map[x][y + 1] = ':';
	map[x][y - 2] = ':';
	map[x][y + 2] = ':';
	map[x][y - 3] = ':';
	map[x][y + 3] = ':';
	map[x][y - 4] = ':';
	map[x][y + 4] = ':';
}

void XoaKhay(int x, int y)
{
	map[x][y] = ' ';
	map[x][y - 1] = ' ';
	map[x][y + 1] = ' ';
	map[x][y - 2] = ' ';
	map[x][y + 2] = ' ';
	map[x][y - 3] = ' ';
	map[x][y + 3] = ' ';
	map[x][y - 4] = ' ';
	map[x][y + 4] = ' ';
}

void XuLyTrungVaoKhay(int &x, int &y, int &diem)
{
	XoaTrung(x, y);
	x = 0;
	y = (rand() % 60 + 4);
	diem++;
	gotoxy(77, 17); cout << "Diem: " << diem;
}



//int main()
//{
//	/*BrickGame newGame;
//	newGame.run();*/
//	resizeConsole(1000, 500);
//	int x = 23, y = 33;
//	int x1 = 0, y1 = 35;
//	int x2 = 5, y2 = 11;
//	int diem = 0;
//	GiaoDien();
//
//	while (true)
//	{
//	lenday:
//		VeKhung();
//		VeTrung(x1, y1);
//		VeTrung(x2, y2);
//		VeKhay(x, y);
//		XoaManHinh();
//		InGiaoDien();
//	}
//
//	return 0;
//}