/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QLabel *label_3;
    QFrame *line;
    QPlainTextEdit *previewEdit;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *titleEdit;
    QWidget *widget;
    QFormLayout *formLayout;
    QRadioButton *CoordXRadioButton;
    QRadioButton *CoordYRadioButton;
    QRadioButton *HDAmountRadioButton;
    QRadioButton *CoordZRadioButton;
    QRadioButton *faciesRadioButton;
    QRadioButton *titleRadioButton;
    QLabel *label_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *defaultButton;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QStringLiteral("InputDialog"));
        InputDialog->resize(789, 264);
        label_3 = new QLabel(InputDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 371, 20));
        line = new QFrame(InputDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(400, 10, 21, 241));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        previewEdit = new QPlainTextEdit(InputDialog);
        previewEdit->setObjectName(QStringLiteral("previewEdit"));
        previewEdit->setGeometry(QRect(430, 50, 341, 181));
        label_4 = new QLabel(InputDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 20, 341, 20));
        label = new QLabel(InputDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 31, 16));
        titleEdit = new QLineEdit(InputDialog);
        titleEdit->setObjectName(QStringLiteral("titleEdit"));
        titleEdit->setGeometry(QRect(60, 50, 331, 20));
        widget = new QWidget(InputDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 110, 371, 88));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        CoordXRadioButton = new QRadioButton(widget);
        CoordXRadioButton->setObjectName(QStringLiteral("CoordXRadioButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, CoordXRadioButton);

        CoordYRadioButton = new QRadioButton(widget);
        CoordYRadioButton->setObjectName(QStringLiteral("CoordYRadioButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, CoordYRadioButton);

        HDAmountRadioButton = new QRadioButton(widget);
        HDAmountRadioButton->setObjectName(QStringLiteral("HDAmountRadioButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, HDAmountRadioButton);

        CoordZRadioButton = new QRadioButton(widget);
        CoordZRadioButton->setObjectName(QStringLiteral("CoordZRadioButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, CoordZRadioButton);

        faciesRadioButton = new QRadioButton(widget);
        faciesRadioButton->setObjectName(QStringLiteral("faciesRadioButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, faciesRadioButton);

        titleRadioButton = new QRadioButton(widget);
        titleRadioButton->setObjectName(QStringLiteral("titleRadioButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, titleRadioButton);

        label_2 = new QLabel(InputDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(24, 20, 361, 20));
        widget1 = new QWidget(InputDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 210, 371, 25));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(widget1);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        defaultButton = new QPushButton(widget1);
        defaultButton->setObjectName(QStringLiteral("defaultButton"));

        horizontalLayout->addWidget(defaultButton);

        okButton = new QPushButton(widget1);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(InputDialog);

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Output Parameters:</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("InputDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Preview</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("InputDialog", "<html><head/><body><p>Title: </p></body></html>", Q_NULLPTR));
        CoordXRadioButton->setText(QApplication::translate("InputDialog", "Coordenate X", Q_NULLPTR));
        CoordYRadioButton->setText(QApplication::translate("InputDialog", "Coordenate Y", Q_NULLPTR));
        HDAmountRadioButton->setText(QApplication::translate("InputDialog", "Hard Data amount", Q_NULLPTR));
        CoordZRadioButton->setText(QApplication::translate("InputDialog", "Coordenate Z", Q_NULLPTR));
        faciesRadioButton->setText(QApplication::translate("InputDialog", "Facies", Q_NULLPTR));
        titleRadioButton->setText(QApplication::translate("InputDialog", "Title", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Hard Data List Output</span></p></body></html>", Q_NULLPTR));
        saveButton->setText(QApplication::translate("InputDialog", "Save", Q_NULLPTR));
        defaultButton->setText(QApplication::translate("InputDialog", "Default", Q_NULLPTR));
        okButton->setText(QApplication::translate("InputDialog", "Ok", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InputDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
