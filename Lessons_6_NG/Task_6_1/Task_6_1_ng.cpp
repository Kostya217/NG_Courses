#include "CesareanCode.h"

int main()
{
    string str = "";
    int key = 0;
    cout << "Enter the string you want to encode : ";
    getline(cin, str);
    cout << "Enter key : ";
    cin >> key;
    
    CesareanCode *сesarean = new CesareanCode();
    сesarean -> SetStr(str);
    сesarean -> SetKey(key);

    if (сesarean->GetStr() != "" || сesarean->GetKey() > 0) {
        cout << сesarean->Encryption() << endl;
        cout << сesarean->Decryption() << endl;
    }
    else cout << "ERROR" << endl;

    cout << сesarean->Decryption("Euax zgyq bkxe otzkxkyzotm!", 6) << endl;
    
    delete сesarean;
}
