#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher 类
//Student 类
//下课后，老师触发饿了信号，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    this->te = new Teacher(this);
    //创建一个学生对象
    this->st = new Student(this);

    //链接带参数的信号和槽
    //函数指针->函数地址
    void(Teacher::*TeacherSignal)(QString) = &Teacher::hungry;
    void(Student::*StudentSlot)(QString) = &Student::treat;
    connect(te, TeacherSignal, st, StudentSlot);
#if 1
    //点击一个下课的按钮，再触发下课
    QPushButton *btn = new QPushButton("下课", this);
    //重置窗口大小
    this->resize(600, 400);
    //点击按钮 触发下课
    connect(btn, &QPushButton::clicked, this, &Widget::ClassIsOver);

    //无参信号和槽链接
#elif 1
    ClassIsOver();
#elif 1
    //老师饿了，学生请客的链接
    connect(te, &Teacher::hungry, st, &Student::treat);
    //调用下课函数
    ClassIsOver();
#endif
}

void Widget::ClassIsOver()
{
    //下课函数，调用后，触发老师饿了信号
#if 1
    emit te->hungry("宫保鸡丁");
#elif 1
    emit te->hungry();
#endif
}

Widget::~Widget()
{
    delete ui;
}
