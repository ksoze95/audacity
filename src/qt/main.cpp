/*  SPDX-License-Identifier: GPL-2.0-or-later */

#include <QtCore/QDebug>
#include <QtGui/QFontDatabase>
#include <QtQml/QQmlApplicationEngine>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);
   QQmlApplicationEngine engine;

   int status = QFontDatabase::addApplicationFont(":/fonts/AudacityIcon.ttf");
   if (status != 0)
   {
      qDebug() << "Unable add AudacityIcon.ttf application font";
      return -1;
   }

   engine.load("qrc:/qml/main.qml");

   if (engine.rootObjects().isEmpty())
   {
      qDebug() << "Unable to load main.qml";
      return -1;
   }

   return app.exec();
}
