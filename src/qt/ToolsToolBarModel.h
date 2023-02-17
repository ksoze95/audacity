#ifndef TOOLS_TOOLBAR_MODEL_H
#define TOOLS_TOOLBAR_MODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <qqml.h>
#include <QString>
#include <QVector>
#include <utility>
#include "uicomponents/IconCode.h"

struct ToolsToolBarItem
{
   ToolsToolBarItem(QString id, IconCode::Code icon, QColor iconColor, std::function<void()> handleClicked = std::function<void()>())
      : id{ id }
      , icon{ icon }
      , iconColor{ iconColor }
      , handleClicked( std::move(handleClicked) )
   {
   }

   explicit ToolsToolBarItem(QString id, IconCode::Code icon, std::function<void()> handleClicked = std::function<void()>())
      : ToolsToolBarItem(id, icon, QColor("black"), std::move(handleClicked))
   {
   }

   QString id;
   IconCode::Code icon;
   QColor iconColor;
   int width{ 32 };
   int height{ 32 };
   std::function<void()> handleClicked;
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

   Q_INVOKABLE void handleClickEvent(QString id);

private:
    void play();
    void stop();
    void rewind();
    void fastForward();
    void record();
    void loop();
    void automation();
    void zoomIn();
    void zoomOut();
    void fitSelection();
    void fitProject();
    void zoomToggle();
    void trim();
    void silence();

private:
   enum Roles {
      IdRole = Qt::UserRole + 1,
      IconRole,
      IconColorRole
   };

   QVector<ToolsToolBarItem> m_items;
};

#endif
