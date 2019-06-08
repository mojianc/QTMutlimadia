#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = 0);
    ~VideoWidget();
    void addToPlaylist(const QStringList& fileNames);
private:
     QMediaPlayer *player;
     QVideoWidget *videoWidget;
     QMediaPlaylist *Playlist;
     QString m_fileName;
};

class MusicWidget : public QWidget
{
    Q_OBJECT

public:
    MusicWidget(QWidget *parent = 0);
    ~MusicWidget();

};

#endif // WIDGET_H
