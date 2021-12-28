#include <iostream>

using namespace std;

int main()
{
    int selector = 1;
    int index = 0;
    int countSymbol = 0;
    int operation = 0;
    char input[5];
    char bank[2][10][5]
    {
        {"0000", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"},// bank account
        {"5858", "1001", "2782", "8585", "7845", "9053", "2316", "3222", "1111", "4444"} // pin code
    };
    int dolars[] {500, 200, 45, 78, 89, 400, 100, 20456, 1200, 789};// money in account $

    while(true){

        // Bank account
        if(selector == 1){
            cout << "Bank account: ";
            cin >> input;
            cout << endl;
            for(index = 0; index < 10 && countSymbol != 4; index++){
                countSymbol = 0;
                for(int symbol = 0; symbol < 4 && input[4] == '\0'; symbol++){
                    if(bank[0][index][symbol] == input[symbol]){
                        countSymbol++;
                    }
                }
                if (countSymbol == 4){
                    selector = 2;
                    index--;
                }
            }
            if(index == 10){
                cout << "I don't can find Bank account, please try again " << endl << endl;
                continue;
            }
        }

        // PIN Code
        if(selector == 2){
            cout << "PIN : " ;
            cin >> input;
            countSymbol = 0;
            for(int symbol = 0; symbol < 4 && input[4] == '\0'; symbol++){
                if(bank[1][index][symbol] == input[symbol]){
                    countSymbol++;
                }
            }
            if(countSymbol == 4) {
                selector = 3;
            }
            else {
                cout << "Is password not correct, please try again " << endl << endl ;
                continue;
            }
        }

        // Operation money
        if(selector == 3){
            cout << endl
                 <<"Your money: " << dolars[index] << "$" << endl
                 << "What I can do?" << endl
                 << "1 - add money" << endl
                 << "2 - withdraw money" << endl << endl;
            cin >> operation;
        }
        switch(operation){
            case 1:
                cout << endl << "How much money do you want to add? " << endl<< endl;
                cin >> operation ;
                if(operation >= 0){
                    dolars[index] += operation;
                    selector = 3;
                }
                else{
                    cout << endl <<  "Enter the correct number" << endl;
                    selector = 0;
                    operation = 1;
                }
                break;
            case 2:
                cout << endl << "How much money do you want to withdraw? " << endl << endl;
                cin >> operation ;
                if(operation >= 0 && operation <= dolars[index] ){
                    dolars[index] -= operation;
                    selector = 3;
                }
                else{
                    cout << endl <<  "Enter the correct number" << endl;
                    selector = 0;
                    operation = 2;
                }
                break;
            default :
                cout << "This command don't find, try again" << endl << endl;
        }
    }
}
