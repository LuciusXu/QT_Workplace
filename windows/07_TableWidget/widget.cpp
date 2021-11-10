#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*TableWidget控件*/
    /*设置列数*/
    ui->tableWidget->setColumnCount(3);
    /*设置水平表头*/
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    /*设置行数*/
    ui->tableWidget->setRowCount(4);
    /*设置正文*/
    QStringList nameList;
    nameList << "亚瑟" << "张飞" << "关羽" << "赵云";
    QList<QString> sexList;
    sexList << "男" << "男" << "男" << "男";
    for (int i = 0; i < 4; i++)
    {
        int j = 0;
        ui->tableWidget->setItem(i, j++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, j++, new QTableWidgetItem(sexList.at(i)));
        /*int转QString*/
        ui->tableWidget->setItem(i, j++, new QTableWidgetItem(QString::number(18)));
    }
}

Widget::~Widget()
{
    delete ui;
}
