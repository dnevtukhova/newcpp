#include "trapezeDraw.h"
using namespace std;


trapezeDraw::trapezeDraw() 
{
	hwnd = FindWindow(TEXT("Notepad"), NULL);
	// �������� �������� �����������
	hdc = GetDC(hwnd);
}

void trapezeDraw::ReadFile(trapeze*t) //������� �� �����
{
	char buff[50];
	int newLowerBase;
	int newUpperBase;
	int newHeight;
	ifstream fin("SaveTrapeze.txt");


	fin >> newLowerBase;
	fin >> newUpperBase;
	fin >> newHeight;

	t->Set_lowerBase(newLowerBase);
	 t->Set_upperBase(newUpperBase);
	 t->Set_height(newHeight);

	fin.close(); // ������� ����
	cout << "������ ������� �� �����\n" << endl;
}



void trapezeDraw::SaveFile(trapeze *t) //��������� � ����
{
	
		ofstream fout("SaveTrapeze.txt");
		
			fout << t->Get_lowerBase () << " ";
			fout << t->Get_upperBase () << " ";
			fout << t->Get_height ()<< " ";
		
		fout.close(); // ������� ����
		cout << "������ �������� � ����\n" << endl;
	
}


int trapezeDraw:: GetColour()
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

void trapezeDraw::SetText() 
{
	// ������������� ���� ����
	SetBkColor(hdc, RGB(0, 0, 0));
	// ������������� ���� ������
	SetTextColor(hdc, RGB(161, 70, 213));
}

void trapezeDraw::SetPen() 
{
	// ������� ������ ����
	 hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// � �������� ��� � �������� �����������, �������� ���������� ����
	hOldPen = SelectPen(hdc, hYellowPen);
	
}

void trapezeDraw::DelBrush()
{
	DeleteBrush(hGreenBrush);
	hOldBrush = SelectBrush(hdc, hOldBrush);
}

void trapezeDraw::SetBrush() //������� ����� ��� �������
{
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
		
	hOldBrush = SelectBrush(hdc, hGreenBrush);
}



void trapezeDraw::risov(trapeze* t)
{
		// �������� ������ ����
		GetClientRect(hwnd, &rt);
		// ��������� ��������� ������
		sprintf(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
		// ������� ������ ������������ ����������
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		int height = t->Get_height();
		int lowerBase = t->Get_lowerBase();
		int upperBase = t->Get_upperBase();
				POINT ppt1[4] = {{ (x+((lowerBase-upperBase)/2)),y },{ x + upperBase,y },{ x + lowerBase, y + height}, {  x,y + height }};
		// ������ ����������� ��������
		Polygon(hdc, ppt1, 4);
}

void trapezeDraw::vlozh(trapeze*t)
{
		int height = t->Get_height();
		int upperBase = t->Get_upperBase();
		int lowerBase = t->Get_lowerBase();
		Ellipse(hdc, (x + ((lowerBase - upperBase) / 2)), y, x+ upperBase, y + height);
	
}

trapezeDraw::~trapezeDraw() 
{	
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

void trapezeDraw::GetNewSize()
{
	cout << "������� ����� �������� ����� ������� ���������" << endl;
	cout << ">>> ";
	cin >> lb;
	cout << "������� ����� �������� ����� �������� ���������" << endl;
	cout << ">>> ";
	cin >> ub;
	cout << "������� ����� �������� ������" << endl;
	cout << ">>> ";
	cin >> h;
	if (lb<1 || lb>500) throw 0;
	if (ub<1 || ub>500) throw 0;
	if (h<1 || h>500) throw 0;
	
}

void trapezeDraw::SetSize(trapeze *t) 
{
	
	t->Set_lowerBase(lb);
	t->Set_upperBase(ub);
	t->Set_height(h);
}

void trapezeDraw:: GetBiass() //������ �������� (��������� ���������)
{
	cout << "������� �������� �� ��� x" << endl;
	cout << ">>> ";
	cin >> x1;
	cout << "������� �������� �� ��� y" << endl;
	cout << ">>> ";
	cin >> y1;
}

void trapezeDraw::SetPosition() // �������� ��������� ������
{
	x = x + x1;
	y = y + y1;

	if (x<0 || x>500) throw 0;
	if (y<0 || y>500) throw 0;
}
