/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *bas1;
    QCustomPlot *bas2;
    QLabel *label;
    QCustomPlot *temp;
    QCustomPlot *height2;
    QCustomPlot *lspeed;
    QPushButton *pushButton;
    QCustomPlot *height1;
    QQuickWidget *quickWidget;
    QPushButton *rgb;
    QQuickWidget *quickWidget_2;
    QListWidget *listWidget;
    QLabel *label_3;
    QLabel *logo;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QCustomPlot *iot;
    QCustomPlot *Irtifa_Farki;
    QCustomPlot *Voltage;
    QPushButton *ayril;
    QLabel *label_10;
    QLabel *label_11;
    QLCDNumber *lcdNumber_4;
    QLabel *kod2;
    QLabel *kod3;
    QLabel *kod4;
    QLabel *kod5;
    QLabel *kod6;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QProgressBar *progressBar;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QCustomPlot *iot2;
    QLabel *kod1;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2000, 950);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow { \n"
"background-color: #6291b6 ;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        bas1 = new QCustomPlot(centralwidget);
        bas1->setObjectName(QString::fromUtf8("bas1"));
        bas1->setGeometry(QRect(815, 290, 200, 180));
        QFont font;
        font.setPointSize(9);
        bas1->setFont(font);
        bas1->setStyleSheet(QString::fromUtf8("QCustomplot{\n"
"background-color:#6291b6\n"
"\n"
"\n"
"}"));
        bas2 = new QCustomPlot(centralwidget);
        bas2->setObjectName(QString::fromUtf8("bas2"));
        bas2->setGeometry(QRect(1040, 290, 200, 180));
        bas2->setStyleSheet(QString::fromUtf8("QCustomPlot{\n"
"border-style: solid;\n"
"  border-width: 4px;\n"
"  border-radius: 50px;\n"
"  border-color: dark blue;\n"
"	padding: 10px;\n"
"\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 50, 261, 41));
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Copperplate"));
        font1.setPointSize(45);
        font1.setBold(true);
        font1.setItalic(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: black;\n"
"\n"
"}"));
        temp = new QCustomPlot(centralwidget);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(1040, 490, 200, 180));
        height2 = new QCustomPlot(centralwidget);
        height2->setObjectName(QString::fromUtf8("height2"));
        height2->setGeometry(QRect(1040, 90, 200, 180));
        lspeed = new QCustomPlot(centralwidget);
        lspeed->setObjectName(QString::fromUtf8("lspeed"));
        lspeed->setGeometry(QRect(815, 690, 200, 180));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 450, 221, 111));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gill Sans"));
        font2.setBold(true);
        font2.setItalic(true);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	color: #fff;\n"
"	font-size: 20px;\n"
"	font-weight: bold;\n"
"border-style: solid;\n"
" \n"
"\n"
"	padding: 10px;\n"
"\n"
"\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ba\305\237latj.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/durdurj.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(300, 300));
        pushButton->setCheckable(true);
        height1 = new QCustomPlot(centralwidget);
        height1->setObjectName(QString::fromUtf8("height1"));
        height1->setGeometry(QRect(815, 90, 200, 180));
        quickWidget = new QQuickWidget(centralwidget);
        quickWidget->setObjectName(QString::fromUtf8("quickWidget"));
        quickWidget->setGeometry(QRect(1275, 90, 260, 341));
        quickWidget->setStyleSheet(QString::fromUtf8(""));
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        rgb = new QPushButton(centralwidget);
        rgb->setObjectName(QString::fromUtf8("rgb"));
        rgb->setGeometry(QRect(20, 540, 211, 101));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Gill Sans"));
        font3.setBold(true);
        font3.setItalic(true);
        font3.setStrikeOut(false);
        rgb->setFont(font3);
        rgb->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	color: #fff;\n"
"	font-size: 20px;\n"
"	font-weight: bold;\n"
"	border-style: solid;\n"
"\n"
"\n"
"\n"
"	padding: 15px;\n"
"\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/filtrelej.png"), QSize(), QIcon::Normal, QIcon::Off);
        rgb->setIcon(icon1);
        rgb->setIconSize(QSize(300, 300));
        rgb->setCheckable(true);
        rgb->setChecked(false);
        quickWidget_2 = new QQuickWidget(centralwidget);
        quickWidget_2->setObjectName(QString::fromUtf8("quickWidget_2"));
        quickWidget_2->setGeometry(QRect(1050, 740, 620, 280));
        quickWidget_2->setStyleSheet(QString::fromUtf8("QquickWidget{\n"
"border-style: solid;\n"
"  border-width: 4px;\n"
"  border-radius: 50px;\n"
"  border-color: dark blue;\n"
"	padding: 10px;\n"
"\n"
"}"));
        quickWidget_2->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 90, 800, 371));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Academy Engraved LET"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setItalic(false);
        listWidget->setFont(font4);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"background-color: #052b47;\n"
"border-style: solid;\n"
"  border-width: 4px;\n"
"  border-radius: 50px;\n"
"  border-color: #5AED72;\n"
"	padding: 10px;\n"
"color: white\n"
"}"));
        listWidget->setFrameShape(QFrame::Shape::StyledPanel);
        listWidget->setMovement(QListView::Movement::Snap);
        listWidget->setFlow(QListView::Flow::TopToBottom);
        listWidget->setResizeMode(QListView::ResizeMode::Fixed);
        listWidget->setViewMode(QListView::ViewMode::ListMode);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, -30, 2211, 1081));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/calis.png")));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(-10, 0, 161, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/itutayf0.png")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(720, 10, 431, 61));
        QPalette palette1;
        QBrush brush3(QColor(125, 211, 138, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label_2->setPalette(palette1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Copperplate"));
        font5.setPointSize(68);
        font5.setBold(false);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: black;\n"
"\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1280, 80, 311, 51));
        QPalette palette2;
        label_4->setPalette(palette2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Copperplate"));
        font6.setPointSize(30);
        font6.setBold(true);
        label_4->setFont(font6);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1050, 678, 371, 101));
        QPalette palette3;
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        label_5->setPalette(palette3);
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: black;\n"
"\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1280, 375, 251, 71));
        label_6->setFont(font6);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(1600, 130, 78, 50));
        QPalette palette4;
        lcdNumber->setPalette(palette4);
        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(1600, 187, 78, 50));
        QPalette palette5;
        lcdNumber_2->setPalette(palette5);
        lcdNumber_3 = new QLCDNumber(centralwidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(1600, 245, 78, 50));
        QPalette palette6;
        lcdNumber_3->setPalette(palette6);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1520, 110, 100, 100));
        QPalette palette7;
        label_7->setPalette(palette7);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Copperplate"));
        font7.setPointSize(26);
        label_7->setFont(font7);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1520, 165, 100, 100));
        QPalette palette8;
        label_8->setPalette(palette8);
        label_8->setFont(font7);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1520, 225, 100, 100));
        QPalette palette9;
        label_9->setPalette(palette9);
        label_9->setFont(font7);
        iot = new QCustomPlot(centralwidget);
        iot->setObjectName(QString::fromUtf8("iot"));
        iot->setGeometry(QRect(350, 690, 200, 180));
        Irtifa_Farki = new QCustomPlot(centralwidget);
        Irtifa_Farki->setObjectName(QString::fromUtf8("Irtifa_Farki"));
        Irtifa_Farki->setGeometry(QRect(580, 490, 200, 180));
        Voltage = new QCustomPlot(centralwidget);
        Voltage->setObjectName(QString::fromUtf8("Voltage"));
        Voltage->setGeometry(QRect(815, 490, 200, 180));
        ayril = new QPushButton(centralwidget);
        ayril->setObjectName(QString::fromUtf8("ayril"));
        ayril->setGeometry(QRect(20, 470, 211, 71));
        ayril->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	color: #fff;\n"
"	font-size: 20px;\n"
"	font-weight: bold;\n"
"border-style: solid;\n"
" \n"
"\n"
"	padding: 10px;\n"
"\n"
"\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ayr\304\261lj.png"), QSize(), QIcon::Normal, QIcon::Off);
        ayril->setIcon(icon2);
        ayril->setIconSize(QSize(320, 300));
        ayril->setCheckable(true);
        ayril->setChecked(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 660, 241, 51));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush6(QColor(5, 43, 71, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush7(QColor(5, 43, 71, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        label_10->setPalette(palette10);
        QFont font8;
        font8.setFamily(QString::fromUtf8("Copperplate"));
        font8.setPointSize(37);
        font8.setBold(true);
        label_10->setFont(font8);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"}"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1220, 30, 161, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label_11->setPalette(palette11);
        label_11->setFont(font6);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: black;\n"
"\n"
"}"));
        lcdNumber_4 = new QLCDNumber(centralwidget);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(120, 720, 131, 41));
        lcdNumber_4->setStyleSheet(QString::fromUtf8("QLCDNumber {\n"
"border: 2px solid white; background-color: #052b47; color: white;\n"
"}"));
        kod2 = new QLabel(centralwidget);
        kod2->setObjectName(QString::fromUtf8("kod2"));
        kod2->setGeometry(QRect(1440, 25, 40, 40));
        kod3 = new QLabel(centralwidget);
        kod3->setObjectName(QString::fromUtf8("kod3"));
        kod3->setGeometry(QRect(1485, 25, 40, 40));
        kod4 = new QLabel(centralwidget);
        kod4->setObjectName(QString::fromUtf8("kod4"));
        kod4->setGeometry(QRect(1530, 25, 40, 40));
        kod5 = new QLabel(centralwidget);
        kod5->setObjectName(QString::fromUtf8("kod5"));
        kod5->setGeometry(QRect(1575, 25, 40, 40));
        kod6 = new QLabel(centralwidget);
        kod6->setObjectName(QString::fromUtf8("kod6"));
        kod6->setGeometry(QRect(1620, 25, 40, 40));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 560, 181, 61));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Copperplate"));
        font9.setPointSize(29);
        lineEdit->setFont(font9);
        lineEdit->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #052b47;\n"
"border:  4px solid white;;\n"
"border-style: solid;\n"
"  border-width: 4px;\n"
"  border-radius: 20px;\n"
"  border-color: #5AED72;\n"
"	padding: 10px;\n"
"color: white;\n"
"}"));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(150, 10, 111, 41));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Copperplate"));
        font10.setPointSize(26);
        font10.setBold(true);
        label_12->setFont(font10);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color:  #052b47;\n"
"}"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 930, 860, 31));
        progressBar->setValue(24);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 970, 81, 16));
        QFont font11;
        font11.setPointSize(12);
        font11.setBold(true);
        label_13->setFont(font11);
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(160, 970, 71, 16));
        label_14->setFont(font11);
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}\n"
""));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(300, 970, 111, 16));
        label_15->setFont(font11);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}\n"
""));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(455, 970, 58, 16));
        label_16->setFont(font11);
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}\n"
""));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(580, 970, 101, 16));
        QFont font12;
        font12.setBold(true);
        label_17->setFont(font12);
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}"));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(770, 970, 71, 16));
        label_18->setFont(font11);
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"color: #052b47;\n"
"\n"
"}"));
        iot2 = new QCustomPlot(centralwidget);
        iot2->setObjectName(QString::fromUtf8("iot2"));
        iot2->setGeometry(QRect(580, 690, 200, 180));
        kod1 = new QLabel(centralwidget);
        kod1->setObjectName(QString::fromUtf8("kod1"));
        kod1->setGeometry(QRect(1395, 25, 40, 40));
        MainWindow->setCentralWidget(centralwidget);
        label_3->raise();
        bas1->raise();
        bas2->raise();
        label->raise();
        temp->raise();
        height2->raise();
        lspeed->raise();
        pushButton->raise();
        height1->raise();
        quickWidget->raise();
        rgb->raise();
        quickWidget_2->raise();
        listWidget->raise();
        logo->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        lcdNumber->raise();
        lcdNumber_2->raise();
        lcdNumber_3->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        iot->raise();
        Irtifa_Farki->raise();
        Voltage->raise();
        ayril->raise();
        label_10->raise();
        label_11->raise();
        lcdNumber_4->raise();
        kod2->raise();
        kod3->raise();
        kod4->raise();
        kod5->raise();
        kod6->raise();
        lineEdit->raise();
        label_12->raise();
        progressBar->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        iot2->raise();
        kod1->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TELEMETRI", nullptr));
        pushButton->setText(QString());
        rgb->setText(QString());
        label_3->setText(QString());
        logo->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ITU TAYF </p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "3D MODEL", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "GPS HAR\304\260TA", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Canl\304\261 Yay\304\261n", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        ayril->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\304\260rtifa Fark\304\261", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "HATA KODU", nullptr));
        kod2->setText(QString());
        kod3->setText(QString());
        kod4->setText(QString());
        kod5->setText(QString());
        kod6->setText(QString());
        lineEdit->setText(QCoreApplication::translate("MainWindow", "7Y8P", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "U\303\247u\305\237a Haz\304\261r", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", " Y\303\274kselme", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", " Model Uydu \304\260ni\305\237", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", " Ayr\304\261lma", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "G\303\266rev Y\303\274k\303\274 \304\260ni\305\237", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Kurtarma", nullptr));
        kod1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
