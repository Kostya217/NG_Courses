#include <iostream>

using namespace std;

int main()
{
    int counterPunctuation = 0;
    int index = 0;
    char sign[11] = {'.', ',', ';', ':', '?', '!', '-', '"', '(', ')', '/'};
    char str [255];

    //Enter a line in which we will count the signs
    cout << "Enter string : ";
    cin.get(str, 255);

    // counting characters
    while(str[index] != '\0'){
        for (int i = 0; i < 11; i++){
            if(str[index] == sign[i]){
                counterPunctuation++;
            }
        }
        index++;
    }
    cout << "the number of punctuation marks is " << counterPunctuation;
    return 0;
}
