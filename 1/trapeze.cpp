#pragma once
#include "trapeze.h"

trapeze::trapeze()  // по умолчанию
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = 100;  // присвоение значения
	*upperBase = 50;
	*height = 50;
}

trapeze::trapeze(int lowerBaseNew, int upperBaseNew, int heightNew)
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = lowerBaseNew;
	*upperBase = upperBaseNew;
	*height = heightNew;
}

trapeze::trapeze(trapeze &t)
{
	lowerBase = new int;  // выделение динамической памяти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = *(t.lowerBase);  // копирование из другого экземпляра
	*upperBase = *(t.upperBase);
	*height = *(t.height);
}
int trapeze::Get_lowerBase() { return *lowerBase; }  // селектор 
int trapeze::Get_upperBase() { return *upperBase; }  // селектор
int trapeze::Get_height() { return *height; }
void trapeze::Set_lowerBase(int lb) { *lowerBase = lb; }  // модификатор
void trapeze::Set_upperBase(int ub) { *upperBase = ub; }  // модификатор
void trapeze::Set_height(int h) { *height = h; }  // модификатор

trapeze::~trapeze()  // деструктор
{
	delete lowerBase;  // очистка памяти
	delete upperBase;
	delete height;
}

