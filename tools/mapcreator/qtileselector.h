#ifndef QTILESELECTOR_H
#define QTILESELECTOR_H

#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QDebug>
#include <QPen>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QSize>
#include <QBrush>
#include <QColor>
#include <QLineEdit>

class QTileSelector : public QLabel
{
    public:
    QTileSelector(QWidget* parent);
    ~QTileSelector();
    void load_bmp(QString file_name);
    void set_background_color(QString color);
    void set_marking_color(QString color);
    const QRect get_marked_area();
    int mark_position_x, mark_position_y, mark_position_x2, mark_position_y2;
    QLineEdit* x_line_edit;
    QLineEdit* y_line_edit;
    QLineEdit* w_line_edit;
    QLineEdit* h_line_edit;

    protected:
    QPixmap* pixmap = nullptr;
    QPixmap* pixmap_copy = nullptr;
    QPainter* painter = nullptr;
    QRect* rect = nullptr;
    QPen* pen = nullptr;

    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
//    void mouseReleaseEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

    private:
    QWidget* parent;
    QString bmp_file_name;
    QColor background_color = Qt::lightGray;
    QColor marking_color = Qt::black;
};

#endif // QTILESELECTOR_H
