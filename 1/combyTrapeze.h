#pragma once
#include "filledTrapeze.h"

class combyTrapeze: public filledTrapeze
{
protected:
	filledTrapeze *ft; //внутренняя фигура - закрашенная

public:
	combyTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew, filledTrapeze *ftNew);
	combyTrapeze(combyTrapeze&ct);

	void DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd);// переопределение чисто виртуальной функции
	void Enclised (HDC hdc); //рисовать вложенную фигуру

	~combyTrapeze();
};

