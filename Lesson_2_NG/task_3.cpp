#include <iostream>
using namespace std;

int main(){
    int size_q ;
    cout << "Enter size square : " ;
    cin >> size_q;

    for(int i = 0; i < size_q; i++){
        cout << "*" ;
        for(int j = 0; j < size_q - 2; j++){
            if (i == 0 || i == size_q - 1)
                cout << "*";
            else
                cout << " " ;
        }
        cout << "*" << endl ;
    }

    return 0;
}
