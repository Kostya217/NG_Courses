#include "cesareancode.h"

string CesareanCode::Encryption() {
    if (key <= 0 || str == "") return "";

    for (int i = 0; i < key; i++)
    {
        for (size_t j = 0; j < str.length(); j++)
        {
            if (str[j] != ' '){
                for (size_t k = 0; k < cesareanLower.length(); k++)
                {
                    if (str[j] == cesareanLower[k]) {
                        CodingEncryption(cesareanLower, k ,j);
                        break;
                    }
                    else if (str[j] == cesareanUpper[k]) {
                        CodingEncryption(cesareanUpper, k, j);
                        break;
                    }
                }
            }
        }
    }
    return str;
}

string CesareanCode::Decryption() {
    for (int i = 0; i < key; i++)
    {
        for (size_t j = 0; j < str.length(); j++)
        {
            if (str[j] != ' '){
                for (size_t k = 0; k < cesareanLower.length(); k++)
                {
                    if (str[j] == cesareanLower[k]) {
                        CodingDecryption(cesareanLower, k, j);
                        break;
                    }
                    else if (str[j] == cesareanUpper[k]) {
                        CodingDecryption(cesareanUpper, k, j);
                        break;
                    }
                }
            }

        }
    }
    return str;
}

void CesareanCode::CodingEncryption(string cesarean, int indexCesarean, int indexString)
{
    if ((indexCesarean + 1) > (int)(cesarean.length() - 1)) str[indexString] = cesarean[(cesarean.length() - indexCesarean - 1)];
    else str[indexString] = cesarean[indexCesarean + 1];
}

void CesareanCode::CodingDecryption(string cesarean, int indexCesarean, int indexString)
{
    if ((indexCesarean - 1) < 0) str[indexString] = cesarean[(cesarean.length() - indexCesarean - 1)];
    else str[indexString] = cesarean[indexCesarean - 1];
}
