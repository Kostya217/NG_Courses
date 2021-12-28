#ifndef CESAREANCODE_H
#define CESAREANCODE_H
#include <iostream>
#include <string>

using namespace std;

class CesareanCode
{
public :
    CesareanCode(){}
    CesareanCode(string inputStr)
    {
        str = inputStr;
    }
    CesareanCode(string inputStr, int inputKey)
    {
        str = inputStr;
        key = inputKey;
    }

    void SetKey(int inputKey) { key = inputKey; }
    int GetKey() { return key; }

    void SetStr(string inputStr) { str = inputStr; }
    string GetStr() { return str; }

    string Encryption();
    string Decryption();

    void CodingEncryption(string cesarean, int indexCesarean, int indexString);
    void CodingDecryption(string cesarean, int indexCesarean, int indexString);

private:
    string cesareanUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cesareanLower = "abcdefghijklmnopqrstuvwxyz";
    string str = "";
    int key = 0;
};

#endif // CESAREANCODE_H
