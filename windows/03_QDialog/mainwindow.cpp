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
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
