#include "trapezeDraw.h"
using namespace std;


trapezeDraw::trapezeDraw() 
{
	hwnd = FindWindow(TEXT("Notepad"), NULL);
	// получаем контекст отображения
	hdc = GetDC(hwnd);
}

void trapezeDraw::ReadFile(trapeze*t) //считать из файла
{
	char buff[50];
	int newLowerBase;
	int newUpperBase;
	int newHeight;
	ifstream fin("SaveTrapeze.txt");


	fin >> newLowerBase;
	fin >> newUpperBase;
	fin >> newHeight;

	t->Set_lowerBase(newLowerBase);
	 t->Set_upperBase(newUpperBase);
	 t->Set_height(newHeight);

	fin.close(); // закрыть файл
	cout << "Данные считаны из файла\n" << endl;
}



void trapezeDraw::SaveFile(trapeze *t) //сохранить в файл
{
	
		ofstream fout("SaveTrapeze.txt");
		
			fout << t->Get_lowerBase () << " ";
			fout << t->Get_upperBase () << " ";
			fout << t->Get_height ()<< " ";
		
		fout.close(); // закрыть файл
		cout << "Данные записаны в файл\n" << endl;
	
}


int trapezeDraw:: GetColour()
{
	int colour;
	cout << "Выберите цвет:\n" << endl;
	cout << "1. Желтый\n"
		<< "2. Зеленый\n"
		<< "3. Красный\n" << endl;
	cout << ">>> ";
	cin >> colour;
	return colour;
}

void trapezeDraw::SetText() 
{
	// устанавливаем цвет фона
	SetBkColor(hdc, RGB(0, 0, 0));
	// устанавливаем цвет текста
	SetTextColor(hdc, RGB(161, 70, 213));
}

void trapezeDraw::SetPen() 
{
	// создаем желтое перо
	 hYellowPen = CreatePen(PS_SOLID, 5, RGB(223, 238, 94));
	// и выбираем его в контекст отображения, сохраняя предыдущее перо
	hOldPen = SelectPen(hdc, hYellowPen);
	
}

void trapezeDraw::DelBrush()
{
	DeleteBrush(hGreenBrush);
	hOldBrush = SelectBrush(hdc, hOldBrush);
}

void trapezeDraw::SetBrush() //выбрать кисть для заливки
{
	int i = GetColour();
	if (i == 1) 
	{
		hGreenBrush = CreateSolidBrush( RGB(254, 254, 34));//желтый
	}

	else 
	{
		if (i == 2)
		{
			hGreenBrush = CreateSolidBrush(RGB(149, 246, 75));//зеленый
		}
		else 
		{
			hGreenBrush = CreateSolidBrush(RGB(252, 40, 71));//красный
		}
	}
		
	hOldBrush = SelectBrush(hdc, hGreenBrush);
}



void trapezeDraw::risov(trapeze* t)
{
		// получаем размер окна
		GetClientRect(hwnd, &rt);
		// формируем выводимую строку
		sprintf(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
		// выводим строку графическими средствами
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		int height = t->Get_height();
		int lowerBase = t->Get_lowerBase();
		int upperBase = t->Get_upperBase();
				POINT ppt1[4] = {{ (x+((lowerBase-upperBase)/2)),y },{ x + upperBase,y },{ x + lowerBase, y + height}, {  x,y + height }};
		// рисуем закрашенную трапецию
		Polygon(hdc, ppt1, 4);
}

void trapezeDraw::vlozh(trapeze*t)
{
		int height = t->Get_height();
		int upperBase = t->Get_upperBase();
		int lowerBase = t->Get_lowerBase();
		Ellipse(hdc, (x + ((lowerBase - upperBase) / 2)), y, x+ upperBase, y + height);
	
}

trapezeDraw::~trapezeDraw() 
{	
	SelectBrush(hdc, hOldBrush);
	// удаляем зеленую кисть
	DeleteBrush(hGreenBrush);
	// выбираем в контекст отображения предыдущее перо
	SelectPen(hdc, hOldPen);
	// удаляем желтое перо
	DeletePen(hYellowPen);
	// освобождаем контекст отображения
	ReleaseDC(hwnd, hdc);
}

void trapezeDraw::GetNewSize()
{
	cout << "Введите новое значение длины нижнего основания" << endl;
	cout << ">>> ";
	cin >> lb;
	cout << "Введите новое значение длины верхнего основания" << endl;
	cout << ">>> ";
	cin >> ub;
	cout << "Введите новое значение высоты" << endl;
	cout << ">>> ";
	cin >> h;
	if (lb<1 || lb>500) throw 0;
	if (ub<1 || ub>500) throw 0;
	if (h<1 || h>500) throw 0;
	
}

void trapezeDraw::SetSize(trapeze *t) 
{
	
	t->Set_lowerBase(lb);
	t->Set_upperBase(ub);
	t->Set_height(h);
}

void trapezeDraw:: GetBiass() //задать смещение (изменение положения)
{
	cout << "Введите смещение по оси x" << endl;
	cout << ">>> ";
	cin >> x1;
	cout << "Введите смещение по оси y" << endl;
	cout << ">>> ";
	cin >> y1;
}

void trapezeDraw::SetPosition() // изменить положение фигуры
{
	x = x + x1;
	y = y + y1;

	if (x<0 || x>500) throw 0;
	if (y<0 || y>500) throw 0;
}
