#pragma once
#include "shapeTrapeze.h"
using namespace std;

shapeTrapeze::shapeTrapeze() 
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	x = new int;
	y = new int;
	*lowerBase = 100;  // присвоение значения
	*upperBase = 50;
	*height = 50;
	*x = 30;
	*y = 30;

}

shapeTrapeze::shapeTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew)
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	x = new int;
	y = new int;
	*lowerBase = lowerBaseNew;
	*upperBase = upperBaseNew;
	*height = heightNew;
	*x = xNew;
	*y = yNew;

}

shapeTrapeze::shapeTrapeze(shapeTrapeze &t)
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	x = new int;
	y = new int;
	*lowerBase = *(t.lowerBase);  // копирование из другого экземпляра
	*upperBase = *(t.upperBase);
	*height = *(t.height);
	*x = *(t.x);
	*y = *(t.y);
}

int shapeTrapeze::Get_lowerBase() { return *lowerBase; }  // селектор

int shapeTrapeze::Get_upperBase() { return *upperBase; }  // селектор

int shapeTrapeze::Get_height() { return *height; }

void shapeTrapeze::Set_lowerBase (int lb) { *lowerBase = lb; }  // модификатор

void shapeTrapeze::Set_upperBase (int ub) { *upperBase = ub; }

void shapeTrapeze::Set_height(int h) { *height = h; }

void shapeTrapeze::SetText(HDC hdc)
{
	// устанавливаем цвет фона
	SetBkColor(hdc, RGB(0, 0, 0));
	// устанавливаем цвет текста
	SetTextColor(hdc, RGB(161, 70, 213));
}
void shapeTrapeze::SetPen(HDC hdc)
{
	// создаем желтое перо
	HPEN hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// и выбираем его в контекст отображения, сохраняя предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hYellowPen);
}
void shapeTrapeze::DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd)
{
	// получаем размер окна
	GetClientRect(hwnd, &rt);
	// формируем выводимую строку
	sprintf(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	// выводим строку графическими средствами
	TextOutA(hdc, 10, 10, buf, strlen(buf));
	int height = Get_height();
	int lowerBase = Get_lowerBase();
	int upperBase = Get_upperBase();
	POINT ppt1[4] = { { (*x + ((lowerBase - upperBase) / 2)),*y },{ *x + upperBase,*y },{ *x + lowerBase, *y + height },{ *x,*y + height } };
	// рисуем трапецию
	Polygon(hdc, ppt1, 4);
}

int shapeTrapeze::GetNewSizeLb(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int lb;
	cout << "Введите новое значение длины нижнего основания" << endl;
	cout << ">>> ";
	cin >> lb;

	if (lb<rt.left || lb>rt.right) throw 0;
	return lb;

}

int shapeTrapeze::GetNewSizeUb(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int ub;
	cout << "Введите новое значение длины верхнего основания" << endl;
	cout << ">>> ";
	cin >> ub;
	if (ub<rt.left || ub>rt.right) throw 0;
	return ub;
}
int shapeTrapeze::GetNewSizeH(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int h;
	cout << "Введите новое значение высоты" << endl;
	cout << ">>> ";
	cin >> h;
	if (h<rt.top || h>rt.bottom) throw 0;
	return h;
}
void shapeTrapeze::SetSize(int lb, int ub, int h)
{
	Set_lowerBase(lb);
	Set_upperBase(ub);
	Set_height(h);
}
void shapeTrapeze::SetPosition(int x1, int y1, RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);

	*x = *x + x1;
	*y = *y + y1;

	if (*x<rt.left || *x>rt.right) throw 0;
	if (*y<rt.top || *y>rt.bottom) throw 0;
}
int shapeTrapeze::GetBiassX()
{
	int x1;
	cout << "Введите смещение по оси x" << endl;
	cout << ">>> ";
	cin >> x1;
	return x1;
}
int shapeTrapeze::GetBiassY()
{
	int y1;
	cout << "Введите смещение по оси y" << endl;
	cout << ">>> ";
	cin >> y1;
	return y1;
}
void shapeTrapeze::ReadFile()
{
	char buff[50];
	int newLowerBase;
	int newUpperBase;
	int newHeight;
	ifstream fin("SaveTrapeze.txt");


	fin >> newLowerBase;
	fin >> newUpperBase;
	fin >> newHeight;

	Set_lowerBase(newLowerBase);
	Set_upperBase(newUpperBase);
	Set_height(newHeight);

	fin.close(); // закрыть файл
	cout << "Данные считаны из файла\n" << endl;
}
void shapeTrapeze::SaveFile()
{
	ofstream fout("SaveTrapeze.txt");

	fout << Get_lowerBase() << " ";
	fout << Get_upperBase() << " ";
	fout << Get_height() << " ";

	fout.close(); // закрыть файл
	cout << "Данные записаны в файл\n" << endl;
}

shapeTrapeze:: ~shapeTrapeze()
{
	delete lowerBase;  // очистка памяти
	delete upperBase;
	delete height;
	delete x;
	delete y;
}