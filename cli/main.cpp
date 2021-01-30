#include <QCoreApplication>

#include "get.h"
#include "post.h"
#include "delete.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TODO: :(((

    //RESTMethod *method = new Get();
    //Get* get = static_cast<Get*>(method);
    //get->setUrl("https://reqbin.com/echo/get/json");
    //get->setUrl("https://www.google.com");
    //get->addParameter("name", "test");
    
//     RESTMethod *method = new Post();
//     Post* post = static_cast<Post*>(method);
//     post->setUrl("https://httpbin.org/post");
//     post->addParameter("who", "Student");
//     post->addParameter("when", "today");
// //    RESTMethod *method = new Get();
// //    Get* get = static_cast<Get*>(method);
// //    get->setUrl("https://reqbin.com/echo/get/json");
// //    //get->setUrl("https://www.google.com");
// //    get->addParameter("name", "test");


// //    method->run();

//     Delete del;
//     del.setUrl("https://reqbin.com/");
//     del.setParameter("sample");
//     del->setParameter("doesnwork");
//     del.run();


    return a.exec();
}
