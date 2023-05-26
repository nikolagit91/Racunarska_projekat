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

#define TRIGGER_PIN 4
#define ECHO_PIN 5


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
    void ultrasonic_read();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QTimer *timer;
};
#endif // DIALOG_H
