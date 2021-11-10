#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*treeWidget树控件使用*/
    /*设置水平头*/
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");
    QTreeWidgetItem *LiItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *MinItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *ZhiItem = new QTreeWidgetItem(QStringList() << "智力");
    /*加载顶层的节点*/
    ui->treeWidget->addTopLevelItem(LiItem);
    ui->treeWidget->addTopLevelItem(MinItem);
    ui->treeWidget->addTopLevelItem(ZhiItem);
    /*追加子节点*/
    QStringList heroL1;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(heroL1);
    LiItem->addChild(l1);

    QStringList heroL2;
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";
    QTreeWidgetItem *l2 = new QTreeWidgetItem(heroL2);
    LiItem->addChild(l2);

    QStringList heroM1;
    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    QTreeWidgetItem *m1 = new QTreeWidgetItem(heroM1);
    MinItem->addChild(m1);

    QStringList heroM2;
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem *m2 = new QTreeWidgetItem(heroM2);
    MinItem->addChild(m2);

    QStringList heroZ1;
    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    QTreeWidgetItem *z1 = new QTreeWidgetItem(heroZ1);
    ZhiItem->addChild(z1);

    QStringList heroZ2;
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem *z2 = new QTreeWidgetItem(heroZ2);
    ZhiItem->addChild(z2);
}

Widget::~Widget()
{
    delete ui;
}
