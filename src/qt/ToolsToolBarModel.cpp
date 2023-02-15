#include <algorithm>
#include "ToolsToolBarModel.h"

ToolsToolBarModel::ToolsToolBarModel(QObject *parent)
   : QAbstractListModel(parent)
{
   m_items << ToolsToolBarItem("play", IconCode::Code::SOLID_PLAY, QColor("#0F7745"), [this](){ this->play(); })
           << ToolsToolBarItem("stop", IconCode::Code::SOLID_STOP, [this](){ this->stop(); })
           << ToolsToolBarItem("rewind", IconCode::Code::SOLID_REWIND, [this](){ this->rewind(); })
           << ToolsToolBarItem("fastForward", IconCode::Code::SOLID_FAST_FORWARD, [this](){ this->fastForward(); })
           << ToolsToolBarItem("record", IconCode::Code::SOLID_RECORD, QColor("#C54444"), [this](){ this->record(); })
           << ToolsToolBarItem("loop", IconCode::Code::LOOP, [this](){ this->loop(); })
           << ToolsToolBarItem("automation", IconCode::Code::AUTOMATION, [this](){ this->automation(); })
           << ToolsToolBarItem("zoomIn", IconCode::Code::ZOOM_IN, [this](){ this->zoomIn(); })
           << ToolsToolBarItem("zoomOut", IconCode::Code::ZOOM_OUT, [this](){ this->zoomOut(); })
           << ToolsToolBarItem("fitSelection", IconCode::Code::ZOOM_FIT_SELECTION, [this](){ this->fitSelection(); })
           << ToolsToolBarItem("fitProject", IconCode::Code::ZOOM_FIT_PROJECT, [this](){ this->fitProject(); })
           << ToolsToolBarItem("trim", IconCode::Code::TRIM, [this](){ this->trim(); })
           << ToolsToolBarItem("silence", IconCode::Code::SILENCE, [this](){ this->silence(); });
}

QVariant ToolsToolBarModel::data(const QModelIndex& index, int role) const
{
   if (!index.isValid() || index.row() >= rowCount())
      return QVariant();

   const ToolsToolBarItem& item = m_items[index.row()];

   switch (role)
   {
   case IdRole:
      return item.id;
   case IconRole:
      return static_cast<char16_t>(item.icon);
   case IconColorRole:
      return item.iconColor;
   }

   return QVariant();
}

int ToolsToolBarModel::rowCount(const QModelIndex& index) const
{
   if (index.isValid())
      return 0;

   return m_items.count();
}

QHash<int, QByteArray> ToolsToolBarModel::roleNames() const
{
   static QHash<int, QByteArray> mapping
   {
      { IdRole, "id" },
      { IconRole, "icon" },
      { IconColorRole, "iconColor" }
   };

   return mapping;
}

void ToolsToolBarModel::play()
{
   qDebug() << "Play clicked";
}

void ToolsToolBarModel::stop()
{
   qDebug() << "Stop clicked";
}

void ToolsToolBarModel::rewind()
{
   qDebug() << "Rewind clicked";
}

void ToolsToolBarModel::fastForward()
{
   qDebug() << "Fast forward clicked";
}

void ToolsToolBarModel::record()
{
   qDebug() << "Record clicked";
}

void ToolsToolBarModel::loop()
{
   qDebug() << "Loop clicked";
}

void ToolsToolBarModel::automation()
{
   qDebug() << "Automation clicked";
}

void ToolsToolBarModel::zoomIn()
{
   qDebug() << "Zoom in clicked";
}

void ToolsToolBarModel::zoomOut()
{
   qDebug() << "Zoom out clicked";
}

void ToolsToolBarModel::fitSelection()
{
   qDebug() << "Zoom fit to selection clicked";
}

void ToolsToolBarModel::fitProject()
{
   qDebug() << "Zoom fit to project clicked";
}

void ToolsToolBarModel::zoomToggle()
{
   qDebug() << "Zoom toggle clicked";
}

void ToolsToolBarModel::trim()
{
   qDebug() << "Trim clicked";
}

void ToolsToolBarModel::silence()
{
   qDebug() << "Silence clicked";
}

void ToolsToolBarModel::handleClickEvent(QString id)
{
   auto it = std::find_if(m_items.begin(), m_items.end(), [&id](auto& item){ return item.id == id; });
   if (it != m_items.end())
   {
      if (it->handleClicked)
         it->handleClicked();
   }
}
