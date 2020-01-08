#include "modelcard.h"

ModelCard::ModelCard()
{

}


QHash<int, QByteArray> ModelCard::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Name] = "name";
    roles[Suit] = "suit";
    roles[Worth] = "worth";
    roles[imagePath] = "imagePath";
    return roles;
}

int ModelCard::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return static_cast<int>(Cards.size());
}

QVariant ModelCard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    switch (role) {
    case Name:
        return Cards[index.row()].m_name;
    case Suit:
        return Cards[index.row()].m_suit;
    case Worth:
        return Cards[index.row()].m_worth;
    case imagePath:
        return Cards[index.row()].m_imagePath;
    default:
        return QVariant();
    }

}

void ModelCard::deleteElement()
{
    beginRemoveRows(QModelIndex(), Cards.size()-1, Cards.size()-1);
    Cards.pop_back();
    endRemoveRows();

    QModelIndex index = createIndex(0, Cards.size(), static_cast<void *>(nullptr));
    emit dataChanged(index, index);
}

void ModelCard::changeSkirt(QString path)
{
        beginResetModel();
        Cards[1].m_imagePath=path;
        endResetModel();
}

void ModelCard::clearModel()
{
    beginResetModel();
    Cards.clear();
    endResetModel();
}


void ModelCard::addElement(PlayingCard card)
{
    beginInsertRows(QModelIndex(), Cards.size(), Cards.size());

    Cards.push_back(card);
    endInsertRows();

    QModelIndex index = createIndex(0, 0, static_cast<void *>(nullptr));
    emit dataChanged(index, index);
}
