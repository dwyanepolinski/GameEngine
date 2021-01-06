#include "qtileselector.h"
#include <QDebug>

QTileSelector::QTileSelector(QWidget* parent) {
    this->parent = parent;
}

QTileSelector::~QTileSelector() {
    delete pixmap;
}

void QTileSelector::load_bmp(QString file_name) {
    this->pixmap = new QPixmap();
    this->pixmap->load(file_name);
    this->setPixmap(*this->pixmap);
}

void QTileSelector::mousePressEvent(QMouseEvent *ev) {
    auto position = ev->pos();
    qDebug() << position.x() <<" " << position.y();
}
