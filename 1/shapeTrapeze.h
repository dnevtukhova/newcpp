#pragma once
#include "trapeze.h"

class shapeTrapeze: public trapeze
{
protected:
	int *x;
	int *y;
public:
	shapeTrapeze();  // конструктор по умолчанию

	shapeTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew);  // конструктор с заданными параметрами
	shapeTrapeze(shapeTrapeze &t);  //конструктор копирования
	int Get_lowerBase(); //получить значение
	int Get_upperBase();
	int Get_height();
	void Set_lowerBase(int lb); // изменить значение
	void Set_upperBase(int ub);
	void Set_height(int h);
	void SetText(HDC hdc);// для вывода размера окна в виде текста
	void SetPen(HDC hdc); //выбрать перо для контура

	void DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd);// переопределение чисто виртуальной функции

	int GetNewSizeLb(RECT rt, HWND hwnd); //задать новые размеры фигуры
	int GetNewSizeUb(RECT rt, HWND hwnd);
	int GetNewSizeH(RECT rt, HWND hwnd);
	void SetSize(int lb, int ub, int h); //изменить размеры фигуры
	void SetPosition(int x1, int y1, RECT rt, HWND hwnd); // изменить положение фигуры
	int GetBiassX(); //задать смещение (изменение положения по оси X)
	int GetBiassY(); //задать смещение (изменение положения по оси Y)
	void ReadFile();//считать из файла
	void SaveFile();//сохранить в файл
	

	~shapeTrapeze();  // деструктор*/

};
