#ifndef TOOLS_TOOLBAR_MODEL_H
#define TOOLS_TOOLBAR_MODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <qqml.h>
#include <QString>
#include <QVector>
#include <functional>
#include <utility>
#include "uicomponents/IconCode.h"

struct ToolsToolBarItem
{
   ToolsToolBarItem(IconCode::Code icon, QColor iconColor, std::function<void()> clickedMethod)
      : icon{ icon }
      , iconColor{ iconColor }
      , clickedMethod(std::move(clickedMethod))
   {
   }

   explicit ToolsToolBarItem(IconCode::Code icon, std::function<void()> clickedMethod)
      : ToolsToolBarItem(icon, QColor("black"), std::move(clickedMethod))
   {
   }

   IconCode::Code icon;
   QColor iconColor;
   std::function<void()> clickedMethod;
};

class ToolsToolBarModel : public QAbstractListModel
{
   Q_OBJECT
   QML_ELEMENT

public:
   explicit ToolsToolBarModel(QObject* parent = nullptr);

   QVariant data(const QModelIndex& parent, int role) const override;
   int rowCount(const QModelIndex& parent = QModelIndex()) const override;
   QHash<int, QByteArray> roleNames() const override;

   Q_INVOKABLE void play();
   Q_INVOKABLE void stop();
   Q_INVOKABLE void rewind();
   Q_INVOKABLE void fastForward();
   Q_INVOKABLE void record();
   Q_INVOKABLE void loop();
   Q_INVOKABLE void automation();
   Q_INVOKABLE void zoomIn();
   Q_INVOKABLE void zoomOut();
   Q_INVOKABLE void fitSelection();
   Q_INVOKABLE void fitProject();
   Q_INVOKABLE void zoomToggle();
   Q_INVOKABLE void trim();
   Q_INVOKABLE void silence();

private:
   enum Roles {
      IconRole = Qt::UserRole + 1,
      IconColorRole,
      ActionRole
   };

   QVector<ToolsToolBarItem> m_items;
};

#endif
