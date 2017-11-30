#include "trapezeDraw.h"
using namespace std;



trapezeDraw::trapezeDraw() {
	HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
	// �������� �������� �����������
	HDC hdc = GetDC(hwnd);
	RECT rt;
	
}

void trapezeDraw::read_file()
{
	fscanf(fp, "%d", &x1);
	fscanf(fp, "%d", &y1);
	fscanf(fp, "%d", &x2);
	fscanf(fp, "%d", &y2);
	printf("Dannye prochitany\n");
	getch();
}



void trapezeDraw::save_file()
{
	fprintf(fp2, "(x1,y1)=(%d,%d);(x2,y2)=(%d,%d)", x1, y1, x2, y2);
	printf("Dannye zapisany\n");
	getch();
}

BYTE trapezeDraw:: SetColour1()
{
	int i= trapezeDraw::GetColour();
	
	if (i = 1) {
		return RGB(223, 238, 94);//������
	}
	else if (i = 2)
	{
		return RGB(149, 246, 75);//�������
	}
	else {
		return RGB(149, 246, 75);//�������
	}
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

void trapezeDraw::SetPen(HDC hdc, RECT rt) {
	// ������� ������ ����
	HPEN hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// � �������� ��� � �������� �����������, �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hYellowPen);
}

void trapezeDraw::SetBrush(HDC hdc, RECT rt) //������� ����� ��� �������
{
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));
	// � �������� �� � �������� �����������, �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
}
void trapezeDraw::SetText(HDC hdc, RECT rt){
	// ������������� ���� ����
	SetBkColor(hdc, RGB(0, 0, 0));
	// ������������� ���� ������
	SetTextColor(hdc, RGB(161, 70, 213));
}

void trapezeDraw::risov(trapeze* t)
{
	do
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
		
		POINT ppt1[4] = {{ 100,30 },{  100+height,30 },{ 100 + height, 30+ upperBase },{ 100,30+ upperBase}};
		// ������ ����������� ��������
		Polygon(hdc, ppt1, 4);
	} while (getch() != 27);
}