#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    int levelIndex; //内部成员属性 记录所选关卡

    /*重写paintEvent事件*/
    void paintEvent(QPaintEvent *);
    int gameArray[4][4]; //二维数组维护每关的具体数据
    MyCoin *coinBtn[4][4];

signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
