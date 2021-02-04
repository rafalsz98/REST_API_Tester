#ifndef UNITTESTMODEL_H
#define UNITTESTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QString>
#include <QByteArray>
#include "unittest.h"
#include "unittestmanager.h"

class UnitTestModel : public QAbstractListModel
{
    Q_OBJECT
    QList<UnitTest>* list;
    int currentId = 1;
    UnitTestManager* unitTestManager = &UnitTestManager::instance();
public:
    explicit UnitTestModel(QObject *parent = nullptr);

    enum {
        IDRole = Qt::UserRole,
        IPRole,
        MethodRole,
        ResStatusCodeRole
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
    void insertParameterRow(const int index);
    void clearRow();
    int parametersCount(const int index);
    void clearParameterRow(const int index);
    void setParameter(const int testIndex, const int paramIndex, const int col, const QString data);
    QString getParameter(const int testIndex, const int paramIndex, const int col);

    QVariant getList();
};

#endif // UNITTESTMODEL_H
