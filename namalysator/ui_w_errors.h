/********************************************************************************
** Form generated from reading UI file 'w_errors.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_ERRORS_H
#define UI_W_ERRORS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w_errors
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QScrollArea *scrollAreaErrorTable;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btnExport;

    void setupUi(QWidget *w_errors)
    {
        if (w_errors->objectName().isEmpty())
            w_errors->setObjectName(QString::fromUtf8("w_errors"));
        w_errors->resize(1035, 817);
        verticalLayout = new QVBoxLayout(w_errors);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(w_errors);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setKerning(false);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollAreaErrorTable = new QScrollArea(tab);
        scrollAreaErrorTable->setObjectName(QString::fromUtf8("scrollAreaErrorTable"));
        QFont font1;
        font1.setKerning(true);
        scrollAreaErrorTable->setFont(font1);
        scrollAreaErrorTable->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 991, 724));
        scrollAreaErrorTable->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollAreaErrorTable, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        btnExport = new QPushButton(w_errors);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));

        verticalLayout->addWidget(btnExport);


        retranslateUi(w_errors);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(w_errors);
    } // setupUi

    void retranslateUi(QWidget *w_errors)
    {
        w_errors->setWindowTitle(QApplication::translate("w_errors", "Form", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("w_errors", "Summary of Errors", 0, QApplication::UnicodeUTF8));
        btnExport->setText(QApplication::translate("w_errors", "Export Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class w_errors: public Ui_w_errors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_ERRORS_H
