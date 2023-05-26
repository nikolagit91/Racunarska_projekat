#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    wiringPiSetup();
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
