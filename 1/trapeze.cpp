#include "trapeze.h"



trapeze::trapeze()  // �� ���������
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = 100;  // ���������� ��������
	*upperBase = 50;
	*height = 50;
}
trapeze::trapeze(int lowerBaseNew, int upperBaseNew, int heightNew)
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = lowerBaseNew;
	*upperBase = upperBaseNew;
	*height = heightNew;
}

trapeze::trapeze(trapeze &t)
{
	lowerBase = new int;  // ��������� ������������ ������ ��� ����������
	upperBase = new int;
	height = new int;
	*lowerBase = *(t.lowerBase);  // ����������� �� ������� ����������
	*upperBase = *(t.upperBase);
	*height = *(t.height);
}

trapeze::~trapeze()  // ����������
{
	delete lowerBase;  // ������� ������
	delete upperBase;
	delete height;
}


