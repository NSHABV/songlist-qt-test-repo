/********************************************************************************
** Form generated from reading UI file 'songlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGLISTDIALOG_H
#define UI_SONGLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SongListDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnCreate;
    QPushButton *btnEdit;
    QPushButton *btnSave;
    QTableView *tableView;

    void setupUi(QDialog *SongListDialog)
    {
        if (SongListDialog->objectName().isEmpty())
            SongListDialog->setObjectName(QString::fromUtf8("SongListDialog"));
        SongListDialog->resize(548, 358);
        gridLayout = new QGridLayout(SongListDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 10, -1, -1);
        btnCreate = new QPushButton(SongListDialog);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        verticalLayout_5->addWidget(btnCreate);

        btnEdit = new QPushButton(SongListDialog);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        verticalLayout_5->addWidget(btnEdit);

        btnSave = new QPushButton(SongListDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout_5->addWidget(btnSave);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);

        tableView = new QTableView(SongListDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(SongListDialog);

        QMetaObject::connectSlotsByName(SongListDialog);
    } // setupUi

    void retranslateUi(QDialog *SongListDialog)
    {
        SongListDialog->setWindowTitle(QString());
        btnCreate->setText(QCoreApplication::translate("SongListDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        btnEdit->setText(QCoreApplication::translate("SongListDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        btnSave->setText(QCoreApplication::translate("SongListDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongListDialog: public Ui_SongListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGLISTDIALOG_H
