#pragma once
#include "trapeze.h"
#include "trapezeTableOrdered.h"
#include <iostream>
#include <string>
using namespace std;

trapezeTableOrdered::trapezeTableOrdered(int tSizeN)
{
	
	 tableTrapeze = new table[tSizeN];
	
	//tableTrapeze->trap = t;
	n = 0;
	tSize = tSizeN;

}



trapezeTableOrdered::~trapezeTableOrdered()
{
	delete[] tableTrapeze;
}



/* Поиск элемента в таблице; результат – индекс найденного элемента или -1 */

int trapezeTableOrdered::findTable(int nkey)

{

	int left = 0, right = n - 1;

	while (1) {

		int middle = (left + right) / 2;

		if (nkey < tableTrapeze[middle].key)
		{
			right = middle - 1;
		}
		else if (nkey > tableTrapeze[middle].key)
		{
			left = middle + 1;
		}
		else
		{
			cout << "Элемент найден" << endl;
			cout << tableTrapeze[middle].key << endl;
			cout << tableTrapeze[middle].trap->Get_lowerBase() << endl;
			cout << tableTrapeze[middle].trap->Get_upperBase() << endl;
			cout << tableTrapeze[middle].trap->Get_height() << endl;
			return middle;
		}
			
		
			if (left > right)
				return -1;
		

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

	for (int i = 0; i < n; i++) {
		if (tableTrapeze[i].key == nKey)
		{
			tableTrapeze[i] = tableTrapeze[i + 1];
			nKey = tableTrapeze[i + 1].key;
		}

		cout << "Удаление выполнено\n" << endl;
	}
	return 0;

}

void trapezeTableOrdered::printTO()//вывод на экран
{
	for (int i = 0; i < n; i++)
	{
		cout <<"Ключ: "<<tableTrapeze[i].key << endl;
		cout << "Нижнее основание: " << tableTrapeze[i].trap->Get_lowerBase() << endl;
		cout << "Верхнее основание: " << tableTrapeze[i].trap->Get_upperBase() << endl;
		cout << "Высота: " << tableTrapeze[i].trap->Get_height()<< endl;
	}
}



int trapezeTableOrdered::inssort(int k, trapeze*tn)

{

	int i;

	for (i = n - 1; i >= 0 && tableTrapeze[i].key > k; i--)

		tableTrapeze[i + 1] = tableTrapeze[i];

	tableTrapeze[i + 1].key = k;

	tableTrapeze[i + 1].trap = tn;
	cout << "Элемент добавлен успешно\n" << endl;

	return ++n;

}


/* добавлениеэлементавтаблицу*/

int trapezeTableOrdered::addTable(int k, trapeze*tn)

{
		if (findTable(k) >= 0)
		{
			cout << "в таблице есть элемент с указанным ключом" << endl;
			return-1;
		}

		else if (n == tSize)
		{
			cout << "в таблице нет свободной позиции для нового элемента" << endl;
			return-2;
		}

		else
		{
			inssort(k, tn);
		}
	
}

void trapezeTableOrdered::saveFileTable()
{
	ofstream fout("SaveOrderedTable.txt");
	//fout << n << " "; //количество элемнтов
	for (int i=0; i < n; i++)
	{
		fout << tableTrapeze[i].trap->Get_lowerBase() << " ";
		fout << tableTrapeze[i].trap->Get_upperBase() << " ";
		fout << tableTrapeze[i].trap->Get_height() << " ";
		fout << tableTrapeze[i].key << " "<<"\n";


	}
	
	fout.close(); // закрыть файл
	cout << "Данные записаны в файл\n" << endl;
}

	void trapezeTableOrdered::printTableOfFile(trapeze*tr, trapezeTableOrdered *ntab, int n) //вывести элементы на экран
	{
		char buff[50];
		//int newn;// считываем кол-во элементов
		int newLowerBase;
		int newUpperBase;
		int newHeight;
		int newkey;
		//int *k;

		
		ifstream fin("SaveOrderedTable.txt");
		
		
		for (int i = 0; i < n; i++)
		{
			fin >> newLowerBase;
			fin >> newUpperBase;
			fin >> newHeight;
			fin >> newkey;

			tr->Set_lowerBase(newLowerBase);
			tr->Set_upperBase(newUpperBase);
			tr->Set_height(newHeight);
			
			
			tableTrapeze[i].trap = tr;
			tableTrapeze[i].key= newkey;
		}
		fin.close(); // закрыть файл
		cout << "Данные считаны из файла\n" << endl;
	
	}
	int trapezeTableOrdered::sizeFromFile()
	{
		ifstream fin("SaveOrderedTable.txt");
		string s;
		int n = 0;
		while (fin.peek() != EOF) {
		getline(fin, s);
		n++;
				}
		return n;
	}
	