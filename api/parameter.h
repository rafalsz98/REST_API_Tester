#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>

struct Parameter {
    int ID;
    QString key;
    QString value;
    Parameter(int ID, QString key, QString value) :
        ID(ID), key(key), value(value) {}
};

#endif // PARAMETER_H
