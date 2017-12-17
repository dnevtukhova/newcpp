#pragma once
#include "filledTrapeze.h"
using namespace std;

filledTrapeze::filledTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew)
:shapeTrapeze(lowerBaseNew, upperBaseNew, heightNew, xNew, yNew) // ����� ������������ �������� ������
{
}

filledTrapeze::filledTrapeze(filledTrapeze&ft)
	: shapeTrapeze(ft)
{
}


void filledTrapeze:: DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd)
{
	
		HBRUSH hGreenBrush = SetBrush(hdc); //������� ����� ��� �������
		HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
		// �������� ������ ����
		GetClientRect(hwnd, &rt);
		// ��������� ��������� ������
		sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
		// ������� ������ ������������ ����������
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		int height = Get_height();
		int lowerBase = Get_lowerBase();
		int upperBase = Get_upperBase();
		POINT ppt1[4] = { { (*x + ((lowerBase - upperBase) / 2)),*y },{ *x + upperBase,*y },{ *x + lowerBase, *y + height },{ *x,*y + height } };
		// ������ ��������
		Polygon(hdc, ppt1, 4);
		DelBrush(hdc, hGreenBrush, hOldBrush); //������� ����� ��� �������
}

filledTrapeze::~filledTrapeze()
{
}