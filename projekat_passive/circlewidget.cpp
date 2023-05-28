#include "circlewidget.h"
#include <QPainter>


circlewidget::circlewidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(35, 35);
}


void circlewidget::setFillColor(const QColor &color)
{
    m_fillColor = color;
    m_isFilled = true;
    update(); // Request a repaint to apply the new color
}


void circlewidget::reset()
{
    m_isFilled = false;
    update(); // Request a repaint to reset the circle
}

void circlewidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);


    QPen pen(Qt::black);
    pen.setWidth(2);

    if (m_isFilled) {
        painter.setPen(Qt::NoPen); // Set the pen to NoPen if the circle is filled
        painter.setBrush(m_fillColor);

    }

    else {
       painter.setPen(pen);
       painter.setBrush(Qt::NoBrush);
}
        QRect adjustedRect = rect().adjusted(5, 5, -5, -5);
        painter.drawEllipse(adjustedRect);
}



