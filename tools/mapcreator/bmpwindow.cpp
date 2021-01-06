#include "bmpwindow.h"
#include "ui_bmpwindow.h"

#include <QLabel>

BMPWindow::BMPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BMPWindow)
{
    ui->setupUi(this);
}

BMPWindow::~BMPWindow()
{
    delete ui;
}

void BMPWindow::set_bmp_file_name(QString name) {
    this->bmp_file_name = name;
}

void BMPWindow::load_bmp() {
    auto label = this->findChild<QLabel*>("bmp");
}
