/********************************************************************************
** Form generated from reading UI file 'document.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENT_H
#define UI_DOCUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_document
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label_penguine;
    QLabel *label_dragonMaster;
    QLabel *label_wizard;
    QLabel *label_cloudCat;
    QLabel *label_vanguard;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_7;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QLabel *label_tower;
    QTextBrowser *textBrowser_11;
    QTextBrowser *textBrowser_10;
    QTextBrowser *textBrowser_9;
    QTextBrowser *textBrowser_8;
    QLabel *label_superTower;
    QLabel *label_remoteTower_2;
    QLabel *label_superRemoteTower;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser_2;

    void setupUi(QWidget *document)
    {
        if (document->objectName().isEmpty())
            document->setObjectName(QString::fromUtf8("document"));
        document->resize(2564, 456);
        gridLayout = new QGridLayout(document);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(document);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_penguine = new QLabel(tab_2);
        label_penguine->setObjectName(QString::fromUtf8("label_penguine"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_penguine->sizePolicy().hasHeightForWidth());
        label_penguine->setSizePolicy(sizePolicy);
        label_penguine->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(label_penguine, 0, 0, 1, 1);

        label_dragonMaster = new QLabel(tab_2);
        label_dragonMaster->setObjectName(QString::fromUtf8("label_dragonMaster"));
        label_dragonMaster->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(label_dragonMaster, 0, 3, 1, 1);

        label_wizard = new QLabel(tab_2);
        label_wizard->setObjectName(QString::fromUtf8("label_wizard"));
        label_wizard->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(label_wizard, 0, 1, 1, 1);

        label_cloudCat = new QLabel(tab_2);
        label_cloudCat->setObjectName(QString::fromUtf8("label_cloudCat"));
        label_cloudCat->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(label_cloudCat, 0, 4, 1, 1);

        label_vanguard = new QLabel(tab_2);
        label_vanguard->setObjectName(QString::fromUtf8("label_vanguard"));
        label_vanguard->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(label_vanguard, 0, 2, 1, 1);

        textBrowser_3 = new QTextBrowser(tab_2);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(textBrowser_3, 1, 0, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_2);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(textBrowser_4, 1, 1, 1, 1);

        textBrowser_5 = new QTextBrowser(tab_2);
        textBrowser_5->setObjectName(QString::fromUtf8("textBrowser_5"));
        textBrowser_5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(textBrowser_5, 1, 2, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_2);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        textBrowser_6->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(textBrowser_6, 1, 3, 1, 1);

        textBrowser_7 = new QTextBrowser(tab_2);
        textBrowser_7->setObjectName(QString::fromUtf8("textBrowser_7"));
        textBrowser_7->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(textBrowser_7, 1, 4, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_tower = new QLabel(tab_3);
        label_tower->setObjectName(QString::fromUtf8("label_tower"));

        gridLayout_3->addWidget(label_tower, 0, 3, 1, 1);

        textBrowser_11 = new QTextBrowser(tab_3);
        textBrowser_11->setObjectName(QString::fromUtf8("textBrowser_11"));

        gridLayout_3->addWidget(textBrowser_11, 1, 7, 1, 1);

        textBrowser_10 = new QTextBrowser(tab_3);
        textBrowser_10->setObjectName(QString::fromUtf8("textBrowser_10"));

        gridLayout_3->addWidget(textBrowser_10, 1, 4, 1, 1);

        textBrowser_9 = new QTextBrowser(tab_3);
        textBrowser_9->setObjectName(QString::fromUtf8("textBrowser_9"));

        gridLayout_3->addWidget(textBrowser_9, 1, 6, 1, 1);

        textBrowser_8 = new QTextBrowser(tab_3);
        textBrowser_8->setObjectName(QString::fromUtf8("textBrowser_8"));

        gridLayout_3->addWidget(textBrowser_8, 1, 3, 1, 1);

        label_superTower = new QLabel(tab_3);
        label_superTower->setObjectName(QString::fromUtf8("label_superTower"));

        gridLayout_3->addWidget(label_superTower, 0, 6, 1, 1);

        label_remoteTower_2 = new QLabel(tab_3);
        label_remoteTower_2->setObjectName(QString::fromUtf8("label_remoteTower_2"));

        gridLayout_3->addWidget(label_remoteTower_2, 0, 4, 1, 1);

        label_superRemoteTower = new QLabel(tab_3);
        label_superRemoteTower->setObjectName(QString::fromUtf8("label_superRemoteTower"));

        gridLayout_3->addWidget(label_superRemoteTower, 0, 7, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textBrowser_2 = new QTextBrowser(tab_4);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout_3->addWidget(textBrowser_2);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(document);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(document);
    } // setupUi

    void retranslateUi(QWidget *document)
    {
        document->setWindowTitle(QCoreApplication::translate("document", "Form", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\346\254\242\350\277\216\346\270\270\347\216\251\346\234\254\351\241\271\347\233\256:</span><span style=\" font-size:16pt; font-weight:600;\">TowerDefense</span><span style=\" font-size:16pt;\">. \350\277\231\346\230\257\344\270\200\346\254\276\345\241\224\351\230\262\346\270\270\346\210\217. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\346\270\270\346\210\217\350\247\204\345\210\231</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\345\234\250\346\270\270\346\210\217\344\270\255, \351\200\232\350\277\207\346\224\276\347\275\256\344\270\215\345\220\214\347\261\273\345\236\213\347\232\204\351\230\262\345\276\241\345\241\224, \345\207\273\350\264\245\346\235\245\347\212\257\347\232\204\346\225\214\344\272\272, \346\234\200\347\273\210\350\216\267\345\276\227\346\270\270\346\210\217\350\203\234\345\210\251! \344\275\240\350\277\230\345\217\257\344\273\245\351\200\232\350\277\207\345\207\273\346\235\200\347\211\271\345\256\232\346\225\214"
                        "\344\272\272\350\247\243\351\224\201\345\271\266\345\256\211\350\243\205\350\257\215\347\274\200\350\247\246\345\217\221\345\274\272\345\212\233\346\225\210\346\236\234, \346\210\226\346\230\257\345\234\250\345\225\206\345\272\227\344\270\255\350\216\267\345\217\226\345\274\272\345\212\233\351\201\223\345\205\267\345\222\214\345\274\272\345\212\233\345\242\236\347\233\212! \345\275\223\347\204\266\344\272\206, \346\225\214\344\272\272\344\271\237\345\271\266\344\270\215\351\203\275\346\230\257\350\275\257\346\237\277\345\255\220, \344\273\226\344\273\254\344\271\237\346\234\211\347\224\250\347\213\254\347\211\271\347\232\204\350\257\215\347\274\200, \345\212\241\345\277\205\345\260\217\345\277\203!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" font-size:16pt; font-weight:600;\">\345\205\263\344\272\216\350\207\252\345\256\232\344\271\211\345\205\263\345\215\241\346\250\241\345\235\227</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\347\202\271\345\207\273</span><span style=\" font-size:16pt; color:#ff0000;\">\346\226\260\345\273\272\346\226\207\344\273\266</span><span style=\" font-size:16pt;\">\345\210\233\345\273\272\346\226\260\347\232\204\345\205\263\345\215\241, \351\200\232\350\277\207\351\200\211\344\270\255\346\226\271\346\240\274\346\235\245\350\247\204\345\210\222\351\201\223\350\267\257, \344\275\206\346\230\257\351\234\200\350\246\201\346\273\241\350\266\263\344\273\245\344\270\213\350\247\204\345\210\231:</span></p>"
                        "\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">1. \346\257\217\346\235\241\350\267\257\345\276\204\347\232\204\350\265\267\345\247\213\347\202\271\345\277\205\351\241\273\346\230\257\345\234\250\346\234\200\345\217\263\350\276\271\344\270\200\345\210\227.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">2. \346\257\217\346\235\241\350\267\257\345\276\204\351\231\244\344\272\206\350\265\267\347\202\271\345\222\214\347\273\210\347\202\271\345\217\252\344\270\216\344\270\200\344\270\252\351\201\223\350\267\257\346\226\271\346\240\274\347\233\270\351\202\273, \345\205\266\344\275\231\345\277\205\351\241\273\344\270\216\344\270\244\344\270\252\351\201\223\350\267\257\346\226\271\346\240\274\347\233\270\351\202\273.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">3. \345\205\210\347\202\271\345\207\273</span><span style=\" font-size:16pt; color:#ff0000;\">\346\267\273\345\212\240\350\267\257\345\276\204</span><span style=\" font-size:16pt;\">, \345\206\215\347\202\271\345\207\273</span><span style=\" font-size:16pt; color:#ff0000;\">\344\277\235\345\255\230\350\267\257\345\276\204</span><span style=\" font-size:16pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\346\234\200\345\220\216\347\232\204\346\234\200\345\220\216, \345\210\253\345\277\230\344\272\206\347\202\271\345\207\273</span><span style=\" font-size:16pt; color:#ff0000;\">\344\277\235\345\255\230/\345\257\274\345\207\272</span><span style=\" font-size:16pt;\">\345\223\246!!!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-ri"
                        "ght:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">\345\205\266\344\273\226\347\232\204\345\206\205\345\256\271\345\260\261\347\224\261\344\275\240\350\207\252\345\267\261\345\234\250\346\270\270\346\210\217\344\270\255\346\216\242\347\264\242\345\220\247!</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("document", "\346\270\270\346\210\217\350\247\204\345\210\231", nullptr));
        label_penguine->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_dragonMaster->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_wizard->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_cloudCat->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_vanguard->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\347\232\207\345\256\266\344\274\201\351\271\205</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\231\252\344\274\264\344\275\234\350\200\205\350\266\237\350\277\207\344\270\215\347\237\245\351\201\223\345\244\232\345\260\221\344\270"
                        "\252bug\344\273\215\347\204\266\345\235\232\346\214\272\347\232\204\345\216\237\345\247\213\346\200\252\347\211\251.</p></body></html>", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\345\234\243\347\201\265\346\263\225\345\270\210</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\245\236\347\247\230\347\232\204\346\263\225\346\235\226\344\275\277\345\256\203\345\205\267\346\234\211\347\251\277\350\266\212\344\270"
                        "\200\344\270\252\350\277\221\346\210\230\346\225\214\344\272\272\351\230\273\346\214\241\347\232\204\350\203\275\345\212\233, \344\270\215\350\277\207\347\251\277\350\266\212\345\220\216\346\263\225\346\235\226\344\271\237\351\234\200\350\246\201\344\270\200\346\256\265\346\227\266\351\227\264\346\201\242\345\244\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\346\200\245\345\205\210\351\224\213(\346\200\245\346\200\245\345\233\275\347\216\213)</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\212\234\346\271\226, \350\265\267\351\243\236\351\243\236\351\243\236\351\243\236"
                        "\351\243\236\351\243\236!</p></body></html>", nullptr));
        textBrowser_6->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\351\251\257\351\276\231\346\263\225\345\270\210</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\251\257\346\234\215\344\272\206\345\267\250\351\276\231\347\232\204\345\234\243\347\201\265\346\263\225\345\270\210, \351\243\236\345\276"
                        "\227\345\277\253, \350\277\230\350\203\275\347\251\277\350\266\212\350\277\221\346\210\230\345\241\224.</p></body></html>", nullptr));
        textBrowser_7->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\347\245\245\344\272\221\345\226\265\345\226\265</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">[BOSS]\345\207\273\346\235\200\344\274\232\351\232\217\346\234\272\350\247\243\351\224\201\344\270\200\344\270\252\345\274\272\345\214\226\350"
                        "\257\215\347\274\200, \345\260\261\346\230\257\350\241\200\345\216\232\344\272\206\344\272\277\347\202\271.(\346\234\252\345\256\236\350\243\205)</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("document", "\346\225\214\344\272\272\345\233\276\351\211\264", nullptr));
        label_tower->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        textBrowser_11->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\350\266\205\347\272\247\350\277\234\347\250\213\345\241\224</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\234\347\250\213\345\241\224\347\232\204\345\237\272\347\241\200\344\270\212, \350\277\230\350\203\275\345\257"
                        "\271\346\224\273\345\207\273\350\214\203\345\233\264\345\206\205\347\232\204\346\210\221\346\226\271\351\230\262\345\276\241\345\241\224\346\201\242\345\244\215\350\241\200\351\207\217.</p></body></html>", nullptr));
        textBrowser_10->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\350\277\234\347\250\213\345\241\224</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\203\275\345\244\237\345\257\271\346\224\273\345\207\273\350\214\203\345\233\264\345\206\205\347\232\204\346\225\214\344\272\272\351\200\240\346\210"
                        "\220\350\277\234\347\250\213\344\274\244\345\256\263.</p></body></html>", nullptr));
        textBrowser_9->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\350\266\205\347\272\247\350\277\221\346\210\230\345\241\224</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\234\250\350\277\221\346\210\230\345\241\224\347\232\204\345\237\272\347\241\200\344\270\212, \346\255\273\344"
                        "\272\241\345\220\216\344\274\232\345\207\272\345\217\221&quot;\345\206\260\347\210\206&quot;---\345\205\250\345\261\217\345\206\260\345\206\273.</p></body></html>", nullptr));
        textBrowser_8->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\350\277\221\346\210\230\345\241\224</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\235\232\345\256\236\347\232\204\346\210\230\345\243\253, \350\203\275\345\244\237\351\230\273\346\214\241\346\225\214\344\272\272\347\232\204\345\211"
                        "\215\350\277\233\345\271\266\345\257\271\346\225\214\344\272\272\351\200\240\346\210\220\344\274\244\345\256\263.</p></body></html>", nullptr));
        label_superTower->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_remoteTower_2->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        label_superRemoteTower->setText(QCoreApplication::translate("document", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("document", "\351\230\262\345\276\241\345\241\224\345\233\276\351\211\264", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("document", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">\345\205\263\344\272\216\351\241\271\347\233\256 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\302\240 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">- repo: yunzinan/TowerDefense (github.com) </span></p>\n"
"<p alig"
                        "n=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">- doc: https://github.com/yunzinan/TowerDefense.wiki.git </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\302\240 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\346\254\242\350\277\216star &amp; fork &amp; \346\211\276bug\346\217\220PR ! </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">------------------------------------------------------------------- </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">\351\241\271\347\233\256\345\274\200\345\217\221\346\225\260\346\215\256 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\274\200\345\217\221\346\227\266\351\225\277: 2.5\345\221\250 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\344\273\243\347\240\201\351\207\217: 3000-3500\350\241\214 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\302\240 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">\345\205\263\344\272\216\344\275\234\350\200\205 </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">yunzinan(github.com) </span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("document", "\345\205\263\344\272\216\351\241\271\347\233\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class document: public Ui_document {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENT_H
