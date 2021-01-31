#ifndef PARAMETERMODEL_H
#define PARAMETERMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QString>
#include <QByteArray>
#include "Parameter.h"

class ParameterModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Parameter> list{{0, "", ""}};
    int currentId = 1;
public:
    explicit ParameterModel(QObject *parent = nullptr);

    enum {
        IDRole = Qt::UserRole,
        KeyRole,
        ValueRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void insertRow();

    void clearRows();

    QVariant getList();
};

#endif // PARAMETERMODEL_H
