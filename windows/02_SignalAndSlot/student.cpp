#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}


#if 1
void Student::treat(QString FoodName)
{
    //QString转char*,去除引号[先转成QByteArray(.toUtf8()),再转char*(.data())]
    qDebug() << "请老师吃饭,老师要吃:" << FoodName.toUtf8().data();
    //qDebug() << "请老师吃饭,老师要吃:" << FoodName;
}
#elif 1
void Student::treat()
{
    qDebug() << "请老师吃饭";
}
#endif
