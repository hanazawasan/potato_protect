#ifndef MYWINDOW_H
#define MYWINDOW_H
#include<config.h>
#include "mybutton.h"
#include "mainscene.h"
#include <QMainWindow>

class Mywindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mywindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

};

#endif // MYWINDOW_H
