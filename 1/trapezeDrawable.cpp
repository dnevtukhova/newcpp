#pragma once
#include "trapeze.h"
#include "trapezeDrawable.h"
using namespace std;


trapezeDrawable::trapezeDrawable(trapeze *t, int xNew, int yNew)
{
	x = new int;
	y = new int;
	*x = xNew;
	*y = yNew;
	trap = t;
	
}

void trapezeDrawable::ReadFile() //������� �� �����
{
	char buff[50];
	int newLowerBase;
	int newUpperBase;
	int newHeight;
	ifstream fin("SaveTrapeze.txt");


	fin >> newLowerBase;
	fin >> newUpperBase;
	fin >> newHeight;

	trap->Set_lowerBase(newLowerBase);
	trap->Set_upperBase(newUpperBase);
	trap->Set_height(newHeight);

	fin.close(); // ������� ����
	cout << "������ ������� �� �����\n" << endl;
}



void trapezeDrawable::SaveFile() //��������� � ����
{
	
		ofstream fout("SaveTrapeze.txt");
		
			fout << trap->Get_lowerBase () << " ";
			fout << trap->Get_upperBase () << " ";
			fout << trap->Get_height ()<< " ";
		
		fout.close(); // ������� ����
		cout << "������ �������� � ����\n" << endl;
	
}


int trapezeDrawable:: GetColour()
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

void trapezeDrawable::SetText(HDC hdc) 
{
	// ������������� ���� ����
	SetBkColor(hdc, RGB(0, 0, 0));
	// ������������� ���� ������
	SetTextColor(hdc, RGB(161, 70, 213));
}

void trapezeDrawable::SetPen(HDC hdc)
{
	// ������� ������ ����
HPEN hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// � �������� ��� � �������� �����������, �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hYellowPen);
	
}

void trapezeDrawable::DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush)
{
	
	DeleteBrush(hGreenBrush);
 hOldBrush = SelectBrush(hdc, hOldBrush);
	
}

HBRUSH trapezeDrawable::SetBrush(HDC hdc) //������� ����� ��� �������
{
	HBRUSH hGreenBrush;
	int i = GetColour();
	if (i == 1) 
	{
		hGreenBrush = CreateSolidBrush( RGB(254, 254, 34));//������
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



void trapezeDrawable::Risov(HDC hdc, char*buf, RECT rt, HWND hwnd)
{
		// �������� ������ ����
		GetClientRect(hwnd, &rt);
		// ��������� ��������� ������
		sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
		// ������� ������ ������������ ����������
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		int height = trap->Get_height();
		int lowerBase = trap->Get_lowerBase();
		int upperBase = trap->Get_upperBase();
				POINT ppt1[4] = {{ (*x+((lowerBase-upperBase)/2)),*y },{ *x + upperBase,*y },{ *x + lowerBase, *y + height}, {  *x,*y + height }};
		// ������ ����������� ��������
		Polygon(hdc, ppt1, 4);
}

void trapezeDrawable::Vlozh(HDC hdc)
{
		int height = trap->Get_height();
		int upperBase = trap->Get_upperBase();
		int lowerBase = trap->Get_lowerBase();
		Ellipse(hdc, (*x + ((lowerBase - upperBase) / 2)), *y, *x+ upperBase, *y + height);
	
}

trapezeDrawable::~trapezeDrawable() 
{	
	/*SelectBrush(hdc, hOldBrush);
	// ������� ������� �����
	DeleteBrush(hGreenBrush);
	// �������� � �������� ����������� ���������� ����
	SelectPen(hdc, hOldPen);
	// ������� ������ ����
	DeletePen(hYellowPen);
	// ����������� �������� �����������
	ReleaseDC(hwnd, hdc);*/
	delete x;
	delete y;
	
}

int trapezeDrawable::GetNewSizeLb(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int lb;
	cout << "������� ����� �������� ����� ������� ���������" << endl;
	cout << ">>> ";
	cin >> lb;
	
	if (lb<rt.left || lb>rt.right) throw 0;
	return lb;
	
}
int trapezeDrawable::GetNewSizeUb(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int ub;
	cout << "������� ����� �������� ����� �������� ���������" << endl;
	cout << ">>> ";
	cin >> ub;
	if (ub<rt.left || ub>rt.right) throw 0;
	return ub;
}

int trapezeDrawable::GetNewSizeH(RECT rt, HWND hwnd)
{
	GetClientRect(hwnd, &rt);
	int h;
	cout << "������� ����� �������� ������" << endl;
	cout << ">>> ";
	cin >> h;
	if (h<rt.top || h>rt.bottom) throw 0;
	return h;
}



void trapezeDrawable::SetSize(int lb, int ub, int h)
{
	
	trap->Set_lowerBase(lb);
	trap->Set_upperBase(ub);
	trap->Set_height(h);
}

int trapezeDrawable:: GetBiassX() //������ �������� (��������� ���������)
{
	int x1;
	cout << "������� �������� �� ��� x" << endl;
	cout << ">>> ";
	cin >> x1;
	return x1;
}

int trapezeDrawable::GetBiassY() //������ �������� (��������� ���������)
{
	int y1;
	cout << "������� �������� �� ��� y" << endl;
	cout << ">>> ";
	cin >> y1;
	return y1;


}



void trapezeDrawable::SetPosition(int x1, int y1, RECT rt, HWND hwnd) // �������� ��������� ������
{
	GetClientRect(hwnd, &rt);

	*x = *x + x1;
	*y = *y + y1;

	if (*x<rt.left || *x>rt.right) throw 0;
	if (*y<rt.top || *y>rt.bottom) throw 0;
}
