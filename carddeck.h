#ifndef CARDDECK_H
#define CARDDECK_H

#include<vector>
#include<QtXml>
#include"playingcard.h"
#include<random>
using namespace std;

class CardDeck
{
public:
    explicit CardDeck();
    vector<PlayingCard> m_deck;
private:    
    void makeDeck();

    //XML reading
    void domXml();
    void readXml(QDomNode &node);
    vector<QString> m_nameList;
    vector<QString> m_suitList;
    vector<QString> m_worthList;
    vector<QString> m_imagePathList;
};

#endif // CARDDECK_H
