#pragma once
#include "trapeze.h"

class trapezeDraw
{
private:
	//int i,a1, b1, a2, b2, x1, x2, y1, y2, cvet, foncvet, shirina, sm_x, sm_y, maxx, maxy;
	FILE*fp;
	FILE*fp2;
	HWND hwnd;
	HDC hdc;
	RECT rt;
	char buf[100];
	
public:
	trapezeDraw();
	~trapezeDraw();

	BYTE SetColour1(); //выбрать цвет
	int GetColour(); //¬вести цвет

	void SetPen(HDC hdc, RECT rt); //выбрать перо дл€ контура
	 void SetBrush(HDC hdc, RECT rt); //выбрать кисть дл€ заливки
	void SetText(HDC hdc, RECT rt);// дл€ вывода размера окна в виде текста
	void trapezeDraw::risov(trapeze* t);
	//-----void trapezeDraw::zaliv();
	void trapezeDraw::vlozh(int *upperBase, int *height);
	//void trapeze::prov_dannyh();
	//void trapeze::prov_vlozh();
	void trapezeDraw::izm_polozh();
	void trapezeDraw::settings(); ///??
	void trapezeDraw::read_file();
	void trapezeDraw::save_file();




	

};