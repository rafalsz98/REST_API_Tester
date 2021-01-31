#include <QCoreApplication>
#include <QTextStream>
#include <QObject>

#include "get.h"
#include "post.h"
#include "delete.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString IP;
    QString method;
    RESTMethod* rest_method;

    QTextStream(stdout)<< "REST API TESTER\n\nEnter IP : \n";
    QTextStream(stdin) >> IP;
    QTextStream(stdout)<< "\nChoose RESTmethod :\nGET\nPOST\nDELETE\nPUT\n";
    QTextStream(stdin) >> method;

    if(method=="DELETE")
    {
        QTextStream(stdout)<< "\nSet parameter : \n";

        Parameter par;
        QVariant qv,parameters;
        QList<QVariant> list;

        QTextStream(stdin) >> par.key;
        qv.setValue(par);
        list.append(qv);
        parameters.setValue(list);

        rest_method=new Delete();
        rest_method->parseParameters(parameters);
    }
    else if (method=="GET" ||method=="POST" ||method=="PUT"  )
    {
        QTextStream(stdout)<< "\nSet parameters \n<key>\n<value>\n[optional]end\n";

        QList<QVariant> list;
        for(int i=0;;i++)
        {
            Parameter par;
            QVariant qv;

            par.ID=i;
            QTextStream(stdin) >> par.key;
            QTextStream(stdin) >> par.value;
            qv.setValue(par);
            list.append(qv);

            QString end;
            QTextStream(stdin) >> end;
            if(end=="end")break;
        }

        QVariant parameters;
        parameters.setValue(list);

        if(method=="GET")
            rest_method=new Get();
        else if(method=="PUT")
            rest_method=new Put();
        else
            rest_method=new Post();

        rest_method->parseParameters(parameters);
    }
    else
    {
        QTextStream(stderr)<< "\nWrong method\n\n";
        return 1;
    }

    QEventLoop loop;
    QObject::connect(rest_method,SIGNAL(replyReady()),&loop,SLOT(quit()));

    rest_method->setUrl(IP);
    rest_method->run();

    loop.exec();

    QTextStream(stdout)<< "\n\nSTATUS CODE : \n" << rest_method->getStatusCode()\
                       << "\n\n\nHEADERS: \n" << rest_method->getHeaders()\
                       <<"\n\nBODY: \n" <<rest_method->getBody();

    delete rest_method;


    return a.exec();
}































