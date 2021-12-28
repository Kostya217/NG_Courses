#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
This calculator can do such things as:
Adding: "+";
Subtraction: "-";
Multiplication: "*";
Division: "/";
Count actions in brackets;
Raise to the degree: "number^power";
Take the square root of the number: "sqrt(number)"
*/

struct ArrayCalc
{
    double* CountCalc;
    int length;
};

void PrintArr(double arr[], int length) {
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << ' ';
    }
}

// Function to remove an element in an array
void DeleteIndexArr(double* arrCountCalc, int indexDelete, int length) {
    for (int i = indexDelete; i < length - 1; i++)
    {
        arrCountCalc[i] = arrCountCalc[i + 1];
    }
    arrCountCalc[length - 1] = 0;
}

// Function to add 2 elements
double Sum(double addition1, double addition2) {
    return addition1 + addition2;
}

// Function for subtracting 2 items
double Subtraction(double reduction, double subtractor) {
    return reduction - subtractor;
}

//Function for multiplying 2 elements
double Multiplication(double multiplier1, double multiplier2) {
    return multiplier1 * multiplier2;
}

// Function for dividing 2 elements
double Division(double divided, double divider) {
    return divided / divider;
}

void EncryptionSing(string inputCalc, double* arrCountCalc, bool logicEncryptionSing = false, double* coding = 0) {
    string number = "";
    int index = 0;
    for (size_t i = 1; i < inputCalc.length(); i++)
    {
        // We skip the action signs and fill them with only numbers.
        if ((inputCalc[i] == '+') || (inputCalc[i] == '-') || (inputCalc[i] == '*') || (inputCalc[i] == '/') || (inputCalc[i] == '(') || (inputCalc[i] == ')') || (inputCalc[i] == '^') || (inputCalc[i] == 's' && inputCalc[i + 1] == 'q' && inputCalc[i + 2] == 'r' && inputCalc[i + 3] == 't') || (inputCalc[i] == '\0')) {
            number = "";
            index++;
            if (logicEncryptionSing) {
                if (inputCalc[i] == '*') {
                    arrCountCalc[index] = *coding + 10;
                    index++;
                } // Sign *
                else if (inputCalc[i] == '/') {
                    arrCountCalc[index] = *coding + 20;
                    index++;
                } // Sign /
                else if (inputCalc[i] == '+') {
                    arrCountCalc[index] = *coding + 30;
                    index++;
                } // Sign +
                else if (inputCalc[i] == '-') {
                    arrCountCalc[index] = *coding + 40;
                    index++;
                } // Sign -
                else if (inputCalc[i] == '(') {
                    index--;
                    arrCountCalc[index] = *coding + 50;
                    index++;
                } // Sign )
                else if (inputCalc[i] == ')') {
                    arrCountCalc[index] = *coding + 60;
                } // Sign (
                else if (inputCalc[i] == '^') {
                    arrCountCalc[index] = *coding + 70;
                    index++;
                } // Sign ^
                else if (inputCalc[i] == 's' && inputCalc[i + 1] == 'q' && inputCalc[i + 2] == 'r' && inputCalc[i + 3] == 't') {
                    index--;
                    arrCountCalc[index] = *coding + 80;
                    index++; i += 3;
                } // Sign #
            }
            else {
                if (inputCalc[i] == 's' && inputCalc[i + 1] == 'q' && inputCalc[i + 2] == 'r' && inputCalc[i + 3] == 't') i += 3;
            }
        }
        // We glue all the signs into one number, which is in front of the action sign
        else {
            number += inputCalc[i];
            if ((inputCalc[i + 1] == '+') || (inputCalc[i + 1] == '-') || (inputCalc[i + 1] == '*') || (inputCalc[i + 1] == '/') || (inputCalc[i + 1] == '(') || (inputCalc[i + 1] == ')') || (inputCalc[i + 1] == '^') || (inputCalc[i + 1] == 's' && inputCalc[i + 2] == 'q' && inputCalc[i + 3] == 'r' && inputCalc[i + 4] == 't') || (inputCalc[i + 1] == '\0')) {
                arrCountCalc[index] = stold(number);
            }
        }
    }
}

// Convert an array of char to an array of double
ArrayCalc ConvertArrayToDouble(string inputCalc, double* coding) {
    inputCalc += '\0';
    ArrayCalc arr;
    arr.length = 0;
    for (size_t i = 1; i < inputCalc.length(); i++)
    {
        // We skip the action signs and fill them with only numbers.
        if ((inputCalc[i] == '+') || (inputCalc[i] == '-') || (inputCalc[i] == '*') || (inputCalc[i] == '/') || (inputCalc[i] == '(') || (inputCalc[i] == ')') || (inputCalc[i] == '^') || (inputCalc[i] == 's' && inputCalc[i + 1] == 'q' && inputCalc[i + 2] == 'r' && inputCalc[i + 3] == 't') || (inputCalc[i] == '\0')) {
            arr.length++;
        }
        // We glue all the signs into one number, which is in front of the action sign
        else {
            if ((inputCalc[i + 1] == '+') || (inputCalc[i + 1] == '-') || (inputCalc[i + 1] == '*') || (inputCalc[i + 1] == '/') || (inputCalc[i + 1] == '(') || (inputCalc[i + 1] == ')') || (inputCalc[i + 1] == '^') || (inputCalc[i + 1] == 's' && inputCalc[i + 2] == 'q' && inputCalc[i + 3] == 'r' && inputCalc[i + 4] == 't') || (inputCalc[i + 1] == '\0')) {
                arr.length++;
            }
        }
    }
    arr.length--;
    arr.CountCalc = new double[arr.length];

    EncryptionSing(inputCalc, arr.CountCalc);

    // We find the maximum number to later take this change for encoding arephmetic operations
    for (size_t i = 0; i < inputCalc.length(); i++)
    {
        if (arr.CountCalc[i] > *coding) {
            *coding = arr.CountCalc[i];
        }
    }

    EncryptionSing(inputCalc, arr.CountCalc, true, &*coding);
    cout << "Convert array -> ";
    PrintArr(arr.CountCalc, arr.length);
    cout << endl;

    // Returns the encoded array
    return arr;
}
// A function that changes the encoding of characters
void CharacterEncoding(double coding, double lastCoding, double* arrCountCalc, int length) {
    for (int j = 0; j < length; j++)
    {
        if ((arrCountCalc[j] == lastCoding + 10) || (arrCountCalc[j] == lastCoding + 20) || (arrCountCalc[j] == lastCoding + 30) || (arrCountCalc[j] == lastCoding + 40) || (arrCountCalc[j] == lastCoding + 50) || (arrCountCalc[j] == lastCoding + 60) || (arrCountCalc[j] == lastCoding + 70) || (arrCountCalc[j] == lastCoding + 80)) {
            if (arrCountCalc[j] == lastCoding + 10) {
                arrCountCalc[j] = coding + 10;
            }// Sing *
            else if (arrCountCalc[j] == lastCoding + 20) {
                arrCountCalc[j] = coding + 20;
            }// Sign /
            else if (arrCountCalc[j] == lastCoding + 30) {
                arrCountCalc[j] = coding + 30;
            }// Sign +
            else if (arrCountCalc[j] == lastCoding + 40) {
                arrCountCalc[j] = coding + 40;
            }// Sign -
            else if (arrCountCalc[j] == lastCoding + 50) {
                arrCountCalc[j] = coding + 50;
            }// Sign (
            else if (arrCountCalc[j] == lastCoding + 60) {
                arrCountCalc[j] = coding + 60;
            }// Sign )
            else if (arrCountCalc[j] == lastCoding + 70) {
                arrCountCalc[j] = coding + 70;
            }// Sign ^
            else if (arrCountCalc[j] == lastCoding + 80) {
                arrCountCalc[j] = coding + 80;
            }// Sign sqrt
        }
    }
    cout << "Character Encoding array -> ";
    PrintArr(arrCountCalc, length);
    cout << endl;
}

void LogicCalc(double* lastCoding, double* coding, int* index, int* indexEnd, double* arrCountCalc, int length, double calc) {
    *lastCoding = *coding;
    // If the arithmetic operation is greater than our coding, we change the coding of numbers for correct calculations
    if (calc > *coding) {
        *coding = calc;
        CharacterEncoding(*coding, *lastCoding, arrCountCalc, length);
    }
    // Arithmetic operation, and remove unnecessary numbers from the array, and shift 2 elements back
    arrCountCalc[*index] = calc;

    DeleteIndexArr(arrCountCalc, *index - 1, length);
    DeleteIndexArr(arrCountCalc, *index, length);

    *index -= 2;
    *indexEnd -= 2;
}

// A function that calculates the arithmetic operations of numbers in a given range
void Calc(double* arrCountCalc, int indexStart, int indexEnd, double* coding, double* lastCoding, int length, bool* error) {
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Raising the number to the power
        if (arrCountCalc[i] == *coding + 70) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            LogicCalc(lastCoding, coding, &i, &indexEnd, arrCountCalc, length, pow(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Square root
        else if (arrCountCalc[i] == *coding + 80) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            // If the number from the square root is greater than our coding, then we change all the coding
            if (sqrt(arrCountCalc[i + 1]) > *coding) {
                *coding = sqrt(arrCountCalc[i + 1]);
                CharacterEncoding(*coding, *lastCoding, arrCountCalc, length);
            }
            // The square root of a number, remove unnecessary elements of the array and shift 1 elements back
            arrCountCalc[i] = sqrt(arrCountCalc[i + 1]);
            DeleteIndexArr(arrCountCalc, i + 1, length);
            i -= 1;
            indexEnd -= 1;
        }
    }
    // Multiplication and Division
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Multiplication
        if (arrCountCalc[i] == *coding + 10) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            LogicCalc(lastCoding, coding, &i, &indexEnd, arrCountCalc, length, Multiplication(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Division
        else if (arrCountCalc[i] == *coding + 20) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            // If the division of two numbers is greater than our coding, we change the coding of numbers for correct calculation
            if (arrCountCalc[i + 1] == 0) {
                *error = true; // Assign an error if we divide by 0
            }
            else {
                LogicCalc(lastCoding, coding, &i, &indexEnd, arrCountCalc, length, Division(arrCountCalc[i - 1], arrCountCalc[i + 1]));

            }

        }
    }

    // Sum and Subtraction
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Sum
        if (arrCountCalc[i] == *coding + 30) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            LogicCalc(lastCoding, coding, &i, &indexEnd, arrCountCalc, length, Sum(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Subtraction
        else if (arrCountCalc[i] == *coding + 40) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            LogicCalc(lastCoding, coding, &i, &indexEnd, arrCountCalc, length, Subtraction(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
    }
}

void Calc(double* arrCountCalc, double* coding, double* lastCoding, int length, bool* error) {
    // Raising the number to the power and square root
    for (int i = 0; i < length; i++)
    {
        // Raising the number to the power
        if (arrCountCalc[i] == *coding + 70) {
            cout << pow(arrCountCalc[i - 1], arrCountCalc[i + 1]) << endl;
            LogicCalc(lastCoding, coding, &i, &length, arrCountCalc, length, pow(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Square root
        else if (arrCountCalc[i] == *coding + 80) {
            *lastCoding = *coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == *coding + 50) {
                continue;
            }
            if (sqrt(arrCountCalc[i + 1]) > *coding) {
                *coding = sqrt(arrCountCalc[i + 1]);
                CharacterEncoding(*coding, *lastCoding, arrCountCalc, length);
            }
            arrCountCalc[i] = sqrt(arrCountCalc[i + 1]);
            DeleteIndexArr(arrCountCalc, i + 1, length);
            i -= 1;
        }
    }
    // Multiplication, Division, Raising the number to the power and Square root
    for (int i = 0; i < length; i++)
    {
        // Multiplication
        if (arrCountCalc[i] == *coding + 10) {
            LogicCalc(lastCoding, coding, &i, &length, arrCountCalc, length, Multiplication(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Division
        else if (arrCountCalc[i] == *coding + 20) {
            if (arrCountCalc[i + 1] == 0) {
                *error = true;
            }
            else {
                LogicCalc(lastCoding, coding, &i, &length, arrCountCalc, length, Division(arrCountCalc[i - 1], arrCountCalc[i + 1]));
            }
        }
    }

    // Sum and Subtraction
    for (int i = 0; i < length; i++)
    {
        // Sum
        if (arrCountCalc[i] == *coding + 30) {
            LogicCalc(lastCoding, coding, &i, &length, arrCountCalc, length, Sum(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
        // Subtraction
        else if (arrCountCalc[i] == *coding + 40) {
            LogicCalc(lastCoding, coding, &i, &length, arrCountCalc, length, Subtraction(arrCountCalc[i - 1], arrCountCalc[i + 1]));
        }
    }
}

void Brackets(double* arrCountCalc, int length, double* coding, double* lastCoding, bool* error) {
    for (int i = 0, index = 0; i < length; i++)
    {
        // Find (
        if (arrCountCalc[i] == *coding + 50) {
            // Delete (
            DeleteIndexArr(arrCountCalc, i, length);
            // We look for "(" or ")", if we do not find, it gives an error
            for (int j = i; j < length; j++)
            {
                // Find ")"
                if (arrCountCalc[j] == *coding + 60) {
                    DeleteIndexArr(arrCountCalc, j, length);
                    index = j;
                    break;
                }
                // Find "("
                else if (arrCountCalc[j] == *coding + 50) {
                    Brackets(arrCountCalc, length, &*coding, &*lastCoding, &*error);
                }
                // if we do not find, it gives an error
                else if (j == length - 1) {
                    *error = true;
                }
            }
            // Calculation
            Calc(arrCountCalc, i, index - 1, &*coding, &*lastCoding, length, &*error);
        }
    }
}

int main()
{
    string inputCalc = "";
    double coding = 0, lastCoding = 0;
    bool error = false;
    ArrayCalc arr;

    cout << "This calculator can do such things as:" << endl <<
            "Adding: +;" << endl <<
            "Subtraction: -;" << endl <<
            "Multiplication: *;" << endl<<
            "Division: /;" << endl <<
            "Count actions in brackets;" << endl <<
            "Raise to the degree: number^power;" << endl <<
            "Take the square root of the number: sqrt(number)" << endl;

    cout << "Enter your example:" << endl;
    getline(cin, inputCalc);

    arr = ConvertArrayToDouble(inputCalc, &coding);// Convert an array of char to an array of double
    Brackets(arr.CountCalc, arr.length, &coding, &lastCoding, &error); // Counting an expression in parentheses
    Calc(arr.CountCalc, &coding, &lastCoding, arr.length, &error); // Counting the whole expression

    if (error) cout << "ERROR" << endl;
    else cout << endl << arr.CountCalc[0] << endl; // Display calculations
    return 0;
}
