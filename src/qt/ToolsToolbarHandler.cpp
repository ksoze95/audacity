#include <QDebug>
#include "ToolsToolbarHandler.h"

ToolsToolbarHandler::ToolsToolbarHandler(QObject *parent)
   : QObject(parent)
{
}

bool ToolsToolbarHandler::playing() const
{
   return m_isPlaying;
}

void ToolsToolbarHandler::setPlaying(bool state)
{
   if (m_isPlaying != state)
   {
      m_isPlaying = state;
      emit playStateChanged(m_isPlaying);
   }
}

void ToolsToolbarHandler::play()
{
   setPlaying(!playing());
   emit updateStatusBar(playing() ? "Play clicked" : "Pause clicked");
}

void ToolsToolbarHandler::stop()
{
   emit updateStatusBar("Stop clicked");
}

void ToolsToolbarHandler::rewind()
{
   emit updateStatusBar("Rewind clicked");
}

void ToolsToolbarHandler::fastForward()
{
   emit updateStatusBar("Fast forward clicked");
}

void ToolsToolbarHandler::record()
{
   emit updateStatusBar("Record clicked");
}

void ToolsToolbarHandler::loop()
{
   emit updateStatusBar("Loop clicked");
}

void ToolsToolbarHandler::automation()
{
   emit updateStatusBar("Automation clicked");
}

void ToolsToolbarHandler::zoomIn()
{
   emit updateStatusBar("Zoom in clicked");
}

void ToolsToolbarHandler::zoomOut()
{
   emit updateStatusBar("Zoom out clicked");
}

void ToolsToolbarHandler::fitSelection()
{
   emit updateStatusBar("Zoom fit to selection clicked");
}

void ToolsToolbarHandler::fitProject()
{
   emit updateStatusBar("Zoom fit to project clicked");
}

void ToolsToolbarHandler::zoomToggle()
{
   emit updateStatusBar("Zoom toggle clicked");
}

void ToolsToolbarHandler::trim()
{
   emit updateStatusBar("Trim clicked");
}

void ToolsToolbarHandler::silence()
{
   emit updateStatusBar("Silence clicked");
}

void ToolsToolbarHandler::setup()
{
   emit updateStatusBar("Setup clicked");
}
