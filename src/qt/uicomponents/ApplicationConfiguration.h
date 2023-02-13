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
   Q_PROPERTY(QColor strokeColor READ strokeColor WRITE setStrokeColor NOTIFY themeChanged FINAL)

   Q_PROPERTY(qreal itemOpacityDisabled READ itemOpacityDisabled WRITE setItemOpacityDisabled NOTIFY themeChanged FINAL)
   Q_PROPERTY(qreal buttonOpacityNormal READ buttonOpacityNormal WRITE setButtonOpacityNormal NOTIFY themeChanged FINAL)
   Q_PROPERTY(qreal buttonOpacityHit READ buttonOpacityHit  WRITE setButtonOpacityHit NOTIFY themeChanged FINAL)
   Q_PROPERTY(qreal buttonOpacityHover READ buttonOpacityHover WRITE setButtonOpacityHover NOTIFY themeChanged FINAL)

   Q_PROPERTY(int borderWidth READ borderWidth  WRITE setBorderWidth NOTIFY themeChanged FINAL)
   Q_PROPERTY(int defaultButtonSize READ defaultButtonSize WRITE setDefaultButtonSize NOTIFY themeChanged FINAL)

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

   QColor strokeColor() const;
   void setStrokeColor(const QColor& color);

   qreal itemOpacityDisabled() const;
   void setItemOpacityDisabled(qreal opacity);

   qreal buttonOpacityNormal() const;
   void setButtonOpacityNormal(qreal opacity);

   qreal buttonOpacityHit() const;
   void setButtonOpacityHit(qreal opacity);

   qreal buttonOpacityHover() const;
   void setButtonOpacityHover(qreal opacity);

   int borderWidth() const;
   void setBorderWidth(int width);

   int defaultButtonSize() const;
   void setDefaultButtonSize(int size);

private:
   QFont m_iconFont;
   QFont m_bodyFont;
   QColor m_buttonColor{ "#CFD5DD" };
   QColor m_accentColor{ "#9F9FFF" };
   QColor m_strokeColor{ "#CED1D4" };
   qreal m_itemOpacityDisabled{ 0.3 };
   qreal m_buttonOpacityNormal{ 0.7 };
   qreal m_buttonOpacityHit{ 1.0 };
   qreal m_buttonOpacityHover{ 0.5 };
   int m_borderWidth{ 0 };
   int m_defaultButtonSize{ 32 };
};

#endif
