#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include<QAbstractListModel>
#include"modelcard.h"
#include"carddeck.h"
#include<random>
#include<vector>

using namespace std;

class GameLogic : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int money READ getMoney WRITE setMoney NOTIFY moneyChanged)
    Q_PROPERTY(int bet READ getBet WRITE setBet NOTIFY betChanged)
    Q_PROPERTY(int playerScore READ getPlayerScore WRITE setPlayerScore NOTIFY playerScoreChanged)
    Q_PROPERTY(int dillerScore READ getDillerScore WRITE setDillerScore NOTIFY dillerScoreChanged)
    Q_PROPERTY(QString result READ getResult WRITE setResult NOTIFY resultChanged)

public:
    GameLogic(ModelCard* First, ModelCard* Second);

    Q_INVOKABLE void startGame();
    Q_INVOKABLE void takeCard();
    Q_INVOKABLE void stopGame();
    Q_INVOKABLE void restart();

    void shuffleTheDeck();

    int getMoney() const;
    int getBet() const;
    int getPlayerScore() const;
    int getDillerScore() const;

    QString getResult() const;

    enum Result{
        Lose=0,
        Busted,
        Won,
        Push
    };

signals:

    void moneyChanged(int money);
    void betChanged(int bet);
    void playerScoreChanged(int playerScore);
    void dillerScoreChanged(int dillerScore);
    void resultChanged(QString result);

public slots:

    void setMoney(int money);
    void setBet(int bet);
    void setPlayerScore(int playerScore);
    void setDillerScore(int dillerScore);
    void setResult(QString result);

private:
    ModelCard *modelViewPlayer;
    ModelCard *modelViewDiller;

    int m_money;
    int m_bet;

    int m_playerScore;
    int _innerPlayerScore;
    int m_countAcePlayer;

    int m_dillerScore;
    int _innerDillerScore;
    int m_countAceDiller;

    //for hidden card
    QString tempImagePath;

    CardDeck Deck;
    vector<PlayingCard> m_mainDeck;
    vector<PlayingCard> m_workDeck;

    QString m_result;
};

#endif // GAMELOGIC_H
