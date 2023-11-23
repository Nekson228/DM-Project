#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../modules/Natural/Natural.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_useButton_clicked();

    void on_naturalPlusButton_clicked();

    void on_naturalSubButton_clicked();

    void on_naturalMultButton_clicked();

    void on_naturalDivButton_clicked();

    void on_naturalModButton_clicked();

    void on_naturalGcdButton_clicked();

    void on_naturalLcmButton_clicked();

    void on_integerPlusButton_clicked();

    void on_integerSubButton_clicked();

    void on_integerMultButton_clicked();

    void on_integerDivButton_clicked();

    void on_integerModButton_clicked();

    void on_integerAbsButton_clicked();

    void on_rationalPlusButton_clicked();

    void on_rationalSubButton_clicked();

    void on_rationalMultButton_clicked();

    void on_rationalDivButton_clicked();

    void on_rationalReduceButton_clicked();

    void on_polynomialPlusButton_clicked();

    void on_subButton_4_clicked();

    void on_polynomialMultButton_clicked();

    void on_polynomialDivButton_clicked();

    void on_polynomialModButton_clicked();

    void on_polynomialDerivativeButton_clicked();

    void on_polynomialGcdButton_clicked();

    void on_polynomialFactorizeButton_clicked();

    void on_polynomialReduceButton_clicked();

    void on_polynomialReduceCButton_clicked();

private:
    Ui::MainWindow *ui;
    bool exceptionThrown = false,
    firstOpOcurred = false;

    void setResult(const iModel &model);

    void exceptionHandler(const std::exception &e);

    template <class X>
    X getOp1();

    template <class X>
    X getOp2();
};
#endif // MAINWINDOW_H
