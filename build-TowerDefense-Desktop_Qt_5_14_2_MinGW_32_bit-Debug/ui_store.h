/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_H
#define UI_STORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Store
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_pts;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_atk;
    QLabel *label_fb;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_hp;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_b;

    void setupUi(QWidget *Store)
    {
        if (Store->objectName().isEmpty())
            Store->setObjectName(QString::fromUtf8("Store"));
        Store->resize(485, 454);
        verticalLayout = new QVBoxLayout(Store);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(Store);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_pts = new QLabel(widget_3);
        label_pts->setObjectName(QString::fromUtf8("label_pts"));
        label_pts->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_pts);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(Store);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_atk = new QLabel(widget);
        label_atk->setObjectName(QString::fromUtf8("label_atk"));

        gridLayout->addWidget(label_atk, 2, 1, 1, 1);

        label_fb = new QLabel(widget);
        label_fb->setObjectName(QString::fromUtf8("label_fb"));

        gridLayout->addWidget(label_fb, 4, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_hp = new QLabel(widget);
        label_hp->setObjectName(QString::fromUtf8("label_hp"));

        gridLayout->addWidget(label_hp, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 5, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 2, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        label_b = new QLabel(widget);
        label_b->setObjectName(QString::fromUtf8("label_b"));

        gridLayout->addWidget(label_b, 5, 1, 1, 1);


        verticalLayout->addWidget(widget);


        retranslateUi(Store);

        QMetaObject::connectSlotsByName(Store);
    } // setupUi

    void retranslateUi(QWidget *Store)
    {
        Store->setWindowTitle(QCoreApplication::translate("Store", "Form", nullptr));
        label->setText(QCoreApplication::translate("Store", "\345\225\206\345\272\227", nullptr));
        label_pts->setText(QCoreApplication::translate("Store", "\345\275\223\345\211\215\347\247\257\345\210\206:0", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Store", "\345\205\205\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("Store", "\351\230\262\345\276\241\345\241\224\347\224\237\345\221\275\345\200\274:", nullptr));
        label_atk->setText(QCoreApplication::translate("Store", "1\345\200\215", nullptr));
        label_fb->setText(QCoreApplication::translate("Store", "\346\225\260\351\207\217: 0\344\270\252", nullptr));
        label_2->setText(QCoreApplication::translate("Store", "\351\230\262\345\276\241\345\241\224\346\224\273\345\207\273\345\200\215\347\216\207:", nullptr));
        pushButton->setText(QCoreApplication::translate("Store", "\345\274\272\345\214\226/5pts", nullptr));
        label_5->setText(QCoreApplication::translate("Store", "\346\257\201\347\201\255\347\202\270\345\274\271", nullptr));
        label_hp->setText(QCoreApplication::translate("Store", "1\345\200\215", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Store", "\350\264\255\344\271\260/2pts", nullptr));
        label_4->setText(QCoreApplication::translate("Store", "\345\206\260\345\260\201\347\202\270\345\274\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Store", "\345\274\272\345\214\226/5pts", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Store", "\350\264\255\344\271\260/1pts", nullptr));
        label_b->setText(QCoreApplication::translate("Store", "\346\225\260\351\207\217: 0\344\270\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Store: public Ui_Store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H
