#include "bmpwindow.h"
#include "ui_bmpwindow.h"
#include "qtileselector.h"

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
    auto tile_selector = this->findChild<QTileSelector*>("bmp");
    tile_selector->load_bmp(this->bmp_file_name);
}
