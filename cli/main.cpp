#include <QCoreApplication>

#include "get.h"
#include "delete.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    RESTMethod *method = new Get();
//    Get* get = static_cast<Get*>(method);
//    get->setUrl("https://reqbin.com/echo/get/json");
//    //get->setUrl("https://www.google.com");
//    get->addParameter("name", "test");


//    method->run();

    Delete del;
    del.setUrl("https://reqbin.com/");
    del.setParameter("sample");
//    del->setParameter("doesnwork");
    del.run();


    return a.exec();
}
