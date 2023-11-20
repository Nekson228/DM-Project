/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *op1Line;
    QWidget *layoutWidget_4;
    QVBoxLayout *_3;
    QLabel *label_4;
    QLineEdit *op2Line;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *outputLine;
    QPushButton *useButton;
    QSpacerItem *verticalSpacer;
    QTabWidget *typeTabs;
    QWidget *tabNatural;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *buttonsLayout;
    QPushButton *naturalLcmButton;
    QPushButton *naturalMultButton;
    QPushButton *naturalGcdButton;
    QPushButton *naturalDivButton;
    QPushButton *naturalModButton;
    QPushButton *naturalPlusButton;
    QPushButton *naturalSubButton;
    QSpacerItem *horizontalSpacer_6;
    QLabel *infoLabel;
    QWidget *tabInteger;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *buttonsLayout_2;
    QPushButton *integerDivButton;
    QPushButton *integerPlusButton;
    QPushButton *integerMultButton;
    QPushButton *integerSubButton;
    QPushButton *integerModButton;
    QPushButton *integerAbsButton;
    QSpacerItem *horizontalSpacer_7;
    QLabel *infoLabel_2;
    QWidget *tabRational;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *buttonsLayout_3;
    QPushButton *rationalDivButton;
    QPushButton *rationalMultButton;
    QPushButton *rationalSubButton;
    QPushButton *rationalPlusButton;
    QPushButton *rationalReduceButton;
    QSpacerItem *horizontalSpacer_8;
    QLabel *infoLabel_3;
    QWidget *tabPolynomial;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *buttonsLayout_4;
    QPushButton *subButton_4;
    QPushButton *polynomialMultButton;
    QPushButton *polynomialDivButton;
    QPushButton *polynomialPlusButton;
    QPushButton *polynomialGcdButton;
    QPushButton *polynomialModButton;
    QPushButton *polynomialDerivativeButton;
    QPushButton *polynomialFactorizeButton;
    QPushButton *polynomialReduceCButton;
    QPushButton *polynomialReduceButton;
    QSpacerItem *horizontalSpacer_9;
    QLabel *infoLabel_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1036, 574);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(false);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        op1Line = new QLineEdit(layoutWidget_3);
        op1Line->setObjectName(QString::fromUtf8("op1Line"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(op1Line->sizePolicy().hasHeightForWidth());
        op1Line->setSizePolicy(sizePolicy);
        op1Line->setMinimumSize(QSize(100, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        op1Line->setFont(font1);

        verticalLayout_4->addWidget(op1Line);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        _3 = new QVBoxLayout(layoutWidget_4);
        _3->setObjectName(QString::fromUtf8("_3"));
        _3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        _3->addWidget(label_4);

        op2Line = new QLineEdit(layoutWidget_4);
        op2Line->setObjectName(QString::fromUtf8("op2Line"));
        sizePolicy.setHeightForWidth(op2Line->sizePolicy().hasHeightForWidth());
        op2Line->setSizePolicy(sizePolicy);
        op2Line->setMinimumSize(QSize(100, 27));
        op2Line->setFont(font1);

        _3->addWidget(op2Line);

        splitter->addWidget(layoutWidget_4);

        horizontalLayout_2->addWidget(splitter);

        horizontalSpacer = new QSpacerItem(218, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        outputLine = new QLineEdit(centralwidget);
        outputLine->setObjectName(QString::fromUtf8("outputLine"));
        outputLine->setEnabled(false);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(false);
        font2.setStyleStrategy(QFont::PreferDefault);
        outputLine->setFont(font2);
        outputLine->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(outputLine);

        useButton = new QPushButton(centralwidget);
        useButton->setObjectName(QString::fromUtf8("useButton"));

        horizontalLayout_3->addWidget(useButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        typeTabs = new QTabWidget(centralwidget);
        typeTabs->setObjectName(QString::fromUtf8("typeTabs"));
        typeTabs->setTabShape(QTabWidget::Rounded);
        tabNatural = new QWidget();
        tabNatural->setObjectName(QString::fromUtf8("tabNatural"));
        verticalLayout_2 = new QVBoxLayout(tabNatural);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonsLayout = new QGridLayout();
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        naturalLcmButton = new QPushButton(tabNatural);
        naturalLcmButton->setObjectName(QString::fromUtf8("naturalLcmButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(naturalLcmButton->sizePolicy().hasHeightForWidth());
        naturalLcmButton->setSizePolicy(sizePolicy1);
        naturalLcmButton->setMinimumSize(QSize(100, 100));
        naturalLcmButton->setFont(font2);

        buttonsLayout->addWidget(naturalLcmButton, 1, 2, 1, 1);

        naturalMultButton = new QPushButton(tabNatural);
        naturalMultButton->setObjectName(QString::fromUtf8("naturalMultButton"));
        sizePolicy1.setHeightForWidth(naturalMultButton->sizePolicy().hasHeightForWidth());
        naturalMultButton->setSizePolicy(sizePolicy1);
        naturalMultButton->setMinimumSize(QSize(100, 100));
        naturalMultButton->setFont(font2);

        buttonsLayout->addWidget(naturalMultButton, 2, 0, 1, 1);

        naturalGcdButton = new QPushButton(tabNatural);
        naturalGcdButton->setObjectName(QString::fromUtf8("naturalGcdButton"));
        sizePolicy1.setHeightForWidth(naturalGcdButton->sizePolicy().hasHeightForWidth());
        naturalGcdButton->setSizePolicy(sizePolicy1);
        naturalGcdButton->setMinimumSize(QSize(100, 100));
        naturalGcdButton->setFont(font2);

        buttonsLayout->addWidget(naturalGcdButton, 0, 2, 1, 1);

        naturalDivButton = new QPushButton(tabNatural);
        naturalDivButton->setObjectName(QString::fromUtf8("naturalDivButton"));
        sizePolicy1.setHeightForWidth(naturalDivButton->sizePolicy().hasHeightForWidth());
        naturalDivButton->setSizePolicy(sizePolicy1);
        naturalDivButton->setMinimumSize(QSize(100, 100));
        naturalDivButton->setFont(font2);

        buttonsLayout->addWidget(naturalDivButton, 0, 1, 1, 1);

        naturalModButton = new QPushButton(tabNatural);
        naturalModButton->setObjectName(QString::fromUtf8("naturalModButton"));
        sizePolicy1.setHeightForWidth(naturalModButton->sizePolicy().hasHeightForWidth());
        naturalModButton->setSizePolicy(sizePolicy1);
        naturalModButton->setMinimumSize(QSize(100, 100));
        naturalModButton->setFont(font2);
        naturalModButton->setAutoRepeat(false);

        buttonsLayout->addWidget(naturalModButton, 1, 1, 1, 1);

        naturalPlusButton = new QPushButton(tabNatural);
        naturalPlusButton->setObjectName(QString::fromUtf8("naturalPlusButton"));
        sizePolicy1.setHeightForWidth(naturalPlusButton->sizePolicy().hasHeightForWidth());
        naturalPlusButton->setSizePolicy(sizePolicy1);
        naturalPlusButton->setMinimumSize(QSize(100, 100));
        naturalPlusButton->setFont(font2);

        buttonsLayout->addWidget(naturalPlusButton, 0, 0, 1, 1);

        naturalSubButton = new QPushButton(tabNatural);
        naturalSubButton->setObjectName(QString::fromUtf8("naturalSubButton"));
        sizePolicy1.setHeightForWidth(naturalSubButton->sizePolicy().hasHeightForWidth());
        naturalSubButton->setSizePolicy(sizePolicy1);
        naturalSubButton->setMinimumSize(QSize(100, 100));
        naturalSubButton->setFont(font2);

        buttonsLayout->addWidget(naturalSubButton, 1, 0, 1, 1);


        horizontalLayout->addLayout(buttonsLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        infoLabel = new QLabel(tabNatural);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy2);
        infoLabel->setTextFormat(Qt::AutoText);
        infoLabel->setWordWrap(true);

        horizontalLayout->addWidget(infoLabel);


        verticalLayout_2->addLayout(horizontalLayout);

        typeTabs->addTab(tabNatural, QString());
        tabInteger = new QWidget();
        tabInteger->setObjectName(QString::fromUtf8("tabInteger"));
        verticalLayout_3 = new QVBoxLayout(tabInteger);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonsLayout_2 = new QGridLayout();
        buttonsLayout_2->setObjectName(QString::fromUtf8("buttonsLayout_2"));
        integerDivButton = new QPushButton(tabInteger);
        integerDivButton->setObjectName(QString::fromUtf8("integerDivButton"));
        sizePolicy1.setHeightForWidth(integerDivButton->sizePolicy().hasHeightForWidth());
        integerDivButton->setSizePolicy(sizePolicy1);
        integerDivButton->setMinimumSize(QSize(100, 100));
        integerDivButton->setFont(font2);

        buttonsLayout_2->addWidget(integerDivButton, 0, 1, 1, 1);

        integerPlusButton = new QPushButton(tabInteger);
        integerPlusButton->setObjectName(QString::fromUtf8("integerPlusButton"));
        sizePolicy1.setHeightForWidth(integerPlusButton->sizePolicy().hasHeightForWidth());
        integerPlusButton->setSizePolicy(sizePolicy1);
        integerPlusButton->setMinimumSize(QSize(100, 100));
        integerPlusButton->setFont(font2);

        buttonsLayout_2->addWidget(integerPlusButton, 0, 0, 1, 1);

        integerMultButton = new QPushButton(tabInteger);
        integerMultButton->setObjectName(QString::fromUtf8("integerMultButton"));
        sizePolicy1.setHeightForWidth(integerMultButton->sizePolicy().hasHeightForWidth());
        integerMultButton->setSizePolicy(sizePolicy1);
        integerMultButton->setMinimumSize(QSize(100, 100));
        integerMultButton->setFont(font2);

        buttonsLayout_2->addWidget(integerMultButton, 2, 0, 1, 1);

        integerSubButton = new QPushButton(tabInteger);
        integerSubButton->setObjectName(QString::fromUtf8("integerSubButton"));
        sizePolicy1.setHeightForWidth(integerSubButton->sizePolicy().hasHeightForWidth());
        integerSubButton->setSizePolicy(sizePolicy1);
        integerSubButton->setMinimumSize(QSize(100, 100));
        integerSubButton->setFont(font2);

        buttonsLayout_2->addWidget(integerSubButton, 1, 0, 1, 1);

        integerModButton = new QPushButton(tabInteger);
        integerModButton->setObjectName(QString::fromUtf8("integerModButton"));
        sizePolicy1.setHeightForWidth(integerModButton->sizePolicy().hasHeightForWidth());
        integerModButton->setSizePolicy(sizePolicy1);
        integerModButton->setMinimumSize(QSize(100, 100));
        integerModButton->setFont(font2);
        integerModButton->setAutoRepeat(false);

        buttonsLayout_2->addWidget(integerModButton, 1, 1, 1, 1);

        integerAbsButton = new QPushButton(tabInteger);
        integerAbsButton->setObjectName(QString::fromUtf8("integerAbsButton"));
        sizePolicy1.setHeightForWidth(integerAbsButton->sizePolicy().hasHeightForWidth());
        integerAbsButton->setSizePolicy(sizePolicy1);
        integerAbsButton->setMinimumSize(QSize(100, 100));
        integerAbsButton->setFont(font2);
        integerAbsButton->setAutoRepeat(false);

        buttonsLayout_2->addWidget(integerAbsButton, 2, 1, 1, 1);


        horizontalLayout_4->addLayout(buttonsLayout_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        infoLabel_2 = new QLabel(tabInteger);
        infoLabel_2->setObjectName(QString::fromUtf8("infoLabel_2"));
        sizePolicy2.setHeightForWidth(infoLabel_2->sizePolicy().hasHeightForWidth());
        infoLabel_2->setSizePolicy(sizePolicy2);
        infoLabel_2->setTextFormat(Qt::AutoText);
        infoLabel_2->setWordWrap(true);

        horizontalLayout_4->addWidget(infoLabel_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        typeTabs->addTab(tabInteger, QString());
        tabRational = new QWidget();
        tabRational->setObjectName(QString::fromUtf8("tabRational"));
        verticalLayout_6 = new QVBoxLayout(tabRational);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        buttonsLayout_3 = new QGridLayout();
        buttonsLayout_3->setObjectName(QString::fromUtf8("buttonsLayout_3"));
        rationalDivButton = new QPushButton(tabRational);
        rationalDivButton->setObjectName(QString::fromUtf8("rationalDivButton"));
        sizePolicy1.setHeightForWidth(rationalDivButton->sizePolicy().hasHeightForWidth());
        rationalDivButton->setSizePolicy(sizePolicy1);
        rationalDivButton->setMinimumSize(QSize(100, 100));
        rationalDivButton->setFont(font2);

        buttonsLayout_3->addWidget(rationalDivButton, 0, 1, 1, 1);

        rationalMultButton = new QPushButton(tabRational);
        rationalMultButton->setObjectName(QString::fromUtf8("rationalMultButton"));
        sizePolicy1.setHeightForWidth(rationalMultButton->sizePolicy().hasHeightForWidth());
        rationalMultButton->setSizePolicy(sizePolicy1);
        rationalMultButton->setMinimumSize(QSize(100, 100));
        rationalMultButton->setFont(font2);

        buttonsLayout_3->addWidget(rationalMultButton, 2, 0, 1, 1);

        rationalSubButton = new QPushButton(tabRational);
        rationalSubButton->setObjectName(QString::fromUtf8("rationalSubButton"));
        sizePolicy1.setHeightForWidth(rationalSubButton->sizePolicy().hasHeightForWidth());
        rationalSubButton->setSizePolicy(sizePolicy1);
        rationalSubButton->setMinimumSize(QSize(100, 100));
        rationalSubButton->setFont(font2);

        buttonsLayout_3->addWidget(rationalSubButton, 1, 0, 1, 1);

        rationalPlusButton = new QPushButton(tabRational);
        rationalPlusButton->setObjectName(QString::fromUtf8("rationalPlusButton"));
        sizePolicy1.setHeightForWidth(rationalPlusButton->sizePolicy().hasHeightForWidth());
        rationalPlusButton->setSizePolicy(sizePolicy1);
        rationalPlusButton->setMinimumSize(QSize(100, 100));
        rationalPlusButton->setFont(font2);

        buttonsLayout_3->addWidget(rationalPlusButton, 0, 0, 1, 1);

        rationalReduceButton = new QPushButton(tabRational);
        rationalReduceButton->setObjectName(QString::fromUtf8("rationalReduceButton"));
        rationalReduceButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(rationalReduceButton->sizePolicy().hasHeightForWidth());
        rationalReduceButton->setSizePolicy(sizePolicy1);
        rationalReduceButton->setMinimumSize(QSize(100, 100));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Courier"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(false);
        font3.setStyleStrategy(QFont::PreferDefault);
        rationalReduceButton->setFont(font3);
        rationalReduceButton->setAutoDefault(false);
        rationalReduceButton->setFlat(false);

        buttonsLayout_3->addWidget(rationalReduceButton, 2, 1, 1, 1);


        horizontalLayout_5->addLayout(buttonsLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        infoLabel_3 = new QLabel(tabRational);
        infoLabel_3->setObjectName(QString::fromUtf8("infoLabel_3"));
        sizePolicy2.setHeightForWidth(infoLabel_3->sizePolicy().hasHeightForWidth());
        infoLabel_3->setSizePolicy(sizePolicy2);
        infoLabel_3->setTextFormat(Qt::AutoText);
        infoLabel_3->setWordWrap(true);

        horizontalLayout_5->addWidget(infoLabel_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        typeTabs->addTab(tabRational, QString());
        tabPolynomial = new QWidget();
        tabPolynomial->setObjectName(QString::fromUtf8("tabPolynomial"));
        verticalLayout_5 = new QVBoxLayout(tabPolynomial);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        buttonsLayout_4 = new QGridLayout();
        buttonsLayout_4->setObjectName(QString::fromUtf8("buttonsLayout_4"));
        subButton_4 = new QPushButton(tabPolynomial);
        subButton_4->setObjectName(QString::fromUtf8("subButton_4"));
        sizePolicy1.setHeightForWidth(subButton_4->sizePolicy().hasHeightForWidth());
        subButton_4->setSizePolicy(sizePolicy1);
        subButton_4->setMinimumSize(QSize(100, 100));
        subButton_4->setFont(font2);

        buttonsLayout_4->addWidget(subButton_4, 1, 0, 1, 1);

        polynomialMultButton = new QPushButton(tabPolynomial);
        polynomialMultButton->setObjectName(QString::fromUtf8("polynomialMultButton"));
        sizePolicy1.setHeightForWidth(polynomialMultButton->sizePolicy().hasHeightForWidth());
        polynomialMultButton->setSizePolicy(sizePolicy1);
        polynomialMultButton->setMinimumSize(QSize(100, 100));
        polynomialMultButton->setFont(font2);

        buttonsLayout_4->addWidget(polynomialMultButton, 2, 0, 1, 1);

        polynomialDivButton = new QPushButton(tabPolynomial);
        polynomialDivButton->setObjectName(QString::fromUtf8("polynomialDivButton"));
        sizePolicy1.setHeightForWidth(polynomialDivButton->sizePolicy().hasHeightForWidth());
        polynomialDivButton->setSizePolicy(sizePolicy1);
        polynomialDivButton->setMinimumSize(QSize(100, 100));
        polynomialDivButton->setFont(font2);

        buttonsLayout_4->addWidget(polynomialDivButton, 0, 1, 1, 1);

        polynomialPlusButton = new QPushButton(tabPolynomial);
        polynomialPlusButton->setObjectName(QString::fromUtf8("polynomialPlusButton"));
        sizePolicy1.setHeightForWidth(polynomialPlusButton->sizePolicy().hasHeightForWidth());
        polynomialPlusButton->setSizePolicy(sizePolicy1);
        polynomialPlusButton->setMinimumSize(QSize(100, 100));
        polynomialPlusButton->setFont(font2);

        buttonsLayout_4->addWidget(polynomialPlusButton, 0, 0, 1, 1);

        polynomialGcdButton = new QPushButton(tabPolynomial);
        polynomialGcdButton->setObjectName(QString::fromUtf8("polynomialGcdButton"));
        sizePolicy1.setHeightForWidth(polynomialGcdButton->sizePolicy().hasHeightForWidth());
        polynomialGcdButton->setSizePolicy(sizePolicy1);
        polynomialGcdButton->setMinimumSize(QSize(100, 100));
        polynomialGcdButton->setFont(font2);

        buttonsLayout_4->addWidget(polynomialGcdButton, 0, 2, 1, 1);

        polynomialModButton = new QPushButton(tabPolynomial);
        polynomialModButton->setObjectName(QString::fromUtf8("polynomialModButton"));
        sizePolicy1.setHeightForWidth(polynomialModButton->sizePolicy().hasHeightForWidth());
        polynomialModButton->setSizePolicy(sizePolicy1);
        polynomialModButton->setMinimumSize(QSize(100, 100));
        polynomialModButton->setFont(font2);
        polynomialModButton->setAutoRepeat(false);

        buttonsLayout_4->addWidget(polynomialModButton, 1, 1, 1, 1);

        polynomialDerivativeButton = new QPushButton(tabPolynomial);
        polynomialDerivativeButton->setObjectName(QString::fromUtf8("polynomialDerivativeButton"));
        polynomialDerivativeButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(polynomialDerivativeButton->sizePolicy().hasHeightForWidth());
        polynomialDerivativeButton->setSizePolicy(sizePolicy1);
        polynomialDerivativeButton->setMinimumSize(QSize(100, 100));
        polynomialDerivativeButton->setFont(font2);
        polynomialDerivativeButton->setAutoDefault(false);

        buttonsLayout_4->addWidget(polynomialDerivativeButton, 2, 1, 1, 1);

        polynomialFactorizeButton = new QPushButton(tabPolynomial);
        polynomialFactorizeButton->setObjectName(QString::fromUtf8("polynomialFactorizeButton"));
        polynomialFactorizeButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(polynomialFactorizeButton->sizePolicy().hasHeightForWidth());
        polynomialFactorizeButton->setSizePolicy(sizePolicy1);
        polynomialFactorizeButton->setMinimumSize(QSize(100, 100));
        polynomialFactorizeButton->setFont(font2);
        polynomialFactorizeButton->setAutoDefault(false);

        buttonsLayout_4->addWidget(polynomialFactorizeButton, 0, 3, 1, 1);

        polynomialReduceCButton = new QPushButton(tabPolynomial);
        polynomialReduceCButton->setObjectName(QString::fromUtf8("polynomialReduceCButton"));
        polynomialReduceCButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(polynomialReduceCButton->sizePolicy().hasHeightForWidth());
        polynomialReduceCButton->setSizePolicy(sizePolicy1);
        polynomialReduceCButton->setMinimumSize(QSize(100, 100));
        polynomialReduceCButton->setFont(font3);
        polynomialReduceCButton->setAutoDefault(false);
        polynomialReduceCButton->setFlat(false);

        buttonsLayout_4->addWidget(polynomialReduceCButton, 1, 3, 1, 1);

        polynomialReduceButton = new QPushButton(tabPolynomial);
        polynomialReduceButton->setObjectName(QString::fromUtf8("polynomialReduceButton"));
        polynomialReduceButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(polynomialReduceButton->sizePolicy().hasHeightForWidth());
        polynomialReduceButton->setSizePolicy(sizePolicy1);
        polynomialReduceButton->setMinimumSize(QSize(100, 100));
        polynomialReduceButton->setFont(font3);
        polynomialReduceButton->setAutoDefault(false);
        polynomialReduceButton->setFlat(false);

        buttonsLayout_4->addWidget(polynomialReduceButton, 2, 3, 1, 1);


        horizontalLayout_6->addLayout(buttonsLayout_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        infoLabel_4 = new QLabel(tabPolynomial);
        infoLabel_4->setObjectName(QString::fromUtf8("infoLabel_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(infoLabel_4->sizePolicy().hasHeightForWidth());
        infoLabel_4->setSizePolicy(sizePolicy3);
        infoLabel_4->setTextFormat(Qt::AutoText);
        infoLabel_4->setWordWrap(true);

        horizontalLayout_6->addWidget(infoLabel_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        typeTabs->addTab(tabPolynomial, QString());

        verticalLayout->addWidget(typeTabs);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        typeTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DM Project", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 1", nullptr));
        op1Line->setInputMask(QString());
        op1Line->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\320\275\320\264 2", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        outputLine->setInputMask(QString());
        outputLine->setText(QApplication::translate("MainWindow", "hello", nullptr));
        useButton->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        useButton->setShortcut(QApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        naturalLcmButton->setText(QApplication::translate("MainWindow", "\320\235\320\236\320\232", nullptr));
        naturalMultButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        naturalGcdButton->setText(QApplication::translate("MainWindow", "\320\235\320\236\320\224", nullptr));
        naturalDivButton->setText(QApplication::translate("MainWindow", "div", nullptr));
        naturalModButton->setText(QApplication::translate("MainWindow", "mod", nullptr));
        naturalPlusButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        naturalSubButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        infoLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\262\320\276\320\264\320\260: [\320\275\320\260\320\261\320\276\321\200 \321\206\320\270\321\204\321\200]<br/>\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: 123; 21; 0 </span></p><p><span style=\" font-size:7pt;\">\320\232\320\276\320\274\320\260\320\275\320\264\321\213:</span></p><p><span style=\" font-size:7pt;\">'+' - \321\201\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 </span></p><p><span style=\" font-size:7pt;\">'-' - \320\262\321\213\321\207\320\270\321\202\320\260\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 (\320\277\320\265\321\200\320\262\321\213\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\261\320\276\320\273\321\214\321\210\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276) </span></p><p><span style=\" font-size:7pt;\">'*' - \321\203\320\274\320\275\320\276"
                        "\320\266\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 </span></p><p><span style=\" font-size:7pt;\">'div' - \320\264\320\265\320\273\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 - \320\275\320\265 \320\275\320\276\320\273\321\214) </span></p><p><span style=\" font-size:7pt;\">'mod' - \320\276\321\201\321\202\320\260\321\202\320\276\320\272 \320\276\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p><p><span style=\" font-size:7pt;\">'\320\235\320\236\320\224' - \320\275\320\260\320\270\320\261\320\276\320\273\321\214\321\210\320\270\320\271 \320\276\320\261\321\211\320\270\320\271 \320\264\320\265\320\273\320\270\321\202\320\265\320"
                        "\273\321\214 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p><p><span style=\" font-size:7pt;\">'\320\235\320\236\320\232' - \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\265\320\265 \320\276\320\261\321\211\320\265\320\265 \320\272\321\200\320\260\321\202\320\275\320\276\320\265 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p></body></html>", nullptr));
        typeTabs->setTabText(typeTabs->indexOf(tabNatural), QApplication::translate("MainWindow", "\320\235\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\321\213\320\265", nullptr));
        integerDivButton->setText(QApplication::translate("MainWindow", "div", nullptr));
        integerPlusButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        integerMultButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        integerSubButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        integerModButton->setText(QApplication::translate("MainWindow", "mod", nullptr));
        integerAbsButton->setText(QApplication::translate("MainWindow", "abs", nullptr));
        infoLabel_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\262\320\276\320\264\320\260: (+-)[\320\235\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\320\276\320\265]<br/>\320\225\321\201\320\273\320\270 \320\277\320\265\321\200\320\265\320\264 \320\275\320\260\320\261\320\276\321\200\320\276\320\274 \321\206\320\270\321\204\321\200 \320\275\320\265\321\202 \320\267\320\275\320\260\320\272\320\260, \321\202\320\276 \321\207\320\270\321\201\320\273\320\276 \320\277\320\276\320\273\320\276\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265<br/>\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: -12; +123; 11</span></p><p><span style=\" font-size:7pt;\">\320\232\320\276\320\274\320\260\320\275\320\264\321\213:</span></p><p><span style=\" font-size:7pt;\">'+' - \321\201\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 </span></p><p><span style=\" font-size:7pt;"
                        "\">'-' - \320\262\321\213\321\207\320\270\321\202\320\260\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 (\320\277\320\265\321\200\320\262\321\213\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\261\320\276\320\273\321\214\321\210\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276) </span></p><p><span style=\" font-size:7pt;\">'*' - \321\203\320\274\320\275\320\276\320\266\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 </span></p><p><span style=\" font-size:7pt;\">'div' - \320\264\320\265\320\273\320\265\320\275\320\270\320\265 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 - \320\275\320\265 \320\275\320\276\320\273\321\214) </span></p><p><span style=\" font-size:7pt;\">'mod' - \320\276\321\201\321\202\320\260\321\202\320\276\320\272 \320\276\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\207\320\270\321\201\320"
                        "\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p><p><span style=\" font-size:7pt;\">'abs' - \320\274\320\276\320\264\321\203\320\273\321\214 \321\207\320\270\321\201\320\273\320\260 \320\262 \320\277\320\265\321\200\320\262\320\276\320\274 \320\276\320\277\320\265\321\200\320\260\320\275\320\264\320\265<br/></span></p></body></html>", nullptr));
        typeTabs->setTabText(typeTabs->indexOf(tabInteger), QApplication::translate("MainWindow", "\320\246\320\265\320\273\321\213\320\265", nullptr));
        rationalDivButton->setText(QApplication::translate("MainWindow", "div", nullptr));
        rationalMultButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        rationalSubButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        rationalPlusButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        rationalReduceButton->setText(QApplication::translate("MainWindow", "\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214\n"
"\320\264\321\200\320\276\320\261\321\214", nullptr));
        infoLabel_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\262\320\276\320\264\320\260: [\320\246\320\265\320\273\320\276\320\265](/ \320\235\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\320\276\320\265).<br/>\320\225\321\201\320\273\320\270 \320\267\320\275\320\260\320\274\320\265\320\275\320\260\321\202\320\265\320\273\321\214 \320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275, \321\202\320\276 \320\276\320\275 \321\201\321\207\320\270\321\202\320\260\320\265\321\202\321\201\321\217 1.<br/>\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: 123/15; -123</span></p><p><span style=\" font-size:7pt;\">'+' - \321\201\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\321\200\320\276\320\261\320\265\320\271 </span></p><p><span style=\" font-size:7pt;\">'-' - \320\262\321\213\321\207\320\270\321\202\320\260\320\275\320\270\320\265 \320\264\321\200\320\276\320\261\320\265\320\271 (\320\277\320\265\321"
                        "\200\320\262\321\213\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\261\320\276\320\273\321\214\321\210\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276) </span></p><p><span style=\" font-size:7pt;\">'*' - \321\203\320\274\320\275\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\321\200\320\276\320\261\320\265\320\271 </span></p><p><span style=\" font-size:7pt;\">'div' - \320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\264\321\200\320\276\320\261\320\265\320\271 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 - \320\275\320\265 \320\275\320\276\320\273\321\214) </span></p><p><span style=\" font-size:7pt;\">'\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\264\321\200\320\276\320\261\321\214' - \321\201\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\264\321\200\320\276\320\261\320\270 :)</span></p><p><span style=\" font-size:7pt;\"><br/"
                        "></span></p></body></html>", nullptr));
        typeTabs->setTabText(typeTabs->indexOf(tabRational), QApplication::translate("MainWindow", "\320\240\320\260\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\265", nullptr));
        subButton_4->setText(QApplication::translate("MainWindow", "-", nullptr));
        polynomialMultButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        polynomialDivButton->setText(QApplication::translate("MainWindow", "div", nullptr));
        polynomialPlusButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        polynomialGcdButton->setText(QApplication::translate("MainWindow", "\320\235\320\236\320\224", nullptr));
        polynomialModButton->setText(QApplication::translate("MainWindow", "mod", nullptr));
        polynomialDerivativeButton->setText(QApplication::translate("MainWindow", "d/dx", nullptr));
        polynomialFactorizeButton->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\275\320\265\321\201\321\202\320\270", nullptr));
        polynomialReduceCButton->setText(QApplication::translate("MainWindow", "\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214\n"
"\320\272\320\276\321\215\321\204\321\204-\321\202\321\213", nullptr));
        polynomialReduceButton->setText(QApplication::translate("MainWindow", "\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214\n"
"\320\272\320\276\321\200\320\275\320\270", nullptr));
        infoLabel_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\262\320\276\320\264\320\260: \320\235\320\260\320\261\320\276\321\200 \320\276\320\264\320\275\320\276\321\207\320\273\320\265\320\275\320\276\320\262 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 [\320\240\320\260\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\276\320\265](*)(x)(^\320\235\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\320\276\320\265)<br/>\320\225\321\201\320\273\320\270 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275, \321\202\320\276 \320\276\320\275 \321\200\320\260\320\262\320\265\320\275 1<br/>\320\225\321\201\320\273\320\270 \321\201\321\202\320\265\320\277\320\265\320\275\321\214 \320\275\320\265 \321\203\320\272\320\260\320\267\320\260\320\275\320\260, \321\202\320\276 \320\276\320\275\320\260 \321\200\320\260"
                        "\320\262\320\275\320\260 1</span></p><p><span style=\" font-size:7pt;\">\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: -x^5 + 5/3 * x^2; x^3 + 2x + 5/6; 12/3</span></p><p><span style=\" font-size:7pt;\">\320\232\320\276\320\274\320\260\320\275\320\264\321\213:</span></p><p><span style=\" font-size:7pt;\">'+' - \321\201\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\276\320\262 </span></p><p><span style=\" font-size:7pt;\">'-' - \320\262\321\213\321\207\320\270\321\202\320\260\320\275\320\270\320\265 \320\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\276\320\262 </span></p><p><span style=\" font-size:7pt;\">'*' - \321\203\320\274\320\275\320\276\320\266\320\265\320\275\320\270\320\265 \320\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\276\320\262 </span></p><p><span style=\" font-size:7pt;\">'div' - \320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320"
                        "\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\276\320\262 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214) </span></p><p><span style=\" font-size:7pt;\">'mod' - \320\276\321\201\321\202\320\260\321\202\320\276\320\272 \320\276\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\276\320\262 (\320\262\321\202\320\276\321\200\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p><p><span style=\" font-size:7pt;\">'\320\235\320\236\320\224' - \320\275\320\260\320\270\320\261\320\276\320\273\321\214\321\210\320\270\320\271 \320\276\320\261\321\211\320\270\320\271 \320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214 \321\207\320\270\321\201\320\265\320\273 (\320\262\321\202\320\276\321\200\320\276\320\271"
                        " \320\276\320\277\320\265\321\200\320\260\320\275\320\264 \320\275\320\265 \320\275\320\276\320\273\321\214)</span></p><p><span style=\" font-size:7pt;\">'\320\262\321\213\320\275\320\265\321\201\321\202\320\270' - \320\262\321\213\320\275\320\265\321\201\320\265\320\275\320\270\320\265 \320\270\320\267 \320\274\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\320\260 \320\235\320\236\320\232 \320\267\320\275\320\260\320\274\320\265\320\275\320\260\321\202\320\265\320\273\320\265\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\276\320\262 \320\270 \320\235\320\236\320\224 \321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\320\265\320\271</span></p><p><span style=\" font-size:7pt;\">'\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\272\320\276\321\215\321\204\321\204-\321\202\321\213' - \321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\262\321\201\320\265 \320\264\321\200\320"
                        "\276\320\261\320\275\321\213\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213</span></p><p><span style=\" font-size:7pt;\">'\321\201\320\276\320\272\321\200\320\260\321\202\320\270\321\202\321\214 \320\272\320\276\321\200\320\275\320\270' - \320\272\321\200\320\260\321\202\320\275\321\213\320\265 \320\272\320\276\321\200\320\275\320\270 \320\262 \320\277\321\200\320\276\321\201\321\202\321\213\320\265</span></p></body></html>", nullptr));
        typeTabs->setTabText(typeTabs->indexOf(tabPolynomial), QApplication::translate("MainWindow", "\320\234\320\275\320\276\320\263\320\276\321\207\320\273\320\265\320\275\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
