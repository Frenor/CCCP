/********************************************************************************
** Form generated from reading UI file 'LeftWidgetPaint.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTWIDGETPAINT_H
#define UI_LEFTWIDGETPAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftWidgetPaint
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *treeView;

    void setupUi(QWidget *LeftWidgetPaint)
    {
        if (LeftWidgetPaint->objectName().isEmpty())
            LeftWidgetPaint->setObjectName(QStringLiteral("LeftWidgetPaint"));
        LeftWidgetPaint->resize(200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftWidgetPaint->sizePolicy().hasHeightForWidth());
        LeftWidgetPaint->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        LeftWidgetPaint->setPalette(palette);
        LeftWidgetPaint->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(LeftWidgetPaint);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, 3, 12, 0);
        label = new QLabel(LeftWidgetPaint);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        treeView = new QTreeView(LeftWidgetPaint);
        treeView->setObjectName(QStringLiteral("treeView"));
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        treeView->setStyleSheet(QLatin1String(" QTreeView::branch:has-siblings:!adjoins-item {\n"
"     border-image: url(:/vline.png) 0;\n"
" }\n"
"\n"
" QTreeView::branch:has-siblings:adjoins-item {\n"
"     border-image: url(:/branch-more.png) 0;\n"
" }\n"
"\n"
" QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"     border-image: url(:/branch-end.png) 0;\n"
" }\n"
"\n"
" QTreeView::branch:has-children:!has-siblings:closed,\n"
" QTreeView::branch:closed:has-children:has-siblings {\n"
"         border-image: none;\n"
"         image: url(:/branch-closed.png);\n"
" }\n"
"\n"
" QTreeView::branch:open:has-children:!has-siblings,\n"
" QTreeView::branch:open:has-children:has-siblings  {\n"
"         border-image: none;\n"
"         image: url(:/branch-open.png);\n"
" }"));
        treeView->setFrameShadow(QFrame::Plain);
        treeView->setLineWidth(1);

        verticalLayout->addWidget(treeView);


        retranslateUi(LeftWidgetPaint);

        QMetaObject::connectSlotsByName(LeftWidgetPaint);
    } // setupUi

    void retranslateUi(QWidget *LeftWidgetPaint)
    {
        LeftWidgetPaint->setWindowTitle(QApplication::translate("LeftWidgetPaint", "Form", 0));
        label->setText(QApplication::translate("LeftWidgetPaint", "Entities in file", 0));
    } // retranslateUi

};

namespace Ui {
    class LeftWidgetPaint: public Ui_LeftWidgetPaint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTWIDGETPAINT_H
