#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include <QMetaType>

struct Parameter {
    int ID;
    QString key;
    QString value;
    Parameter(int ID, QString key, QString value) :
        ID(ID), key(key), value(value) {}
    Parameter() :
        ID(0), key(""), value("") {}
};

Q_DECLARE_METATYPE(Parameter)

#endif // PARAMETER_H
