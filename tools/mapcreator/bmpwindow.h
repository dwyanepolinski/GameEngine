#ifndef BMPWINDOW_H
#define BMPWINDOW_H

#include <QMainWindow>

namespace Ui {
    class BMPWindow;
}

class BMPWindow : public QMainWindow
{
    Q_OBJECT

    public:
    void set_bmp_file_name(QString name);
    void load_bmp();
    explicit BMPWindow(QWidget *parent = 0);
    ~BMPWindow();

    private:
    Ui::BMPWindow *ui;
    QString bmp_file_name;
};

#endif // BMPWINDOW_H
