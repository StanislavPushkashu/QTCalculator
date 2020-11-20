#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void GetNumber();
    void on_CommaButton_clicked();
    void Operations();
    void MathOperations();

    void on_EqualityButton_clicked();

    void on_ACButton_clicked();

private:
    Ui::MainWindow *ui;
    double FirstNum, SecondNum;
};
#endif // MAINWINDOW_H
