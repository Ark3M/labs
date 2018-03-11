#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <algorithm>

using namespace std;

void sdvig(int k,vector<int> mas){
    if(k > 0) rotate(mas.begin(),mas.end()-k,mas.end());
    else{
        k *= -1; rotate(mas.begin(),mas.begin()+k,mas.end());
    }
}

int main(){

    setlocale( LC_ALL,"Russian" );

    int k,n;
    cout << "Введите число k : ";
    cin >> k;
    cout << endl << "Введите число n : ";
    cin >> n;

    vector<int> mas(n); //для вывода в C++
    int* ptr = new int[n]; //для вывода в Си

    for(int i = 0; i < n; i++){
        cin >> mas[i];
        ptr[i] = mas[i];
    }

    cout << "1 способ (Си) : ";
    for(int i = 0; i < n; i++){
        printf("%d ",mas[i]);
    }
    cout << endl;
    cout << "2 способ (Си) : ";

    int i = 0;
    while(i < n){
        printf("%d ",*(ptr+i));
        i++;
    }

    cout << endl << "3 способ (C++) : ";
    for(auto& i : mas) cout << i << ' ';
    cout << endl;

    if(k > 0) rotate(mas.begin(),mas.end()-k,mas.end());
    else{
        k *= -1; rotate(mas.begin(),mas.begin()+k,mas.end());
    }

    cout << endl << "После сдвига на k" << endl;
    for(auto i : mas)cout << i << ' ';

    cout << endl;

    delete[]ptr;

    system("pause");
    return 0;
}
