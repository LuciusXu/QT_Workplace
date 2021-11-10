#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*单选按钮*/
    //设置单选按钮 默认选中男
    ui->rBtnMan->setChecked(true);
    /*选中女后 打印信息*/
    connect(ui->rBtnWoman, &QRadioButton::clicked, [=](){
        qDebug() << "性别勾选女";
    });

    /*多选按钮*/
    /*2是选中 0是未选中*/
    connect(ui->cBox, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
    });

    /*利用listWidget写诗*/
#if 1
    /*方式一*/
    QListWidgetItem *item = new QListWidgetItem("头顶月眼中你");
    /*将诗放入listWidget中*/
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter);
#elif 1
    /*方式二*/
    /*QStringList*/
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
#endif
}

Widget::~Widget()
{
    delete ui;
}
