#pragma once
#include "shapeTrapeze.h"
#include "filled.h"


class filledTrapeze: public shapeTrapeze, public filled 
{

public:
	filledTrapeze(int lowerBaseNew, int upperBaseNew, int heightNew, int xNew, int yNew);
	filledTrapeze(filledTrapeze&ft);

	void DrawTrapeze(HDC hdc, char*buf, RECT rt, HWND hwnd); // переопределение чисто виртуальной функции

	~filledTrapeze();
};
