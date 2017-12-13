#pragma once
#include "trapeze.h"

class trapezeDrawable
{
private:
	trapeze * trap;
	int *x;
	int *y;
		
public:
	trapezeDrawable(trapeze *t, int xNew, int yNew);

	int GetColour(); //Ввести цвет
	void SetText(HDC hdc);// для вывода размера окна в виде текста
	void SetPen(HDC hdc); //выбрать перо для контура
	HBRUSH SetBrush(HDC hdc); //выбрать кисть для заливки
	void DelBrush(HDC hdc, HBRUSH hGreenBrush, HBRUSH hOldBrush); //удалить кисть
	void Risov(HDC hdc, char*buf, RECT rt, HWND hwnd);//рисовать
	void Vlozh(HDC hdc); //рисовать вложенную фигуру
	int GetNewSizeLb(RECT rt, HWND hwnd); //задать новые размеры фигуры
	int GetNewSizeUb(RECT rt, HWND hwnd);
	int GetNewSizeH(RECT rt, HWND hwnd);
	void SetSize(int lb, int ub, int h); //изменить размеры фигуры
	void SetPosition(int x1, int y1, RECT rt, HWND hwnd); // изменить положение фигуры
	int GetBiassX(); //задать смещение (изменение положения по оси X)
	int GetBiassY(); //задать смещение (изменение положения по оси Y)
	void ReadFile();//считать из файла
	void SaveFile();//сохранить в файл

	~trapezeDrawable();
};