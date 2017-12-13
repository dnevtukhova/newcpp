#pragma once
#include "trapeze.h"
#include "trapezeTableOrdered.h"

class trapezeTableOrdered
{
private:
	 const int tSize = 20;	/* ������������ ������ ������� */

	struct table {

		int key;

		trapeze*t;
	}*tableTrapeze;
	int n=0; //������� ������

public:
	trapezeTableOrdered();	
	~trapezeTableOrdered();
	int addTable(int k, trapeze*t); //��������
	int inssort(int k, trapeze*t);//����������
	int deleteTable(int nkey); //�������
	int findTable(int nkey); //����� ������� �� �����
	void saveFileTable(); //��������� � ����
	void printTable(); //������� �������� �� �����



};

