#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "parametermodel.h"
#include "delete.h"
#include "post.h"
#include "get.h"
#include "appmanager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<ParameterModel>("ParameterModel", 1, 0, "ParameterModel");
    qmlRegisterType<Get>("Get", 1, 0, "Get");
    qmlRegisterType<Delete>("Delete", 1, 0, "Delete");
    qmlRegisterType<Post>("Post", 1, 0, "Post");
    qmlRegisterUncreatableType<AppManager>("AppManager", 1, 0, "AppManager", QStringLiteral("Only one per app"));

    AppManager manager;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("AppManager"), &manager);
    engine.addImportPath("qrc:/components");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
