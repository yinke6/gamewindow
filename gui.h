#ifndef GUI_H
#define GUI_H
#include "gamewindow.h"
#include<QObject>
#include<QString>
#include<QVector>
#include<QPair>
//部分提示词已包含在程序中

class gui:public QObject
{
    Q_OBJECT
public:
    gui();
    void showgame();//窗口出现
    void refresh(QVector<QPair<int,int>>);//加入玩家:改为接受列表
    void myplayer(int seat, int id);//自身信息
    void start(int role);//开始游戏，告知身份
    void getmessage(int seat,QString str);//收取发言并显示
    void myturn();//开始发言
    //void runforpolice();
    int vote(QVector<int>);//选警长和投票通用，本来这两个就没区别吧
    bool officercandidate();//传递警徽也用vote（），点击自己头像即为撕毁
    bool officerdecide();
    int wolfsturn(QVector<int>);//自带提示“你要杀谁？”
    bool medicine();
    int poison(QVector<int> player);//选择是、否
    int prophet(QVector<int> player);//预言家出场，验人结果用字符串告知
    int hunter(QVector<int>);//猎人死亡，发动技能
    //void gameover();
    void endturn();//自爆时强制结束对话
    //killed已删除，直接发一句话就够了
signals:
    void prepared();//准备
    void unprepared();//取消准备
    void goback();//返回大厅
    void speak(QString);//发言
    void end();//结束发言
    void explode();//自爆
private:
    GameWindow g;
    void gprepared();
    void gunprepared();
    void ggoback();

    void gspeak(QString);
    void gendturn();
    void gchoice(int);
    void gexplode();
};

#endif // GUI_H
