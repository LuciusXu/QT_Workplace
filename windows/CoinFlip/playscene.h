#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    int levelIndex; //内部成员属性 记录所选关卡

    /*重写paintEvent事件*/
    void paintEvent(QPaintEvent *);
signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
