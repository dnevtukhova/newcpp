#pragma once
#include "trapeze.h"

class trapezeDraw
{
private:
	int lb, ub, h; //��� ������� ����� ��������
	//������ ��������� �������� ��� ��������� x � y
	int x = 30;
	int y = 30;
	int x1, y1; // ��� ������� �������� �� ���� x � y
	HWND hwnd;
	HDC hdc;
	RECT rt;
	char buf[100];
	HBRUSH hOldBrush;
	HBRUSH hGreenBrush;
	HPEN hYellowPen;
	HPEN hOldPen;
	
	
public:
	trapezeDraw();

	int GetColour(); //������ ����
	void SetText();// ��� ������ ������� ���� � ���� ������
	void SetPen(); //������� ���� ��� �������
	void SetBrush(); //������� ����� ��� �������
	void DelBrush(); //������� �����
	void risov(trapeze* t);
	void vlozh(trapeze*t); 
	void GetNewSize(); //������ ����� ������� ������
	void SetSize(trapeze*t); //�������� ������� ������
	void SetPosition(); // �������� ��������� ������
	void GetBiass(); //������ �������� (��������� ���������)
	void ReadFile(trapeze*t);
	void SaveFile(trapeze*t);

	~trapezeDraw();
};