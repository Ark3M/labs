#include <iostream>
#include <vector>
#include "plus.hpp"
#include <cstdlib>
using namespace std;

int main()
{

    setlocale( LC_ALL,"Russian" );
    //���� ������������ vector ��� ��������

    int n;
    cout<<"������� ������ ������� : ";
    cin >> n;
    vector<int> mas(n);
    cout<<"������� �������� ������� :"<<endl;
    for(int i = 0; i < n; i++){
        cin >> mas[i]; //��� cin >> mas[i]
        cout<<mas[i]<<' ';
    }
    cout<<endl;

    if(find_plus(mas)){
        cout<<"��� �������� ������� �������������!"<<endl;
    }
    else{
        cout<<"�� ��� �������� ������� �������������."<<endl;
    }

    system("pause");
    return 0;
}
