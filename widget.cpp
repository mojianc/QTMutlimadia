#include "widget.h"
#include <QBoxLayout>

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent)
{
    player = new QMediaPlayer;

    Playlist = new QMediaPlaylist();
    player->setPlaylist(Playlist);

    videoWidget = new QVideoWidget(this);
    player->setVideoOutput(videoWidget);


    //垂直布局：视频播放器、进度条、控制按钮布局
    QBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(videoWidget);
    //设置布局
    this->setLayout(mainLayout);
    QStringList lis;
    lis.append("G:/Mixxx/Madia/01.mp4");
    addToPlaylist(lis);
    player->play();
}

VideoWidget::~VideoWidget()
{

}



void VideoWidget::addToPlaylist(const QStringList& fileNames)
{
    foreach (QString const &argument, fileNames) {
        QFileInfo fileInfo(argument);
        if (fileInfo.exists()) {
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                Playlist->load(url);
            } else
                Playlist->addMedia(url);
        } else {
            QUrl url(argument);
            if (url.isValid()) {
                Playlist->addMedia(url);
            }
        }
    }
}

MusicWidget::MusicWidget(QWidget *parent)
{
    QMediaPlayer  *music = new QMediaPlayer(NULL);//初始化音乐

    QMediaPlaylist *playlist = new QMediaPlaylist(NULL);//初始化播放列表

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);//设置播放模式(顺序播放，单曲循环，随机播放等)

//    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/迷途.mp3"));//添加歌曲，这里添加的是歌曲的路径

    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/9er_tan.mp3"));//添加歌曲，这里添加的是歌曲的路径

    music->setPlaylist(playlist);  //设置播放列表
    music->play();//播放歌曲
}

MusicWidget::~MusicWidget()
{

}
