#ifndef SPINBOX_H
#define SPINBOX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpinBox; }
QT_END_NAMESPACE

class SpinBox : public QMainWindow
{
    Q_OBJECT

public:
    SpinBox(QWidget *parent = nullptr);
    ~SpinBox();

private:
    Ui::SpinBox *ui;
    void SumOfNumbers();
    void NormalSpinBox();
};
#endif // SPINBOX_H
