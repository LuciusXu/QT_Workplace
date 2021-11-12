#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    /*重写绘图事件*/
    void paintEvent(QPaintEvent *);

    /*游戏场景对象指针*/
    PlayScene *play = NULL;
signals:
    /*自定义信号，告诉主场景点击了返回*/
    void chooseSceneBack(); //自定义信号，只需申明，无需实现

public slots:
};

#endif // CHOOSELEVELSCENE_H
