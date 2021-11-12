#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    /*重写绘图事件*/
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // CHOOSELEVELSCENE_H
