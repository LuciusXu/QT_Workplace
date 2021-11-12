#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>

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

MainScene::~MainScene()
{
    delete ui;
}
