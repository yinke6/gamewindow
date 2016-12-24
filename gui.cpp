#include "gui.h"
#include<gamewindow.h>
gui::gui()
{
    QObject::connect(&g,&GameWindow::prepared,this,&gui::gprepared);
    QObject::connect(&g,&GameWindow::unprepared,this,&gui::gunprepared);
    QObject::connect(&g,&GameWindow::goback,this,&gui::ggoback);
    QObject::connect(&g,&GameWindow::endturn,this,&gui::gendturn);
    QObject::connect(&g,&GameWindow::explode,this,&gui::gexplode);
}
void gui::showgame()
{
    g.show();
}

void gui::refresh(QVector<QPair<int, int> > vect)
{
    QVector<QPair<int,int>>::iterator i;
    for(i=vect.begin();i!=vect.end();i++){
    g.addplayer(i->first,i->second);}
}
void gui::myplayer(int seat, int id)
{
    g.myplayer(seat,id);
}

void gui::gprepared()
{
    emit prepared();
}
void gui::gunprepared()
{
    emit unprepared();
}
void gui::ggoback()
{
    emit goback();
}

void gui::start(int role)
{
    g.start(role);
}
void gui::getmessage(int seat, QString str)
{
    g.getmessage(seat,str);
}
void gui::gspeak(QString str)
{
    emit speak(str);
}
void gui::myturn()
{
    g.myturn();
}
void gui::gendturn()
{
    emit end();
}

/*void gui::gameover()
{
    g.gameover();
}*/
int gui::wolfsturn(QVector<int> player)
{
    return g.wolfsturn(player);
}
int gui::vote(QVector<int> player)
{
    return g.vote(player);
}


bool gui::officercandidate()
{
    return g.officercandidate();
}
bool gui::medicine()
{
    return g.medicine();
}
int gui::poison(QVector<int> player)
{
    return g.poison(player);
}
int gui::prophet(QVector<int> player)
{
    return g.prophet(player);
}
int gui::hunter(QVector<int> player)
{
    return g.hunter(player);
}
bool gui::officerdecide()
{
    return g.officerdecide();
}
void gui::gexplode()
{
    emit explode();
}
void gui::endturn()
{
    g.endturn();
}
