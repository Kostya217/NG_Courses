#include <iostream>

using namespace std;

int main()
{
    int length = 255;
    int counterFack = 0;
    char str[length];

    cout << "Enter string : ";
    cin.get(str, length);

    for(int i = 0; i < length - 1; i++){
        if(str[i] != ' '){
            if( str[i] == 'f' &&
                str[i + 1] == 'u' &&
                str[i + 2] == 'c' &&
                str[i + 3] == 'k') {
                    i += 3;
                    for(int j = 0; j < 4; j++){
                        str[i - j] = '*';
                    }
            }
        }
    }

    cout << str << endl;
}
