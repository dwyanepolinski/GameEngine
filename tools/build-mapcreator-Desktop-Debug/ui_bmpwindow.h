/********************************************************************************
** Form generated from reading UI file 'bmpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMPWINDOW_H
#define UI_BMPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtileselector.h"

QT_BEGIN_NAMESPACE

class Ui_BMPWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *bmp_file_name;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QTileSelector *bmp;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *BMPWindow)
    {
        if (BMPWindow->objectName().isEmpty())
            BMPWindow->setObjectName(QStringLiteral("BMPWindow"));
        BMPWindow->resize(489, 341);
        centralwidget = new QWidget(BMPWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        bmp_file_name = new QLabel(centralwidget);
        bmp_file_name->setObjectName(QStringLiteral("bmp_file_name"));

        gridLayout->addWidget(bmp_file_name, 0, 1, 1, 1);

        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 216, 261));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        bmp = new QTileSelector(scrollAreaWidgetContents_2);
        bmp->setObjectName(QStringLiteral("bmp"));
        bmp->setMouseTracking(false);
        bmp->setStyleSheet(QStringLiteral("border: 1px solid black;"));

        gridLayout_3->addWidget(bmp, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea_2, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);


        verticalLayout->addLayout(formLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 228, 103));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        BMPWindow->setCentralWidget(centralwidget);

        retranslateUi(BMPWindow);

        QMetaObject::connectSlotsByName(BMPWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BMPWindow)
    {
        BMPWindow->setWindowTitle(QApplication::translate("BMPWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("BMPWindow", "BMP: ", Q_NULLPTR));
        bmp_file_name->setText(QString());
        bmp->setText(QString());
        label_2->setText(QApplication::translate("BMPWindow", "X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("BMPWindow", "Y: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("BMPWindow", "W: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("BMPWindow", "H: ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BMPWindow", "Add", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BMPWindow", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BMPWindow: public Ui_BMPWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMPWINDOW_H
