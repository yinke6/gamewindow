#include "gamewindow.h"
#include <QApplication>
#include "gui.h"
#include<QDebug>
#include<QVector>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gui maingui;

    maingui.showgame();
    maingui.myplayer(1,1234);

    QPair<int,int> pair1(1,1234),pair2(2,5678),pair3(5,2333);

    QVector<QPair<int,int>> vectp;
    vectp<<pair1<<pair2<<pair3;
    maingui.refresh(vectp);
    maingui.start(1);
    maingui.getmessage(0,"天黑请闭眼");
    maingui.getmessage(1,"我是预言家");
    QVector<int> vect;
    vect<<2<<5;
    bool v=maingui.officercandidate();
    qDebug("%d",v);

    return a.exec();

}
