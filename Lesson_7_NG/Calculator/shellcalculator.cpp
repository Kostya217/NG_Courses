#include "shellcalculator.h"
#include "ui_shellcalculator.h"

ShellCalculator::ShellCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShellCalculator)
{
    ui->setupUi(this);
    connect(ui->b_zero, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_one, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_two, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_three, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_four, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_five, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_six, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_seven, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_eight, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_nine, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_point, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_plus, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_minus, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_multiply, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_division, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_pow, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_pow_two, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_square_root, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_percent, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_parentheses, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_plus_or_minus, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_delete, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_clear, &QPushButton::clicked, this, &ShellCalculator::PressButton);
    connect(ui->b_equals, &QPushButton::clicked, this, &ShellCalculator::PressButton);


}

ShellCalculator::~ShellCalculator()
{
    delete ui;
}

void ShellCalculator::PressButton()
{
    QPushButton *button = (QPushButton*)sender();
    QString textInput = ui->l_input->text();

    if(textInput == ""){
        ui->l_input->setText(ui->l_input->text());
    }
    else if((button == ui->b_zero||
            button == ui->b_one ||
            button == ui->b_two ||
            button == ui->b_three ||
            button == ui->b_four ||
            button == ui->b_five ||
            button == ui->b_six ||
            button == ui->b_seven ||
            button == ui->b_eight ||
             button == ui->b_nine) && textInput.right(1) == ')'){
        ui->l_input->setText(ui->l_input->text() + '*');
    }

    if(button == ui->b_zero){
        ui->l_input->setText(ui->l_input->text() + '0');
    }
    else if(button == ui->b_one){
        ui->l_input->setText(ui->l_input->text() + '1');
    }
    else if(button == ui->b_two){
        ui->l_input->setText(ui->l_input->text() + '2');
    }
    else if(button == ui->b_three){
        ui->l_input->setText(ui->l_input->text() + '3');
    }
    else if(button == ui->b_four){
        ui->l_input->setText(ui->l_input->text() + '4');
    }
    else if(button == ui->b_five){
        ui->l_input->setText(ui->l_input->text() + '5');
    }
    else if(button == ui->b_six){
        ui->l_input->setText(ui->l_input->text() + '6');
    }
    else if(button == ui->b_seven){
        ui->l_input->setText(ui->l_input->text() + '7');
    }
    else if(button == ui->b_eight){
        ui->l_input->setText(ui->l_input->text() + '8');
    }
    else if(button == ui->b_nine){
        ui->l_input->setText(ui->l_input->text() + '9');
    }
    else if(button == ui->b_point){
        if(!CheckSing(ui->l_input->text())){
            if(CheckPoint(ui->l_input->text())){
                ui->l_input->setText(ui->l_input->text() + '.');
            }
        }
        else{
            if(CheckPoint(ui->l_input->text())){
                ui->l_input->setText(ui->l_input->text() + "0.");
            }
        }
    }
    else if(button == ui->b_plus){
        SetSing('+');
    }
    else if(button == ui->b_minus){
        if(ui->l_input->text() == ""){
            ui->l_input->setText(ui->l_input->text() + '-');

        }
        SetSing('-');
    }
    else if(button == ui->b_multiply){
        SetSing('*');
    }
    else if(button == ui->b_division){
        SetSing('/');
    }
    else if(button == ui->b_pow){
        !CheckSing(ui->l_input->text())?
            ui->l_input->setText(ui->l_input->text() + "^("):
            ui->l_input->setText(ui->l_input->text());
        countParentheses++;
    }
    else if(button == ui->b_pow_two){
        !CheckSing(ui->l_input->text())?
            ui->l_input->setText(ui->l_input->text() + "^(2)"):
            ui->l_input->setText(ui->l_input->text());
    }
    else if(button == ui->b_square_root){

        if(CheckSing(ui->l_input->text())){
            if(CheckPoint(ui->l_input->text())){
                ui->l_input->setText(ui->l_input->text() + "sqrt(");
                countParentheses++;
            }
            else{
                ui->l_input->setText(ui->l_input->text());
            }
        }
        else{
            ui->l_input->setText(ui->l_input->text() + "*sqrt(");
            countParentheses++;
        }
    }
    else if(button == ui->b_percent){
        if(!CheckSing(ui->l_input->text()) && textInput[textInput.size() - 1] != '%'){
            ui->l_input->setText(ui->l_input->text() + '%');
         }
         else{
            ui->l_input->setText(ui->l_input->text());
         }
    }
    else if(button == ui->b_parentheses){
        if(ui->l_input->text() == ""){
            ui->l_input->setText(ui->l_input->text() + '(');
            countParentheses++;
        }
        else if(CheckSing(ui->l_input->text()) && textInput[textInput.size() - 1] != '.'){
            ui->l_input->setText(ui->l_input->text() + '(');
            countParentheses++;
        }
        else if(!CheckSing(ui->l_input->text()) && countParentheses == 0){
            ui->l_input->setText(ui->l_input->text() + "*(");
            countParentheses++;
        }
        else if(textInput[textInput.size() - 1] != '.'){
            ui->l_input->setText(ui->l_input->text() + ')');
            checkMinus = true;
            countParentheses--;
        }
    }
    else if(button == ui->b_plus_or_minus){
        ui->l_input->setText(InsertPlusOrMinus(ui->l_input->text()));
    }
    else if(button == ui->b_delete){
        if(textInput.right(1) == '('){
            countParentheses--;
        }
        else if(textInput.right(1) == ')'){
            countParentheses++;
        }
        textInput.chop(1);
        ui->l_input->setText(textInput);
    }
    else if(button == ui->b_clear){
        ui->l_input->clear();
        countParentheses = 0;
    }
    else if(button == ui->b_equals){
        Calculation *calc = new Calculation();
        calc->SetText(ReplacementPercent(ui->l_input->text()));
        if(countParentheses != 0){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Wrong format used");
            messageBox.setFixedSize(500,200);
        }else{
            ui->l_input->setText(calc->GetAnswer());
        }
    }

}

bool ShellCalculator::CheckSing(QString text)
{
    if(text == ""){
        return true;
    }
    if(text[text.size() - 1] == '+' ||
       text[text.size() - 1] == '-' ||
       text[text.size() - 1] == '*' ||
       text[text.size() - 1] == '/' ||
       text[text.size() - 1] == '.' ||
       text[text.size() - 1] == '(' ){
        return true;
    }
    else {
        return false;
    }
}

bool ShellCalculator::CheckPoint(QString text)
{
    if(text == ""){
        return true;
    }
    for(int i = text.size() - 1; i >= 0; i-- ){
        if((text[i] == '+' ||
            text[i] == '-' ||
            text[i] == '*' ||
            text[i] == '/' ||
            text[i] == '(' ||
            i == 0)){
            return true;
        }
        else if(text[i] == '.'){
            return false;
        }
    }
    return false;
}

QString ShellCalculator::InsertPlusOrMinus(QString text)
{
    if(text == ""){
        text = "(-";
        checkMinus = false;
        countParentheses++;
        return text;
    }
    for(int i = text.size() - 1; i >= 0; i--){
        if(i == 0 && checkMinus){
            text.insert(i, "(-");
            checkMinus = false;
            countParentheses++;
            break;
        }
        else if((text[i] == '+' ||
            text[i] == '-' ||
            text[i] == '*' ||
            text[i] == '/' ||
            text[i] == '(')
            && checkMinus){
            text.insert(i + 1, "(-");
            checkMinus = false;
            countParentheses ++;
            break;
        }
        else if(text[i - 1] == '(' && text[i] == '-'){
            text.remove(i - 1, 2);
            checkMinus = true;
            countParentheses--;
            break;
        }
    }
    return text;
}

QString ShellCalculator::ReplacementPercent(QString text)
{
    text.replace(QRegExp("[%]"), "/100");
    return text;
}

void ShellCalculator::SetSing(QChar sign)
{
    if(!CheckSing(ui->l_input->text())){
        ui->l_input->setText(ui->l_input->text() + sign);
        checkMinus = true;
     }
    else{
        ui->l_input->setText(ui->l_input->text());
    }
}

