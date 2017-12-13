#pragma once
#include "trapeze.h"
#include "trapezeDrawable.h"
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
		<< "8. Выход из программы\n"
		<< "9. Добавить объект в таблицу\n"
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
	
	trapeze* t = new trapeze(500, 400, 300);
	trapezeDrawable *tD = new trapezeDrawable(t,30,30);

	setlocale(LC_ALL, "rus");
	for (;;)
		{
		
			int variant = menu();
			switch (variant)
			{
			case 1:
				
				tD->SetPen(hdc); //выбрать перо для контура
				tD->SetText(hdc);// для вывода размера окна в виде текста
				do{
					tD->Risov(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				break;
			case 2:
				
				tD->SetPen(hdc); //выбрать перо для контура
				tD->SetText(hdc);// для вывода размера окна в виде текста
				do
				{
					hGreenBrush = tD->SetBrush(hdc); //выбрать кисть для заливки
					HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
				tD->Risov(hdc, buf, rt, hwnd);
				tD->DelBrush(hdc, hGreenBrush, hOldBrush); //удалить кисть для заливки
				} while (getch() != 27);
				
				break;
			case 3:
				tD->SetPen(hdc); //выбрать перо для контура
				
				tD->SetText(hdc);// для вывода размера окна в виде текста
				do {
					hGreenBrush = tD->SetBrush(hdc); //выбрать кисть для заливки
					HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
					tD->Risov(hdc, buf, rt, hwnd);
					tD->DelBrush(hdc, hGreenBrush, hOldBrush); //удалить кисть для заливки
					tD->Vlozh(hdc);
				} while (getch() != 27);
					
				break;
			case 4:
				tD->SaveFile();
				break;
			case 5:
				tD->ReadFile();
				break;
			case 6:
				
				try 
				{
					ub = tD->GetNewSizeUb(rt, hwnd);
					lb = tD->GetNewSizeLb(rt, hwnd);
					h = tD->GetNewSizeH(rt, hwnd);
					
				}
				catch (int error)
				{
					if (error==0)
					cout<<"Некорректно заданы параметры!!!"<<endl;
				}
				tD->SetSize(lb, ub, h);
			
				break;
			case 7:
				x1 = tD->GetBiassX();
				y1 = tD->GetBiassY();
				try 
				{
					tD->SetPosition(x1, y1, rt, hwnd);
				}
				catch (int error)
				{
					if (error == 0)
						cout << "Некорректно введено смещение!!!" << endl;
				}
				break;
			case 8:
				exit(0);
				break;
			case 9:
				trapezeTableOrdered *ntab = new trapezeTableOrdered;
				ntab->addTable(1, t);
				trapeze *t2 = new trapeze(100, 100, 300);
				ntab->addTable(1, t2);
				ntab->findTable(1);
				break;
			}
		}
	delete tD;
	delete t;
}
