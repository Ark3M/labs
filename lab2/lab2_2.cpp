#include <iostream>
using namespace std;

// �������, ������� ����� ������������ � �������� �������
template <typename T, typename S>
S myfunc(S start,T numb)
{
	if (numb>0) return start+1; else return start;
}

// ������-�������
auto g = [](auto s,auto n){ return myfunc(s,n); };

// �������� ������� � ������� ���������� ������ � �������
template <typename S,typename T,typename F>
S mainfunc(T mas[], int size,F f)
{
	S res = 0;
	// ��� ���� ��������� ������� �������� func � ���������� res
	for (int i=0;i<size;i++) res = f(res,mas[i]);
	return res;
}

int main()
{
    int mas[5] = {1,2,-1,-2,4};
    cout<<mainfunc<int>(mas,5,g)<<endl;

    float mas2[5] = {1.0,2.0,-1.0,-2.7,4.5};
    cout<<mainfunc<int>(mas2,5,g)<<endl;

    double mas3[5] = {1.0,2.0,-1.0,-2.7,4.5};
    cout<<mainfunc<float>(mas3,5,g)<<endl;

    return 0;
}
