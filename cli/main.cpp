#include <QCoreApplication>

#include "get.h"
#include "post.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //RESTMethod *method = new Get();
    //Get* get = static_cast<Get*>(method);
    //get->setUrl("https://reqbin.com/echo/get/json");
    //get->setUrl("https://www.google.com");
    //get->addParameter("name", "test");
    
    RESTMethod *method = new Post();
    Post* post = static_cast<Post*>(method);
    post->setUrl("https://httpbin.org/post");
    post->addParameter("who", "Student");
    post->addParameter("when", "today");


    method->run();

    return a.exec();
}
