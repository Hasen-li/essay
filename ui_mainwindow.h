/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newpage;
    QAction *open;
    QAction *save;
    QAction *saveas;
    QAction *exit;
    QAction *action_Y;
    QAction *action_X;
    QAction *action_C;
    QAction *action_V;
    QAction *action_D;
    QAction *action_16;
    QAction *action_17;
    QAction *action_18;
    QAction *action_20;
    QAction *action_help;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu111;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        newpage = new QAction(MainWindow);
        newpage->setObjectName(QString::fromUtf8("newpage"));
        open = new QAction(MainWindow);
        open->setObjectName(QString::fromUtf8("open"));
        save = new QAction(MainWindow);
        save->setObjectName(QString::fromUtf8("save"));
        saveas = new QAction(MainWindow);
        saveas->setObjectName(QString::fromUtf8("saveas"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        action_Y = new QAction(MainWindow);
        action_Y->setObjectName(QString::fromUtf8("action_Y"));
        action_X = new QAction(MainWindow);
        action_X->setObjectName(QString::fromUtf8("action_X"));
        action_C = new QAction(MainWindow);
        action_C->setObjectName(QString::fromUtf8("action_C"));
        action_V = new QAction(MainWindow);
        action_V->setObjectName(QString::fromUtf8("action_V"));
        action_D = new QAction(MainWindow);
        action_D->setObjectName(QString::fromUtf8("action_D"));
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QString::fromUtf8("action_16"));
        action_17 = new QAction(MainWindow);
        action_17->setObjectName(QString::fromUtf8("action_17"));
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QString::fromUtf8("action_18"));
        action_20 = new QAction(MainWindow);
        action_20->setObjectName(QString::fromUtf8("action_20"));
        action_help = new QAction(MainWindow);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menubar->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        menu111 = new QMenu(menubar);
        menu111->setObjectName(QString::fromUtf8("menu111"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu111->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu111->addSeparator();
        menu111->addSeparator();
        menu111->addAction(newpage);
        menu111->addAction(open);
        menu111->addAction(save);
        menu111->addAction(saveas);
        menu111->addAction(exit);
        menu->addAction(action_Y);
        menu->addAction(action_X);
        menu->addAction(action_C);
        menu->addAction(action_V);
        menu->addAction(action_D);
        menu_2->addAction(menu_3->menuAction());
        menu_2->addSeparator();
        menu_2->addAction(action_20);
        menu_3->addSeparator();
        menu_3->addAction(action_16);
        menu_3->addAction(action_17);
        menu_3->addAction(action_18);
        menu_4->addSeparator();
        menu_4->addSeparator();
        menu_4->addAction(action_2);
        menu_4->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        newpage->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\n"
"", nullptr));
        saveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_Y->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
        action_X->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
        action_C->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        action_V->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
        action_D->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        action_16->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
        action_17->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
        action_18->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215\351\273\230\350\256\244\347\274\251\346\224\276", nullptr));
        action_20->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217\n"
"", nullptr));
        action_help->setText(QApplication::translate("MainWindow", "help", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\350\257\264\346\230\216", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254", nullptr));
        menu111->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\347\274\251\346\224\276", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
