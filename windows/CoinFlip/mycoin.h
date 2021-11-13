#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg); //参数代表传入的金币或银币路径

signals:

public slots:
};

#endif // MYCOIN_H
