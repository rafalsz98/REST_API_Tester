#include "parametersmodel.h"

ParametersModel::ParametersModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    list.push_back({"test", "abcdd"});
}

QModelIndex ParametersModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

QModelIndex ParametersModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int ParametersModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
    return list.length();
}

int ParametersModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ParametersModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto pair = list.at(index.row());
    switch (role) {
    case KeyRole:
        return QVariant(pair.first);
    case ValueRole:
        return QVariant(pair.second);
    }

    return QVariant();
}

bool ParametersModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto pair = list[index.row()];
        switch (role) {
        case KeyRole:
            list[index.row()].first = value.toString();
        case ValueRole:
            list[index.row()].second = value.toString();
        }

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ParametersModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void ParametersModel::insertRow()
{
    auto index = list.length() - 1;
    beginInsertRows(QModelIndex(), index, index);
    list.push_back({"", ""});
    endInsertRows();
}

void ParametersModel::removeRow(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    list.removeAt(row);
    endRemoveRows();
}

QHash<int, QByteArray> ParametersModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[KeyRole] = "key";
    names[ValueRole] = "value";
    return names;
}

QVector<QPair<QString, QString>> ParametersModel::getList()
{
    return list;
}
