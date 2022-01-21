#ifndef SHELLCALCULATOR_H
#define SHELLCALCULATOR_H

#include <QMainWindow>
#include "calculation.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ShellCalculator; }
QT_END_NAMESPACE

class ShellCalculator : public QMainWindow
{
    Q_OBJECT

public:
    ShellCalculator(QWidget *parent = nullptr);
    ~ShellCalculator();

private:
    Ui::ShellCalculator *ui;
    int countParentheses = 0;
    void PressButton();
    bool CheckSing(QString text);
    bool CheckPoint(QString text);
    bool checkMinus = true;
    QString InsertPlusOrMinus(QString text);
    QString ReplacementPercent(QString text);
    void SetSing(QChar sign);
};
#endif // SHELLCALCULATOR_H
