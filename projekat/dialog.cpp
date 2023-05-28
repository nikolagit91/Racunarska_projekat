#include "dialog.h"
#include "ui_dialog.h"

float distance;
float lowerRange=3.5;
float upperRange=50.0;
float Range=upperRange-lowerRange;
int highTime;
int lowTime;
bool bazer=false;
int k;



float getDistance()
{
    // slanje trigera
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);


    // mjerenje trajanja echo signala
    while (digitalRead(ECHO_PIN) == LOW)
    {
    }
    long echoStartTime = micros();


    while (digitalRead(ECHO_PIN) == HIGH)
    {
    }
    long echoEndTime = micros();

    // izracunjavanje razdaljine
    float duration = (float)(echoEndTime - echoStartTime);
    float distance = duration * 0.03432 / 2.0;

    return distance;
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(updateDistance()));


    timer1=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(updateWidgets()));
    connect (timer1, SIGNAL(timeout()), this,SLOT(updateBuzzer()));
}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::updateDistance()
{
    distance=getDistance();
    ui->lcdNumber->display(distance);

    if (distance<lowerRange) {
        lowTime=0;
        highTime=1000;
        QMessageBox *warningBox=new QMessageBox(QMessageBox::Warning, "SUDAR", "Odmakni se !!!");
        QTimer::singleShot(2000,warningBox, &QMessageBox::accept);
        warningBox->exec();
     }
}

void Dialog::updateWidgets()
{
    if (distance > upperRange ) {
        ui->widget->reset();
        ui->widget_2->reset();
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=0;
   }

    if ((distance >= (lowerRange + Range*0.82)) && (distance < upperRange)) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->reset();
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=1;
        lowTime=200;
        highTime=200;

   }

    if ((distance >=(lowerRange + Range*0.66)) && (distance <(lowerRange + Range*0.82))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->reset();
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=1;
        lowTime=200;
        highTime=200;
   }

    if ((distance >=(lowerRange + Range*0.5)) && (distance < (lowerRange + Range*0.66))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->reset();
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=1;
        lowTime=200;
        highTime=200;
   }

    if ((distance >=(lowerRange + Range*0.35)) && (distance < (lowerRange + Range*0.5))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->reset();
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=1;
        lowTime=100;
        highTime=200;
   }

    if ((distance >=(lowerRange +Range*0.2)) && (distance < (lowerRange + Range*0.35))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->reset();
        ui->widget_7->reset();
        k=1;
        lowTime=100;
        highTime=200;
   }

    if ((distance >=(lowerRange + Range*0.1)) && (distance < (lowerRange +Range*0.2))) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->setFillColor(QColor(211,33,45));
        ui->widget_7->reset();
        k=1;
        lowTime=50;
        highTime=200;
   }


    if (distance <(lowerRange + Range*0.1)) {
        ui->widget->setFillColor(QColor(69,153,81));
        ui->widget_2->setFillColor(QColor(69,153,81));
        ui->widget_3->setFillColor(QColor(69,153,81));
        ui->widget_4->setFillColor(QColor(247,139,0));
        ui->widget_5->setFillColor(QColor(247,139,0));
        ui->widget_6->setFillColor(QColor(211,33,45));
        ui->widget_7->setFillColor(QColor(211,33,45));
        k=1;
        lowTime=25;
        highTime=200;
    }
}


void Dialog::updateBuzzer()
{
    if (bazer)
    {
        if (k==1) {
            digitalWrite(BUZZER_PIN,HIGH);
            delay(highTime);
            digitalWrite(BUZZER_PIN,LOW);
            delay(lowTime);
        }
          else if (k==0)
            digitalWrite(BUZZER_PIN,LOW);
        }
}


void Dialog::on_pushButton_clicked()
{
    timer->setInterval(250);
    timer->start();
    timer1->setInterval(250);
    timer1->start();
}


void Dialog::on_pushButton_2_clicked()
{
    timer->stop();
    timer1->stop();
    bazer=false;
    ui->pushButton_5->setChecked(false);
    ui->widget->reset();
    ui->widget_2->reset();
    ui->widget_3->reset();
    ui->widget_4->reset();
    ui->widget_5->reset();
    ui->widget_6->reset();
    ui->widget_7->reset();
    ui->lcdNumber->display(0);

}


void Dialog::on_pushButton_4_clicked()
{
    float min,max;
    min=ui->lineEdit->text().toFloat();
    max=ui->lineEdit_2->text().toFloat();

    if ( (min < 3.5 || min > 150 || max < 3.5 || max > 100) || min >= max)
        QMessageBox::warning(this, "POGRESAN UNOS", "Brojevi moraju biti veci od 3.5 i manji od 100, a minimum manji od maksimuma");
    else
    {
        lowerRange=ui->lineEdit->text().toFloat();
        upperRange=ui->lineEdit_2->text().toFloat();
        Range=upperRange-lowerRange;
    }

}


void Dialog::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    lowerRange=2.5;
    upperRange=50;
}


void Dialog::on_pushButton_5_clicked(bool checked)
{
    bazer= checked;
}
