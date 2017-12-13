#pragma once
#include "trapeze.h"

trapeze::trapeze()  // �� ���������
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = 100;  // ���������� ��������
	*upperBase = 50;
	*height = 50;
}

trapeze::trapeze(int lowerBaseNew, int upperBaseNew, int heightNew)
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = lowerBaseNew;
	*upperBase = upperBaseNew;
	*height = heightNew;
}

trapeze::trapeze(trapeze &t)
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = *(t.lowerBase);  // ����������� �� ������� ����������
	*upperBase = *(t.upperBase);
	*height = *(t.height);
}
int trapeze::Get_lowerBase() { return *lowerBase; }  // �������� 
int trapeze::Get_upperBase() { return *upperBase; }  // ��������
int trapeze::Get_height() { return *height; }
void trapeze::Set_lowerBase(int lb) { *lowerBase = lb; }  // �����������
void trapeze::Set_upperBase(int ub) { *upperBase = ub; }  // �����������
void trapeze::Set_height(int h) { *height = h; }  // �����������

trapeze::~trapeze()  // ����������
{
	delete lowerBase;  // ������� ������
	delete upperBase;
	delete height;
}

