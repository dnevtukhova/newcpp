﻿#pragma once
#include "trapeze.h"
#include "trapezeTableOrdered.h"

class trapezeTableOrdered
{
private:
	int tSize;	/* максимальный размер таблицы */

	struct table {

		int key;

		trapeze*trap;
	}*tableTrapeze;
	int n; //текущий размер

public:
	trapezeTableOrdered(int tSize);
	~trapezeTableOrdered();
	int addTable(int k, trapeze*t); //добавить
	int inssort(int k, trapeze*t);//сортировка
	int deleteTable(int nkey); //удалить
	int findTable(int nkey); //найти элемент по ключу
	void saveFileTable(); //сохранить в файл
	void printTable(); //вывести элементы на экран
	void printTO();



};

