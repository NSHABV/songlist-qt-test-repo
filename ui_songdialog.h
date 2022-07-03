/********************************************************************************
** Form generated from reading UI file 'songdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGDIALOG_H
#define UI_SONGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SongDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPreview;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPreview;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSlider *horizontalSlider;
    QLineEdit *authorLineEdit;
    QLineEdit *durationLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SongDialog)
    {
        if (SongDialog->objectName().isEmpty())
            SongDialog->setObjectName(QString::fromUtf8("SongDialog"));
        SongDialog->resize(332, 342);
        gridLayout = new QGridLayout(SongDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelPreview = new QLabel(SongDialog);
        labelPreview->setObjectName(QString::fromUtf8("labelPreview"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPreview->sizePolicy().hasHeightForWidth());
        labelPreview->setSizePolicy(sizePolicy);
        labelPreview->setMinimumSize(QSize(125, 125));

        horizontalLayout->addWidget(labelPreview);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPreview = new QPushButton(SongDialog);
        btnPreview->setObjectName(QString::fromUtf8("btnPreview"));
        sizePolicy.setHeightForWidth(btnPreview->sizePolicy().hasHeightForWidth());
        btnPreview->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnPreview);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(SongDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEdit = new QLineEdit(SongDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_6 = new QLabel(SongDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(SongDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(SongDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        horizontalSlider = new QSlider(SongDialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(5);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setValue(5);
        horizontalSlider->setSliderPosition(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, horizontalSlider);

        authorLineEdit = new QLineEdit(SongDialog);
        authorLineEdit->setObjectName(QString::fromUtf8("authorLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, authorLineEdit);

        durationLineEdit = new QLineEdit(SongDialog);
        durationLineEdit->setObjectName(QString::fromUtf8("durationLineEdit"));
        durationLineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        durationLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(2, QFormLayout::FieldRole, durationLineEdit);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SongDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(SongDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SongDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SongDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SongDialog);
    } // setupUi

    void retranslateUi(QDialog *SongDialog)
    {
        SongDialog->setWindowTitle(QCoreApplication::translate("SongDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        labelPreview->setToolTip(QCoreApplication::translate("SongDialog", "\320\237\321\200\320\265\320\262\321\214\321\216", nullptr));
#endif // QT_CONFIG(tooltip)
        labelPreview->setText(QString());
#if QT_CONFIG(tooltip)
        btnPreview->setToolTip(QCoreApplication::translate("SongDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPreview->setText(QCoreApplication::translate("SongDialog", "+", nullptr));
        label_5->setText(QCoreApplication::translate("SongDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("SongDialog", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("SongDialog", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("SongDialog", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        durationLineEdit->setInputMask(QString());
        durationLineEdit->setText(QString());
        durationLineEdit->setPlaceholderText(QCoreApplication::translate("SongDialog", "(in seconds)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongDialog: public Ui_SongDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGDIALOG_H
