#include <iostream>

using namespace std;

int main()
{
    int length = 255;
    char str[length];
    cout << "Enter string : ";
    cin.get(str, 255);

    for(int i = 0; str[i + 1] != '\0'; i++){
        char fuck[4] = {'f', 'u', 'c', 'k'};
        int counterFack = 0;
        for(int j = 0; j < 4; j++ ,i++)
            if(str[i] == fuck[j]){
                counterFack++ ;
            }
            else {
                break;
            }
        if(counterFack == 4)
            for(int j = 0; j < 4; j++){
                str[i - j - 1] = '*';
            }
    }
    cout << str;
}
