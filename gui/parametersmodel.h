#ifndef PARAMETERSMODEL_H
#define PARAMETERSMODEL_H

#include <QAbstractItemModel>
#include <QVector>
#include <QString>
#include <QPair>
#include <QByteArray>

class ParametersModel : public QAbstractItemModel
{
    Q_OBJECT
    QVector<QPair<QString, QString>> list{{"", ""}};

public:
    explicit ParametersModel(QObject *parent = nullptr);

    enum {
        KeyRole = Qt::UserRole,
        ValueRole
    };

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    void insertRow();

    // Remove data:
    void removeRow(int row);

    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    QVector<QPair<QString, QString>> getList();
};

#endif // PARAMETERSMODEL_H
