#include <QFontDatabase>
#include "ApplicationConfiguration.h"

namespace {
   QMap<QString, QFont> applicationFonts;

   void LoadApplicationFont(const QString& filename)
   {
      if (applicationFonts.contains(filename))
         return;

      auto id = QFontDatabase::addApplicationFont(filename);
      if (id == -1)
         return;

      auto family = QFontDatabase::applicationFontFamilies(id).at(0);
      applicationFonts.insert(filename, QFont(family));
   }

   QFont GetApplicationFont(const QString& filename)
   {
      LoadApplicationFont(filename);
      return applicationFonts[filename];
   }
}

ApplicationConfiguration::ApplicationConfiguration()
{
   m_iconFont = GetApplicationFont(":/fonts/AudacityIcon.ttf");
   m_bodyFont = GetApplicationFont(":/fonts/Inter-Regular.ttf");
}
                                                                        
QFont ApplicationConfiguration::iconFont() const
{
   return m_iconFont;
}

void ApplicationConfiguration::setIconFont(const QFont& font)
{
   if (m_iconFont != font)
   {
      m_iconFont = font;
      emit themeChanged();
   }
}

QFont ApplicationConfiguration::bodyFont() const
{
   return m_bodyFont;
}

void ApplicationConfiguration::setBodyFont(const QFont& font)
{
   if (m_bodyFont == font)
   {
      m_bodyFont = font;
      emit themeChanged();
   }
}

QColor ApplicationConfiguration::buttonColor() const
{
   return m_buttonColor;
}

void ApplicationConfiguration::setButtonColor(const QColor& color)
{
   if (m_buttonColor != color)
   {
      m_buttonColor = color;
      emit themeChanged();
   }
}

QColor ApplicationConfiguration::accentColor() const
{
   return m_accentColor;
}

void ApplicationConfiguration::setAccentColor(const QColor& color)
{
   if (m_accentColor != color)
   {
      m_accentColor = color;
      emit themeChanged();
   }
}

QColor ApplicationConfiguration::strokeColor() const
{
   return m_strokeColor;
}

void ApplicationConfiguration::setStrokeColor(const QColor& color)
{
   if (m_strokeColor != color)
   {
      m_strokeColor = color;
      emit themeChanged();
   }
}

qreal ApplicationConfiguration::itemOpacityDisabled() const
{
   return m_itemOpacityDisabled;
}

void ApplicationConfiguration::setItemOpacityDisabled(qreal opacity)
{
   if (m_itemOpacityDisabled != opacity)
   {
      m_itemOpacityDisabled = opacity;
      emit themeChanged();
   }
}

qreal ApplicationConfiguration::buttonOpacityNormal() const
{
   return m_buttonOpacityNormal;
}

void ApplicationConfiguration::setButtonOpacityNormal(qreal opacity)
{
   if (m_buttonOpacityNormal != opacity)
   {
      m_buttonOpacityNormal = opacity;
      emit themeChanged();
   }
}

qreal ApplicationConfiguration::buttonOpacityHit() const
{
   return m_buttonOpacityHit;
}

void ApplicationConfiguration::setButtonOpacityHit(qreal opacity)
{
   if (m_buttonOpacityHit != opacity)
   {
      m_buttonOpacityHit = opacity;
      emit themeChanged();
   }
}

qreal ApplicationConfiguration::buttonOpacityHover() const
{
   return m_buttonOpacityHover;
}

void ApplicationConfiguration::setButtonOpacityHover(qreal opacity)
{
   if (m_buttonOpacityHover != opacity)
   {
      m_buttonOpacityHover = opacity;
      emit themeChanged();
   }
}

int ApplicationConfiguration::borderWidth() const
{
   return m_borderWidth;
}

void ApplicationConfiguration::setBorderWidth(int width)
{
   if (m_borderWidth != width)
   {
      m_borderWidth = width;
      emit themeChanged();
   }
}

int ApplicationConfiguration::defaultButtonSize() const
{
   return m_defaultButtonSize;
}

void ApplicationConfiguration::setDefaultButtonSize(int size)
{
   if (m_defaultButtonSize != size)
   {
      m_defaultButtonSize = size;
      emit themeChanged();
   }
}
