#include "parametermodel.h"

ParameterModel::ParameterModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ParameterModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return list.length();
}

QVariant ParameterModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto parameter = list.at(index.row());
    switch (role) {
    case IDRole:
        return QVariant(parameter.ID);
    case KeyRole:
        return QVariant(parameter.key);
    case ValueRole:
        return QVariant(parameter.value);
    }

    return QVariant();
}

bool ParameterModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        Parameter parameter{list.at(index.row())};
        switch (role) {
        case KeyRole:
            parameter.key = value.toString();
        case ValueRole:
            parameter.value = value.toString();
        }
        list.replace(index.row(), parameter);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ParameterModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void ParameterModel::insertRow()
{
    auto index = list.length() - 1;
    beginInsertRows(QModelIndex(), index, index);
    list.push_back({index + 1, "", ""});
    endInsertRows();
}

void ParameterModel::removeRow(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    list.removeAt(row);
    endRemoveRows();
}

QHash<int, QByteArray> ParameterModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IDRole] = "id";
    names[KeyRole] = "key";
    names[ValueRole] = "value";
    return names;
}

QList<Parameter> ParameterModel::getList()
{
    return list;
}
