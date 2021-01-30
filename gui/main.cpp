#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "parametersmodel.h"
#include "delete.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<ParametersModel>("ParametersModel", 1, 0, "ParametersModel");
    qmlRegisterType<Delete>("Delete", 1, 0, "Delete");

    QQmlApplicationEngine engine;
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
