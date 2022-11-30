/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *l_progress;
    QLabel *l_money;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *l_level;
    QLabel *l_hp;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_1;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_stop;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_2;
    QLabel *label_5;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QWidget *w_mainScene;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(630, 463);
        gridLayout_2 = new QGridLayout(GameWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(GameWindow);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(400, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        l_progress = new QLabel(widget);
        l_progress->setObjectName(QString::fromUtf8("l_progress"));

        gridLayout->addWidget(l_progress, 3, 1, 1, 1);

        l_money = new QLabel(widget);
        l_money->setObjectName(QString::fromUtf8("l_money"));

        gridLayout->addWidget(l_money, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        l_level = new QLabel(widget);
        l_level->setObjectName(QString::fromUtf8("l_level"));

        gridLayout->addWidget(l_level, 0, 1, 1, 1);

        l_hp = new QLabel(widget);
        l_hp->setObjectName(QString::fromUtf8("l_hp"));

        gridLayout->addWidget(l_hp, 1, 1, 1, 1);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        radioButton_1 = new QRadioButton(widget_3);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));

        gridLayout_4->addWidget(radioButton_1, 2, 0, 1, 1);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_stop = new QPushButton(widget_4);
        pb_stop->setObjectName(QString::fromUtf8("pb_stop"));

        horizontalLayout->addWidget(pb_stop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_4->addWidget(widget_4, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(widget_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_4->addWidget(radioButton_2, 3, 0, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        radioButton_3 = new QRadioButton(widget_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_4->addWidget(radioButton_3, 5, 0, 1, 1);

        radioButton_4 = new QRadioButton(widget_3);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_4->addWidget(radioButton_4, 6, 0, 1, 1);


        verticalLayout_2->addWidget(widget_3);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        w_mainScene = new QWidget(GameWindow);
        w_mainScene->setObjectName(QString::fromUtf8("w_mainScene"));
        verticalLayout = new QVBoxLayout(w_mainScene);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(w_mainScene);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        gridLayout_2->addWidget(w_mainScene, 0, 0, 1, 1);


        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "Form", nullptr));
        l_progress->setText(QCoreApplication::translate("GameWindow", "\347\254\2540\346\263\242", nullptr));
        l_money->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "\346\270\270\346\210\217\350\277\233\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("GameWindow", "\351\207\221\351\222\261", nullptr));
        label->setText(QCoreApplication::translate("GameWindow", "\345\205\263\345\215\241\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "\347\224\237\345\221\275:", nullptr));
        l_level->setText(QCoreApplication::translate("GameWindow", "\347\254\2540\345\205\263", nullptr));
        l_hp->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        radioButton_1->setText(QCoreApplication::translate("GameWindow", "\345\241\2241: \350\277\221\346\210\230\346\234\272\347\224\262", nullptr));
        pb_stop->setText(QCoreApplication::translate("GameWindow", "\346\232\202\345\201\234/\347\273\247\347\273\255", nullptr));
        radioButton_2->setText(QCoreApplication::translate("GameWindow", "\345\241\2242: \350\266\205\347\272\247\350\277\221\346\210\230\346\234\272\347\224\262", nullptr));
        label_5->setText(QCoreApplication::translate("GameWindow", "\346\224\276\347\275\256\351\235\242\346\235\277", nullptr));
        radioButton_3->setText(QCoreApplication::translate("GameWindow", "\345\241\2243: \350\277\234\347\250\213\346\234\272\347\224\262", nullptr));
        radioButton_4->setText(QCoreApplication::translate("GameWindow", "\345\241\2244: \350\266\205\347\272\247\350\277\234\347\250\213\346\234\272\347\224\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
