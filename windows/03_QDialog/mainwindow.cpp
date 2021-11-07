#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮 弹出一个对话框
    connect(ui->actionNew, &QAction::triggered, [=](){
#if 0
        //对话框 分类
        //模态对话框（不可以对其它窗口进行操作）非模态对话框（可以对其它窗口进行操作）
        //模态创建 阻塞
        QDialog dlg(this);
        dlg.resize(200, 100);
        dlg.exec();
        qDebug() << "模态对话框弹出了";
#elif 1
        //非模态对话框
        QDialog *dlg2 = new QDialog(this);
        dlg2->resize(200, 100);
        dlg2->show();
        qDebug() << "非模态对话框弹出了";
#endif
        /*消息对话框*/
#if 0
        /*错误对话框*/
        QMessageBox::critical(this, "critical", "错误"); //标题 内容
#elif 0
        /*信息对话框*/
        QMessageBox::information(this, "info", "信息");
#elif 0
        /*提问对话框*/
        /*参数1：父亲 参数2：标题 参数3：提示内容 参数4：按键类型 参数5：默认关联回车按键*/
        if (QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        {
            qDebug() << "选择的是保存";
        }
        else
        {
            qDebug() << "选择的是取消";
        }
#elif 1
        /*警告对话框*/
        QMessageBox::warning(this, "warning", "警告");
#endif
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
