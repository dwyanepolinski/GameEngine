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
#include <QtWidgets/QComboBox>
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
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *x_edit;
    QLabel *label_3;
    QLineEdit *y_edit;
    QLabel *label_4;
    QLineEdit *w_edit;
    QLabel *label_5;
    QLineEdit *h_edit;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *bmp_file_name;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QTileSelector *bmp;
    QPushButton *change_bmp_btn;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *BMPWindow)
    {
        if (BMPWindow->objectName().isEmpty())
            BMPWindow->setObjectName(QStringLiteral("BMPWindow"));
        BMPWindow->resize(880, 653);
        centralwidget = new QWidget(BMPWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        x_edit = new QLineEdit(centralwidget);
        x_edit->setObjectName(QStringLiteral("x_edit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, x_edit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        y_edit = new QLineEdit(centralwidget);
        y_edit->setObjectName(QStringLiteral("y_edit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, y_edit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_4);

        w_edit = new QLineEdit(centralwidget);
        w_edit->setObjectName(QStringLiteral("w_edit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, w_edit);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        h_edit = new QLineEdit(centralwidget);
        h_edit->setObjectName(QStringLiteral("h_edit"));

        formLayout->setWidget(8, QFormLayout::FieldRole, h_edit);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_7);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(10, QFormLayout::FieldRole, comboBox_2);


        verticalLayout->addLayout(formLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 423, 275));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        bmp_file_name = new QLabel(centralwidget);
        bmp_file_name->setObjectName(QStringLiteral("bmp_file_name"));

        gridLayout->addWidget(bmp_file_name, 1, 0, 1, 1);

        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 412, 561));
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

        gridLayout->addWidget(scrollArea_2, 2, 1, 1, 1);

        change_bmp_btn = new QPushButton(centralwidget);
        change_bmp_btn->setObjectName(QStringLiteral("change_bmp_btn"));

        gridLayout->addWidget(change_bmp_btn, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        BMPWindow->setCentralWidget(centralwidget);

        retranslateUi(BMPWindow);

        QMetaObject::connectSlotsByName(BMPWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BMPWindow)
    {
        BMPWindow->setWindowTitle(QApplication::translate("BMPWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("BMPWindow", "X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("BMPWindow", "Y: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("BMPWindow", "X2 ", Q_NULLPTR));
        label_5->setText(QApplication::translate("BMPWindow", "Y2: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("BMPWindow", "Background color: ", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("BMPWindow", "gray", Q_NULLPTR)
         << QApplication::translate("BMPWindow", "black", Q_NULLPTR)
         << QApplication::translate("BMPWindow", "white", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("BMPWindow", "Marking color: ", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("BMPWindow", "black", Q_NULLPTR)
         << QApplication::translate("BMPWindow", "gray", Q_NULLPTR)
         << QApplication::translate("BMPWindow", "white", Q_NULLPTR)
        );
        bmp_file_name->setText(QApplication::translate("BMPWindow", "BMP: ", Q_NULLPTR));
        bmp->setText(QString());
        change_bmp_btn->setText(QApplication::translate("BMPWindow", "Change BMP", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BMPWindow", "Add", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BMPWindow", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BMPWindow: public Ui_BMPWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMPWINDOW_H
