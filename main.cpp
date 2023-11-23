#include "UI/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./DM.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
