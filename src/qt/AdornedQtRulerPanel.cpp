#include <cassert>
#include <QtCore/QDebug>
#include <QtCore/QList>
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

   auto w = width();
   auto h = height();

   auto littleTick = h / 8;
   auto bigTick = h / 4;

   QList<QLineF> ticks;

   int x = m_offset;
   while (x < w)
   {
      int tickLength = ticks.count() % 4 == 0 ? bigTick : littleTick;
      ticks.append(QLineF(x, h - 1, x, h - 1 - tickLength));
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
