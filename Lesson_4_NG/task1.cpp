#include <iostream>

using namespace std;

int main()
{
    int counterPunctuation = 0;
    int index = 0;
    const int lengthStr = 255;
    const int lengthSign = 11;
    char sign[lengthSign] = {'.', ',', ';', ':', '?', '!', '-', '"', '(', ')', '/'};
    char str [lengthStr];

    //Enter a line in which we will count the signs
    cout << "Enter string : ";
    cin.get(str, lengthStr);

    // counting characters
    while(str[index] != '\0'){
        for (int i = 0; i < lengthSign; i++){
            if(str[index] == sign[i]){
                counterPunctuation++;
            }
        }
        index++;
    }
    cout << "the number of punctuation marks is " << counterPunctuation;
    return 0;
}
