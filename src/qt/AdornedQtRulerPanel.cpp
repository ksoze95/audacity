#include <cassert>
#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <QtCore/QPoint>
#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtGui/QStaticText>
#include <QtGui/QWheelEvent>
#include <QtQml/QQmlContext>
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

   auto object = qmlContext(this)->objectForName("root");
   if (object == nullptr)
      return;

   const auto w = width();
   const auto h = height();

   const auto littleTick = h / 8;
   const auto bigTick = h / 4;
   const auto fullTick = h;

   QList<QLineF> ticks;
   QVector<QPair<int, QString>> values;

   double value{ 0.0 };
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

      if (ticks.count() % 2 == 0)
      {
         values.append(qMakePair(x + (values.count() % 5 == 0 ? 3 : 0), QString::number(value, 'f', 2)));
         value += m_increment;
      }

      ticks.append(QLineF(x, h - 1, x, h - 1 - tickLength));

      x += m_interval;
   }

   painter->save();

   auto font = object->property("textFont").value<QFont>();
   font.setPixelSize(12);

   for (qsizetype i = 0; i < values.count(); i++)
   {
      font.setBold(i % 5 == 0);

      painter->setFont(font);
      painter->drawText(QRectF(values[i].first, 0, w, h / 2), Qt::AlignLeft | Qt::AlignVCenter, values[i].second);
   }

   auto tickColor = object->property("separatorColor").value<QColor>();
   if (tickColor.isValid())
   {
      QPen pen = painter->pen();
      pen.setColor(tickColor);
      pen.setWidth(1);

      painter->setPen(pen);
      painter->drawLines(ticks);
   }

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
