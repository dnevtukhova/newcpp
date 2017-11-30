#include "trapeze.h"

#define _CRT_SECURE_NO_WARNINGS
void paintLine();
using namespace std;
//меню
int menu() 
{
	// ¬ыбранный вариант меню
	int variant; 
	cout << "¬ыберите пункт меню\n" << endl;
	cout << "1. Ќарисовать контур трапеции\n"
		<< "2. Ќарисовать закрашенную трапецию\n"
		<< "3. Ќарисовать фигуру внутри трапеции\n"
		<< "4. ¬ыход\n" << endl; 
	cout << ">>> ";
	cin >> variant;
	return variant;
}
//рисуем закрашенную фигуру
void paintPoligon()
{
	HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
	//проверка наличи€ окна в блокноте
	if (hwnd != NULL)  
	{
		cout << "ќкно найдено\n";
		wchar_t name[1024];
		GetWindowText(hwnd, name, sizeof(name));
		wcout << name << endl;
	}
	else 
	{
		cout << "ќкно не найдено\n";
	}
	cin.get();
	// получаем контекст отображени€
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	// устанавливаем цвет фона
	SetBkColor(hdc, RGB(0, 0, 0));
	// устанавливаем цвет текста
	SetTextColor(hdc, RGB(161, 70, 213));
	// создаем желтое перо
	HPEN hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// и выбираем его в контекст отображени€, сохран€€ предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hYellowPen);
	// создаем зеленую кисть
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));
	// и выбираем ее в контекст отображени€, сохран€€ предыдущую кисть
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	do
	{
		// получаем размер окна
		GetClientRect(hwnd, &rt);
		// формируем выводимую строку
		sprintf(buf, "–азмер окна %d на %d пикселей", rt.right, rt.bottom);
		// выводим строку графическими средствами
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		POINT ppt1[4] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 } };
		// рисуем закрашенную трапецию
		Polygon(hdc, ppt1, 4);
	} while (getch() != 27);
	// выбираем в контекст отображени€ предыдущую кисть
	SelectBrush(hdc, hOldBrush);
	// удал€ем зеленую кисть
	DeleteBrush(hGreenBrush);
	// выбираем в контекст отображени€ предыдущее перо
	SelectPen(hdc, hOldPen);
	// удал€ем желтое перо
	DeletePen(hYellowPen);
	// освобождаем контекст отображени€
	ReleaseDC(hwnd, hdc);
	
}

//рисуем контур
void paintLine()
{
// получаем контекст отображени€
HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
HDC hdc = GetDC(hwnd);
RECT rt;
char buf[100];
// устанавливаем цвет фона
SetBkColor(hdc, RGB(0, 0, 0));
// устанавливаем цвет текста
SetTextColor(hdc, RGB(161, 70, 213));
// создаем желтое перо
HPEN hYellowPen1 = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
HPEN hOldPen = SelectPen(hdc, hYellowPen1);
do
{
GetClientRect(hwnd, &rt);
sprintf(buf, "–азмер окна %d на %d пикселей", rt.right, rt.bottom);
TextOutA(hdc, 10, 10, buf, strlen(buf));
POINT ppt1[5] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 },{ 100,30 } };
//контур трапеции
Polygon(hdc, ppt1, 5);
} while (getch() != 27);

// выбираем в контекст отображени€ предыдущее перо
SelectPen(hdc, hOldPen);
// удал€ем желтое перо
DeletePen(hYellowPen1);
// освобождаем контекст отображени€
ReleaseDC(hwnd, hdc);
}

//рисуем две вложенные фигуры - трапецию, а в нее вложен эллипс
void paintTwoFigure()
{
HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
HDC hdc = GetDC(hwnd);
RECT rt;
char buf[100];
// устанавливаем цвет фона
SetBkColor(hdc, RGB(0, 0, 0));
// устанавливаем цвет текста
SetTextColor(hdc, RGB(161, 70, 213));
// создаем желтое перо
HPEN hYellowPen2 = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
HPEN hOldPen = SelectPen(hdc, hYellowPen2);
do
{
GetClientRect(hwnd, &rt);
sprintf(buf, "–азмер окна %d на %d пикселей", rt.right, rt.bottom);
TextOutA(hdc, 10, 10, buf, strlen(buf));
HBRUSH hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));
HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
POINT ppt1[5] = { { 100,30 },{ rt.right - 100,30 },{ rt.right - 50, rt.bottom - 50 },{ 30,rt.bottom - 50 },{ 100,30 } };
//трапеци€
Polygon (hdc, ppt1, 5);

SelectBrush(hdc, hOldBrush);
DeleteBrush(hGreenBrush);

Ellipse(hdc, 100, 30, rt.right - 100, rt.bottom - 50);
} while (getch() != 27);
// выбираем в контекст отображени€ предыдущее перо
SelectPen(hdc, hOldPen);
// удал€ем желтое перо
DeletePen(hYellowPen2);
// освобождаем контекст отображени€
ReleaseDC(hwnd, hdc);
}



void main()
{
	

	setlocale(LC_ALL, "rus");
	for (;;)
		{
			int variant = menu();
			switch (variant)
			{
			case 1:
				paintLine();
				break;
			case 2:
				paintPoligon();
				break;
			case 3:
				paintTwoFigure();
				break;
			}
		}		
}
