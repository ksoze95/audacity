/*  SPDX-License-Identifier: GPL-2.0-or-later */

#include <QtCore/QDebug>
#include <QtGui/QFontDatabase>
#include <QtQml/QQmlApplicationEngine>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);
   QQmlApplicationEngine engine;

   engine.load("qrc:/qml/main.qml");

   if (engine.rootObjects().isEmpty())
   {
      qDebug() << "Unable to load main.qml";
      return -1;
   }

   return app.exec();
}
