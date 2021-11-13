#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"

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

    /*显示当前的关卡号*/
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏"); //字体
    font.setPointSize(20); //字号
    QString str1 = QString("Level:%1").arg(this->levelIndex);
    /*将字体设置到标签控件中*/
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30, this->height()- 50, 120, 50);

    dataConfig config;
    /*初始化每个关卡的二维数组*/
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    /*显示金币背景图*/
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            /*绘制背景图片*/
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel *label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i * 50, 200 + j * 50);

            /*创建金币*/
            QString str;
            if (this->gameArray[i][j] == 1) //显示金币
            {
                str = ":/res/Coin0001.png";
            }
            else //显示银币
            {
                str = ":/res/Coin0008.png";
            }

            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i * 50, 204 + j *50);

            /*给金币属性赋值*/
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j]; //1正面 0反面

            /*将金币放入二维数组以便后期维护*/
            coinBtn[i][j] = coin;

            /*点击金币 进行翻转*/
            connect(coin, &MyCoin::clicked, [=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                /*延时翻转周围硬币*/
                QTimer::singleShot(300, this, [=](){
                    if (coin->posX + 1 <= 3) //周围右侧硬币反转条件
                    {
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
                    }
                    if (coin->posX - 1 >= 0) //周围左侧硬币反转条件
                    {
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                    }
                    if (coin->posY + 1 <= 3) //周围上侧硬币反转条件
                    {
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }
                    if (coin->posY - 1 >= 0) //周围下侧硬币反转条件
                    {
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }

                    /*判断是否胜利*/
                    this->isWin = true;
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            if (coinBtn[i][j]->flag == false) //只要一个为反面，即失败
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if (this->isWin)
                    {
                        qDebug() << "胜利";
                        /*将所有按钮胜利标志改为true,如果再次点击按钮直接return,不做响应*/
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                    }
                });


            });
        }
    }
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
