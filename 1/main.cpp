﻿#pragma once
#include "trapeze.h"
#include "shapeTrapeze.h"
#include "filledTrapeze.h"
#include "combyTrapeze.h"
#include "trapezeTableOrdered.h"
#include "trapezeTableOrdered.cpp"
#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//меню
int menu() 
{
	// Выбранный вариант меню
	int variant; 
	cout << "Выберите пункт меню\n" << endl;
	cout << "1. Нарисовать контур трапеции\n"
		<< "2. Нарисовать закрашенную трапецию\n"
		<< "3. Нарисовать  эллипс внутри трапеции\n"
		<< "4. Сохранить в файл\n"
		<< "5. Считать из файла\n"
		<< "6. Изменить размеры\n"
		<< "7. Переместить фигуру\n"
		<< "8. Добавить объект в таблицу\n(для демонстрации работы шаблона)"
		<< "9. Сохранить таблицу в файл\n"
		<< "10.Загрузить таблицу из файла\n"
		<< "11.Удалить элемент из таблицы\n" 
		<< "12.Вывести таблицу на экран\n(для демонстрации работы шаблона)"
		<< "13. Поиск элемента таблицы по индексу\n"
		<< "14. Выход из программы\n"
		<< "Для выхода с уровня нажмите Esc\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int lb, ub, h; //для задания новых размеров
				   //задаем начальные значения для координат x и y
	
	int x1, y1; // для задания смещения по осям x и y
	HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
	//проверка наличия окна в блокноте
	if (hwnd != NULL)
		{
		cout << "Окно найдено\n";
		wchar_t name[1024];
		GetWindowText(hwnd, name, sizeof(name));
		wcout << name << endl;
		}
	else
		 {
		cout << "Окно не найдено\n";
		}
	cin.get();
	// получаем контекст отображения
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	HBRUSH hOldBrush;
	HBRUSH hGreenBrush;
	HPEN hYellowPen;
	HPEN hOldPen;

	trapeze *t;
	
	shapeTrapeze* sht = new shapeTrapeze(500, 400, 300,30,30);
	filledTrapeze* filt = new filledTrapeze(350, 200, 400, 30, 30);
	combyTrapeze* comt = new combyTrapeze(400, 300, 400, 30, 30);
	
	trapezeTableOrdered <shapeTrapeze*> ntabShape(20);
	trapezeTableOrdered <filledTrapeze*> ntabFilled(20);
	trapezeTableOrdered <combyTrapeze*> ntabComby(20);
	
	setlocale(LC_ALL, "rus");
	for (;;)
		{
		shapeTrapeze *K = new shapeTrapeze(*sht); //вызываем конструктор копирования для создания нового объекта класса
		filledTrapeze*Kf = new filledTrapeze(*filt);
		combyTrapeze*Kc = new combyTrapeze(*comt);
			int variant = menu();
			int n;
			switch (variant)
			{
			case 1:
				t = sht;
				
				sht->SetPen(hdc); //выбрать перо для контура
				sht->SetText(hdc);// для вывода размера окна в виде текста
				do{
					sht->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				break;
			case 2:
				t = filt;
				filt->SetPen(hdc); //выбрать перо для контура
				filt->SetText(hdc);// для вывода размера окна в виде текста
				do
				{
					filt->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				
				break;
			case 3:
				t = comt;
				comt->SetPen(hdc); //выбрать перо для контура
				
				comt->SetText(hdc);// для вывода размера окна в виде текста
				do {
					comt->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
					
				break;
			case 4:
				sht->SaveFile();
			break;
			case 5:
				sht->ReadFile();
			case 6:
			
				try 
				{
					ub = sht->GetNewSizeUb(rt, hwnd);
					lb = sht->GetNewSizeLb(rt, hwnd);
					h = sht->GetNewSizeH(rt, hwnd);
					
				}
				catch (int error)
				{
					if (error==0)
					cout<<"Некорректно заданы параметры!!!"<<endl;
				}
				sht->SetSize(lb, ub, h);
			
				break;
			case 7:
				x1 = sht->GetBiassX();
				y1 = sht->GetBiassY();
				try 
				{
					sht->SetPosition(x1, y1, rt, hwnd);
				}
				catch (int error)
				{
					if (error == 0)
						cout << "Некорректно введено смещение!!!" << endl;
				}
				break;
			case 8:
				
				int i;
				cout << "Введите ключ добавляемого элемента для контура:\n" << endl;
				cin >> i;
				
							ntabShape.addTable(i, K);
				int i1;
				cout << "Введите ключ добавляемого элемента для закрашенной:\n" << endl;
				cin >> i1;
						
							ntabFilled.addTable(i1, Kf);
				int i2;
				cout << "Введите ключ добавляемого элемента для вложенной:\n" << endl;
				cin >> i2;
						
							ntabComby.addTable(i2, Kc);
				break;
			case 9:
				ntabShape.saveFileTable();
				break;
			case 10:
				n = ntabShape.sizeFromFile();
				ntabShape.set_n(n);
				ntabShape.printTableOfFile(sht, &ntabShape, n);
				break;
			case 11:
				int j;
				cout << "Введите ключ удаляемого элемента:\n" << endl;
				cin >> j;
				ntabShape.deleteTable(j);
				break;
			case 12:
				cout << "Трапеция-контур:\n" << endl;
				ntabShape.printTO();
				cout << "Трапеция-закрашенная:\n" << endl;
				ntabFilled.printTO();
				cout << "Трапеция с вложенной фигурой:\n" << endl;
				ntabComby.printTO();
				break;
			case 13:
				int find;
				cout << "Введите ключ элемента для поиска:\n" << endl;
				cin >> find;
				ntabShape.findTable(find);
				break;
			case 14:
				exit(0);
				break;
			}
		}
	delete sht;
	delete filt;
	delete comt;
}
