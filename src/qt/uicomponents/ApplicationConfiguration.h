#ifndef APPLICATION_CONFIGURATION_H
#define APPLICATION_CONFIGURATION_H

#include <QtCore/QObject>
#include <QtGui/QColor>
#include <QtGui/QFont>
#include <QtQml/qqml.h>

class ApplicationConfiguration : public QObject
{
   Q_OBJECT
   QML_ELEMENT

   Q_PROPERTY(QFont iconFont READ iconFont WRITE setIconFont NOTIFY themeChanged FINAL)
   Q_PROPERTY(QFont bodyFont READ bodyFont WRITE setBodyFont NOTIFY themeChanged FINAL)

   Q_PROPERTY(QColor buttonColor READ buttonColor WRITE setButtonColor NOTIFY themeChanged FINAL)
   Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY themeChanged FINAL)

   Q_PROPERTY(qreal itemOpacityDisabled READ itemOpacityDisabled WRITE setItemOpacityDisabled NOTIFY themeChanged FINAL)

signals:
   void themeChanged();

public:
   ApplicationConfiguration();

   QFont iconFont() const;
   void setIconFont(const QFont& font);

   QFont bodyFont() const;
   void setBodyFont(const QFont& font);

   QColor buttonColor() const;
   void setButtonColor(const QColor& color);

   QColor accentColor() const;
   void setAccentColor(const QColor& color);

   qreal itemOpacityDisabled() const;
   void setItemOpacityDisabled(const qreal& opacity);

private:
   QFont m_iconFont;
   QFont m_bodyFont;
   QColor m_buttonColor{"#CFD5DD"};
   QColor m_accentColor{"#9F9FFF"};
   qreal m_itemOpacityDisabled{0.3};
};

#endif
