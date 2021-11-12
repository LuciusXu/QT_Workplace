#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    /*配置选关场景*/
    this->setFixedSize(320, 588); //设置固定大小
    this->setWindowIcon(QPixmap(":/res/Coin0001.png")); //设置图标
    this->setWindowTitle("请选关"); //设置标题

    /*创建菜单栏*/
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("选项"); //创建开始菜单
    QAction *quitAction = startMenu->addAction("退出"); //创建退出菜单项
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });//点击退出按钮实现退出

    /*返回按钮*/
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png"); //加载按钮图片
    backBtn->setParent(this); //设置父类
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height()); //移动到右下角

    /*点击返回*/
    connect(backBtn, &MyPushButton::clicked, [=](){
       qDebug() << "点击了返回按钮";
    });
}

/*绘图事件方法*/
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    /*加载背景*/
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png"); //加载背景图
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    /*添加背景图标*/
    pix.load(":/res/Title.png"); //加载背景图标
    painter.drawPixmap((this->width() - pix.width()) * 0.5, 30, pix.width(), pix.height(), pix); //填充图标
}
