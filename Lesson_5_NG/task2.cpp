#include <iostream>

using namespace std;

int BankAccount(char bank[][5], char input[]){
    int index = 0;
    int countSymbol = 0;
    for(; index < 10 && countSymbol != 4; index++){
        countSymbol = 0;

        for(int symbol = 0; symbol < 4 && input[4] == '\0'; symbol++){
            if(bank[index][symbol] == input[symbol]){
                countSymbol++;
            }
        }
        if (countSymbol == 4){
            break;
        }
    }
    if(index == 10){
        return -1;
    }
    return index;
}

int PinCode(char pin[][5], char input[], int index){

    int countSymbol = 0;
    for(int symbol = 0; symbol < 4 && input[4] == '\0'; symbol++){
        if(pin[index][symbol] == input[symbol]){
                    countSymbol++;
                }
        }
    if(countSymbol == 4) {
        return 0;
    }
    else {
        return -1;
        }
}

int OperationWithMoney(int dolars, int money, string AddOrWithdraw){

    if(money >= 0 && AddOrWithdraw == "add"){
        dolars += money;
    }
    else if(money >= 0 && money <= dolars && AddOrWithdraw == "withdraw"){
        dolars -= money;
    }
    else{
        cout << endl << "Enter the correct value" << endl;
        return -1;
    }
    return dolars;
}

int ErrorInputCheking(int dolars, int money, int *selector, string AddOrWithdraw){
    if(OperationWithMoney(dolars, money, AddOrWithdraw) == -1){
        *selector = 0;
    }else{
        dolars = OperationWithMoney(dolars, money, AddOrWithdraw) ;
        *selector = 3;
    }
    return dolars;
}

int main()
{
    int selector = 1;
    int index = 0;
    int operation = 0;
    int money = 0;
    char input[5];
    char bank[10][5] // bank account
        {"0000",
         "1111",
         "2222",
         "3333",
         "4444",
         "5555",
         "6666",
         "7777",
         "8888",
         "9999"};


    char pin[10][5]// pin code
        {"5858",
         "1001",
         "2782",
         "8585",
         "7845",
         "9053",
         "2316",
         "3222",
         "1111",
         "4444"};

    int dolars[10]// money in account $
        {500,
        200,
        45,
        78,
        89,
        400,
        100,
        20456,
        1200,
        789};

    while(true){
        // Bank account
        if(selector == 1){
            cout << "Bank account: ";
            cin >> input;
            cout << endl;
            if(BankAccount(bank, input) != -1){
                index = BankAccount(bank, input);
                selector = 2;

            }
            else {
                cout << "I don't can find Bank account, please try again " << endl << endl;
                continue;
            }
        }

        // PIN Code
        if(selector == 2){
            cout << "PIN : " ;
            cin >> input;

            if(PinCode(pin, input, index) == 0) {
                selector = 3;
            }
            else {
                cout << endl << "Is password not correct, please try again " << endl << endl ;
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
                cin >> money;
                dolars[index] = ErrorInputCheking(dolars[index], money, &selector, "add");

                break;
            case 2:
                cout << endl << "How much money do you want to withdraw? " << endl << endl;
                cin >> money;
                dolars[index] = ErrorInputCheking(dolars[index], money, &selector, "withdraw");
                break;
            default :
                cout << "This command don't find, try again" << endl << endl;
        }
    }
}
