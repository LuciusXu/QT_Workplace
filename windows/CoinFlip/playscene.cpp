#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第%1关").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum; //记忆关卡

    /*初始化游戏场景*/
    this->setFixedSize(320, 588); //设置固定大小
    this->setWindowIcon(QPixmap(":/res/Coin0001.png")); //设置图标
    this->setWindowTitle("加油、加油"); //设置标题

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
       qDebug() << "翻金币场景：点击了返回按钮";
       /*延时返回*/
       QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack();
       });
    });

}

void PlayScene::paintEvent(QPaintEvent *)
{
    /*创建背景*/
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    /*加载标题*/
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}
