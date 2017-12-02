#pragma once
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <tchar.h>
#include <fstream>

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
	int Get_lowerBase(); //�������� ��������
	int Get_upperBase();
	int Get_height();
	void Set_lowerBase(int lb); // �������� ��������
	void Set_upperBase(int ub);
	void Set_height(int h);

	~trapeze();  // ����������
};