#pragma once
#include "trapeze.h"
#include "shapeTrapeze.h"
#include "filledTrapeze.h"
#include "combyTrapeze.h"
#include "trapezeTableOrdered.h"

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
		<< "8. Добавить объект в таблицу\n"
		<< "9. Сохранить таблицу в файл\n"
		<< "10.Загрузить таблицу из файла\n"
		<< "11.Удалить элемент из таблицы\n" 
		<< "12.Вывести таблицу на экран\n"
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
	
	shapeTrapeze* t = new shapeTrapeze(500, 400, 300,30,30);
	filledTrapeze* filt = new filledTrapeze(500, 400, 300, 30, 30);
	combyTrapeze* comt = new combyTrapeze(500, 400, 300, 30, 30, filt);
	
	trapezeTableOrdered *ntab = new trapezeTableOrdered(20);
	
	setlocale(LC_ALL, "rus");
	for (;;)
		{
		shapeTrapeze *K = new shapeTrapeze(*t); //вызываем конструктор копирования для создания нового объекта класса
		filledTrapeze*Kf = new filledTrapeze(*filt);
		combyTrapeze*Kc = new combyTrapeze(*comt);
			int variant = menu();
			int n;
			switch (variant)
			{
			case 1:
				
				t->SetPen(hdc); //выбрать перо для контура
				t->SetText(hdc);// для вывода размера окна в виде текста
				do{
					t->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				break;
			case 2:
				
				filt->SetPen(hdc); //выбрать перо для контура
				filt->SetText(hdc);// для вывода размера окна в виде текста
				do
				{
					filt->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				
				break;
			case 3:
				comt->SetPen(hdc); //выбрать перо для контура
				
				comt->SetText(hdc);// для вывода размера окна в виде текста
				do {
					comt->DrawTrapeze(hdc, buf, rt, hwnd);
				} while (getch() != 27);
					
				break;
			case 4:
				t->SaveFile();
				break;
			case 5:
				t->ReadFile();
				break;
			case 6:
				
				try 
				{
					ub = t->GetNewSizeUb(rt, hwnd);
					lb = t->GetNewSizeLb(rt, hwnd);
					h = t->GetNewSizeH(rt, hwnd);
					
				}
				catch (int error)
				{
					if (error==0)
					cout<<"Некорректно заданы параметры!!!"<<endl;
				}
				t->SetSize(lb, ub, h);
			
				break;
			case 7:
				x1 = t->GetBiassX();
				y1 = t->GetBiassY();
				try 
				{
					t->SetPosition(x1, y1, rt, hwnd);
				}
				catch (int error)
				{
					if (error == 0)
						cout << "Некорректно введено смещение!!!" << endl;
				}
				break;
			case 8:
				int i;
				cout << "Введите ключ добавляемого элемента:\n" << endl;
				cin >> i;
				
				ntab->addTable(i, K);
				break;
			case 9:
				ntab->saveFileTable();
				break;
			case 10:
				n = ntab->sizeFromFile();
				ntab->set_n(n);
				ntab->printTableOfFile(t, ntab, n);
				break;
			case 11:
				int j;
				cout << "Введите ключ удаляемого элемента:\n" << endl;
				cin >> j;
				ntab->deleteTable(j);
				break;
			case 12:
				ntab->printTO();
				break;
			case 13:
				int find;
				cout << "Введите ключ элемента для поиска:\n" << endl;
				cin >> find;
				ntab->findTable(find);
				break;
			case 14:
				exit(0);
				break;
			}
		}
	delete t;
	delete filt;
	delete comt;
}
