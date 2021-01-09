#include "qtileselector.h"

QTileSelector::QTileSelector(QWidget* parent) {
    this->parent = parent;
}

QTileSelector::~QTileSelector() {
    delete pixmap;
    delete pixmap_copy;
    delete painter;
    delete rect;
    delete pen;
    delete x_line_edit;
    delete y_line_edit;
    delete w_line_edit;
    delete h_line_edit;
}

void QTileSelector::load_bmp(QString file_name) {
    pixmap = new QPixmap();
    pixmap_copy = new QPixmap();
    pixmap->load(file_name);
    pixmap_copy->load(file_name);
    bmp_file_name = file_name;
}

void QTileSelector::set_background_color(QString color) {
    if(color == "black")
        background_color = Qt::black;
    else if(color == "white")
        background_color = Qt::white;
    else
        background_color = Qt::lightGray;
}

void QTileSelector::set_marking_color(QString color) {
    if(color == "black")
        marking_color = Qt::black;
    else if(color == "white")
        marking_color = Qt::white;
    else
        marking_color = Qt::lightGray;
}

const QRect QTileSelector::get_marked_area() {
    return *rect;
}

void QTileSelector::mousePressEvent(QMouseEvent *ev) {
    auto position = ev->pos();
    mark_position_x = mark_position_x2 = position.x();
    mark_position_y = mark_position_y2 = position.y();
    if(rect) {
        delete rect;
        rect = nullptr;
    }
}

void QTileSelector::mouseMoveEvent(QMouseEvent *ev) {

    auto position = ev->pos();
    mark_position_x2 = position.x();
    mark_position_y2 = position.y();
    if(rect)
        delete rect;

    rect = new QRect(mark_position_x, mark_position_y, mark_position_x2 - mark_position_x, mark_position_y2 - mark_position_y);
    x_line_edit->setText(QString::number(mark_position_x));
    y_line_edit->setText(QString::number(mark_position_y));
    w_line_edit->setText(QString::number(mark_position_x2));
    h_line_edit->setText(QString::number(mark_position_y2));
}

void QTileSelector::paintEvent(QPaintEvent* ev) {
    QLabel::paintEvent(ev);
    if (!painter) {
        painter = new QPainter(pixmap_copy);
        pen = new QPen();
        pen->setColor(marking_color);
        pen->setWidth(1);
        painter->setPen(*pen);
    }
    if(pen->color() != marking_color) {
        pen->setColor(marking_color);
        painter->setPen(*pen);
    }
    if(painter && painter->isActive()) {
        painter->eraseRect(pixmap_copy->rect());
        painter->fillRect(pixmap_copy->rect(), background_color);
        painter->drawPixmap(pixmap_copy->rect(), *pixmap);

        if(rect){
            painter->drawLine(mark_position_x, mark_position_y, mark_position_x2, mark_position_y);
            painter->drawLine(mark_position_x, mark_position_y, mark_position_x, mark_position_y2);
            painter->drawLine(mark_position_x, mark_position_y2, mark_position_x2, mark_position_y2);
            painter->drawLine(mark_position_x2, mark_position_y, mark_position_x2, mark_position_y2);
        }
    }
    setPixmap(*pixmap_copy);
}
