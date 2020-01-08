#include "gamelogic.h"


GameLogic::GameLogic(ModelCard *First, ModelCard *Second):modelViewPlayer(First), modelViewDiller(Second),
    m_money(400),m_bet(10), m_playerScore(0),_innerPlayerScore(0),m_countAcePlayer(0),
    m_dillerScore(0),_innerDillerScore(0),m_countAceDiller(0),tempImagePath(""),  m_result("")
{
    m_workDeck=m_mainDeck=Deck.m_deck;
    shuffleTheDeck();
}

void GameLogic::shuffleTheDeck()
{
    std::random_device random;
    std::mt19937 mersenne(random());
    shuffle(m_workDeck.begin(),m_workDeck.end(), mersenne);
}

void GameLogic::startGame()
{
    //at the start, everyone gets two cards
    for(int i=0; i<2;++i){
        PlayingCard card1=m_workDeck.back();
        m_workDeck.pop_back();
        // hide the second card
        if(i==1){
            tempImagePath=card1.m_imagePath;
            card1.m_imagePath="/cardIcon/ShirtCard.svg";
            modelViewDiller->addElement(card1);
        }else {
            modelViewDiller->addElement(card1);
        }
        _innerDillerScore+=card1.m_worth;
        if (card1.m_name==11){
            m_countAceDiller++;
        }

        PlayingCard card2=m_workDeck.back();
        m_workDeck.pop_back();
        modelViewPlayer->addElement(card2);
        _innerPlayerScore+=card2.m_worth;
        if (card2.m_worth==11){
            m_countAcePlayer++;
        }
    }

    m_playerScore=_innerPlayerScore;
    //recount the result if there are aces
    int tempCountAce{m_countAcePlayer};
    while(m_playerScore>21 && tempCountAce--)
    {
        m_playerScore-=10;
    }

    setDillerScore(_innerDillerScore);
    emit playerScoreChanged(m_playerScore);
}

void GameLogic::takeCard()
{
    //take cards and recount the result depending on the number of aces
    PlayingCard card=m_workDeck.back();
    m_workDeck.pop_back();
    modelViewPlayer->addElement(card);
    _innerPlayerScore+=card.m_worth;
    if (card.m_worth==11){
        m_countAcePlayer++;
    }
    m_playerScore=_innerPlayerScore;
    int tempCountAce{m_countAcePlayer};
    while(m_playerScore>21 && tempCountAce--)
    {
        m_playerScore-=10;
    }
    emit playerScoreChanged(m_playerScore);
}

void GameLogic::stopGame()
{
    //flip a hidden card
    modelViewDiller->changeSkirt(tempImagePath);
    //recount the result if there are aces
    int tempCountAce{m_countAceDiller};
    while(m_dillerScore>21 && tempCountAce--)
    {
        m_playerScore-=10;
    }
    //gain at least 17
    while(m_dillerScore<18||m_dillerScore<m_playerScore){
        if(m_dillerScore>=18&&m_playerScore>21){
            break;
        }
        PlayingCard card=m_workDeck.back();
        m_workDeck.pop_back();
        modelViewDiller->addElement(card);
        _innerDillerScore+=card.m_worth;
        if (card.m_worth==11){
            m_countAceDiller++;
        }
        m_dillerScore=_innerDillerScore;

        int tempCountAce{m_countAceDiller};
        while(m_dillerScore>21 && tempCountAce--)
        {
            m_dillerScore-=10;
        }
        emit dillerScoreChanged(m_dillerScore);
    }

    Result tempResult=Result::Lose;
    if ((m_playerScore>21&&m_dillerScore<=21)||(m_playerScore<m_dillerScore&&m_dillerScore<=21)){
        tempResult=Result::Lose;
    }
     else if(m_playerScore>21&&m_dillerScore>21){
        tempResult=Result::Busted;
    }
     else if(m_playerScore<=21&&(m_dillerScore<m_playerScore||m_dillerScore>21)) {
        tempResult=Result::Won;
    }
    else{
        tempResult=Result::Push;
    }

    switch (tempResult) {
    case Result::Lose:
    {
        m_result="You LOSE!";
        m_money-=m_bet;
        break;
    }
    case Result::Busted:
    {
        m_result="Busted both!";
        break;
    }
    case Result::Won:
    {
        m_money+=(m_bet*2);
        m_result="You WON!";
        break;
    }
    case Result::Push:
    {
        m_result="PUSH!";
        break;
    }
    }
    emit moneyChanged(m_money);
}

void GameLogic::restart()
{
    m_workDeck=m_mainDeck;
    m_bet=10;
    m_playerScore=0;
    _innerPlayerScore=0;
    m_countAcePlayer=0;
    m_dillerScore=0;
    _innerDillerScore=0;
    m_countAceDiller=0;
    m_result="";
    modelViewDiller->clearModel();
    modelViewPlayer->clearModel();

    emit betChanged(m_bet);
    emit playerScoreChanged(m_playerScore);
    emit dillerScoreChanged(m_dillerScore);
    emit resultChanged(m_result);

    shuffleTheDeck();
    startGame();
}

int GameLogic::getMoney() const
{
    return m_money;
}

int GameLogic::getBet() const
{
    return m_bet;
}

int GameLogic::getPlayerScore() const
{
    return m_playerScore;
}

int GameLogic::getDillerScore() const
{
    return m_dillerScore;
}

QString GameLogic::getResult() const
{
    return m_result;
}

void GameLogic::setMoney(int money)
{
    if (m_money == money)
        return;
    m_money = money;
    emit moneyChanged(m_money);
}

void GameLogic::setBet(int bet)
{
    if (m_bet == bet)
        return;
    m_bet = bet;
    emit betChanged(m_bet);
}

void GameLogic::setPlayerScore(int playerScore)
{
    if (m_playerScore == playerScore)
        return;
    m_playerScore = playerScore;
    emit playerScoreChanged(m_playerScore);
}

void GameLogic::setDillerScore(int dillerScore)
{
    if (m_dillerScore == dillerScore)
        return;
    m_dillerScore = dillerScore;
    emit dillerScoreChanged(m_dillerScore);
}

void GameLogic::setResult(QString result)
{
    if (m_result == result)
        return;
    m_result = result;
    emit resultChanged(m_result);
}

