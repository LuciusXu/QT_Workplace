#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    //早期Qt版本，必须写到public slots下，高级版本可以写到public或者全局下
    //返回值void，需要声明，也需要实现
    //可以有参数，可以发生重载
#if 1
    void treat(QString FoodName);
#elif 1
    void treat();
#endif
};

#endif // STUDENT_H
