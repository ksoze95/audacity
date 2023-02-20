#ifndef TOOLS_TOOLBAR_HANDLER_H
#define TOOLS_TOOLBAR_HANDLER_H

#include <QtCore/QObject>
#include <QtQml/qqmlregistration.h>

class ToolsToolbarHandler : public QObject
{
   Q_OBJECT
   QML_ELEMENT

   Q_PROPERTY(bool isPlaying READ playing WRITE setPlaying)

signals:
   void updateStatusBar(QString status);
   void playStateChanged(bool isPlaying);

public:
   explicit ToolsToolbarHandler(QObject* parent = nullptr);
   virtual ~ToolsToolbarHandler() = default;

   bool playing() const;
   void setPlaying(bool state);

public slots:
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
   void setup();

private:
   bool m_isPlaying{ false };
};

#endif
