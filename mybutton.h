#ifndef MYBUTTON_H
#define MYBUTTON_H


#include<QPushButton>
#include <QWidget>

class Mybutton : public QPushButton
{
    Q_OBJECT
public:
   Mybutton(QString pix);

signals:

};

#endif // MYBUTTON_H
