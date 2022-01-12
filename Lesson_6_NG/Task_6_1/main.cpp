#include "cesareancode.h"

int main()
{
    string str = "";
    string result = "";
    int key = 0;
    cout << "Enter the string you want to encode : ";
    getline(cin, str);
    cout << "Enter key : ";
    cin >> key;

    CesareanCode *cesarean = new CesareanCode();
    cesarean -> SetStr(str);
    cesarean -> SetKey(key);



    if (cesarean->GetStr() != "" || cesarean->GetKey() > 0) {
        result = cesarean->Encryption();
        cout << result << endl;
        result = cesarean->Decryption();
        cout << result << endl;
    }
    else {
        cout << "ERROR" << endl;
    }

    cesarean->SetStr("Euax zgyq bkxe otzkxkyzotm!");
    cesarean->SetKey(6);
    result = cesarean->Decryption();
    cout << result << endl;
    return 0;
}
