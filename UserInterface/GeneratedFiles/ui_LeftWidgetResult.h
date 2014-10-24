/********************************************************************************
** Form generated from reading UI file 'LeftWidgetResult.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTWIDGETRESULT_H
#define UI_LEFTWIDGETRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftWidgetResult
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QWidget *LeftWidgetResult)
    {
        if (LeftWidgetResult->objectName().isEmpty())
            LeftWidgetResult->setObjectName(QStringLiteral("LeftWidgetResult"));
        LeftWidgetResult->resize(200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftWidgetResult->sizePolicy().hasHeightForWidth());
        LeftWidgetResult->setSizePolicy(sizePolicy);
        LeftWidgetResult->setMinimumSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        LeftWidgetResult->setPalette(palette);
        LeftWidgetResult->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(LeftWidgetResult);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, 3, 12, 0);
        label = new QLabel(LeftWidgetResult);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(LeftWidgetResult);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(200);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(listWidget);


        retranslateUi(LeftWidgetResult);

        QMetaObject::connectSlotsByName(LeftWidgetResult);
    } // setupUi

    void retranslateUi(QWidget *LeftWidgetResult)
    {
        LeftWidgetResult->setWindowTitle(QApplication::translate("LeftWidgetResult", "Form", 0));
        label->setText(QApplication::translate("LeftWidgetResult", "Results in file", 0));
    } // retranslateUi

};

namespace Ui {
    class LeftWidgetResult: public Ui_LeftWidgetResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTWIDGETRESULT_H
