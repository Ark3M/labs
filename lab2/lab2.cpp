#include <iostream>
using namespace std;

// функция, которая будет передаваться в основную функцию
int myfunc(int start,int numb)
{
	// если число положительное, то увеличиваем переданный start на 1
	// иначе просто возвращаем его без изменений
	if (numb>0) return start+1; else return start;
}

// основная функция в которую передается массив и функция
int mainfunc(int *mas, int size, int (*func)(int start,int numb))
{
	int res = 0;
	// для всех элементов массива вызываем func с параметром res
	for (int i=0;i<size;i++) res = func(res,mas[i]);
	return res;
}

int main()
{
	int mas[5] = {-1,2,-3,4}; // тестовый массив
	cout<<"Positive numbers: "<<mainfunc(mas,5,myfunc)<<endl; // печатаем результат
	system("pause");
	return 0;
}

