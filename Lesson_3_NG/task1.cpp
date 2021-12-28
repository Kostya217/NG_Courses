#include <iostream>

using namespace std;

int main()
{
    int arrayNum [10], sum = 0;
    for(int i = 0; i < 10; i++){
        cout << "Enter element array " << i << " : " ;
        cin >> arrayNum[i];
    }

    cout << endl << "[" ;
    for(int i = 0; i <  10 ; i++){
        cout << " | " << arrayNum[i] << " | " ;
    }
    cout << "]" << endl;

    cout << endl << "Enter the value by which you want to increment all the numbers in the array : " ;
    cin >> sum;

    for(int i = 0; i < 10; i++){
        arrayNum[i] += sum;
    }

    cout << endl << "[" ;
    for(int i = 0; i <  10 ; i++){
        cout << " | " << arrayNum[i] << " | " ;
    }
    cout << "]" << endl;

}
