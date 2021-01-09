#include "bmpwindow.h"
#include "ui_bmpwindow.h"


BMPWindow::BMPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BMPWindow) {
    ui->setupUi(this);

    tile_selector = this->findChild<QTileSelector*>("bmp");
    bmp_file_name_label = findChild<QLabel*>("bmp_file_name");

    tile_selector->x_line_edit = findChild<QLineEdit*>("x_edit");
    tile_selector->y_line_edit = findChild<QLineEdit*>("y_edit");
    tile_selector->w_line_edit = findChild<QLineEdit*>("w_edit");
    tile_selector->h_line_edit = findChild<QLineEdit*>("h_edit");
}

BMPWindow::~BMPWindow() {
    delete ui;
    delete tile_selector;
    delete bmp_file_name_label;
}

void BMPWindow::load_bmp(QString name) {
    bmp_file_name = name;
    bmp_file_name_label->setText("BMP: " + bmp_file_name);
    tile_selector->load_bmp(this->bmp_file_name);
}

void BMPWindow::on_comboBox_currentIndexChanged(const QString &arg1) {
    tile_selector->set_background_color(arg1);
}

void BMPWindow::on_comboBox_2_currentIndexChanged(const QString &arg1) {
    tile_selector->set_marking_color(arg1);
}

void BMPWindow::on_x_edit_textChanged(const QString &arg1) {
    tile_selector->mark_position_x = arg1.toInt();
}

void BMPWindow::on_y_edit_textChanged(const QString &arg1) {
    tile_selector->mark_position_y = arg1.toInt();
}

void BMPWindow::on_w_edit_textChanged(const QString &arg1) {
    tile_selector->mark_position_x2 = arg1.toInt();
}

void BMPWindow::on_h_edit_textChanged(const QString &arg1) {
    tile_selector->mark_position_y2 = arg1.toInt();
}
