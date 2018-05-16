#include <iostream>
using namespace std;

// �������, ������� ����� ������������ � �������� �������
int myfunc(int start,int numb)
{
	// ���� ����� �������������, �� ����������� ���������� start �� 1
	// ����� ������ ���������� ��� ��� ���������
	if (numb>0) return start+1; else return start;
}

// �������� ������� � ������� ���������� ������ � �������
int mainfunc(int *mas, int size, int (*func)(int start,int numb))
{
	int res = 0;
	// ��� ���� ��������� ������� �������� func � ���������� res
	for (int i=0;i<size;i++) res = func(res,mas[i]);
	return res;
}

int main()
{
	int mas[5] = {-1,2,-3,4}; // �������� ������
	cout<<"Positive numbers: "<<mainfunc(mas,5,myfunc)<<endl; // �������� ���������
	system("pause");
	return 0;
}

