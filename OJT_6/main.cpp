#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <calculator.h>

int main(int argc, char *argv[])
{
    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Calculator 클래스를 동적으로 생성, 생성된 클래스를 QML 컨텍스트에 등록해 QML에서 클래스 객체에 접근
    Calculator *ca = new Calculator();
    engine.rootContext()->setContextProperty("Calculator", ca);

    return app.exec();
}
