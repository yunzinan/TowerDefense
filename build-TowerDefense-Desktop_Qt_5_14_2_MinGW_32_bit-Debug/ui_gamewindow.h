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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QGridLayout *gridLayout_2;
    QWidget *w_mainScene;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *l_progress;
    QLabel *l_hp;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *l_money;
    QLabel *label_3;
    QLabel *label;
    QLabel *l_level;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_stop;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(708, 748);
        gridLayout_2 = new QGridLayout(GameWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        w_mainScene = new QWidget(GameWindow);
        w_mainScene->setObjectName(QString::fromUtf8("w_mainScene"));
        verticalLayout = new QVBoxLayout(w_mainScene);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(w_mainScene);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        gridLayout_2->addWidget(w_mainScene, 0, 0, 1, 1);

        widget_2 = new QWidget(GameWindow);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(500, 0));
        widget_2->setMaximumSize(QSize(400, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 400));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        l_progress = new QLabel(widget);
        l_progress->setObjectName(QString::fromUtf8("l_progress"));

        gridLayout->addWidget(l_progress, 3, 1, 1, 1);

        l_hp = new QLabel(widget);
        l_hp->setObjectName(QString::fromUtf8("l_hp"));

        gridLayout->addWidget(l_hp, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        l_money = new QLabel(widget);
        l_money->setObjectName(QString::fromUtf8("l_money"));

        gridLayout->addWidget(l_money, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        l_level = new QLabel(widget);
        l_level->setObjectName(QString::fromUtf8("l_level"));

        gridLayout->addWidget(l_level, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 200));
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

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMaximumSize(QSize(16777215, 400));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton_1 = new QRadioButton(widget_5);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));

        verticalLayout_4->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(widget_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_4->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(widget_5);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_4->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(widget_5);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout_4->addWidget(radioButton_4);


        gridLayout_4->addWidget(widget_5, 2, 0, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 400));
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 40));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget = new QTableWidget(widget_7);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_5->addWidget(tableWidget);

        checkBox = new QCheckBox(widget_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_5->addWidget(checkBox);

        checkBox_2 = new QCheckBox(widget_7);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_5->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(widget_7);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout_5->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(widget_7);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout_5->addWidget(checkBox_4);


        verticalLayout_3->addWidget(widget_7);


        verticalLayout_2->addWidget(widget_6);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);


        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "Form", nullptr));
        l_progress->setText(QCoreApplication::translate("GameWindow", "\347\254\2540\346\263\242", nullptr));
        l_hp->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "\347\224\237\345\221\275:", nullptr));
        label_4->setText(QCoreApplication::translate("GameWindow", "\351\207\221\351\222\261", nullptr));
        l_money->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "\346\270\270\346\210\217\350\277\233\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("GameWindow", "\345\205\263\345\215\241\344\277\241\346\201\257", nullptr));
        l_level->setText(QCoreApplication::translate("GameWindow", "\347\254\2540\345\205\263", nullptr));
        label_5->setText(QCoreApplication::translate("GameWindow", "\346\224\276\347\275\256\351\235\242\346\235\277", nullptr));
        pb_stop->setText(QCoreApplication::translate("GameWindow", "\346\232\202\345\201\234/\347\273\247\347\273\255", nullptr));
        radioButton_1->setText(QCoreApplication::translate("GameWindow", "\345\241\2241: \350\277\221\346\210\230\346\234\272\347\224\262", nullptr));
        radioButton_2->setText(QCoreApplication::translate("GameWindow", "\345\241\2242: \350\266\205\347\272\247\350\277\221\346\210\230\346\234\272\347\224\262", nullptr));
        radioButton_3->setText(QCoreApplication::translate("GameWindow", "\345\241\2243: \350\277\234\347\250\213\346\234\272\347\224\262", nullptr));
        radioButton_4->setText(QCoreApplication::translate("GameWindow", "\345\241\2244: \350\266\205\347\272\247\350\277\234\347\250\213\346\234\272\347\224\262", nullptr));
        label_6->setText(QCoreApplication::translate("GameWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GameWindow", "\345\261\236\346\200\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GameWindow", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GameWindow", "\350\241\200\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GameWindow", "\346\224\273\345\207\273\345\212\233", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GameWindow", "\346\224\273\345\207\273\350\214\203\345\233\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GameWindow", "\346\224\273\345\207\273\351\200\237\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GameWindow", "\347\247\273\345\212\250\351\200\237\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("GameWindow", "\350\257\215\347\274\2001", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("GameWindow", "\350\257\215\347\274\2002", nullptr));
        checkBox->setText(QCoreApplication::translate("GameWindow", "\346\210\221\346\226\271\350\257\215\347\274\2001: \347\213\202\346\232\264", nullptr));
        checkBox_2->setText(QCoreApplication::translate("GameWindow", "\346\210\221\346\226\271\350\257\215\347\274\2002: \345\206\260\345\206\273", nullptr));
        checkBox_3->setText(QCoreApplication::translate("GameWindow", "\346\210\221\346\226\271\350\257\215\347\274\2003: \346\265\201\350\241\200", nullptr));
        checkBox_4->setText(QCoreApplication::translate("GameWindow", "\346\210\221\346\226\271\350\257\215\347\274\2004: \347\276\244\344\274\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
