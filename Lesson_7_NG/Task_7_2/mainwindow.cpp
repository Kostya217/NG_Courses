#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->t_antimat_filter, &QTextEdit::textChanged, this, &MainWindow::AntimatFilter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AntimatFilter()
{


    if(ui->t_antimat_filter->toPlainText().indexOf("fuck", 0, Qt::CaseInsensitive) == -1){
        return;
    }

    qDebug() << "i call this function";
    QString text = ui->t_antimat_filter->toPlainText();
    text.replace("fuck", "****", Qt::CaseInsensitive);

    QTextCursor cursor = ui->t_antimat_filter->textCursor();
    int position = cursor.position();

    disconnect(ui->t_antimat_filter, &QTextEdit::textChanged, this, &MainWindow::AntimatFilter);
    ui->t_antimat_filter->setText(text);
    connect(ui->t_antimat_filter, &QTextEdit::textChanged, this, &MainWindow::AntimatFilter);

    cursor.setPosition(position);
    ui->t_antimat_filter->setTextCursor(cursor);
}

