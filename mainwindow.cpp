#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool flag = false;
std::string expression;

void MainWindow::checkFirstEvent () {
    if (flag == true) {
        return;
    }
    ui -> label_2 -> setText("");
}


void MainWindow::on_pushButton_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "9";
    expression += "9";
    ui -> label_2 -> setText(currText);
}

void MainWindow::on_pushButton_2_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "8";
    expression += "8";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_3_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "7";
    expression += "7";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_4_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "6";
    expression += "6";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_5_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "5";
    expression += "5";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_6_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "4";
    expression += "4";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_7_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "3";
    expression += "3";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_8_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "2";
    expression += "2";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_9_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "1";
    expression += "1";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_10_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "0";
    expression += "0";
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_11_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "+";
    expression += '+';
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_12_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "-";
    expression += '-';
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_13_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "*";
    expression += '*';
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_14_clicked()
{
    checkFirstEvent();
    flag = true;
    QString currText = ui -> label_2 -> text();
    currText += "/";
    expression += '/';
    ui -> label_2 -> setText(currText);
}


void MainWindow::on_pushButton_15_clicked()
{
    checkFirstEvent();
    flag = false;
    expression += "=";
    int res = expressionIsOver();
    ui -> label_2 -> setText(QString::number(res));
}

int MainWindow::expressionIsOver()
{
    int size = 0;
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            ++size;
        }
    }
    std::vector<std::string> vec(2 * size + 1, "/0");
    std::string tmp;
    int vec_counter = 0;
    for (int i = 0; i < expression.size() - 1; ++i) {
        while (i < expression.size() && (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')) {
            tmp += expression[i];
            if (i < expression.size() - 2) {
                ++i;
            }
            else {
                break;
            }
        }
        vec[vec_counter] = tmp;
        ++vec_counter;
        if (i < expression.size() - 2) {
            vec[vec_counter] = std::string(1, expression[i]);
            ++vec_counter;
        }
        tmp = "";
    }
    for (int i = 0; i < vec.size(); ++i) {
        if (vec.size() == 1) {
            return stoi(vec[0]);
        }
        if (vec[i] == "*" || vec[i] == "/") {
            if (vec[i] == "*" && i < vec.size()) {
                int operand1 = stoi(vec[i - 1]);
                int operand2 = stoi(vec[i + 1]);
                vec[i - 1] = std::to_string(operand1 * operand2);
                if (i + 2 == vec.size()) {
                    vec.erase(vec.begin() + i, vec.begin() + i + 1);
                }
                else {
                    vec.erase(vec.begin() + i, vec.begin() + i + 2);
                }
            }
            if (vec[i] == "/" && i < vec.size()) {
                int operand1 = stoi(vec[i - 1]);
                int operand2 = stoi(vec[i + 1]);
                if (operand2 == 0) {
                    return -1;
                }
                vec[i - 1] = std::to_string(operand1 / operand2);
                vec.erase(vec.begin() + i, vec.begin() + i + 2);
            }
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        if (vec.size() == 1) {
            return stoi(vec[0]);
        }
        if (vec[i] == "+" || vec[i] == "-") {
            if (vec[i] == "+" && i < vec.size()) {
                int operand1 = stoi(vec[i - 1]);
                int operand2 = stoi(vec[i + 1]);
                vec[i - 1] = std::to_string(operand1 + operand2);
                if (i + 2 == vec.size()) {
                    vec.erase(vec.begin() + i, vec.begin() + i + 1);
                }
                else {
                    vec.erase(vec.begin() + i, vec.begin() + i + 2);
                }
            }
            if (vec[i] == "-" && i < vec.size()) {
                int operand1 = stoi(vec[i - 1]);
                int operand2 = stoi(vec[i + 1]);
                vec[i - 1] = std::to_string(operand1 - operand2);
                vec.erase(vec.begin() + i, vec.begin() + i + 2);
            }
        }
    }
    expression = "";
    return stoi(vec[0]);
}

