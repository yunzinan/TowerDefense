/********************************************************************************
** Form generated from reading UI file 'makemap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEMAP_H
#define UI_MAKEMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakeMap
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_new;
    QPushButton *pb_import;
    QLabel *l_fp;
    QPushButton *pb_export;
    QPushButton *pb_exit1;
    QWidget *w_display;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QGridLayout *gridLayout_2;
    QPushButton *pb_addPath;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox;
    QComboBox *comboBox;
    QPushButton *pb_savePath;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label;
    QSpinBox *spinBox_type;
    QLabel *label_6;
    QSpinBox *spinBox_num;
    QPushButton *pb_addItem;
    QPushButton *pb_clear;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *MakeMap)
    {
        if (MakeMap->objectName().isEmpty())
            MakeMap->setObjectName(QString::fromUtf8("MakeMap"));
        MakeMap->resize(594, 406);
        verticalLayout = new QVBoxLayout(MakeMap);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MakeMap);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_new = new QPushButton(widget_3);
        pb_new->setObjectName(QString::fromUtf8("pb_new"));

        horizontalLayout_2->addWidget(pb_new);

        pb_import = new QPushButton(widget_3);
        pb_import->setObjectName(QString::fromUtf8("pb_import"));

        horizontalLayout_2->addWidget(pb_import);

        l_fp = new QLabel(widget_3);
        l_fp->setObjectName(QString::fromUtf8("l_fp"));

        horizontalLayout_2->addWidget(l_fp);

        pb_export = new QPushButton(widget_3);
        pb_export->setObjectName(QString::fromUtf8("pb_export"));

        horizontalLayout_2->addWidget(pb_export);

        pb_exit1 = new QPushButton(widget_3);
        pb_exit1->setObjectName(QString::fromUtf8("pb_exit1"));

        horizontalLayout_2->addWidget(pb_exit1);


        gridLayout->addWidget(widget_3, 0, 0, 1, 2);

        w_display = new QWidget(tab_2);
        w_display->setObjectName(QString::fromUtf8("w_display"));

        gridLayout->addWidget(w_display, 1, 0, 1, 1);

        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(400, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_2 = new QGridLayout(widget_5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pb_addPath = new QPushButton(widget_5);
        pb_addPath->setObjectName(QString::fromUtf8("pb_addPath"));

        gridLayout_2->addWidget(pb_addPath, 3, 0, 1, 1);

        spinBox_2 = new QSpinBox(widget_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(10);
        spinBox_2->setMaximum(20);

        gridLayout_2->addWidget(spinBox_2, 1, 1, 1, 1);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        spinBox = new QSpinBox(widget_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(4);
        spinBox->setMaximum(10);

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        comboBox = new QComboBox(widget_5);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 1, 1, 1);

        pb_savePath = new QPushButton(widget_5);
        pb_savePath->setObjectName(QString::fromUtf8("pb_savePath"));

        gridLayout_2->addWidget(pb_savePath, 3, 1, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout_3->addWidget(widget_5);


        gridLayout->addWidget(widget_4, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        treeWidget = new QTreeWidget(tab_3);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        widget = new QWidget(tab_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 100));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        spinBox_type = new QSpinBox(widget);
        spinBox_type->setObjectName(QString::fromUtf8("spinBox_type"));

        horizontalLayout->addWidget(spinBox_type);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        spinBox_num = new QSpinBox(widget);
        spinBox_num->setObjectName(QString::fromUtf8("spinBox_num"));

        horizontalLayout->addWidget(spinBox_num);

        pb_addItem = new QPushButton(widget);
        pb_addItem->setObjectName(QString::fromUtf8("pb_addItem"));

        horizontalLayout->addWidget(pb_addItem);

        pb_clear = new QPushButton(widget);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));

        horizontalLayout->addWidget(pb_clear);


        verticalLayout_4->addWidget(widget);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MakeMap);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MakeMap);
    } // setupUi

    void retranslateUi(QWidget *MakeMap)
    {
        MakeMap->setWindowTitle(QCoreApplication::translate("MakeMap", "Form", nullptr));
        pb_new->setText(QCoreApplication::translate("MakeMap", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        pb_import->setText(QCoreApplication::translate("MakeMap", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        l_fp->setText(QCoreApplication::translate("MakeMap", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        pb_export->setText(QCoreApplication::translate("MakeMap", " \344\277\235\345\255\230/\345\257\274\345\207\272", nullptr));
        pb_exit1->setText(QCoreApplication::translate("MakeMap", "\351\200\200\345\207\272", nullptr));
        pb_addPath->setText(QCoreApplication::translate("MakeMap", "\346\267\273\345\212\240\350\267\257\345\276\204", nullptr));
        label_5->setText(QCoreApplication::translate("MakeMap", "\345\210\227\346\225\260", nullptr));
        pb_savePath->setText(QCoreApplication::translate("MakeMap", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        label_4->setText(QCoreApplication::translate("MakeMap", " \350\241\214\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("MakeMap", "\345\275\223\345\211\215\350\267\257\345\276\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MakeMap", "\345\234\260\345\233\276\345\210\266\344\275\234", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MakeMap", "\346\225\260\351\207\217", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MakeMap", "\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("MakeMap", "\347\272\277\350\267\257", nullptr));
        label->setText(QCoreApplication::translate("MakeMap", "\346\225\214\344\272\272\347\261\273\345\236\213", nullptr));
        label_6->setText(QCoreApplication::translate("MakeMap", "\346\225\260\351\207\217", nullptr));
        pb_addItem->setText(QCoreApplication::translate("MakeMap", "\346\267\273\345\212\240", nullptr));
        pb_clear->setText(QCoreApplication::translate("MakeMap", "\346\270\205\351\231\244\345\205\250\351\203\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MakeMap", "\346\225\214\344\272\272\351\203\250\347\275\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MakeMap", "\345\234\260\345\233\276\351\242\204\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MakeMap: public Ui_MakeMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEMAP_H
