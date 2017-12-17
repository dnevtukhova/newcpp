#pragma once
#include "filledTrapeze.h"
#include "trapezeTableOrdered.h"

class trapezeTableOrdered
{
private:
	int tSize;	/* максимальный размер таблицы */

	struct table {

		int key;

		shapeTrapeze*trap;
	}*tableTrapeze;
	int n; //текущий размер

public:
	trapezeTableOrdered(int tSize);
	~trapezeTableOrdered();
	int addTable(int k, shapeTrapeze*t); //добавить
	int inssort(int k, shapeTrapeze*t);//сортировка
	int deleteTable(int nkey); //удалить
	int findTable(int nkey); //найти элемент по ключу
	void saveFileTable(); //сохранить в файл
	void printTableOfFile(shapeTrapeze*tr, trapezeTableOrdered *ntab, int n); //вывести элементы на экран
	void printTO();
	int sizeFromFile(); //размерность таблицы из файла
	void set_n(int nn) { n = nn; }
	
};

