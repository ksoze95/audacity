#include <QFileDialog>
#include <QFileInfo>
#include <wx/log.h>
#include "NewAudacity.h"

NewAudacity::NewAudacity(QObject* parent)
   : QObject(parent)
{
}

NewAudacity::~NewAudacity()
{
}

void NewAudacity::Browse()
{
   QFileDialog dialog;
   dialog.setNameFilter("Audio files (*.wav)");

   if (dialog.exec() == QDialog::Accepted)
   {
      auto files = dialog.selectedFiles();
      if (files.isEmpty())
      {
         wxLogWarning("No wav file chosen.");
         return;
      }

      sound_file = QDir::toNativeSeparators(files.first());
   }
}

void NewAudacity::Play()
{
   if (sound_file.isEmpty())
   {
      wxLogError("sound file path is empty");
      return;
   }

   QFileInfo file_info(sound_file);
   if (!file_info.exists())
   {
      wxLogError("sound file does not exist");
      return;
   }

   if (!file_info.isFile())
   {
      wxLogError("'%s' is not a file type", sound_file.toStdString());
      return;
   }

   wxLogDebug("Attempting to play sound file '%s", sound_file.toStdString());

   wxLogError("Play functionality not yet implemented");
}

void NewAudacity::Stop()
{
   wxLogError("Stop functionality not yet implemented");
}

