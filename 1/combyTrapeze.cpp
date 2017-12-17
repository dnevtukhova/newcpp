#pragma once
#include "combyTrapeze.h"
using namespace std;


combyTrapeze::combyTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew, filledTrapeze *ftNew)
	:filledTrapeze(lowerBaseNew, upperBaseNew, heightNew, xNew, yNew)
{
	ft = ftNew;
}

combyTrapeze::combyTrapeze(combyTrapeze&ct)
	: filledTrapeze(ct)
{

}

void combyTrapeze::DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd)
{
	ft->DrawTrapeze(hdc, buf, rt, hwnd);
	Enclised(hdc);
}

void combyTrapeze::Enclised(HDC hdc) //�������� ��������� ������
{
	int height = Get_height();
	int upperBase = Get_upperBase();
	int lowerBase = Get_lowerBase();
	Ellipse(hdc, (*x + ((lowerBase - upperBase) / 2)), *y, *x + upperBase, *y + height);
}




combyTrapeze::~combyTrapeze()
{
	delete ft;
}
