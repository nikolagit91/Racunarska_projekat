#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H
#include <QWidget>
#include <QColor>


class circlewidget : public QWidget
{
    Q_OBJECT

public:
    explicit circlewidget(QWidget *parent = nullptr);
    void setFillColor(const QColor& color);
    void reset();

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    QColor m_fillColor;
    bool m_isFilled=false;



};



#endif // CIRCLEWIDGET_H
