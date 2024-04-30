/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *message;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *message_recived;
    QLabel *message_recived_2;
    QPushButton *sendBT;
    QLineEdit *messageInput;
    QGroupBox *groupBox_3;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(359, 247);
        Widget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"        background-image: url(:/img/Images/send.png);\n"
"        background-color: rgb(37,211,102);\n"
"        color:white;\n"
"        border-style:outset;\n"
"        border-radius:18px;\n"
"        font-weight:bold;\n"
"		transition:1s;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:#1a8e45;\n"
"	cursor:pointer;\n"
"}"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 10, 360, 240));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 361, 221));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        message = new QLabel(groupBox);
        message->setObjectName("message");
        message->setGeometry(QRect(210, 50, 120, 30));
        message->setStyleSheet(QString::fromUtf8(""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 360, 221));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        message_recived = new QLabel(groupBox_2);
        message_recived->setObjectName("message_recived");
        message_recived->setGeometry(QRect(10, 110, 120, 30));
        message_recived->setStyleSheet(QString::fromUtf8(""));
        message_recived_2 = new QLabel(groupBox_2);
        message_recived_2->setObjectName("message_recived_2");
        message_recived_2->setGeometry(QRect(10, 75, 120, 30));
        message_recived_2->setStyleSheet(QString::fromUtf8(""));
        tabWidget->addTab(tab_2, QString());
        sendBT = new QPushButton(Widget);
        sendBT->setObjectName("sendBT");
        sendBT->setGeometry(QRect(310, 200, 36, 36));
        sendBT->setStyleSheet(QString::fromUtf8(""));
        sendBT->setFlat(false);
        messageInput = new QLineEdit(Widget);
        messageInput->setObjectName("messageInput");
        messageInput->setGeometry(QRect(10, 200, 296, 36));
        messageInput->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(235, -5, 111, 41));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(5, 19, 63, 20));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QString());
        message->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "Sender", nullptr));
        groupBox_2->setTitle(QString());
        message_recived->setText(QString());
        message_recived_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "Receiver", nullptr));
        sendBT->setText(QString());
        messageInput->setPlaceholderText(QCoreApplication::translate("Widget", " Message ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "the code", nullptr));
        label->setText(QCoreApplication::translate("Widget", "0101101", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
