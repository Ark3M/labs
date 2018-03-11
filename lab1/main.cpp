#include <iostream>
#include <vector>
#include "plus.hpp"
#include <cstdlib>
using namespace std;

int main()
{

    setlocale( LC_ALL,"Russian" );
    //буду использовать vector для простоты

    int n;
    cout<<"Задайте размер массива : ";
    cin >> n;
    vector<int> mas(n);
    cout<<"Введите элементы массива :"<<endl;
    for(int i = 0; i < n; i++){
        cin >> mas[i]; //или cin >> mas[i]
        cout<<mas[i]<<' ';
    }
    cout<<endl;

    if(find_plus(mas)){
        cout<<"Все элементы массива положительные!"<<endl;
    }
    else{
        cout<<"Не все элементы массива положительные."<<endl;
    }

    system("pause");
    return 0;
}
