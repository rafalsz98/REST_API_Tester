#include <QtTest>
#include <QSignalSpy>
#include <QVariant>
#include <QList>

#include "get.h"
#include "parameter.h"

class GetTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void test_get()
    {
        Get get{};
        get.setUrl("https://reqbin.com/echo/get/json");

        Parameter param1 = {0, "status", "student"};
        Parameter param2 = {1, "when", "today"};

        QVariant qparam1, qparam2;
        qparam1.setValue(param1);
        qparam2.setValue(param2);

        QList<QVariant> qlist = {qparam1, qparam2};

        QVariant var;
        var.setValue(qlist);

        get.parseParameters(var);

        get.run();

        QSignalSpy spy(&get,SIGNAL(replyReady()));
        QVERIFY(spy.wait(2000));

        QVERIFY(get.getUrl() == "https://reqbin.com/echo/get/json" );

        QVERIFY(get.getStatusCode() == 200);

        QVERIFY(get.getBody() == "{\"success\":\"true\"}\n");
    }

};

QTEST_MAIN(GetTest)

#include "tst_gettest.moc"
