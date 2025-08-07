#include "mainwindow.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QtGui>
#include <QtQuick3D/qquick3d.h>
#include <QApplication>
#include <QWebEngineView>
#include <QUrl>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
   /* ScreenRecorder recorder(10, "output.avi");
    recorder.start();

    // Run the application for 10 seconds, then stop recording
    QTimer::singleShot(10000, &app, &QApplication::quit);  */

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat());

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/model_cansat.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/mapnew.qml")));



    if (engine.rootObjects().isEmpty())
        return -1;







    QApplication a(argc, argv);
    MainWindow w;

     w.showFullScreen();
    w.show();
    return a.exec();
}
