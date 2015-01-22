/********************************************************************************
** Form generated from reading UI file 'entityDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTITYDIALOG_H
#define UI_ENTITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntityProperties
{
public:
    QGridLayout *gridLayout;
    QLabel *EntityNameLabel;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *nodesLabel;
    QTableView *tableView;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QLabel *segmentLabel;
    QSpinBox *segmentSpinBox;
    QLabel *materialLabel;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;

    void setupUi(QDialog *EntityProperties)
    {
        if (EntityProperties->objectName().isEmpty())
            EntityProperties->setObjectName(QStringLiteral("EntityProperties"));
        EntityProperties->resize(400, 317);
        gridLayout = new QGridLayout(EntityProperties);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        EntityNameLabel = new QLabel(EntityProperties);
        EntityNameLabel->setObjectName(QStringLiteral("EntityNameLabel"));

        gridLayout->addWidget(EntityNameLabel, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(EntityProperties);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nodesLabel = new QLabel(EntityProperties);
        nodesLabel->setObjectName(QStringLiteral("nodesLabel"));

        verticalLayout_2->addWidget(nodesLabel);

        tableView = new QTableView(EntityProperties);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMaximumSize(QSize(214, 16777215));

        verticalLayout_2->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout_2);

        line = new QFrame(EntityProperties);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        segmentLabel = new QLabel(EntityProperties);
        segmentLabel->setObjectName(QStringLiteral("segmentLabel"));

        verticalLayout_4->addWidget(segmentLabel);

        segmentSpinBox = new QSpinBox(EntityProperties);
        segmentSpinBox->setObjectName(QStringLiteral("segmentSpinBox"));
        segmentSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        segmentSpinBox->setReadOnly(false);
        segmentSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        segmentSpinBox->setMaximum(10000);
        segmentSpinBox->setDisplayIntegerBase(10);

        verticalLayout_4->addWidget(segmentSpinBox);

        materialLabel = new QLabel(EntityProperties);
        materialLabel->setObjectName(QStringLiteral("materialLabel"));

        verticalLayout_4->addWidget(materialLabel);

        comboBox = new QComboBox(EntityProperties);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        line_2 = new QFrame(EntityProperties);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 1, 1, 1);


        retranslateUi(EntityProperties);
        QObject::connect(buttonBox, SIGNAL(accepted()), EntityProperties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EntityProperties, SLOT(reject()));

        QMetaObject::connectSlotsByName(EntityProperties);
    } // setupUi

    void retranslateUi(QDialog *EntityProperties)
    {
        EntityProperties->setWindowTitle(QApplication::translate("EntityProperties", "Entity Properties", 0));
        EntityNameLabel->setText(QApplication::translate("EntityProperties", "EntityName", 0));
        nodesLabel->setText(QApplication::translate("EntityProperties", "Nodes:", 0));
        segmentLabel->setText(QApplication::translate("EntityProperties", "Number of segments:", 0));
        materialLabel->setText(QApplication::translate("EntityProperties", "Materials:", 0));
    } // retranslateUi

};

namespace Ui {
    class EntityProperties: public Ui_EntityProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTITYDIALOG_H
