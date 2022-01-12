#include <iostream>

using namespace std;

int main(){
    int num = 0;
    int sum = 0;

    cout << "Enter your number : ";
    cin >> num;

    for(int i = num; i > 0; i /= 10){
        int lastNumber = i % 10;
        int number = i / 10;
        if( (lastNumber == number % 10) ||(num % 10 == lastNumber && number == 0)) {
            sum += lastNumber;
        }
    }

    cout << "Sum hesh = " << sum << endl;
    return 0;
}
