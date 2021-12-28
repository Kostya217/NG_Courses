#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int arrA[4], arrB[4];
    int summA = 0, summB = 0;
    srand(time(0));
    for(int i = 0; i < 4; i++){// filling the array with random numbers
        int num = 1 + rand() % (50 - 1 + 1);
        arrA[i] = num;

        num = 1 + rand() % (50 - 1 + 1);
        arrB[i] = num;
    }

    for(int i = 0; i < 4; i++) // print array A
        cout << arrA[i] << " " ;
    cout << endl << endl;

    for(int i = 0; i < 4; i++) // print array B
        cout << arrB[i] << " " ;

    // gluing array A
    for(int i = 0; i < 4; i++){
        for(int val = arrA[i]; val > 0; val /= 10){
            summA *= 10;
        }
        summA += arrA[i] ;
    }

    // gluing array B
    for(int i = 0; i < 4; i++){
        for(int val = arrB[i]; val > 0; val /= 10){
            summB *= 10;
        }
        summB += arrB[i] ;
    }

    cout << endl << endl << "Got : " << summA << " + " << summB << endl ;
    cout << "Result : " << summA + summB;
}
