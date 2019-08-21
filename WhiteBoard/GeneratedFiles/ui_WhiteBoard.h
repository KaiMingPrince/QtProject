/********************************************************************************
** Form generated from reading UI file 'WhiteBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHITEBOARD_H
#define UI_WHITEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "WhiteBoard.h"

QT_BEGIN_NAMESPACE

class Ui_WhiteBoardClass
{
public:
    QHBoxLayout *horizontalLayout;
    WhiteBoard *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_pen_width;
    QComboBox *comboBox_eraser_width;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_sync;
    QSpacerItem *verticalSpacer;
    WhiteBoard *widget_2;

    void setupUi(QWidget *WhiteBoardClass)
    {
        if (WhiteBoardClass->objectName().isEmpty())
            WhiteBoardClass->setObjectName(QStringLiteral("WhiteBoardClass"));
        WhiteBoardClass->resize(731, 300);
        horizontalLayout = new QHBoxLayout(WhiteBoardClass);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new WhiteBoard(WhiteBoardClass);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox_pen_width = new QComboBox(WhiteBoardClass);
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->addItem(QString());
        comboBox_pen_width->setObjectName(QStringLiteral("comboBox_pen_width"));
        comboBox_pen_width->setFrame(true);

        verticalLayout->addWidget(comboBox_pen_width);

        comboBox_eraser_width = new QComboBox(WhiteBoardClass);
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->addItem(QString());
        comboBox_eraser_width->setObjectName(QStringLiteral("comboBox_eraser_width"));

        verticalLayout->addWidget(comboBox_eraser_width);

        pushButton_clear = new QPushButton(WhiteBoardClass);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        verticalLayout->addWidget(pushButton_clear);

        pushButton_sync = new QPushButton(WhiteBoardClass);
        pushButton_sync->setObjectName(QStringLiteral("pushButton_sync"));
        pushButton_sync->setCheckable(true);

        verticalLayout->addWidget(pushButton_sync);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        widget_2 = new WhiteBoard(WhiteBoardClass);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        horizontalLayout->addWidget(widget_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(WhiteBoardClass);

        QMetaObject::connectSlotsByName(WhiteBoardClass);
    } // setupUi

    void retranslateUi(QWidget *WhiteBoardClass)
    {
        WhiteBoardClass->setWindowTitle(QApplication::translate("WhiteBoardClass", "WhiteBoard", nullptr));
        comboBox_pen_width->setItemText(0, QApplication::translate("WhiteBoardClass", "4", nullptr));
        comboBox_pen_width->setItemText(1, QApplication::translate("WhiteBoardClass", "6", nullptr));
        comboBox_pen_width->setItemText(2, QApplication::translate("WhiteBoardClass", "8", nullptr));
        comboBox_pen_width->setItemText(3, QApplication::translate("WhiteBoardClass", "10", nullptr));
        comboBox_pen_width->setItemText(4, QApplication::translate("WhiteBoardClass", "12", nullptr));
        comboBox_pen_width->setItemText(5, QApplication::translate("WhiteBoardClass", "14", nullptr));

        comboBox_eraser_width->setItemText(0, QApplication::translate("WhiteBoardClass", "4", nullptr));
        comboBox_eraser_width->setItemText(1, QApplication::translate("WhiteBoardClass", "6", nullptr));
        comboBox_eraser_width->setItemText(2, QApplication::translate("WhiteBoardClass", "8", nullptr));
        comboBox_eraser_width->setItemText(3, QApplication::translate("WhiteBoardClass", "10", nullptr));
        comboBox_eraser_width->setItemText(4, QApplication::translate("WhiteBoardClass", "12", nullptr));
        comboBox_eraser_width->setItemText(5, QApplication::translate("WhiteBoardClass", "14", nullptr));

        pushButton_clear->setText(QApplication::translate("WhiteBoardClass", "\346\270\205\347\251\272", nullptr));
        pushButton_sync->setText(QApplication::translate("WhiteBoardClass", "\345\220\214\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WhiteBoardClass: public Ui_WhiteBoardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHITEBOARD_H
