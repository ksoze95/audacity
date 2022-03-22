#pragma once

#include <QObject>
#include <QString>

class NewAudacity : public QObject
{
   Q_OBJECT

   public:
      explicit NewAudacity(QObject* parent = nullptr);
      virtual ~NewAudacity();

   public slots:
      void Browse();
      void Play();
      void Stop();

   private:
      QString sound_file;
};
