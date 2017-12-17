#pragma once
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>
#include <fstream>

class filled 
{
public:
	int GetColour(); //Ввести цвет
	HBRUSH SetBrush(HDC hdc); //выбрать кисть для заливки
	void DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush); //удалить кисть
};
