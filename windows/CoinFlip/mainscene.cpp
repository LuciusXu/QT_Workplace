#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    /*配置主场景*/
    setFixedSize(320, 588);                             //设置主场景固定大小
    setWindowIcon(QIcon(":/res/Coin0001.png"));         //设置图标
    setWindowTitle("Lucius带你翻金币");                   //设置标题
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });                                                 //退出按钮实现

    /*开始按钮*/
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);
    connect(startBtn, &MyPushButton::clicked, [=](){
       qDebug() << "点击了开始按钮";
       /*实现点击特效*/
    startBtn->zoom1();
    startBtn->zoom2();
    });
}

void MainScene::paintEvent(QPaintEvent *)
{
    /*画背景图*/
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");                         //加载背景图片
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);   //填充背景图片

    /*添加背景图标*/
    pix.load(":/res/Title.png");                              //加载背景图标
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);  //图标缩放
    painter.drawPixmap(10, 30, pix);                          //填充图标
}

void MyPushButton::zoom1()
{
    /*创建动画对象*/
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    /*设置动画时间间隔*/
    animation->setDuration(200);
    /*起始位置*/
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    /*结束位置*/
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    /*设置弹跳曲线*/
    animation->setEasingCurve(QEasingCurve::OutBounce);
    /*执行动画*/
    animation->start();
}

void MyPushButton::zoom2()
{
    /*创建动画对象*/
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    /*设置动画时间间隔*/
    animation->setDuration(200);
    /*起始位置*/
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    /*结束位置*/
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    /*设置弹跳曲线*/
    animation->setEasingCurve(QEasingCurve::OutBounce);
    /*执行动画*/
    animation->start();
}

MainScene::~MainScene()
{
    delete ui;
}
