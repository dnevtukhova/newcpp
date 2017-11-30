#include "trapeze.h"

#define _CRT_SECURE_NO_WARNINGS
void paintLine();
using namespace std;
//����
int menu() 
{
	// ��������� ������� ����
	int variant; 
	cout << "�������� ����� ����\n" << endl;
	cout << "1. ���������� ������ ��������\n"
		<< "2. ���������� ����������� ��������\n"
		<< "3. ���������� ������ ������ ��������\n"
		<< "4. �����\n" << endl; 
	cout << ">>> ";
	cin >> variant;
	return variant;
}
//������ ����������� ������
void paintPoligon()
{
	HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
	//�������� ������� ���� � ��������
	if (hwnd != NULL)  
	{
		cout << "���� �������\n";
		wchar_t name[1024];
		GetWindowText(hwnd, name, sizeof(name));
		wcout << name << endl;
	}
	else 
	{
		cout << "���� �� �������\n";
	}
	cin.get();
	// �������� �������� �����������
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	// ������������� ���� ����
	SetBkColor(hdc, RGB(0, 0, 0));
	// ������������� ���� ������
	SetTextColor(hdc, RGB(161, 70, 213));
	// ������� ������ ����
	HPEN hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// � �������� ��� � �������� �����������, �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hYellowPen);
	// ������� ������� �����
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));
	// � �������� �� � �������� �����������, �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	do
	{
		// �������� ������ ����
		GetClientRect(hwnd, &rt);
		// ��������� ��������� ������
		sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
		// ������� ������ ������������ ����������
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		POINT ppt1[4] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 } };
		// ������ ����������� ��������
		Polygon(hdc, ppt1, 4);
	} while (getch() != 27);
	// �������� � �������� ����������� ���������� �����
	SelectBrush(hdc, hOldBrush);
	// ������� ������� �����
	DeleteBrush(hGreenBrush);
	// �������� � �������� ����������� ���������� ����
	SelectPen(hdc, hOldPen);
	// ������� ������ ����
	DeletePen(hYellowPen);
	// ����������� �������� �����������
	ReleaseDC(hwnd, hdc);
	
}

//������ ������
void paintLine()
{
// �������� �������� �����������
HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
HDC hdc = GetDC(hwnd);
RECT rt;
char buf[100];
// ������������� ���� ����
SetBkColor(hdc, RGB(0, 0, 0));
// ������������� ���� ������
SetTextColor(hdc, RGB(161, 70, 213));
// ������� ������ ����
HPEN hYellowPen1 = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
HPEN hOldPen = SelectPen(hdc, hYellowPen1);
do
{
GetClientRect(hwnd, &rt);
sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
TextOutA(hdc, 10, 10, buf, strlen(buf));
POINT ppt1[5] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 },{ 100,30 } };
//������ ��������
Polygon(hdc, ppt1, 5);
} while (getch() != 27);

// �������� � �������� ����������� ���������� ����
SelectPen(hdc, hOldPen);
// ������� ������ ����
DeletePen(hYellowPen1);
// ����������� �������� �����������
ReleaseDC(hwnd, hdc);
}

//������ ��� ��������� ������ - ��������, � � ��� ������ ������
void paintTwoFigure()
{
HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
HDC hdc = GetDC(hwnd);
RECT rt;
char buf[100];
// ������������� ���� ����
SetBkColor(hdc, RGB(0, 0, 0));
// ������������� ���� ������
SetTextColor(hdc, RGB(161, 70, 213));
// ������� ������ ����
HPEN hYellowPen2 = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
HPEN hOldPen = SelectPen(hdc, hYellowPen2);
do
{
GetClientRect(hwnd, &rt);
sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
TextOutA(hdc, 10, 10, buf, strlen(buf));
HBRUSH hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));
HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
POINT ppt1[5] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 },{ 100,30 } };
//��������
Polygon (hdc, ppt1, 5);

SelectBrush(hdc, hOldBrush);
DeleteBrush(hGreenBrush);

Ellipse(hdc, 100, 30, rt.right - 100, rt.bottom - 50);
} while (getch() != 27);
// �������� � �������� ����������� ���������� ����
SelectPen(hdc, hOldPen);
// ������� ������ ����
DeletePen(hYellowPen2);
// ����������� �������� �����������
ReleaseDC(hwnd, hdc);
}



void main()
{
	

	setlocale(LC_ALL, "rus");
	for (;;)
		{
			int variant = menu();
			switch (variant)
			{
			case 1:
				paintLine();
				break;
			case 2:
				paintPoligon();
				break;
			case 3:
				paintTwoFigure();
				break;
			}
		}		
}
