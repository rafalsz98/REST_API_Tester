#include "get.h"

#include <QtDebug>

Get::Get()
{

}

void Get::run()
{
    if (reply != nullptr)
    {
        delete reply;
    }
    reply = networkManager.get(request);
}
