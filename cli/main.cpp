#include <QCoreApplication>

#include "get.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Get get{};
    get.setUrl("https://google.com/");
    get.addParameter("name", "test");
    //get.removeParameter(0);
    get.run();



    return a.exec();
}
