#pragma once
#include "trapeze.h"
#include "trapezeDrawable.h"
#include "trapezeTableOrdered.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
//����
int menu() 
{
	// ��������� ������� ����
	int variant; 
	cout << "�������� ����� ����\n" << endl;
	cout << "1. ���������� ������ ��������\n"
		<< "2. ���������� ����������� ��������\n"
		<< "3. ����������  ������ ������ ��������\n"
		<< "4. ��������� � ����\n"
		<< "5. ������� �� �����\n"
		<< "6. �������� �������\n"
		<< "7. ����������� ������\n"
		<< "8. ����� �� ���������\n"
		<< "9. �������� ������ � �������\n"
		<< "��� ������ � ������ ������� Esc\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int lb, ub, h; //��� ������� ����� ��������
				   //������ ��������� �������� ��� ��������� x � y
	
	int x1, y1; // ��� ������� �������� �� ���� x � y
	HWND hwnd = FindWindow(TEXT("Notepad"), NULL);
	//�������� ������� ���� � ��������
	if (hwnd != NULL)
		{
		cout << "���� �������\n";
		wchar_t name[1024];
		GetWindowText(hwnd, name, sizeof(name));
		wcout << name << endl;
		}
	else
		 {
		cout << "���� �� �������\n";
		}
	cin.get();
	// �������� �������� �����������
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	HBRUSH hOldBrush;
	HBRUSH hGreenBrush;
	HPEN hYellowPen;
	HPEN hOldPen;
	
	trapeze* t = new trapeze(500, 400, 300);
	trapezeDrawable *tD = new trapezeDrawable(t,30,30);

	setlocale(LC_ALL, "rus");
	for (;;)
		{
		
			int variant = menu();
			switch (variant)
			{
			case 1:
				
				tD->SetPen(hdc); //������� ���� ��� �������
				tD->SetText(hdc);// ��� ������ ������� ���� � ���� ������
				do{
					tD->Risov(hdc, buf, rt, hwnd);
				} while (getch() != 27);
				break;
			case 2:
				
				tD->SetPen(hdc); //������� ���� ��� �������
				tD->SetText(hdc);// ��� ������ ������� ���� � ���� ������
				do
				{
					hGreenBrush = tD->SetBrush(hdc); //������� ����� ��� �������
					HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
				tD->Risov(hdc, buf, rt, hwnd);
				tD->DelBrush(hdc, hGreenBrush, hOldBrush); //������� ����� ��� �������
				} while (getch() != 27);
				
				break;
			case 3:
				tD->SetPen(hdc); //������� ���� ��� �������
				
				tD->SetText(hdc);// ��� ������ ������� ���� � ���� ������
				do {
					hGreenBrush = tD->SetBrush(hdc); //������� ����� ��� �������
					HBRUSH	hOldBrush = SelectBrush(hdc, hGreenBrush);
					tD->Risov(hdc, buf, rt, hwnd);
					tD->DelBrush(hdc, hGreenBrush, hOldBrush); //������� ����� ��� �������
					tD->Vlozh(hdc);
				} while (getch() != 27);
					
				break;
			case 4:
				tD->SaveFile();
				break;
			case 5:
				tD->ReadFile();
				break;
			case 6:
				
				try 
				{
					ub = tD->GetNewSizeUb(rt, hwnd);
					lb = tD->GetNewSizeLb(rt, hwnd);
					h = tD->GetNewSizeH(rt, hwnd);
					
				}
				catch (int error)
				{
					if (error==0)
					cout<<"����������� ������ ���������!!!"<<endl;
				}
				tD->SetSize(lb, ub, h);
			
				break;
			case 7:
				x1 = tD->GetBiassX();
				y1 = tD->GetBiassY();
				try 
				{
					tD->SetPosition(x1, y1, rt, hwnd);
				}
				catch (int error)
				{
					if (error == 0)
						cout << "����������� ������� ��������!!!" << endl;
				}
				break;
			case 8:
				exit(0);
				break;
			case 9:
				trapezeTableOrdered *ntab = new trapezeTableOrdered;
				ntab->addTable(1, t);
				trapeze *t2 = new trapeze(100, 100, 300);
				ntab->addTable(1, t2);
				ntab->findTable(1);
				break;
			}
		}
	delete tD;
	delete t;
}
