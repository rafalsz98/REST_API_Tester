#ifndef UNITTEST_H
#define UNITTEST_H

#include <QList>
#include <QString>
#include <QMetaType>

#include "parameter.h"

enum httpMethods{
    GET,
    POST,
    PUT,
    DELETE
};

struct UnitTest {
    int ID;
    QString IP;
    httpMethods method;
    QList<Parameter>* parameterList{};
    int resStatusCode;

    UnitTest(int ID, QString IP, httpMethods method, QList<Parameter>* parameterList, int resStatusCode) :
        ID(ID), IP(IP), method(method), parameterList(parameterList), resStatusCode(resStatusCode) {}
    UnitTest() :
        ID(0), IP(""), method(), resStatusCode(0)
    {
        parameterList = new QList<Parameter>();
        parameterList->push_back({0, "", ""});
    }
};

Q_DECLARE_METATYPE(UnitTest)
Q_DECLARE_METATYPE(httpMethods)

#endif // UNITTEST_H

