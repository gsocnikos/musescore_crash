#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStandardPaths>



#include "crash_handler.h"


int buggyFunc() {
    delete reinterpret_cast<QString*>(0xFEE1DEAD);
    return 0;
}



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Breakpad::CrashHandler::instance()->Init(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Breakpad::AnnotateCrashReport("testKey","testData");

    if (engine.rootObjects().isEmpty())
        return -1;

    buggyFunc();

    return app.exec();
}
