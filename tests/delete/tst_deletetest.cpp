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
        Delete del{};
        del.setUrl("https://reqbin.com/");
        del.setParameter("sample");
        del.run();

        QSignalSpy spy(&del,SIGNAL(replyReady()));

        QVERIFY(spy.wait(1000));

        QVERIFY(del.getBody() == "{\"success\":\"true\"}\n");
        QVERIFY(del.getUrl() == "https://reqbin.com/sample/delete/json" );
        QVERIFY(del.getHeaders() == "");
        QVERIFY(del.getStatusCode() == 200);
    }
};

QTEST_MAIN(DeleteTest)

#include "tst_deletetest.moc"
