#include <QtTest>
#include <QSignalSpy>

#include "post.h"

class PostTest : public QObject
{
    Q_OBJECT

private slots:
    void test_post()
    {
        Post post{};
        post.setUrl("https://httpbin.org/post");
//        post.addParameter("who", "Student");
//        post.addParameter("when", "today");
        post.run();

        QSignalSpy spy(&post,SIGNAL(replyReady()));
        QVERIFY(spy.wait(1000));

        QVERIFY(post.getUrl() == "https://httpbin.org/post" );

        QVERIFY(post.getStatusCode() == 200);
    }
};


QTEST_MAIN(PostTest)

#include "tst_posttest.moc"
