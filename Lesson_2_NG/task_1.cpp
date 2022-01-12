#include <iostream>

using namespace std;

int main(){
    int num, sum = 0;
    cout << "Enter your number : ";
    cin >> num ;

    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    cout <<"Sum all numbers in this number = " << sum ;
    return 0;
}








