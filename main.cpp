#include "widget.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtCore/QtPlugin>

#include <QtPlugin>

//Q_IMPORT_PLUGIN(DSServicePlugin)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMediaPlayer  *music = new QMediaPlayer(NULL);//��ʼ������

    QMediaPlaylist *playlist = new QMediaPlaylist(NULL);//��ʼ�������б�

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);//���ò���ģʽ(˳�򲥷ţ�����ѭ����������ŵ�)

//    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/��;.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/9er_tan.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

    music->setPlaylist(playlist);  //���ò����б�
    music->play();//���Ÿ���

    VideoWidget w;
    w.setFixedSize(500, 500);
    w.show();

    return a.exec();
}
