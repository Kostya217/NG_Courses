#include <iostream>

using namespace std;

int main()
{
    int hesh = 0;
    const int lengthVowels = 6;
    const int lengthStr = 255;
    char vowels[lengthVowels] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    char str[lengthStr];

    cout << "Enter string : ";
    cin.get(str, 255);

    for(int i = 0 ; str[i] != '\0'; i++){
        if(str[i] != ' '){
            for(int j = 0; j < lengthVowels; j++){
                if (str[i] == vowels[j] || str[i] == vowels[j] + 32) {
                    hesh ++;
                }
            }
        }else if(str[i + 1] != ' ') {
            if(str[i + 1] != '\0'){
                hesh *= 10;
            }
        }
    }
    cout << "Hesh string is " << hesh;
    return 0;
}
