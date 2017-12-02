#include "trapeze.h"
#include "trapezeDraw.h"

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
		<< "��� ������ � ������ ������� Esc\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void main()
{
	setlocale(LC_ALL, "rus");
	trapeze* t = new trapeze(500, 400, 300);
	trapezeDraw *tD = new trapezeDraw();

	setlocale(LC_ALL, "rus");
	for (;;)
		{
		
			int variant = menu();
			switch (variant)
			{
			case 1:
				
				tD->SetPen(); //������� ���� ��� �������
				tD->SetText();// ��� ������ ������� ���� � ���� ������
				do{
					tD->risov(t);
				} while (getch() != 27);
				break;
			case 2:
				
				tD->SetPen(); //������� ���� ��� �������
				tD->SetText();// ��� ������ ������� ���� � ���� ������
				do
				{
				tD->SetBrush(); //������� ����� ��� �������
				tD->risov(t);
				} while (getch() != 27);
				tD->DelBrush(); //������� ����� ��� �������
				break;
			case 3:
				tD->SetPen(); //������� ���� ��� �������
				
				tD->SetText();// ��� ������ ������� ���� � ���� ������
				do {
					tD->SetBrush(); //������� ����� ��� �������
					tD->risov(t);
					tD->DelBrush(); //������� ����� ��� �������
					tD->vlozh(t);
				} while (getch() != 27);
					
				break;
			case 4:
				tD->SaveFile(t);
				break;
			case 5:
				tD->ReadFile(t);
				break;
			case 6:
				tD->GetNewSize();
				try 
				{
					tD->SetSize(t);
				}
				catch (int error)
				{
					if (error==0)
					cout<<"����������� ������ ���������!!!"<<endl;
				}

				break;
			case 7:
				tD->GetBiass();
				try 
				{
					tD->SetPosition();
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
			}
		}
	delete tD;
	delete t;
}
