#ifndef BMPWINDOW_H
#define BMPWINDOW_H

#include <QMainWindow>
#include "qtileselector.h"

namespace Ui {
    class BMPWindow;
}

class BMPWindow : public QMainWindow
{
    Q_OBJECT

    public:
    void load_bmp(QString name);
    explicit BMPWindow(QWidget *parent = 0);
    ~BMPWindow();

    private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_x_edit_textChanged(const QString &arg1);

    void on_y_edit_textChanged(const QString &arg1);

    void on_w_edit_textChanged(const QString &arg1);

    void on_h_edit_textChanged(const QString &arg1);

    private:
    Ui::BMPWindow *ui;
    QString bmp_file_name;
    QTileSelector* tile_selector = nullptr;
    QLabel* bmp_file_name_label = nullptr; //, mouse_position_label = nullptr;
//    QLineEdit* x_line_edit = nullptr, y_line_edit = nullptr, w_line_edit = nullptr, h_line_edit = nullptr;
};

#endif // BMPWINDOW_H
