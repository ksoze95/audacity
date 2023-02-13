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

qreal ApplicationConfiguration::itemOpacityDisabled() const
{
   return m_itemOpacityDisabled;
}

void ApplicationConfiguration::setItemOpacityDisabled(const qreal& opacity)
{
   if (m_itemOpacityDisabled != opacity)
   {
      m_itemOpacityDisabled = opacity;
      emit themeChanged();
   }
}
