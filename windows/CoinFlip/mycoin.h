#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg); //参数代表传入的金币或银币路径
    /*金币的属性*/
    int posX; //x坐标
    int posY; //y坐标
    bool flag; //正反标志

    /*改变标志的方法*/
    void changeFlag();
    QTimer *timer1; //正面翻反面的定时器
    QTimer *timer2; //反面翻正面的定时器
    int min = 1;
    int max = 8;

    /*执行动画的标志*/
    bool isAnimation = false;

    /*重写按下事件*/
    void mousePressEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYCOIN_H
