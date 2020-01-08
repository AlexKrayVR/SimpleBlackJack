#ifndef MODELCARD_H
#define MODELCARD_H

#include <QObject>
#include<vector>
#include<QAbstractListModel>
#include"playingcard.h"
using namespace std;

class ModelCard : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModelCard();

    vector<PlayingCard> Cards;

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent)const override;
    QVariant data(const QModelIndex& index, int role) const override;
    enum CardRoles{
        Name=Qt::UserRole+1,
        Suit,
        Worth,
        imagePath
    };

    void addElement(PlayingCard card);
    void deleteElement();
    void changeSkirt(QString path);
    void clearModel();

    //for hidden card
    QString tempPath;
private:

signals:

public slots:
};

#endif // MODELCARD_H
