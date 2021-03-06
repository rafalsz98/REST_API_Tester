#ifndef UNITTEST_H
#define UNITTEST_H

#include <QList>
#include <QString>
#include <QMetaType>

#include "parameter.h"
#include "httpmethods.h"

struct UnitTest {
    int ID;
    QString IP;
    httpMethods method;
    QList<Parameter>* parameterList{};
    int resStatusCode;

    UnitTest(int ID, QString IP, httpMethods method, QList<Parameter>* parameterList, int resStatusCode) :
        ID(ID), IP(IP), method(method), parameterList(parameterList), resStatusCode(resStatusCode) {}
    UnitTest(int ID=0) :
        ID(ID), IP(""), method(httpMethods::GET), resStatusCode(0)
    {
        parameterList = new QList<Parameter>();
        parameterList->push_back({0, "", ""});
    }
};

Q_DECLARE_METATYPE(UnitTest)

#endif // UNITTEST_H

