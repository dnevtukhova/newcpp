#pragma once
#include "filledTrapeze.h"
#include "trapezeTableOrdered.h"

template <class Type> 
class trapezeTableOrdered
{
public:
	int tSize;	/* максимальный размер таблицы */

	struct table {

		int key;

	Type trap;
	}*tableTrapeze;
	int n; //текущий размер

public:
	trapezeTableOrdered(int tSize);
	~trapezeTableOrdered();
	int addTable(int k, Type t); //добавить
	int inssort(int k, Type t);//сортировка
	int deleteTable(int nkey); //удалить
	int findTable(int nkey); //найти элемент по ключу
	void saveFileTable(); //сохранить в файл
	void printTableOfFile(Type tr, trapezeTableOrdered *ntab, int n); //вывести элементы на экран
	void printTO();
	int sizeFromFile(); //размерность таблицы из файла
	void set_n(int nn) { n = nn; }
	
};

