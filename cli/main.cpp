#include <QCoreApplication>

#include "get.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RESTMethod *method = new Get();
    Get* get = static_cast<Get*>(method);
    get->setUrl("https://google.com/");
    get->addParameter("name", "test");


    method->run();

    return a.exec();
}
