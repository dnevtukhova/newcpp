#pragma once
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>
#include <fstream>

class trapeze
{
protected:
	int *lowerBase; //длина нижнего основани я
	int *upperBase; //длина верхнего основания
	int *height; //высота

public:
	virtual void DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd) = 0; // чисто виртуальная функция
	/*trapeze();  // конструктор по умолчанию

	trapeze(int lowerBase, int upperBase, int height);  // конструктор с заданными параметрами
	trapeze(trapeze &t);  //конструктор копирования
	int Get_lowerBase(); //получить значение
	int Get_upperBase();
	int Get_height();
	void Set_lowerBase(int lb); // изменить значение
	void Set_upperBase(int ub);
	void Set_height(int h);

	~trapeze();  // деструктор*/
};