#include "calculation.h"

Calculation::Calculation()
{

}

// Function to add 2 elements
double Calculation::Sum(double addition1, double addition2) {
    return addition1 + addition2;
}

// Function for subtracting 2 items
double Calculation::Subtraction(double reduction, double subtractor) {
    return reduction - subtractor;
}

//Function for multiplying 2 elements
double Calculation::Multiplication(double multiplier1, double multiplier2) {
    return multiplier1 * multiplier2;
}

// Function for dividing 2 elements
double Calculation::Division(double divided, double divider) {
    return divided / divider;
}

void Calculation::EncryptionSing(bool logicEncryptionSing) {
    QString number = "";
    for (int i = 0; i < input.length(); i++)
    {
        // We skip the action signs and fill them with only numbers.
        if ((input[i] == '+') ||
            (input[i] == '-') ||
            (input[i] == '*') ||
            (input[i] == '/') ||
            (input[i] == '(') ||
            (input[i] == ')') ||
            (input[i] == '^') ||
            (input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't') ||
            (input[i] == '\0')) {
            number = "";


            if (logicEncryptionSing) {
                if (input[i] == '*') {
                    arrCountCalc.push_back(coding + 10);
                } // Sign *
                else if (input[i] == '/') {
                    arrCountCalc.push_back(coding + 20);
                } // Sign /
                else if (input[i] == '+') {
                    arrCountCalc.push_back(coding + 30);
                } // Sign +
                else if (input[i] == '-') {
                        arrCountCalc.push_back(coding + 40);
                } // Sign -
                else if (input[i] == '(') {
                    arrCountCalc.push_back(coding + 50);
                } // Sign )
                else if (input[i] == ')') {
                    arrCountCalc.push_back(coding + 60);
                } // Sign (
                else if (input[i] == '^') {
                    arrCountCalc.push_back(coding + 70);
                } // Sign ^
                else if (input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't') {
                    arrCountCalc.push_back(coding + 80);
                    i += 3;
                } // Sign sqtr
            }
            else {
                if (input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' && input[i + 3] == 't') {
                    i += 3;
                }
            }


        }
        // We glue all the signs into one number, which is in front of the action sign
        else {
            number += input[i];
            if ((input[i + 1] == '+') ||
                (input[i + 1] == '-') ||
                (input[i + 1] == '*') ||
                (input[i + 1] == '/') ||
                (input[i + 1] == '(') ||
                (input[i + 1] == ')') ||
                (input[i + 1] == '^') ||
                (input[i + 1] == 's' && input[i + 2] == 'q' && input[i + 3] == 'r' && input[i + 4] == 't') ||
                (input[i + 1] == '\0')) {

                // We find the maximum number to later take this change for encoding arephmetic operations
                if (number.toDouble() > coding) {
                    coding = number.toDouble();
                }
                arrCountCalc.push_back(number.toDouble());
            }
        }
    }
}

// Convert an array of char to an array of double
void Calculation::ConvertArrayToDouble() {
    EncryptionSing(false);
    arrCountCalc.clear();
    EncryptionSing(true);
}
// A function that changes the encoding of characters
void Calculation::CharacterEncoding() {
    for (int j = 0; j < arrCountCalc.size(); j++)
    {
        if ((arrCountCalc[j] == lastCoding + 10) ||
            (arrCountCalc[j] == lastCoding + 20) ||
            (arrCountCalc[j] == lastCoding + 30) ||
            (arrCountCalc[j] == lastCoding + 40) ||
            (arrCountCalc[j] == lastCoding + 50) ||
            (arrCountCalc[j] == lastCoding + 60) ||
            (arrCountCalc[j] == lastCoding + 70) ||
            (arrCountCalc[j] == lastCoding + 80)) {
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
}

void Calculation::LogicCalc(int index, double calc) {
    lastCoding = coding;
    // If the arithmetic operation is greater than our coding, we change the coding of numbers for correct calculations
    if (calc > coding) {
        coding = calc;
        CharacterEncoding();
    }
    // Arithmetic operation, and remove unnecessary numbers from the array, and shift 2 elements back
    arrCountCalc[index] = calc;
    arrCountCalc.remove(index - 1);
    arrCountCalc.remove(index);
}

// A function that calculates the arithmetic operations of numbers in a given range
void Calculation::Calc(int indexStart, int indexEnd) {
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Raising the number to the power
        if (arrCountCalc[i] == coding + 70) {
            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            LogicCalc(i, pow(arrCountCalc[i - 1], arrCountCalc[i + 1]));
            i -=2;
            indexEnd -=2;
        }
        // Square root
        else if (arrCountCalc[i] == coding + 80) {
            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            // If the number from the square root is greater than our coding, then we change all the coding
            if (sqrt(arrCountCalc[i + 1]) > coding) {
                coding = sqrt(arrCountCalc[i + 1]);
                CharacterEncoding();
            }
            // The square root of a number, remove unnecessary elements of the array and shift 1 elements back
            arrCountCalc[i] = sqrt(arrCountCalc[i + 1]);
            arrCountCalc.remove(i + 1);
            i -= 1;
            indexEnd -= 1;
        }
    }
    // Multiplication and Division
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Multiplication
        if (arrCountCalc[i] == coding + 10) {
            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            LogicCalc(i, Multiplication(arrCountCalc[i - 1], arrCountCalc[i + 1]));
            i -=2;
            indexEnd -=2;
        }
        // Division
        else if (arrCountCalc[i] == coding + 20) {
            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            // If the division of two numbers is greater than our coding, we change the coding of numbers for correct calculation
            if (arrCountCalc[i + 1] == 0) {
                error = true; // Assign an error if we divide by 0
            }
            else {
                LogicCalc(i, Division(arrCountCalc[i - 1], arrCountCalc[i + 1]));
                i -=2;
                indexEnd -=2;

            }

        }
    }

    // Sum and Subtraction
    for (int i = indexStart; i < indexEnd; i++)
    {
        // Sum
        if (arrCountCalc[i] == coding + 30) {

            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            LogicCalc(i, Sum(arrCountCalc[i - 1], arrCountCalc[i + 1]));
            i -=2;
            indexEnd -=2;
        }
        // Subtraction
        else if (arrCountCalc[i] == coding + 40) {
            lastCoding = coding;
            // If we get to the bracket, then we move on to the next iteration
            if (arrCountCalc[i + 1] == coding + 50) {
                continue;
            }
            if (arrCountCalc[0] == coding + 40) {

                // If the arithmetic operation is greater than our coding, we change the coding of numbers for correct calculations
                if (Subtraction(0, arrCountCalc[i + 1]) > coding) {
                    coding = Subtraction(0, arrCountCalc[i + 1]);
                    CharacterEncoding();
                }
                // Arithmetic operation, and remove unnecessary numbers from the array, and shift 2 elements back
                arrCountCalc[i] = Subtraction(0, arrCountCalc[i + 1]);

                arrCountCalc.remove(i + 1);

                i --;
                indexEnd --;
            }
            else if (arrCountCalc[i - 1] >= coding + 10){
                if (Subtraction(0, arrCountCalc[i + 1]) > coding) {
                    coding = Subtraction(0, arrCountCalc[i + 1]);
                    CharacterEncoding();
                }
                // Arithmetic operation, and remove unnecessary numbers from the array, and shift 2 elements back
                arrCountCalc[i] = Subtraction(0, arrCountCalc[i + 1]);

                arrCountCalc.remove(i + 1);

                i --;
                indexEnd --;
            }
            else {
                LogicCalc(i, Subtraction(arrCountCalc[i - 1], arrCountCalc[i + 1]));
                i -=2;
                indexEnd -=2;
            }
        }
    }
}

void Calculation::Brackets() {
    for (int i = 0, index = 0; i < arrCountCalc.size(); i++)
    {
        // Find (
        if (arrCountCalc[i] == coding + 50) {
            // Delete (
            arrCountCalc.remove(i);
            // We look for "(" or ")", if we do not find, it gives an error
            for (int j = i; j < arrCountCalc.size(); j++)
            {
                // Find ")"
                if (arrCountCalc[j] == coding + 60) {
                    arrCountCalc.remove(j);
                    index = j;
                    break;
                }
                // Find "("
                else if (arrCountCalc[j] == coding + 50) {
                    Brackets();
                }
                // if we do not find, it gives an error
                else if (j == arrCountCalc.size() - 1) {
                    error = true;
                }
            }
            // Calculation
            Calc(i, index - 1);
        }
    }
}

void Calculation::SetText(QString input)
{
    this->input = input;
}


QString Calculation::GetAnswer()
{
    ConvertArrayToDouble();
    Brackets(); // Counting an expression in parentheses
    Calc(0, arrCountCalc.size()); // Counting the whole expression
    answer = QString::number(arrCountCalc[0]);
    return answer;
}

