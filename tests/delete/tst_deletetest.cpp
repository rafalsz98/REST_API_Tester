#include <QTest>
#include <QSignalSpy>

#include "delete.h"

class DeleteTest : public QObject
{
    Q_OBJECT

public:

private slots:
    void test()
    {
        Parameter par{0,"sample",""};
        QVariant qv,parameters;
        QList<QVariant> list;
        qv.setValue(par);
        list.append(qv);
        parameters.setValue(list);

        Delete del{};
        del.setUrl("https://reqbin.com/");
        del.parseParameters(parameters);

        QSignalSpy spy(&del,SIGNAL(replyReady()));

        del.run();

        QVERIFY(spy.wait(1000));

        QVERIFY(del.getBody() == "{\"success\":\"true\"}\n");
        QVERIFY(del.getUrl() == "https://reqbin.com/sample/delete/json" );
        QVERIFY(del.getStatusCode() == 200);
    }
};

QTEST_MAIN(DeleteTest)

#include "tst_deletetest.moc"
