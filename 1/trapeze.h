#pragma once
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>

class trapeze
{
private:
		int *lowerBase; //����� ������� ���������
	int *upperBase; //����� �������� ���������
	int *height; //������

public:
	trapeze();  // ����������� �� ���������
	trapeze(int lowerBase, int upperBase, int height);  // ����������� � ��������� �����������
	trapeze(trapeze &t);  //����������� �����������
	~trapeze();  // ����������
	int Get_lowerBase() { return *lowerBase; }  // �������� 
	int Get_upperBase() { return *upperBase; }  // ��������
	int Get_height() { return *height; }
	void Set_lowerBase(int lb) { *lowerBase = lb; }  // �����������
	void Set_dlin_vis(int ub) { *upperBase = ub; }  // �����������
	void Set_dlin_vis(int h) { *height = h; }  // �����������

};


