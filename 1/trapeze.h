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
private:
		int *lowerBase; //длина нижнего основания
	int *upperBase; //длина верхнего основания
	int *height; //высота

public:
	trapeze();  // конструктор по умолчанию
	trapeze(int lowerBase, int upperBase, int height);  // конструктор с заданными параметрами
	trapeze(trapeze &t);  //конструктор копирования
	~trapeze();  // деструктор
	int Get_lowerBase() { return *lowerBase; }  // селектор 
	int Get_upperBase() { return *upperBase; }  // селектор
	int Get_height() { return *height; }
	void Set_lowerBase(int lb) {  *lowerBase = lb; }  // модификатор
	void Set_upperBase(int ub) { *upperBase = ub; }  // модификатор
	void Set_height(int h) { *height = h; }  // модификатор

};


