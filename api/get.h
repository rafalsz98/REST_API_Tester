#ifndef GET_H
#define GET_H

#include "restmethod.h"

class API_EXPORT Get : public RESTMethod
{
public:
    Get();
    void run();
};

#endif // GET_H
