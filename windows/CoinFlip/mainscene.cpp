#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QTimer>
#include <QSound>

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

    /*准备开始按钮的音效*/
    QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);

    /*开始按钮*/
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

    /*实例化选关场景*/
    chooseScene = new ChooseLevelScene;

    /*监听选关场景的返回信号*/
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        this->setGeometry(chooseScene->geometry());

        chooseScene->hide(); //隐藏选关场景
        this->show(); //显示主场景
    });

    /*监听开始按钮*/
    connect(startBtn, &MyPushButton::clicked, [=](){
       qDebug() << "点击了开始按钮";
       /*播放开始音效*/
       startSound->play();
       /*实现点击特效*/
        startBtn->zoom1();
        startBtn->zoom2();

        /*延时进入选关场景*/
        QTimer::singleShot(500, this, [=](){
            /*设置chooseScene场景位置*/
            chooseScene->setGeometry(this->geometry());

            this->hide(); //隐藏主场景
            chooseScene->show(); //显示选关场景
        });
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
