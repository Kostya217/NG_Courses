#ifndef CALCULATION_H
#define CALCULATION_H
#include <QMainWindow>
#include <cmath>
#include <QVector>

class Calculation
{
public:
    Calculation();
    void SetText(QString input);
    QString GetAnswer();
private:
    QString input = "";
    QString answer = 0;
    QVector<double> arrCountCalc;
    double coding = 0.0;
    double lastCoding = 0.0;
    bool error = false;

private:
    double Sum(double addition1, double addition2);
    double Subtraction(double reduction, double subtractor);
    double Multiplication(double multiplier1, double multiplier2);
    double Division(double divided, double divider);
    void ConvertArrayToDouble();
    void EncryptionSing(bool logicEncryptionSing);
    void CharacterEncoding();
    void LogicCalc(int index, double calc);
    void Calc(int indexStart, int indexEnd);
    void Brackets();
};

#endif // CALCULATION_H
