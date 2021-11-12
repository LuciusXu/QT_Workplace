#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

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
       /*延时返回*/
       QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack(); //主场景监听ChooseLevelScene的返回按钮
       });
    });

    /*创建选关按钮*/
    for (int i = 0; i < 20; i++)
    {
        /*添加按钮*/
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this); //设置父类
        menuBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        /*监听每个关卡按钮的点击事件*/
        connect(menuBtn, &MyPushButton::clicked, [=](){
            QString str = QString("选中了第%1关").arg(i + 1);
            qDebug() << str;

            /*进入到游戏场景*/
            this->hide(); //隐藏选关场景
            play = new PlayScene(i + 1); //创建游戏场景
            play->show(); //显示游戏场景

            connect(play, &PlayScene::chooseSceneBack, [=](){
               this->show();
               delete play;
                play = NULL;
            });
        });

        /*添加数字*/
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        /*设置label上的文字对齐方式*/
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //水平居中和垂直居中

        /*设置鼠标穿透label*/
        label->setAttribute(Qt::WA_TransparentForMouseEvents); //51号属性
    }
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
