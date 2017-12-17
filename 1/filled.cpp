#pragma once
#include "filled.h"
using namespace std;


int filled::GetColour()
{
	int colour;
	cout << "�������� ����:\n" << endl;
	cout << "1. ������\n"
		<< "2. �������\n"
		<< "3. �������\n" << endl;
	cout << ">>> ";
	cin >> colour;
	return colour;
}

HBRUSH filled::SetBrush(HDC hdc)
{
	HBRUSH hGreenBrush;
	int i = GetColour();
	if (i == 1)
	{
		hGreenBrush = CreateSolidBrush(RGB(254, 254, 34));//������
	}

	else
	{
		if (i == 2)
		{
			hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));//�������
		}
		else
		{
			hGreenBrush = CreateSolidBrush(RGB(252, 40, 71));//�������
		}
	}

	return hGreenBrush;
}

void filled::DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush)
{
	DeleteBrush(hGreenBrush);
	hOldBrush = SelectBrush(hdc, hOldBrush);
}