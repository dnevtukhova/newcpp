#include "trapeze.h"
#include "trapezeDraw.h"

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
		<< "Для выхода с уровня нажмите Esc\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void main()
{
	setlocale(LC_ALL, "rus");
	trapeze* t = new trapeze(500, 400, 300);
	trapezeDraw *tD = new trapezeDraw();

	setlocale(LC_ALL, "rus");
	for (;;)
		{
		
			int variant = menu();
			switch (variant)
			{
			case 1:
				
				tD->SetPen(); //выбрать перо для контура
				tD->SetText();// для вывода размера окна в виде текста
				do{
					tD->risov(t);
				} while (getch() != 27);
				break;
			case 2:
				
				tD->SetPen(); //выбрать перо для контура
				tD->SetText();// для вывода размера окна в виде текста
				do
				{
				tD->SetBrush(); //выбрать кисть для заливки
				tD->risov(t);
				} while (getch() != 27);
				tD->DelBrush(); //удалить кисть для заливки
				break;
			case 3:
				tD->SetPen(); //выбрать перо для контура
				
				tD->SetText();// для вывода размера окна в виде текста
				do {
					tD->SetBrush(); //выбрать кисть для заливки
					tD->risov(t);
					tD->DelBrush(); //удалить кисть для заливки
					tD->vlozh(t);
				} while (getch() != 27);
					
				break;
			case 4:
				tD->SaveFile(t);
				break;
			case 5:
				tD->ReadFile(t);
				break;
			case 6:
				tD->GetNewSize();
				try 
				{
					tD->SetSize(t);
				}
				catch (int error)
				{
					if (error==0)
					cout<<"Некорректно заданы параметры!!!"<<endl;
				}

				break;
			case 7:
				tD->GetBiass();
				try 
				{
					tD->SetPosition();
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
			}
		}
	delete tD;
	delete t;
}
