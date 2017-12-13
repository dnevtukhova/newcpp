#pragma once
#include "trapeze.h"

class trapezeDrawable
{
private:
	trapeze * trap;
	int *x;
	int *y;
		
public:
	trapezeDrawable(trapeze *t, int xNew, int yNew);

	int GetColour(); //������ ����
	void SetText(HDC hdc);// ��� ������ ������� ���� � ���� ������
	void SetPen(HDC hdc); //������� ���� ��� �������
	HBRUSH SetBrush(HDC hdc); //������� ����� ��� �������
	void DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush); //������� �����
	void Risov(HDC hdc, char*buf, RECT rt, HWND hwnd);//��������
	void Vlozh(HDC hdc); //�������� ��������� ������
	int GetNewSizeLb(RECT rt, HWND hwnd); //������ ����� ������� ������
	int GetNewSizeUb(RECT rt, HWND hwnd);
	int GetNewSizeH(RECT rt, HWND hwnd);
	void SetSize(int lb, int ub, int h); //�������� ������� ������
	void SetPosition(int x1, int y1, RECT rt, HWND hwnd); // �������� ��������� ������
	int GetBiassX(); //������ �������� (��������� ��������� �� ��� X)
	int GetBiassY(); //������ �������� (��������� ��������� �� ��� Y)
	void ReadFile();//������� �� �����
	void SaveFile();//��������� � ����

	~trapezeDrawable();
};