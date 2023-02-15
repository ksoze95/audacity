#include "ToolsToolBarModel.h"

ToolsToolBarModel::ToolsToolBarModel(QObject *parent)
   : QAbstractListModel(parent)
{
   m_items << ToolsToolBarItem(IconCode::Code::SOLID_PLAY, QColor("#0F7745"), [this](){this->play();})
           << ToolsToolBarItem(IconCode::Code::SOLID_STOP, [this](){this->stop();})
           << ToolsToolBarItem(IconCode::Code::SOLID_REWIND, [this](){this->rewind();})
           << ToolsToolBarItem(IconCode::Code::SOLID_FAST_FORWARD, [this](){this->play();})
           << ToolsToolBarItem(IconCode::Code::SOLID_RECORD, QColor("#C54444"), [this](){this->record();})
           << ToolsToolBarItem(IconCode::Code::LOOP, [this](){this->loop();})
           << ToolsToolBarItem(IconCode::Code::AUTOMATION, [this](){this->automation();})
           << ToolsToolBarItem(IconCode::Code::ZOOM_IN, [this](){this->zoomIn();})
           << ToolsToolBarItem(IconCode::Code::ZOOM_OUT, [this](){this->zoomOut(); })
           << ToolsToolBarItem(IconCode::Code::ZOOM_FIT_SELECTION, [this](){this->fitSelection();})
           << ToolsToolBarItem(IconCode::Code::ZOOM_FIT_PROJECT, [this](){this->fitProject();})
           << ToolsToolBarItem(IconCode::Code::ZOOM_TOGGLE, [this](){this->zoomToggle();})
           << ToolsToolBarItem(IconCode::Code::TRIM, [this](){this->trim();})
           << ToolsToolBarItem(IconCode::Code::SILENCE, [this]() {this->silence();});
}

QVariant ToolsToolBarModel::data(const QModelIndex& index, int role) const
{
   if (!index.isValid() || index.row() >= rowCount())
      return QVariant();

   const ToolsToolBarItem& item = m_items[index.row()];

   if (role == IconRole)
      return static_cast<char16_t>(item.icon);
   else if (role == IconColorRole)
      return item.iconColor;

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
      { IconRole, "icon" },
      { IconColorRole, "iconColor" },
      { ActionRole, "action" }
   };

   return mapping;
}

Q_INVOKABLE void ToolsToolBarModel::play()
{
   qDebug() << "Play clicked";
}

Q_INVOKABLE void ToolsToolBarModel::stop()
{
   qDebug() << "Stop clicked";
}

Q_INVOKABLE void ToolsToolBarModel::rewind()
{
   qDebug() << "Rewind clicked";
}

Q_INVOKABLE void ToolsToolBarModel::fastForward()
{
   qDebug() << "Fast forward clicked";
}

Q_INVOKABLE void ToolsToolBarModel::record()
{
   qDebug() << "Record clicked";
}

Q_INVOKABLE void ToolsToolBarModel::loop()
{
   qDebug() << "Loop clicked";
}

Q_INVOKABLE void ToolsToolBarModel::automation()
{
   qDebug() << "Automation clicked";
}

Q_INVOKABLE void ToolsToolBarModel::zoomIn()
{
   qDebug() << "Automation clicked";
}

Q_INVOKABLE void ToolsToolBarModel::zoomOut()
{
   qDebug() << "Zoom out clicked";
}

Q_INVOKABLE void ToolsToolBarModel::fitSelection()
{
   qDebug() << "Zoom fit selection clicked";
}

Q_INVOKABLE void ToolsToolBarModel::fitProject()
{
   qDebug() << "Zoom fit project clicked";
}

Q_INVOKABLE void ToolsToolBarModel::zoomToggle()
{
   qDebug() << "Zoom toggle clicked";
}

Q_INVOKABLE void ToolsToolBarModel::trim()
{
   qDebug() << "Trim clicked";
}

Q_INVOKABLE void ToolsToolBarModel::silence()
{
   qDebug() << "Silence clicked";
}

