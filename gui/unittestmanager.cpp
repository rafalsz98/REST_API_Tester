#include "unittestmanager.h"

#include <QtDebug>

UnitTestManager &UnitTestManager::instance()
{
    static UnitTestManager instance{};
    return instance;
}

void UnitTestManager::addUnitTest()
{
    m_unitTestResults.append(-1);
}

void UnitTestManager::clearUnitTests()
{
    m_unitTestResults.clear();
}

void UnitTestManager::replyReady()
{
    replyCount++;
    if (replyCount >= replyMax) {
        processReplies();
    }
}

QVariantList UnitTestManager::getUnitTestResults() {
    QVariantList result;
    foreach(int el, m_unitTestResults) {
        QVariant var{el};
        result.append(var);
    }
    return result;
}

void UnitTestManager::runTests(QVariant list)
{
    QList<QVariant> unitTestList = list.toList();
    replyMax = unitTestList.length();
    replyCount = 0;
    foreach(const QVariant& unitTestVar, unitTestList) {
        UnitTest unitTest = unitTestVar.value<UnitTest>();

        QList<QVariant> parametersList;
        foreach(Parameter parameter, *unitTest.parameterList) {
            QVariant parameterVar;
            parameterVar.setValue(parameter);
            parametersList.append(parameterVar);
        }

        QVariant parameters;
        parameters.setValue(parametersList);
        RESTMethod* method = nullptr;

        switch (unitTest.method) {
        case httpMethods::GET:
            method = new Get();
            break;
        case httpMethods::POST:
            qDebug() << "post";
            method = new Post();
            break;
        case httpMethods::PUT:
            method = new Put();
            break;
        case httpMethods::DELETE:
            method = new Delete();
            break;
        }

        connect(method, SIGNAL(replyReady()), this, SLOT(replyReady()));
        allocatedMethods.append({method, unitTest.resStatusCode});

        method->setUrl(unitTest.IP);
        method->parseParameters(parameters);
        method->run();
    }

}

void UnitTestManager::processReplies()
{
    qDebug() << "All replies ready!";
    int i = 0;
    foreach(auto pair, allocatedMethods) {
        qDebug() << pair.second << pair.first->getStatusCode();
        m_unitTestResults[i] = pair.second == pair.first->getStatusCode()
                ? 0
                : 1;
        i++;
    }
    allocatedMethods.clear();
    qDebug() << m_unitTestResults;
    emit finished();
}
