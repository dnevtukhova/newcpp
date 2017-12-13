#pragma once
#include "trapeze.h"
#include "trapezeTableOrdered.h"
using namespace std;

trapezeTableOrdered::trapezeTableOrdered()
{
	tableTrapeze = new table[tSize];
	n = 1;

}



trapezeTableOrdered::~trapezeTableOrdered()
{
	delete[] tableTrapeze;
}



/* ����� �������� � �������; ��������� � ������ ���������� �������� ��� -1 */

int trapezeTableOrdered::findTable(int nkey)

{

	int i = 0, k = tSize - 1;

	while (i <= k) {

		int j = (i + k) / 2;

		if (tableTrapeze->key == nkey)
			cout << "������� ������" << endl;
			cout << tableTrapeze->key << endl;
			return tableTrapeze->key; /* ������������� */


		if (tableTrapeze->key <nkey)

			i = j + 1;
		else
			k = j - 1;

	}

	cout << "�������� � ������� ���" << endl;
	return -1;

}

/* �������� �������� � ������� */

int trapezeTableOrdered::deleteTable(int nKey)
{

	int i;

	if ((i=findTable(nKey) < 0))

		return-1;	/* �������� � ������� ��� */

	--n;	/* ����� ������� ������ ������� */

	for (; i< n; i++)

		tableTrapeze[i] = tableTrapeze[i + 1];

	cout << "�������� ���������" << endl;

	return 0;

}




int trapezeTableOrdered::inssort(int k, trapeze*tn)

{

	int i;

	for (i = n - 1; i >= 0 && tableTrapeze[i].key > k; i--)

		tableTrapeze[i + 1] = tableTrapeze[i];

	tableTrapeze[i + 1].key = k;

	tableTrapeze[i + 1].t = tn;

	return ++n;

}

/* ��������������������������*/

int trapezeTableOrdered::addTable(int k, trapeze*tn)

{

	if (findTable(k) >= 0)
		cout << "� ������� ���� ������� � ��������� ������" << endl;
		return-1;	

	if (n == tSize)
		cout << "� ������� ��� ��������� ������� ��� ������ ��������" << endl;
		return-2;

	return inssort(k, tn);

}
void trapezeTableOrdered::saveFileTable()
{
	ofstream fout("SaveOrderedTable.txt");
	for (int i=0; i < n; i++)
	{
		fout << tableTrapeze[i].t->Get_lowerBase() << " ";
		fout << tableTrapeze[i].t->Get_upperBase() << " ";
		fout << tableTrapeze[i].t->Get_height() << " ";
		fout << tableTrapeze[i].key << " \n";

	}
	fout.close(); // ������� ����
	cout << "������ �������� � ����\n" << endl;
}

	void trapezeTableOrdered::printTable() //������� �������� �� �����
	{
		char buff[50];
		int newLowerBase;
		int newUpperBase;
		int newHeight;
		int newkey;
		ifstream fin("SaveTrapeze.txt");

		for (int i = 0; i < n; i++)
		{
			fin >> newLowerBase;
			fin >> newUpperBase;
			fin >> newHeight;
			fin >> newkey;

			tableTrapeze[i].t->Set_lowerBase(newLowerBase);
			tableTrapeze[i].t->Set_upperBase(newUpperBase);
			tableTrapeze[i].t->Set_height(newHeight);
			tableTrapeze[i].key;
		}
		fin.close(); // ������� ����
		cout << "������ ������� �� �����\n" << endl;
	
	}