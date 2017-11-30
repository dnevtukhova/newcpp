#include "trapeze.h"



trapeze::trapeze()  // по умолчанию
{
	lowerBase = new int;  // выделение динамической пам€ти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = 100;  // присвоение значени€
	*upperBase = 50;
	*height = 50;
}
trapeze::trapeze(int lowerBaseNew, int upperBaseNew, int heightNew)
{
	lowerBase = new int;  // выделение динамической пам€ти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = lowerBaseNew;
	*upperBase = upperBaseNew;
	*height = heightNew;
}

trapeze::trapeze(trapeze &t)
{
	lowerBase = new int;  // выделение динамической пам€ти под переменные
	upperBase = new int;
	height = new int;
	*lowerBase = *(t.lowerBase);  // копирование из другого экземпл€ра
	*upperBase = *(t.upperBase);
	*height = *(t.height);
}

trapeze::~trapeze()  // деструктор
{
	delete lowerBase;  // очистка пам€ти
	delete upperBase;
	delete height;
}


