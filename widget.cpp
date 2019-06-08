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


    //��ֱ���֣���Ƶ�������������������ư�ť����
    QBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(videoWidget);
    //���ò���
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
    QMediaPlayer  *music = new QMediaPlayer(NULL);//��ʼ������

    QMediaPlaylist *playlist = new QMediaPlaylist(NULL);//��ʼ�������б�

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);//���ò���ģʽ(˳�򲥷ţ�����ѭ����������ŵ�)

//    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/��;.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

    playlist->addMedia(QUrl::fromLocalFile("E:/CloudMusic/9er_tan.mp3"));//��Ӹ�����������ӵ��Ǹ�����·��

    music->setPlaylist(playlist);  //���ò����б�
    music->play();//���Ÿ���
}

MusicWidget::~MusicWidget()
{

}
