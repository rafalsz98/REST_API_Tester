#ifndef UNITTESTMANAGER_H
#define UNITTESTMANAGER_H

#include <QObject>
#include <QPair>
#include <QVariant>
#include "unittest.h"
#include "get.h"
#include "post.h"
#include "put.h"
#include "delete.h"

class UnitTestManager : public QObject
{
    Q_OBJECT
public:
    static UnitTestManager& instance();
    void addUnitTest();
    void clearUnitTests();


signals:
    void finished();

public slots:
    void replyReady();
    QVariantList getUnitTestResults();
    void runTests(QVariant list);

private:
    UnitTestManager() {addUnitTest();}

    void processReplies();

    int replyCount = 0;
    int replyMax = 1;

    QList<int> m_unitTestResults;
    QList<QPair<RESTMethod*, int>> allocatedMethods;
};

#endif // UNITTESTMANAGER_H
