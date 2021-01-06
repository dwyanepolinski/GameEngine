#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "bmpwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_map_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open BMP file"), "/home/john/Pobrane", tr("BMP Files (*.bmp)"));
    auto bmp_window = new BMPWindow();
    bmp_window->set_bmp_file_name(file_name);
    this->hide();
    bmp_window->show();
}
