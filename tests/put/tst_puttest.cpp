#include <QtTest>
#include <QSignalSpy>
#include <QVariant>
#include <QList>

#include "put.h"
#include "parameter.h"

class PutTest : public QObject
{
    Q_OBJECT

private slots:
    void test_put()
    {
        Put put{};
        put.setUrl("https://reqres.in/api/users/2");

        Parameter param1 = {0, "name", "Tomasz"};
        Parameter param2 = {1, "job", "Sklepikarz"};

        QVariant qparam1, qparam2;
        qparam1.setValue(param1);
        qparam2.setValue(param2);

        QList<QVariant> qlist = {qparam1, qparam2};

        QVariant var;
        var.setValue(qlist);

        put.parseParameters(var);

        put.run();

        QSignalSpy spy(&put,SIGNAL(replyReady()));
        QVERIFY(spy.wait(2000));

        QVERIFY(put.getUrl() == "https://reqres.in/api/users/2" );

        QVERIFY(put.getStatusCode() == 200);
    }
};


QTEST_MAIN(PutTest)

#include "tst_puttest.moc"
