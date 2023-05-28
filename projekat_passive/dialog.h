#ifndef DIALOG_H
#define DIALOG_H

#include "circlewidget.h"
#include <QDialog>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <QTimer>
#include <QColorDialog>
#include <QPen>
#include <QMessageBox>
#include <QDebug>

#define TRIGGER_PIN 4
#define ECHO_PIN 5
#define BUZZER_PIN 27


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void updateDistance();

    void updateWidgets();

    void updateBuzzer();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked(bool checked);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::Dialog *ui;
    QTimer *timer;
    QTimer *timer1;

};
#endif // DIALOG_H
