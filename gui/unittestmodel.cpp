#include "unittestmodel.h"

UnitTestModel::UnitTestModel(QObject *parent)
    : QAbstractListModel(parent)
{
    list = new QList<UnitTest>();
    list->push_back(UnitTest{});
}

int UnitTestModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return list->length();
}

QVariant UnitTestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto parameter = list->at(index.row());
    switch (role) {
    case IDRole:
        return QVariant(parameter.ID);
    case IPRole:
        return QVariant(parameter.IP);
    case MethodRole:
        return QVariant::fromValue(parameter.method);
    case ResStatusCodeRole:
        return QVariant(parameter.resStatusCode);
    }

    return QVariant();
}

bool UnitTestModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        UnitTest unitTest{list->at(index.row())};
        switch (role) {
        case IPRole:
            unitTest.IP = value.toString();
        case MethodRole:
            unitTest.method = value.value<httpMethods>();
        case ResStatusCodeRole:
            unitTest.resStatusCode = value.toInt();
        }
        list->replace(index.row(), unitTest);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags UnitTestModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> UnitTestModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IDRole] = "id";
    names[IPRole] = "ip";
    names[MethodRole] = "method";
    names[ResStatusCodeRole] = "resStatusCode";
    return names;
}

void UnitTestModel::insertRow()
{
    auto index = list->length();
    beginInsertRows(QModelIndex(), index, index);
    list->push_back(UnitTest{index});
    unitTestManager->addUnitTest();
    endInsertRows();
}

void UnitTestModel::insertParameterRow(const int listIndex)
{
    QModelIndex left=index(listIndex,listIndex);

    auto id= list->at(listIndex).parameterList->length();
    list->at(listIndex).parameterList->push_back({id, "", ""});

    emit layoutChanged();
    emit dataChanged(left,left);
}

void UnitTestModel::clearRow()
{
    beginRemoveRows(QModelIndex(), 0, list->length() - 1);
    list->clear();
    unitTestManager->clearUnitTests();
    unitTestManager->addUnitTest();
    endRemoveRows();
    insertRow();
}

int UnitTestModel::parametersCount(const int index)
{
    return list->at(index).parameterList->length();
}

void UnitTestModel::clearParameterRow(const int listIndex)
{
    QModelIndex left=index(listIndex,listIndex);

    list->at(listIndex).parameterList->clear();
    list->at(listIndex).parameterList->push_back({list->length(), "", ""});

    emit layoutChanged();
    emit dataChanged(left,left);
}

void UnitTestModel::setParameter(const int testIndex, const int paramIndex, const int col, const QString data)
{
    Parameter param{list->at(testIndex).parameterList->at(paramIndex)};

    if(col==0)
        param.key = data;
    else if(col==1)
        param.value = data;

    list->at(testIndex).parameterList->replace(paramIndex, param);
}

QString UnitTestModel::getParameter(const int testIndex, const int paramIndex, const int col)
{
    Parameter param{list->at(testIndex).parameterList->at(paramIndex)};

    return (col==1)?param.value:param.key;
}

QVariant UnitTestModel::getList()
{
    QVariant var;
    var.setValue(*list);
    return var;
}








