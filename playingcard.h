#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H
#include <QString>

class PlayingCard
{
public:
    PlayingCard(QString name="", QString suit="", int worth=0, QString imagePath="");

    QString m_name;
    QString m_suit;
    int m_worth;
    QString m_imagePath;
};

#endif // PLAYINGCARD_H
