/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Open_file;
    QAction *actionExit;
    QAction *Set_input_parameters;
    QWidget *centralWidget;
    QSplitter *splitter_10;
    GLWidget *openGLWidget;
    QSplitter *splitter_9;
    QSplitter *splitter_8;
    QLabel *simulationGridlabel;
    QSplitter *splitter_7;
    QSplitter *splitter_5;
    QSplitter *splitter;
    QLabel *label;
    QSpinBox *sg_x0_Box;
    QSplitter *splitter_2;
    QLabel *label_2;
    QSpinBox *sg_y0_Box;
    QSplitter *splitter_6;
    QSplitter *splitter_3;
    QLabel *label_3;
    QSpinBox *sg_width_Box;
    QSplitter *splitter_4;
    QLabel *label_4;
    QSpinBox *sg_height_Box;
    QPushButton *generate_Button;
    QScrollBar *verticalScrollBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(826, 587);
        MainWindow->setMinimumSize(QSize(0, 0));
        Open_file = new QAction(MainWindow);
        Open_file->setObjectName(QStringLiteral("Open_file"));
        QIcon icon;
        icon.addFile(QStringLiteral("img/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        Open_file->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        Set_input_parameters = new QAction(MainWindow);
        Set_input_parameters->setObjectName(QStringLiteral("Set_input_parameters"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter_10 = new QSplitter(centralWidget);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setGeometry(QRect(10, 10, 811, 501));
        splitter_10->setOrientation(Qt::Horizontal);
        openGLWidget = new GLWidget(splitter_10);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(100, 100));
        splitter_10->addWidget(openGLWidget);
        splitter_9 = new QSplitter(splitter_10);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Vertical);
        splitter_8 = new QSplitter(splitter_9);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setOrientation(Qt::Vertical);
        simulationGridlabel = new QLabel(splitter_8);
        simulationGridlabel->setObjectName(QStringLiteral("simulationGridlabel"));
        splitter_8->addWidget(simulationGridlabel);
        splitter_7 = new QSplitter(splitter_8);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Vertical);
        splitter_5 = new QSplitter(splitter_7);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_5);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        splitter->addWidget(label);
        sg_x0_Box = new QSpinBox(splitter);
        sg_x0_Box->setObjectName(QStringLiteral("sg_x0_Box"));
        sg_x0_Box->setMinimumSize(QSize(50, 20));
        sg_x0_Box->setMaximumSize(QSize(50, 20));
        splitter->addWidget(sg_x0_Box);
        splitter_5->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_5);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        sg_y0_Box = new QSpinBox(splitter_2);
        sg_y0_Box->setObjectName(QStringLiteral("sg_y0_Box"));
        sg_y0_Box->setMinimumSize(QSize(50, 20));
        sg_y0_Box->setMaximumSize(QSize(50, 20));
        splitter_2->addWidget(sg_y0_Box);
        splitter_5->addWidget(splitter_2);
        splitter_7->addWidget(splitter_5);
        splitter_6 = new QSplitter(splitter_7);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Vertical);
        splitter_3 = new QSplitter(splitter_6);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        sg_width_Box = new QSpinBox(splitter_3);
        sg_width_Box->setObjectName(QStringLiteral("sg_width_Box"));
        sg_width_Box->setMinimumSize(QSize(50, 20));
        sg_width_Box->setMaximumSize(QSize(50, 20));
        sg_width_Box->setBaseSize(QSize(100, 100));
        splitter_3->addWidget(sg_width_Box);
        splitter_6->addWidget(splitter_3);
        splitter_4 = new QSplitter(splitter_6);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_4->addWidget(label_4);
        sg_height_Box = new QSpinBox(splitter_4);
        sg_height_Box->setObjectName(QStringLiteral("sg_height_Box"));
        sg_height_Box->setMinimumSize(QSize(50, 20));
        sg_height_Box->setMaximumSize(QSize(50, 20));
        splitter_4->addWidget(sg_height_Box);
        splitter_6->addWidget(splitter_4);
        splitter_7->addWidget(splitter_6);
        splitter_8->addWidget(splitter_7);
        splitter_9->addWidget(splitter_8);
        generate_Button = new QPushButton(splitter_9);
        generate_Button->setObjectName(QStringLiteral("generate_Button"));
        splitter_9->addWidget(generate_Button);
        splitter_10->addWidget(splitter_9);
        verticalScrollBar = new QScrollBar(splitter_10);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setMaximumSize(QSize(20, 16777215));
        verticalScrollBar->setOrientation(Qt::Vertical);
        splitter_10->addWidget(verticalScrollBar);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(Open_file);
        menuMenu->addAction(actionExit);
        menuEdit->addAction(Set_input_parameters);
        toolBar->addAction(Open_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HD Generator", Q_NULLPTR));
        Open_file->setText(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        Set_input_parameters->setText(QApplication::translate("MainWindow", "Set Output Parameters", Q_NULLPTR));
        simulationGridlabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Simulation Grid</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">x0:</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">y0:</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Width:</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Height:</p></body></html>", Q_NULLPTR));
        generate_Button->setText(QApplication::translate("MainWindow", "Generate", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
