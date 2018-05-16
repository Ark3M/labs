#include <iostream>
#include <math.h>

using namespace std;

// структура - точка на плоскости
struct my_point     
{                  
	int x,y;	
};                 
 
// функция - определяет, входит ли точка в окружность
// 1 - входит
// 2 - лежит на окружности
// 0 - не входит
int point_in_circle(my_point center, int radius, my_point point)
{
	// получаем расстояние от центра до точки
	double res = sqrt(pow(center.x - point.x,2.0)+pow(center.y - point.y,2.0));
	// если оно больше радиуса, то не входит
	if (res>radius) return 0; else
	// если равно радиусу с погрешностью, то лежит
	if (fabs(res-radius)<0.000001) return 2; 
	// иначе входит в окружность
	else return 1;
}

// определяем входит ли фигура в окружность
// 1 - входит
// 2 - лежит на окружности
// 0 - не входит
int figure_in_circle(my_point center, int radius, my_point *figure, int len)
{
	int all_on_perimetr = 1; // по умолчанию ставим, что все вершины на окружности
	// перебираем все вершины фигуры
	for (int i=0;i<len;i++)
	{	
		int res = point_in_circle(center,radius,figure[i]); // получаем результат по i-ой вершине
		if (res==0) return 0; // если лежит вне, то фигура не лежит в окружности
		if (res==1) all_on_perimetr = 0; // если вершина лежит внутри, то отменяем условие, что все вершины на окружности
	}
	if (all_on_perimetr==1) return 2; // если все на окружности, то фигура касается окружности
	return 1; // фигура лежит внутри окружности
}

int main()
{
	// вводим данные
	my_point center;
	int radius;
	cout<<"Input center of circle and radius: ";
	cin>>center.x>>center.y>>radius;

	int select;
	cout<<"Triangle(1) or rectangle(2) (1 or 2)?: ";
	cin>>select;

	my_point tr[4];
	int len=0;
	if (select==1) // вводим треугольник
	{
		cout<<"Input 3 points, x and y:";
		len = 3;
		cin>>tr[0].x>>tr[0].y>>tr[1].x>>tr[1].y>>tr[2].x>>tr[2].y;
	}
	else // вводим прямоугольник
	{
		cout<<"Input 4 points, x and y:";
		len = 4;
		cin>>tr[0].x>>tr[0].y>>tr[1].x>>tr[1].y>>tr[2].x>>tr[2].y>>tr[3].x>>tr[3].y;
	}
	// получаем и выводим результат
	switch (figure_in_circle(center,radius,tr,len))
	{
	case 0: {cout<<"outside"<<endl;break;}
	case 1: {cout<<"inside"<<endl;break;}
	case 2: {cout<<"touch"<<endl;break;}
	}
	system("pause");
	return 0;
}

