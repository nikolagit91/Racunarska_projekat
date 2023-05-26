#include "dialog.h"
#include "ui_dialog.h"


float distance;
float lowerRange=2.5;
float upperRange=50.0;
float Range=upperRange-lowerRange;

float getDistance()
{
   /* digitalWrite(TRIGGER_PIN,LOW);
    delayMicroseconds(2);*/


    // Send a 10us pulse to trigger the sensor
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);


    // Measure the duration of the pulse on the echo pin
    while (digitalRead(ECHO_PIN) == LOW)
    {
    }

    long echoStartTime = micros();


    while (digitalRead(ECHO_PIN) == HIGH)
    {
    }
    long echoEndTime = micros();

    // Calculate the distance based on the speed of sound (343.2 m/s)
    float duration = (float)(echoEndTime - echoStartTime);
    float distance = duration * 0.03432 / 2.0; // Divide by 2 for round trip

    return distance;
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(ultrasonic_read()));


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ultrasonic_read()
{
    distance=getDistance();
    ui->lcdNumber->display(distance);

    if (distance<lowerRange) {
        QMessageBox::warning(this, "SUDAR", "Odmakni se !!!");
    }

    if (distance > upperRange ) {
        ui->widget->reset();
        ui->widget_2->reset();
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >= (lowerRange + Range*0.8)) && (distance < upperRange)) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->reset();
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >=(lowerRange + Range*0.6)) && (distance <(lowerRange + Range*0.8))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >=(lowerRange + Range*0.4)) && (distance < (lowerRange + Range*0.6))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >=(lowerRange + Range*0.275)) && (distance < (lowerRange + Range*0.4))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >=(lowerRange +Range*0.15)) && (distance < (lowerRange + Range*0.275))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->reset();
        ui->widget_7->reset();
   }

    if ((distance >=(lowerRange + Range*0.075)) && (distance < (lowerRange +Range*0.15))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->setFillColor(QColor(211,33,45));
        ui->widget_7->reset();
   }


    if (distance <(lowerRange + Range*0.075)) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->setFillColor(QColor(211,33,45));
        ui->widget_7->setFillColor(QColor(211,33,45));
   }
}


void Dialog::on_pushButton_clicked()
{
    timer->setInterval(250);
    timer->start();
}

void Dialog::on_pushButton_2_clicked()
{
    timer->stop();
    ui->widget->reset();
    ui->widget_2->reset();
    ui->widget_3->reset();
    ui->widget_4->reset();
    ui->widget_5->reset();
    ui->widget_6->reset();
    ui->widget_7->reset();
    ui->lcdNumber->display(0);

}
