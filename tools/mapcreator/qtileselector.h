#ifndef QTILESELECTOR_H
#define QTILESELECTOR_H

#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QString>
#include <QMouseEvent>

class QTileSelector : public QLabel
{
    public:
    QTileSelector(QWidget* parent);
    ~QTileSelector();
    void load_bmp(QString file_name);

    protected:
    QPixmap* pixmap;

    void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

    private:
    QWidget* parent;
};

#endif // QTILESELECTOR_H
