/********************************************************************************
** Form generated from reading UI file 'ChangeHeaderWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEHEADERWND_H
#define UI_CHANGEHEADERWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <UI/DragScrollArea.h>

QT_BEGIN_NAMESPACE

class Ui_ChangeHeaderWnd
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_upload;
    QSpacerItem *horizontalSpacer_2;
    DragScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label_header;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QPushButton *pushButton_anti;
    QPushButton *pushButton_clock;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QLabel *label_tip;

    void setupUi(QWidget *ChangeHeaderWnd)
    {
        if (ChangeHeaderWnd->objectName().isEmpty())
            ChangeHeaderWnd->setObjectName(QStringLiteral("ChangeHeaderWnd"));
        ChangeHeaderWnd->resize(242, 399);
        ChangeHeaderWnd->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"	font-size:14px;\n"
"}\n"
"QWidget#UploadHeaderWnd\n"
"{\n"
"	background:#dddddd;\n"
"}\n"
"QWidget#widget_title\n"
"{\n"
"	background:#f0f0f0;\n"
"}\n"
"QLabel#label_title\n"
"{\n"
"	color:#666666;\n"
"}\n"
"QPushButton\n"
"{\n"
"	border:1px solid gray;\n"
"	border-radius:2px;\n"
"	background:white;\n"
"	font-size:16px;\n"
"}\n"
"QPushButton#pushButton_close\n"
"{\n"
"	border:none;\n"
"	background:transparent;\n"
"}\n"
"QPushButton#pushButton_anti\n"
"{\n"
"	border:none;\n"
"	background:#dddddd;\n"
"	background-image:url(:/QRC/UI/Image/rotate_anti_normal.png);\n"
"}\n"
"QPushButton#pushButton_anti:hover\n"
"{\n"
"	background-image:url(:/QRC/UI/Image/rotate_anti_hover.png);\n"
"}\n"
"QPushButton#pushButton_clock\n"
"{\n"
"	border:none;\n"
"	background:#dddddd;\n"
"	background-image:url(:/QRC/UI/Image/rotate_clock_normal.png);\n"
"}\n"
"QPushButton#pushButton_clock:hover\n"
"{\n"
"	background-image:url(:/QRC/UI/Image/rotate_clock_hover.png);\n"
"}\n"
"QPushButton#pushButton_ok\n"
"{\n"
"	color"
                        ":white;\n"
"	background:lightblue;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(ChangeHeaderWnd);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        widget_title = new QWidget(ChangeHeaderWnd);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(14, 8, 14, 8);
        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));

        horizontalLayout->addWidget(label_title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(widget_title);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(14, 14));
        pushButton_close->setMaximumSize(QSize(14, 14));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QRC/UI/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon);
        pushButton_close->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout_2->addWidget(widget_title);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_upload = new QPushButton(ChangeHeaderWnd);
        pushButton_upload->setObjectName(QStringLiteral("pushButton_upload"));

        horizontalLayout_2->addWidget(pushButton_upload);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        scrollArea = new DragScrollArea(ChangeHeaderWnd);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 220, 218));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_header = new QLabel(scrollAreaWidgetContents);
        label_header->setObjectName(QStringLiteral("label_header"));
        label_header->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_header);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSlider = new QSlider(ChangeHeaderWnd);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        pushButton_anti = new QPushButton(ChangeHeaderWnd);
        pushButton_anti->setObjectName(QStringLiteral("pushButton_anti"));
        pushButton_anti->setMinimumSize(QSize(30, 30));
        pushButton_anti->setMaximumSize(QSize(30, 30));
        pushButton_anti->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(pushButton_anti);

        pushButton_clock = new QPushButton(ChangeHeaderWnd);
        pushButton_clock->setObjectName(QStringLiteral("pushButton_clock"));
        pushButton_clock->setMinimumSize(QSize(30, 30));
        pushButton_clock->setMaximumSize(QSize(30, 30));
        pushButton_clock->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(pushButton_clock);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_ok = new QPushButton(ChangeHeaderWnd);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(ChangeHeaderWnd);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_cancel);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_3);

        label_tip = new QLabel(ChangeHeaderWnd);
        label_tip->setObjectName(QStringLiteral("label_tip"));
        label_tip->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_tip);

        verticalLayout_2->setStretch(1, 1);

        retranslateUi(ChangeHeaderWnd);

        QMetaObject::connectSlotsByName(ChangeHeaderWnd);
    } // setupUi

    void retranslateUi(QWidget *ChangeHeaderWnd)
    {
        ChangeHeaderWnd->setWindowTitle(QApplication::translate("ChangeHeaderWnd", "ChangeHeaderWnd", Q_NULLPTR));
        label_title->setText(QApplication::translate("ChangeHeaderWnd", "\346\233\264\346\215\242\345\244\264\345\203\217", Q_NULLPTR));
        pushButton_close->setText(QString());
        pushButton_upload->setText(QApplication::translate("ChangeHeaderWnd", "\344\270\212\344\274\240\345\244\264\345\203\217", Q_NULLPTR));
        label_header->setText(QString());
        pushButton_anti->setText(QString());
        pushButton_clock->setText(QString());
        pushButton_ok->setText(QApplication::translate("ChangeHeaderWnd", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("ChangeHeaderWnd", "\345\217\226\346\266\210", Q_NULLPTR));
        label_tip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeHeaderWnd: public Ui_ChangeHeaderWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEHEADERWND_H
