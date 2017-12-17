#pragma once
#include "trapeze.h"

class shapeTrapeze: public trapeze
{
protected:
	int *x;
	int *y;
public:
	shapeTrapeze();  // ����������� �� ���������

	shapeTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew);  // ����������� � ��������� �����������
	shapeTrapeze(shapeTrapeze &t);  //����������� �����������
	int Get_lowerBase(); //�������� ��������
	int Get_upperBase();
	int Get_height();
	void Set_lowerBase(int lb); // �������� ��������
	void Set_upperBase(int ub);
	void Set_height(int h);
	void SetText(HDC hdc);// ��� ������ ������� ���� � ���� ������
	void SetPen(HDC hdc); //������� ���� ��� �������

	void DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd);// ��������������� ����� ����������� �������

	int GetNewSizeLb(RECT rt, HWND hwnd); //������ ����� ������� ������
	int GetNewSizeUb(RECT rt, HWND hwnd);
	int GetNewSizeH(RECT rt, HWND hwnd);
	void SetSize(int lb, int ub, int h); //�������� ������� ������
	void SetPosition(int x1, int y1, RECT rt, HWND hwnd); // �������� ��������� ������
	int GetBiassX(); //������ �������� (��������� ��������� �� ��� X)
	int GetBiassY(); //������ �������� (��������� ��������� �� ��� Y)
	void ReadFile();//������� �� �����
	void SaveFile();//��������� � ����
	

	~shapeTrapeze();  // ����������*/

};
