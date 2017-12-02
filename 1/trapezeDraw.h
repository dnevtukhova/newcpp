#pragma once
#include "trapeze.h"

class trapezeDraw
{
private:
	int lb, ub, h; //для задания новых размеров
	//задаем начальные значения для координат x и y
	int x = 30;
	int y = 30;
	int x1, y1; // для задания смещения по осям x и y
	HWND hwnd;
	HDC hdc;
	RECT rt;
	char buf[100];
	HBRUSH hOldBrush;
	HBRUSH hGreenBrush;
	HPEN hYellowPen;
	HPEN hOldPen;
	
	
public:
	trapezeDraw();

	int GetColour(); //Ввести цвет
	void SetText();// для вывода размера окна в виде текста
	void SetPen(); //выбрать перо для контура
	void SetBrush(); //выбрать кисть для заливки
	void DelBrush(); //удалить кисть
	void risov(trapeze* t);
	void vlozh(trapeze*t); 
	void GetNewSize(); //задать новые размеры фигуры
	void SetSize(trapeze*t); //изменить размеры фигуры
	void SetPosition(); // изменить положение фигуры
	void GetBiass(); //задать смещение (изменение положения)
	void ReadFile(trapeze*t);
	void SaveFile(trapeze*t);

	~trapezeDraw();
};