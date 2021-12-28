#include <iostream>

using namespace std;

int main()
{
    int length = 255;
    char stringArrOne[length] = "";
    char stringArrTwo[length] = "";

    cout << "Enter string 1" << endl;
    cin.get(stringArrOne, length);
    cin.get();

    cout << "Enter string 2" << endl;
    cin.get(stringArrTwo, length);

    bool boolCompare = true;

    for(int i = 0; i < length; i ++)
    {
        if (stringArrOne[i] != stringArrTwo[i]) { boolCompare = false; break; }
    }
    boolCompare == true ? cout << "Strings are equal" : cout << "Strings not equal";
}
