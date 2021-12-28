#include <iostream>
#include <cmath>

using namespace std;

struct EquationRoots
{
    double x1 = 0.0;
    double x2 = 0.0;
    double discriminant = 0.0;
};

double askValue(char symbol){
    double number;
    cout << "Enter " << symbol << " : ";
    cin >>  number;
    return number;
}

double Arithmetic(int sign, double a, double b, double discriminant){
    return ((-1 * b) + sign * sqrt(discriminant))/(2*a);
}

EquationRoots QuadraticEquation(double a = 0.0, double b = 0.0, double c = 0.0)
{
    EquationRoots x;
    x.discriminant = pow(b,2) - (4 * a * c);
    if (x.discriminant > 0){
        x.x1 = Arithmetic(-1, a, b, x.discriminant);
        x.x2 = Arithmetic(1, a, b, x.discriminant);
        return x;
    }
    if (x.discriminant == 0){
        x.x1 = (-1 * b)/(2*a);
        x.x2 = x.x1;
        return x;
    }
    else{
        return x;
    }
}

void Roots(double x1, double x2, double discriminant)
{
    if (discriminant < 0){
        cout << "There are no roots :3";
    }
    else if(x1 == x2){
        cout << "X = " << x1 ;
    }
    else{
        cout << "X1 = " << x1 << endl
         << "X2 = " << x2 ;
    }
}

void SolveQuadraticEquation(double a, double b, double c){
    EquationRoots x;
    cout << endl << a <<"x^2 + " << b << "x + " << c << " = 0" << endl << endl;
    x = QuadraticEquation(a, b, c);
    Roots(x.x1, x.x2, x.discriminant);
    cout << endl;
}

int main()
{
    SolveQuadraticEquation(askValue('c'), askValue('b'), askValue('a'));
    return 0;
}
