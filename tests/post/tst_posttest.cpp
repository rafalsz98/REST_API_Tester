#include <QtTest>
#include <QSignalSpy>
#include <QVariant>
#include <QList>

#include "post.h"
#include "parameter.h"

class PostTest : public QObject
{
    Q_OBJECT

private slots:
    void test_post()
    {
        Post post{};
        post.setUrl("https://httpbin.org/post");

        Parameter param1 = {0, "status", "student"};
        Parameter param2 = {1, "when", "today"};

        QVariant qparam1, qparam2;
        qparam1.setValue(param1);
        qparam2.setValue(param2);

        QList<QVariant> qlist = {qparam1, qparam2};

        QVariant var;
        var.setValue(qlist);

        post.parseParameters(var);

        post.run();

        QSignalSpy spy(&post,SIGNAL(replyReady()));
        QVERIFY(spy.wait(2000));

        QVERIFY(post.getUrl() == "https://httpbin.org/post" );

        QVERIFY(post.getStatusCode() == 200);
    }
};


QTEST_MAIN(PostTest)

#include "tst_posttest.moc"
