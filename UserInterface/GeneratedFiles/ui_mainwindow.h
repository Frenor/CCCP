/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <GraphicsView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LeftWidgetPaint.h"
#include "LeftWidgetResult.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *drawTab;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_7;
    QRadioButton *Thin;
    QRadioButton *Filled;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Circle;
    QPushButton *Polygon;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *Delete;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextModeMesh;
    QWidget *meshTab;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *defaultMeshOpts;
    QLineEdit *maxElementSize;
    QLabel *label;
    QLineEdit *minElementSize;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *customArgs;
    QSpacerItem *horizontalSpacer;
    QPushButton *reMesh;
    QPushButton *nextModeSolve;
    QWidget *resultsTab;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *meshVisible;
    QCheckBox *resultVisible;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *treeAndVTK;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeViewOld;
    LeftWidgetResult *leftWidgetResult;
    LeftWidgetPaint *leftWidgetPaint;
    GraphicsView *GraphicsWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QButtonGroup *drawingTypeButtonGroup;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1038, 753);
        MainWindowClass->setAutoFillBackground(false);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 5, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMaximumSize(QSize(16777215, 135));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        drawTab = new QWidget();
        drawTab->setObjectName(QStringLiteral("drawTab"));
        drawTab->setMaximumSize(QSize(16777215, 16777215));
        drawTab->setAutoFillBackground(false);
        horizontalLayout_4 = new QHBoxLayout(drawTab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_7 = new QGroupBox(drawTab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(100, 0));
        Thin = new QRadioButton(groupBox_7);
        drawingTypeButtonGroup = new QButtonGroup(MainWindowClass);
        drawingTypeButtonGroup->setObjectName(QStringLiteral("drawingTypeButtonGroup"));
        drawingTypeButtonGroup->addButton(Thin);
        Thin->setObjectName(QStringLiteral("Thin"));
        Thin->setGeometry(QRect(10, 50, 82, 17));
        Thin->setChecked(false);
        Filled = new QRadioButton(groupBox_7);
        drawingTypeButtonGroup->addButton(Filled);
        Filled->setObjectName(QStringLiteral("Filled"));
        Filled->setGeometry(QRect(10, 30, 61, 17));
        Filled->setChecked(true);

        horizontalLayout_4->addWidget(groupBox_7);

        groupBox_2 = new QGroupBox(drawTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(100, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Circle = new QPushButton(groupBox_2);
        Circle->setObjectName(QStringLiteral("Circle"));
        Circle->setMinimumSize(QSize(0, 22));
        Circle->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu_draw/images/circle-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        Circle->setIcon(icon);
        Circle->setCheckable(false);

        verticalLayout_2->addWidget(Circle);

        Polygon = new QPushButton(groupBox_2);
        Polygon->setObjectName(QStringLiteral("Polygon"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Polygon->sizePolicy().hasHeightForWidth());
        Polygon->setSizePolicy(sizePolicy1);
        Polygon->setMinimumSize(QSize(0, 22));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/menu_draw/images/polygon-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        Polygon->setIcon(icon1);

        verticalLayout_2->addWidget(Polygon);


        horizontalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(drawTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(100, 0));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Delete = new QPushButton(groupBox);
        Delete->setObjectName(QStringLiteral("Delete"));
        Delete->setMinimumSize(QSize(0, 22));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/menu_draw/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        Delete->setIcon(icon2);

        verticalLayout_4->addWidget(Delete);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 22));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/menu_draw/images/accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);

        verticalLayout_4->addWidget(pushButton);


        horizontalLayout_4->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        nextModeMesh = new QPushButton(drawTab);
        nextModeMesh->setObjectName(QStringLiteral("nextModeMesh"));
        QFont font;
        font.setPointSize(12);
        nextModeMesh->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/menu_draw/images/next-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextModeMesh->setIcon(icon4);
        nextModeMesh->setIconSize(QSize(78, 128));
        nextModeMesh->setAutoDefault(false);
        nextModeMesh->setDefault(false);
        nextModeMesh->setFlat(false);

        horizontalLayout_4->addWidget(nextModeMesh);

        QIcon icon5;
        icon5.addFile(QStringLiteral(":/menu_tabs/images/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(drawTab, icon5, QString());
        meshTab = new QWidget();
        meshTab->setObjectName(QStringLiteral("meshTab"));
        horizontalLayout_3 = new QHBoxLayout(meshTab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_5 = new QGroupBox(meshTab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(220, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        defaultMeshOpts = new QPushButton(groupBox_5);
        defaultMeshOpts->setObjectName(QStringLiteral("defaultMeshOpts"));

        gridLayout_2->addWidget(defaultMeshOpts, 2, 2, 1, 1);

        maxElementSize = new QLineEdit(groupBox_5);
        maxElementSize->setObjectName(QStringLiteral("maxElementSize"));

        gridLayout_2->addWidget(maxElementSize, 2, 1, 1, 1);

        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        minElementSize = new QLineEdit(groupBox_5);
        minElementSize->setObjectName(QStringLiteral("minElementSize"));

        gridLayout_2->addWidget(minElementSize, 1, 1, 1, 1);


        horizontalLayout_3->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(meshTab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(200, 0));
        groupBox_6->setMaximumSize(QSize(250, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customArgs = new QLineEdit(groupBox_6);
        customArgs->setObjectName(QStringLiteral("customArgs"));
        customArgs->setMinimumSize(QSize(0, 0));
        customArgs->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(customArgs);


        horizontalLayout_3->addWidget(groupBox_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        reMesh = new QPushButton(meshTab);
        reMesh->setObjectName(QStringLiteral("reMesh"));
        reMesh->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/menu_draw/images/redo-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        reMesh->setIcon(icon6);
        reMesh->setIconSize(QSize(78, 72));

        horizontalLayout_3->addWidget(reMesh);

        nextModeSolve = new QPushButton(meshTab);
        nextModeSolve->setObjectName(QStringLiteral("nextModeSolve"));
        nextModeSolve->setFont(font);
        nextModeSolve->setIcon(icon4);
        nextModeSolve->setIconSize(QSize(78, 128));

        horizontalLayout_3->addWidget(nextModeSolve);

        QIcon icon7;
        icon7.addFile(QStringLiteral(":/menu_tabs/images/mesh-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(meshTab, icon7, QString());
        resultsTab = new QWidget();
        resultsTab->setObjectName(QStringLiteral("resultsTab"));
        groupBox_3 = new QGroupBox(resultsTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 90, 73));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        meshVisible = new QCheckBox(groupBox_3);
        meshVisible->setObjectName(QStringLiteral("meshVisible"));
        meshVisible->setChecked(true);

        verticalLayout_5->addWidget(meshVisible);

        resultVisible = new QCheckBox(groupBox_3);
        resultVisible->setObjectName(QStringLiteral("resultVisible"));
        resultVisible->setChecked(true);

        verticalLayout_5->addWidget(resultVisible);

        groupBox_4 = new QGroupBox(resultsTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(120, 10, 56, 73));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_6->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_6->addWidget(radioButton_2);

        QIcon icon8;
        icon8.addFile(QStringLiteral(":/menu_tabs/images/result-m.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(resultsTab, icon8, QString());

        verticalLayout->addWidget(tabWidget);

        treeAndVTK = new QHBoxLayout();
        treeAndVTK->setSpacing(0);
        treeAndVTK->setObjectName(QStringLiteral("treeAndVTK"));
        treeAndVTK->setContentsMargins(-1, 0, 2, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        treeViewOld = new QTreeView(centralWidget);
        treeViewOld->setObjectName(QStringLiteral("treeViewOld"));
        treeViewOld->setVisible(false);

        verticalLayout_3->addWidget(treeViewOld);

        leftWidgetResult = new LeftWidgetResult(centralWidget);
        leftWidgetResult->setObjectName(QStringLiteral("leftWidgetResult"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(200);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leftWidgetResult->sizePolicy().hasHeightForWidth());
        leftWidgetResult->setSizePolicy(sizePolicy2);
        leftWidgetResult->setMinimumSize(QSize(200, 100));

        verticalLayout_3->addWidget(leftWidgetResult);

        leftWidgetPaint = new LeftWidgetPaint(centralWidget);
        leftWidgetPaint->setObjectName(QStringLiteral("leftWidgetPaint"));
        sizePolicy2.setHeightForWidth(leftWidgetPaint->sizePolicy().hasHeightForWidth());
        leftWidgetPaint->setSizePolicy(sizePolicy2);
        leftWidgetPaint->setMinimumSize(QSize(200, 100));

        verticalLayout_3->addWidget(leftWidgetPaint);


        treeAndVTK->addLayout(verticalLayout_3);

        GraphicsWidget = new GraphicsView(centralWidget);
        GraphicsWidget->setObjectName(QStringLiteral("GraphicsWidget"));
        sizePolicy.setHeightForWidth(GraphicsWidget->sizePolicy().hasHeightForWidth());
        GraphicsWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(34, 60, 173, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        GraphicsWidget->setPalette(palette);
        GraphicsWidget->setAutoFillBackground(true);

        treeAndVTK->addWidget(GraphicsWidget);


        verticalLayout->addLayout(treeAndVTK);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1038, 21));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(false);
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(MainWindowClass);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindowClass, SLOT(openFile()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindowClass, SLOT(saveFile()));
        QObject::connect(Delete, SIGNAL(clicked()), MainWindowClass, SLOT(deleteEntity()));
        QObject::connect(Polygon, SIGNAL(clicked()), MainWindowClass, SLOT(addPolygon()));
        QObject::connect(tabWidget, SIGNAL(tabBarClicked(int)), MainWindowClass, SLOT(setMode(int)));
        QObject::connect(Circle, SIGNAL(clicked()), MainWindowClass, SLOT(addCircle()));
        QObject::connect(nextModeMesh, SIGNAL(clicked()), MainWindowClass, SLOT(setMeshMode()));
        QObject::connect(nextModeSolve, SIGNAL(clicked()), MainWindowClass, SLOT(setResultMode()));
        QObject::connect(reMesh, SIGNAL(clicked()), MainWindowClass, SLOT(setMeshMode()));
        QObject::connect(minElementSize, SIGNAL(editingFinished()), MainWindowClass, SLOT(setMinElementSize()));
        QObject::connect(maxElementSize, SIGNAL(editingFinished()), MainWindowClass, SLOT(setMaxElementSize()));
        QObject::connect(customArgs, SIGNAL(editingFinished()), MainWindowClass, SLOT(setCustomArguments()));
        QObject::connect(defaultMeshOpts, SIGNAL(clicked()), MainWindowClass, SLOT(resetMeshOptions()));
        QObject::connect(meshVisible, SIGNAL(toggled(bool)), MainWindowClass, SLOT(setMeshVisible(bool)));
        QObject::connect(resultVisible, SIGNAL(toggled(bool)), MainWindowClass, SLOT(setResultVisible(bool)));
        QObject::connect(MainWindowClass, SIGNAL(meshVisible(bool)), meshVisible, SLOT(setChecked(bool)));
        QObject::connect(MainWindowClass, SIGNAL(resultVisible(bool)), resultVisible, SLOT(setChecked(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), GraphicsWidget, SLOT(enterPressed()));
        QObject::connect(Filled, SIGNAL(toggled(bool)), MainWindowClass, SLOT(setDrawTypeFilled(bool)));
        QObject::connect(Thin, SIGNAL(toggled(bool)), MainWindowClass, SLOT(setDrawTypeThin(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Composite Crossection Calculation", 0));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindowClass", "Drawing type", 0));
        Thin->setText(QApplication::translate("MainWindowClass", "Thin walled", 0));
        Filled->setText(QApplication::translate("MainWindowClass", "Filled", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Create figures", 0));
        Circle->setText(QApplication::translate("MainWindowClass", "Circle    ", 0));
        Polygon->setText(QApplication::translate("MainWindowClass", "Polygon", 0));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Operations", 0));
        Delete->setText(QApplication::translate("MainWindowClass", "Delete", 0));
        pushButton->setText(QApplication::translate("MainWindowClass", "Done  ", 0));
        nextModeMesh->setText(QApplication::translate("MainWindowClass", "Mesh", 0));
        tabWidget->setTabText(tabWidget->indexOf(drawTab), QApplication::translate("MainWindowClass", "Draw", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindowClass", "Element Size", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "Maximum", 0));
        defaultMeshOpts->setText(QApplication::translate("MainWindowClass", "Default", 0));
        maxElementSize->setText(QApplication::translate("MainWindowClass", "1e+22", 0));
        label->setText(QApplication::translate("MainWindowClass", "Minimum", 0));
        minElementSize->setText(QApplication::translate("MainWindowClass", "0", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindowClass", "Custom Arguments", 0));
        reMesh->setText(QApplication::translate("MainWindowClass", "ReMesh", 0));
        nextModeSolve->setText(QApplication::translate("MainWindowClass", "Solve", 0));
        tabWidget->setTabText(tabWidget->indexOf(meshTab), QApplication::translate("MainWindowClass", "Mesh", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "Show/Hide", 0));
        meshVisible->setText(QApplication::translate("MainWindowClass", "Mesh", 0));
        resultVisible->setText(QApplication::translate("MainWindowClass", "Result", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindowClass", "Overlay", 0));
        radioButton->setText(QApplication::translate("MainWindowClass", "2D", 0));
        radioButton_2->setText(QApplication::translate("MainWindowClass", "3D", 0));
        tabWidget->setTabText(tabWidget->indexOf(resultsTab), QApplication::translate("MainWindowClass", "Results", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
