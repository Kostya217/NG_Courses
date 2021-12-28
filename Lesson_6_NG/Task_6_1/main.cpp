#include "cesareancode.h"

int main()
{
    string str = "";
    int key = 0;
    cout << "Enter the string you want to encode : ";
    getline(cin, str);
    cout << "Enter key : ";
    cin >> key;

    CesareanCode *cesarean = new CesareanCode();
    cesarean -> SetStr(str);
    cesarean -> SetKey(key);



    if (cesarean->GetStr() != "" || cesarean->GetKey() > 0) {
        cout << cesarean->Encryption() << endl;
        cout << cesarean->Decryption() << endl;
    }
    else cout << "ERROR" << endl;

    cesarean->SetStr("Euax zgyq bkxe otzkxkyzotm!");
    cesarean->SetKey(6);
    cout << cesarean->Decryption() << endl;
    return 0;
}
