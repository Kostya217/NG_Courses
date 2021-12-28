#include <iostream>

using namespace std;

void PrintLine(int lengthLine, char symbol){
    cout << symbol;
    if(lengthLine > 1) {
        PrintLine(lengthLine - 1, symbol);
    }
}

void RecursiveDrawSquareFrame(int hight, int width){
     if ((hight == width) || (width - hight == width - 1)) {
        PrintLine(width, '*');
     }
     else {
        cout << "*";
        PrintLine(width - 2, ' ');
        cout << "*";
    }
    cout << endl;
    if(hight > 1) {
        RecursiveDrawSquareFrame(hight - 1, width);
    }
}

void DrawingSquareFrame(int sizeSquare){
    RecursiveDrawSquareFrame(sizeSquare, sizeSquare);
}

int main(){
    int sizeFrame = 0;
    cout << "Enter size Frame : " ;
    cin >> sizeFrame;
    DrawingSquareFrame(sizeFrame);
    return 0;
}
