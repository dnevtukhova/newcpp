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
	int GetColour(); //������ ����
	HBRUSH SetBrush(HDC hdc); //������� ����� ��� �������
	void DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush); //������� �����
};
