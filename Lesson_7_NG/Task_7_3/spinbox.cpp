#include "spinbox.h"
#include "ui_spinbox.h"

SpinBox::SpinBox(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpinBox)
{
    ui->setupUi(this);
    connect(ui->s_1, &QSpinBox::textChanged, this, &SpinBox::SumOfNumbers);
    connect(ui->s_2, &QSpinBox::textChanged, this, &SpinBox::SumOfNumbers);
    connect(ui->s_read_only_3, &QSpinBox::textChanged, this, &SpinBox::SumOfNumbers);

}

SpinBox::~SpinBox()
{
    delete ui;
}

void SpinBox::SumOfNumbers()
{
    int valueSpinBoxOne = ui->s_1->value();
    int valueSpinBoxTwo = ui->s_2->value();
    ui->s_read_only_3->setValue(valueSpinBoxOne + valueSpinBoxTwo);
}

