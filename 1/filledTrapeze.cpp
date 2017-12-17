#pragma once
#include "filledTrapeze.h"
using namespace std;

filledTrapeze::filledTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew)
:shapeTrapeze(lowerBaseNew, upperBaseNew, heightNew, xNew, yNew) // вызов конструктора базового класса
{
}

filledTrapeze::filledTrapeze(filledTrapeze&ft)
	: shapeTrapeze(ft)
{
}


void filledTrapeze:: DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd)
{
	
		HBRUSH hGreenBrush = SetBrush(hdc); //выбрать кисть для заливки
		HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
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
		DelBrush(hdc, hGreenBrush, hOldBrush); //удалить кисть для заливки
}

filledTrapeze::~filledTrapeze()
{
}