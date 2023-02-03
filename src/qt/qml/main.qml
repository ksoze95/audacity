import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
   width: 640
   height: 480
   visible: true
   title: qsTr("Audacity")

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
      spacing: 2

      FontLoader {
         id: audacityIcon
         source: "qrc:/fonts/AudacityIcon.ttf"
      }

      StyledIconLabel {
         id: play
         font.family: audacityIcon.name
         font.pixelSize: 10
         iconCode: 0xF446
         color: "#0F7745"
      }

      StyledIconLabel {
         id: stop
         font.family: audacityIcon.name
         font.pixelSize: 10
         iconCode: 0xF447
      }

      StyledIconLabel {
         id: rewind
         font.family: audacityIcon.name
         font.pixelSize: 10
         iconCode: 0xF448
      }

      StyledIconLabel {
         id: fastFoward
         font.family: audacityIcon.name
         font.pixelSize: 10
         iconCode: 0xF449
      }

      StyledIconLabel {
         id: record
         font.family: audacityIcon.name
         font.pixelSize: 12
         iconCode: 0xF44A
         color: "#C54444"
      }

      StyledIconLabel {
         id: loop
         font.family: audacityIcon.name
         font.pixelSize: 14
         iconCode: 0xEF1F
      }

      StyledIconLabel {
         id: automation
         font.family: audacityIcon.name
         iconCode: 0xF3CB
      }

      StyledIconLabel {
         id: zoomIn
         font.family: audacityIcon.name
         iconCode: 0xEF18
      }

      StyledIconLabel {
         id: zoomOut
         font.family: audacityIcon.name
         iconCode: 0xEF16
      }

      StyledIconLabel {
         id: zoomFitSelection
         font.family: audacityIcon.name
         iconCode: 0xF439
      }

      StyledIconLabel {
         id: zoomFitProject
         font.family: audacityIcon.name
         iconCode: 0xF438
      }

      StyledIconLabel {
         id: zoomToggle
         font.family: audacityIcon.name
         iconCode: 0xF437
      }

      StyledIconLabel {
         id: trim
         font.family: audacityIcon.name
         iconCode: 0xF43B
      }

      StyledIconLabel {
         id: silence
         font.family: audacityIcon.name
         iconCode: 0xF43A
      }
   }
}
