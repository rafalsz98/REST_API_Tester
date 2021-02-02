#ifndef HTTPMETHODS_H
#define HTTPMETHODS_H

#include <QMetaType>

enum class httpMethods
{
    GET,
    POST,
    PUT,
    DELETE
};

Q_DECLARE_METATYPE(httpMethods)

#endif // HTTPMETHODS_H
