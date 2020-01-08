#include "carddeck.h"

CardDeck::CardDeck():m_deck(52)
{
    makeDeck();
}

void CardDeck::makeDeck()
{
    domXml();
    for(unsigned long long i=0;i<52;++i){
        m_deck[i].m_name=m_nameList[i];
        m_deck[i].m_suit=m_suitList[i];
        m_deck[i].m_worth=(m_worthList[i]).toInt();
        m_deck[i].m_imagePath="/cardIcon"+m_imagePathList[i]+".svg";
    }
}

void CardDeck::domXml()
{
    QFile fileXml(":/CardResource/XMLFile.xml");
    QDomDocument domDoc;    
    if (fileXml.open(QIODevice::ReadOnly))
    {
        if(domDoc.setContent(&fileXml)){
            QDomElement domEl=domDoc.documentElement();
            readXml(domEl);
        }
        fileXml.close();
    }
}

void CardDeck::readXml(QDomNode &node)
{
    QDomNode nodeXML=node.firstChild();
    while(!nodeXML.isNull()){
        if(nodeXML.isElement()){
            QDomElement domEl=nodeXML.toElement();
            if(!domEl.isNull()){
                if(domEl.tagName()=="name"){
                    m_nameList.push_back(domEl.text());
                }
                if(domEl.tagName()=="suit"){
                    m_suitList.push_back(domEl.text());
                }
                if(domEl.tagName()=="worth"){
                    m_worthList.push_back(domEl.text());
                }
                if(domEl.tagName()=="pathImage"){
                    m_imagePathList.push_back(domEl.text());
                }
            }
        }
        readXml(nodeXML);
        nodeXML=nodeXML.nextSibling();
    }
}
