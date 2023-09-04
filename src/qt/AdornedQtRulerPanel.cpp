#include <cassert>
#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <QtCore/QString>
#include <QtGui/QPainter>
#include <QtGui/QWheelEvent>
#include "AdornedQtRulerPanel.h"

AdornedQtRulerPanel::AdornedQtRulerPanel(QQuickItem *parent)
   : QQuickPaintedItem(parent)
{
}

void AdornedQtRulerPanel::paint(QPainter *painter)
{
   assert(painter != nullptr);
   if (painter == nullptr)
      return;

   const auto w = width();
   const auto h = height();

   const auto littleTick = h / 8;
   const auto bigTick = h / 4;
   const auto fullTick = h;

   QList<QLineF> ticks;

   int x = m_offset;
   while (x < w)
   {
      const int count = ticks.count();

      const int tickLength = [&]() {
         if (count % 10 == 0)
            return fullTick;
         else if (count % 2 == 0)
            return bigTick;
         else
            return littleTick;
      }();

      ticks.append(QLineF(x, h - 1, x, h - 1 - tickLength));
      x += m_interval;
   }

   qDebug() << "================> ticks.count()" << ticks.count();

   QList<QPair<QLineF, QString>> values;
   double value{ 0 };

   int index = 1;

   x = m_offset;
   while (x < w)
   {
      auto foobar = x + values.count() % 10 ? 3 : 0;
      qDebug() << "=========================>" << index << foobar << QString::number(value, 'f', 2);
      value += 0.01;
      index++;
      x += m_interval;
   }

   painter->save();

   QPen pen = painter->pen();
   pen.setColor("green");
   pen.setWidth(1);
   painter->setPen(pen);

   painter->drawLines(ticks);
   painter->restore();
}

int AdornedQtRulerPanel::Offset() const
{
   return m_offset;
}

void AdornedQtRulerPanel::SetOffset(int offset)
{
   if (m_offset != offset)
   {
      m_offset = offset;
      update();
      emit offsetChanged();
   }
}

void AdornedQtRulerPanel::ZoomIn()
{
   m_interval += 4;
   update();
}

void AdornedQtRulerPanel::ZoomOut()
{
   m_interval -= 4;
   if (m_interval < 1)
      m_interval = 4;

   update();
}

void AdornedQtRulerPanel::wheelEvent(QWheelEvent *event)
{
   assert(event != nullptr);

   if (event->angleDelta().y() > 0)
   {
      m_interval += 4;
   }
   else
   {
      m_interval -= 4;
      if (m_interval < 1)
         m_interval = 4;
   }

   update();
}
