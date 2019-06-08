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

    QMediaPlayer  *music = new QMediaPlayer(NULL);//初始化音乐

    QMediaPlaylist *playlist = new QMediaPlaylist(NULL);//初始化播放列表

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);//设置播放模式(顺序播放，单曲循环，随机播放等)

//    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/迷途.mp3"));//添加歌曲，这里添加的是歌曲的路径

    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/9er_tan.mp3"));//添加歌曲，这里添加的是歌曲的路径

    music->setPlaylist(playlist);  //设置播放列表
    music->play();//播放歌曲

    VideoWidget w;
    w.setFixedSize(500, 500);
    w.show();

    return a.exec();
}
