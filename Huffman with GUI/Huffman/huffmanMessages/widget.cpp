#include "widget.h"
#include "ui_widget.h"
#include "HuffmanHeader.h"
#include <iostream>

using namespace std;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->message->raise();

    setWindowTitle("Huffman coding messages");

    ui->message->setStyleSheet(
        "border-radius:14px;"
        );

    ui->message_recived->setStyleSheet(
        "border-radius:14px;"
        );

    ui->messageInput->setStyleSheet(
        "background-color:rgb(45,45,45);"
        "color: rgb(255, 255, 255);"
        "border-style:outset;"
        "border-radius:17px;"
        "padding-left:10px;"
        );

    /*ui->sendBT->setStyleSheet(
        "background-image: url(:/img/Images/send.png);"
        "background-color: rgb(37,211,102);"
        "color:white;"
        "border-style:outset;"
        "border-radius:18px;"
        "font-weight:bold;"
        );*/


    ui->groupBox->setStyleSheet(
        "background-image: url(:/img/Images/background.png);"
        "background-color: rgb(10, 10, 10);"
        );

    ui->groupBox_2->setStyleSheet(
        "background-image: url(:/img/Images/background.png);"
        "background-color: rgb(10, 10, 10);"
        );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendBT_clicked()
{

    // Get the widget object
    QWidget* msg_recived_2 = ui->message_recived_2;
    QWidget* msg_recived = ui->message_recived;
    QWidget* OriginalMsg = ui->message;



    // Set the size policy to expanding
    int width = ui->messageInput->text().length();
    msg_recived_2->setGeometry(10,75,width*23, 30);
    msg_recived->setGeometry(10,110,width*12, 30);
    OriginalMsg->setGeometry(350-width*12,40,width*12, 30);




    string message;
    message = ui->messageInput->text().toStdString();
    Huffman huffmann;
    huffmann.buildTree(message);
    string encodedText = huffmann.encode(message);
    string decodedText = huffmann.decode(encodedText);
    QString qmsq = QString::fromStdString(message);
    QString qencodedText = QString::fromStdString(encodedText);
    QString qdecodedText = QString::fromStdString(decodedText);
    ui->message->setText(qmsq);
    ui->message_recived->setText(qdecodedText);
    ui->message_recived_2->setText(qencodedText);


    ui->messageInput->clear();
    ui->message->setStyleSheet(
        "background-image: url(:/img/Images/message.png);"
        "background-color: rgba(37,211,102,1);"
        "border-radius:14px;"
        "color:white;"
        "padding-left:5px;"
        "font-size:17px;"
        );
    ui->message_recived->setStyleSheet(
        "background-image: url(:/img/Images/message_recived.png);"
        "border-radius:14px;"
        "color:white;"
        "padding-left:5px;"
        "font-size:17px;"
        );
    ui->message_recived_2->setStyleSheet(
        "background-image: url(:/img/Images/message_recived.png);"
        "border-radius:14px;"
        "color:white;"
        "padding-left:5px;"
        "font-size:17px;"
        );
}



