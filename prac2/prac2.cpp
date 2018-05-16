#include <iostream>
#include <math.h>

using namespace std;

// ��������� - ����� �� ���������
struct my_point     
{                  
	int x,y;	
};                 
 
// ������� - ����������, ������ �� ����� � ����������
// 1 - ������
// 2 - ����� �� ����������
// 0 - �� ������
int point_in_circle(my_point center, int radius, my_point point)
{
	// �������� ���������� �� ������ �� �����
	double res = sqrt(pow(center.x - point.x,2.0)+pow(center.y - point.y,2.0));
	// ���� ��� ������ �������, �� �� ������
	if (res>radius) return 0; else
	// ���� ����� ������� � ������������, �� �����
	if (fabs(res-radius)<0.000001) return 2; 
	// ����� ������ � ����������
	else return 1;
}

// ���������� ������ �� ������ � ����������
// 1 - ������
// 2 - ����� �� ����������
// 0 - �� ������
int figure_in_circle(my_point center, int radius, my_point *figure, int len)
{
	int all_on_perimetr = 1; // �� ��������� ������, ��� ��� ������� �� ����������
	// ���������� ��� ������� ������
	for (int i=0;i<len;i++)
	{	
		int res = point_in_circle(center,radius,figure[i]); // �������� ��������� �� i-�� �������
		if (res==0) return 0; // ���� ����� ���, �� ������ �� ����� � ����������
		if (res==1) all_on_perimetr = 0; // ���� ������� ����� ������, �� �������� �������, ��� ��� ������� �� ����������
	}
	if (all_on_perimetr==1) return 2; // ���� ��� �� ����������, �� ������ �������� ����������
	return 1; // ������ ����� ������ ����������
}

int main()
{
	// ������ ������
	my_point center;
	int radius;
	cout<<"Input center of circle and radius: ";
	cin>>center.x>>center.y>>radius;

	int select;
	cout<<"Triangle(1) or rectangle(2) (1 or 2)?: ";
	cin>>select;

	my_point tr[4];
	int len=0;
	if (select==1) // ������ �����������
	{
		cout<<"Input 3 points, x and y:";
		len = 3;
		cin>>tr[0].x>>tr[0].y>>tr[1].x>>tr[1].y>>tr[2].x>>tr[2].y;
	}
	else // ������ �������������
	{
		cout<<"Input 4 points, x and y:";
		len = 4;
		cin>>tr[0].x>>tr[0].y>>tr[1].x>>tr[1].y>>tr[2].x>>tr[2].y>>tr[3].x>>tr[3].y;
	}
	// �������� � ������� ���������
	switch (figure_in_circle(center,radius,tr,len))
	{
	case 0: {cout<<"outside"<<endl;break;}
	case 1: {cout<<"inside"<<endl;break;}
	case 2: {cout<<"touch"<<endl;break;}
	}
	system("pause");
	return 0;
}

