#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->NineButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->EightButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->SevenButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->SixButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->FiveButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->FourButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->ThreeButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->TwoButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->OneButton, SIGNAL(clicked()), this, SLOT(GetNumber()));
    connect(ui->ZeroButton, SIGNAL(clicked()), this, SLOT(GetNumber()));

    connect(ui->InverseSignButton, SIGNAL(clicked()), this, SLOT(Operations()));
    connect(ui->PercentButton, SIGNAL(clicked()), this, SLOT(Operations()));

    connect(ui->MinusButton, SIGNAL(clicked()), this, SLOT(MathOperations()));
    connect(ui->PlusButton, SIGNAL(clicked()), this, SLOT(MathOperations()));
    connect(ui->MultiplicationButton, SIGNAL(clicked()), this, SLOT(MathOperations()));
    connect(ui->DivisionButton, SIGNAL(clicked()), this, SLOT(MathOperations()));

    ui->DivisionButton->setCheckable(true);
    ui->MultiplicationButton->setCheckable(true);
    ui->PlusButton->setCheckable(true);
    ui->MinusButton->setCheckable(true);

}

void MainWindow::GetNumber()
{
    double Num;
    QString help;
    QPushButton *Button = (QPushButton *) sender();

    if (ui->ResultShow->text().contains(".") && ui->ResultShow->text() == "0"){
        help = ui->ResultShow->text() + Button->text();
    }
    else {
        Num = (ui->ResultShow->text() + Button->text()).toDouble();
        help = QString::number(Num, 'g', 9);
    }
    ui->ResultShow->setText(help);
}

void MainWindow::Operations()
{
    double Num;
    QString help;
    QPushButton *Button = (QPushButton *) sender();

    if (Button->text() == "+/-"){
        Num = (ui->ResultShow->text()).toDouble();
        Num *= -1;
        help = QString::number(Num, 'g', 9);

    }
    else if (Button->text() == "%"){
        Num = (ui->ResultShow->text()).toDouble();
        Num *= 0.01;
        help = QString::number(Num, 'g', 9);
    }

    ui->ResultShow->setText(help);
}

void MainWindow::on_CommaButton_clicked()
{
    if (!ui->ResultShow->text().contains('.'))
        ui->ResultShow->setText(ui->ResultShow->text() + '.');
}

void MainWindow::MathOperations()
{
    QPushButton *Button = (QPushButton *) sender();

    FirstNum = ui->ResultShow->text().toDouble();
    ui->ResultShow->setText("");

    Button->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EqualityButton_clicked()
{
    double lnumber;
    QString help;

    SecondNum = ui->ResultShow->text().toDouble();

    if (ui->PlusButton->isChecked()){
        lnumber = FirstNum + SecondNum;
        help = QString::number(lnumber, 'g', 9);

        ui->ResultShow->setText(help);
        ui->PlusButton->setChecked(false);
    }
    else if (ui->MinusButton->isChecked()){
        lnumber = FirstNum - SecondNum;
        help = QString::number(lnumber, 'g', 9);

        ui->ResultShow->setText(help);
        ui->MinusButton->setChecked(false);
    }
    else if (ui->DivisionButton->isChecked()){
        if (SecondNum == 0){
            ui->ResultShow->setText("0");
        }
        else {
            lnumber = FirstNum / SecondNum;
            help = QString::number(lnumber, 'g', 9);

            ui->ResultShow->setText(help);
            ui->DivisionButton->setChecked(false);
        }
    }
    else if (ui->MultiplicationButton->isChecked()){
        lnumber = FirstNum * SecondNum;
        help = QString::number(lnumber, 'g', 9);

        ui->ResultShow->setText(help);
        ui->MultiplicationButton->setChecked(false);
    }
}

void MainWindow::on_ACButton_clicked()
{
    ui->PlusButton->setChecked(false);
    ui->MinusButton->setChecked(false);
    ui->MultiplicationButton->setChecked(false);
    ui->DivisionButton->setChecked(false);

    ui->ResultShow->setText("0");
}
