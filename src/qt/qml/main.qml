import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Audacity.UiComponents

ApplicationWindow {
   width: 640
   height: 480
   visible: true
   title: qsTr("Audacity")

   required property ApplicationConfiguration appConfig

   menuBar: MenuBar {
      Menu {
         title: qsTr("File")
         MenuItem {
            text: qsTr("Exit")
            onTriggered: Qt.quit()
         }
      }
   }

   RowLayout {
      id: rowLayout
      spacing: 2

      FlatButton {
         id: play
         icon: IconCode.SOLID_PLAY
         iconColor: "#0F7745"
      }

      FlatButton {
         id: stop
         icon: IconCode.SOLID_STOP
      }

      FlatButton {
         id: rewind
         icon: IconCode.SOLID_REWIND
      }

      FlatButton {
         id: fastFoward
         icon: IconCode.SOLID_FAST_FORWARD
      }

      FlatButton {
         id: record
         icon: IconCode.SOLID_RECORD
         iconColor: "#C54444"
      }

      FlatButton {
         id: loop
         icon: IconCode.LOOP
      }

      FlatButton {
         id: automation
         icon: IconCode.AUTOMATION
      }

      FlatButton {
         id: zoomIn
         icon: IconCode.ZOOM_IN
      }

      FlatButton {
         id: zoomOut
         icon: IconCode.ZOOM_OUT
      }

      FlatButton {
         id: zoomFitSelection
         icon: IconCode.ZOOM_FIT_SELECTION
      }

      FlatButton {
         id: zoomFitProject
         icon: IconCode.ZOOM_FIT_PROJECT
      }

      FlatButton {
         id: zoomToggle
         icon: IconCode.ZOOM_TOGGLE
      }

      FlatButton {
         id: trim
         icon: IconCode.TRIM
         enabled: false
      }

      FlatButton {
         id: silence
         icon: IconCode.SILENCE
         accentButton: true
      }
   }
}
