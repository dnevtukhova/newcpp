#pragma once
#include "trapeze.h"
#include "trapezeTableOrdered.h"

class trapezeTableOrdered
{
private:
	 const int tSize = 20;	/* максимальный размер таблицы */

	struct table {

		int key;

		trapeze*t;
	}*tableTrapeze;
	int n=0; //текущий размер

public:
	trapezeTableOrdered();	
	~trapezeTableOrdered();
	int addTable(int k, trapeze*t); //добавить
	int inssort(int k, trapeze*t);//сортировка
	int deleteTable(int nkey); //удалить
	int findTable(int nkey); //найти элемент по ключу
	void saveFileTable(); //сохранить в файл
	void printTable(); //вывести элементы на экран



};

