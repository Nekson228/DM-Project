#include "mainwindow.h"
#include "../ui_mainwindow.h"
#include "../modules/Natural/Natural.h"
#include "../modules/Integer/Integer.h"
#include "../modules/Rational/Rational.h"
#include "../modules/Polynomial/Polynomial.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

template <class X>
X MainWindow::getOp1() {
    return X{ui->op1Line->text().toStdString()};
}

template <class X>
X MainWindow::getOp2() {
    return X{ui->op2Line->text().toStdString()};
}

void MainWindow::setResult(const iModel &model) {
    exceptionThrown = false;
    firstOpOcurred = true;
    ui->outputLine->setStyleSheet("");
    ui->outputLine->setText(model.str().c_str());
}

void MainWindow::exceptionHandler(const std::exception &e) {
    exceptionThrown = true;
    ui->outputLine->setStyleSheet("QLineEdit { color: #fa7878 }");
    ui->outputLine->setText(e.what());
}

void MainWindow::on_useButton_clicked() {
    if (ui->outputLine->text().isEmpty() || exceptionThrown || !firstOpOcurred)
        return;
    ui->op1Line->setText(ui->outputLine->text());
    ui->outputLine->clear();
}

void MainWindow::on_naturalPlusButton_clicked() {
    try {
        setResult(getOp1<Natural>() + getOp2<Natural>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_naturalSubButton_clicked() {
    try {
        setResult(getOp1<Natural>() - getOp2<Natural>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_naturalMultButton_clicked() {
    try {
        setResult(getOp1<Natural>() * getOp2<Natural>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_naturalDivButton_clicked() {
    try {
        setResult(getOp1<Natural>() / getOp2<Natural>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_naturalModButton_clicked() {
    try {
        setResult(getOp1<Natural>() % getOp2<Natural>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_naturalGcdButton_clicked() {
    try {
        setResult(Natural::gcd(getOp1<Natural>(), getOp2<Natural>()));
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}

void MainWindow::on_naturalLcmButton_clicked() {
    try {
        setResult(Natural::lcm(getOp1<Natural>(), getOp2<Natural>()));
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_integerPlusButton_clicked() {
    try {
        setResult(getOp1<Integer>() + getOp2<Integer>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_integerSubButton_clicked() {
    try {
        setResult(getOp1<Integer>() - getOp2<Integer>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_integerMultButton_clicked() {
    try {
        setResult(getOp1<Integer>() * getOp2<Integer>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}

void MainWindow::on_integerDivButton_clicked() {
    try {
        setResult(getOp1<Integer>() / getOp2<Integer>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_integerModButton_clicked() {
    try {
        setResult(getOp1<Integer>() % getOp2<Integer>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}

void MainWindow::on_integerAbsButton_clicked()
{
    try {
        setResult(getOp1<Integer>().abs());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_rationalPlusButton_clicked() {
    try {
        setResult(getOp1<Rational>() + getOp2<Rational>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_rationalSubButton_clicked()
{
    try {
        setResult(getOp1<Rational>() - getOp2<Rational>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_rationalMultButton_clicked()
{
    try {
        setResult(getOp1<Rational>() * getOp2<Rational>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}



void MainWindow::on_rationalDivButton_clicked() {
    try {
        setResult(getOp1<Rational>() / getOp2<Rational>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }

}

void MainWindow::on_rationalReduceButton_clicked()
{
    try {
        setResult(getOp1<Rational>().reduce());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}




void MainWindow::on_polynomialPlusButton_clicked() {
    try {
        setResult(getOp1<Polynomial>() + getOp2<Polynomial>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_subButton_4_clicked()
{
    try {
        setResult(getOp1<Polynomial>() - getOp2<Polynomial>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialMultButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>() * getOp2<Polynomial>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialDivButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>() / getOp2<Polynomial>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialModButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>() % getOp2<Polynomial>());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}



void MainWindow::on_polynomialDerivativeButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>().derivative());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialGcdButton_clicked()
{
    try {
        setResult(Polynomial::gcd(getOp1<Polynomial>(), getOp2<Polynomial>()));
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialFactorizeButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>().factorize());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialReduceButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>().singlify());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}


void MainWindow::on_polynomialReduceCButton_clicked()
{
    try {
        setResult(getOp1<Polynomial>().reduceAllCoefficients());
    }
    catch (const std::exception &e) {
        exceptionHandler(e);
    }
}

