/*  SPDX-License-Identifier: GPL-2.0-or-later */

#include <QtQml>
#include <QtWidgets/QApplication>
#include <QtGui/QSurfaceFormat>
#include <QtDebug>
#include <QFileInfo>
#include "NewAudacity.h"

int main(int argc, char *argv[])
{
#if !defined(Q_OS_WIN) && !defined(Q_OS_DARWIN)
   QFileInfo info(argv[0]);

   QString qtLibDir = info.dir().path() + "/../lib/audacity/qt";
   QCoreApplication::addLibraryPath(qtLibDir);
   qDebug() << qtLibDir;
#endif

   QApplication app(argc, argv);
   QQmlApplicationEngine engine;

   NewAudacity new_audacity;
   engine.rootContext()->setContextProperty("new_audacity", &new_audacity);

#if defined(Q_OS_WIN)
   engine.addImportPath(QGuiApplication::applicationDirPath() + "/qml");
#elif defined(Q_OS_DARWIN)
   engine.addImportPath(QGuiApplication::applicationDirPath() + "/../PlugIns/qml");
#else
   engine.addImportPath(qtLibDir + "/qml");
#endif

   engine.load("qrc:/qml/main.qml");

   if (engine.rootObjects().isEmpty())
      return -1;

   return app.exec();
}
