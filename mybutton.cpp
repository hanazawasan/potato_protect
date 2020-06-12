#include "mybutton.h"
#include<QPixmap>
Mybutton::Mybutton(QString pix):QPushButton(0)
{
    QPixmap pixmap(pix);
    this->setFixedSize(200,200);

    this->setStyleSheet("QPushButton{border.Opx;}");
    this->setIcon(pixmap);

    this->setIconSize(QSize(200,200));

}
