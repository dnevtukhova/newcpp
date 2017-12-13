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



/* Поиск элемента в таблице; результат – индекс найденного элемента или -1 */

int trapezeTableOrdered::findTable(int nkey)

{

	int i = 0, k = tSize - 1;

	while (i <= k) {

		int j = (i + k) / 2;

		if (tableTrapeze->key == nkey)
			cout << "Элемент найден" << endl;
			cout << tableTrapeze->key << endl;
			return tableTrapeze->key; /* элементнайден */


		if (tableTrapeze->key <nkey)

			i = j + 1;
		else
			k = j - 1;

	}

	cout << "Элемента в таблице нет" << endl;
	return -1;

}

/* удаление элемента в таблице */

int trapezeTableOrdered::deleteTable(int nKey)
{

	int i;

	if ((i=findTable(nKey) < 0))

		return-1;	/* элемента в таблице нет */

	--n;	/* новый текущий размер таблицы */

	for (; i< n; i++)

		tableTrapeze[i] = tableTrapeze[i + 1];

	cout << "Удаление выполнено" << endl;

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

/* добавлениеэлементавтаблицу*/

int trapezeTableOrdered::addTable(int k, trapeze*tn)

{

	if (findTable(k) >= 0)
		cout << "в таблице есть элемент с указанным ключом" << endl;
		return-1;	

	if (n == tSize)
		cout << "в таблице нет свободной позиции для нового элемента" << endl;
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
	fout.close(); // закрыть файл
	cout << "Данные записаны в файл\n" << endl;
}

	void trapezeTableOrdered::printTable() //вывести элементы на экран
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
		fin.close(); // закрыть файл
		cout << "Данные считаны из файла\n" << endl;
	
	}