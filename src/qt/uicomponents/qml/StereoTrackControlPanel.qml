import QtQuick
import QtQuick.Layouts

import Audacity
import Audacity.UiComponents
import Audacity.UiThemes

Item {
   id: root
   objectName: "StereoTrackControlPanel"
   height: implicitHeight
   width: implicitWidth
   implicitHeight: 126
   implicitWidth: 280

   property string name: ""
   property bool muted: false
   property bool soloed: false

   signal optionsClicked()
   signal muteClicked()
   signal soloClicked()
   signal addClicked()

   Rectangle {
      id: background
      anchors.fill: parent
      color: UiTheme.backgroundColor2
      opacity: 1.0

      states: [
         State {
            name: "HOVERED"
            when: mouseArea.containsMouse

            PropertyChanges {
               target: background
               color: UiTheme.backgroundColor1
               opacity: UiTheme.buttonOpacityHover
            }
         }
      ]
   }

   MouseArea {
      id: mouseArea
      anchors.fill: parent
      hoverEnabled: true

      Item {
         Text {
            id: icon
            x: 12
            y: 14
            width: 16
            height: 16
            color: UiTheme.fontColor1
            text: String.fromCharCode(IconCode.MICROPHONE)

            font {
               family: appConfig.iconFont.family
               pixelSize: 16
            }
         }

         Text {
            x: 36
            y: 14
            height: 16
            horizontalAlignment: Text.AlignLeft
            color: UiTheme.fontColor1
            text: name

            font {
               family: appConfig.bodyFont.family
               pixelSize: 12
            }
         }

         FlatButton {
            id: options
            x: 224
            y: 12
            width: 20
            height: 20
            transparent: true
            icon: IconCode.MENU_THREE_DOTS
            onClicked: root.optionsClicked()
         }

         FlatButton {
            id: mute
            x: 12
            y: 48
            width: 20
            height: 20
            text: qsTr("M")
            textFont.pixelSize: 12
            accentButton: muted
            onClicked: root.muteClicked()
         }

         FlatButton {
            id: solo
            x: 36
            y: 48
            width: 20
            height: 20
            text: qsTr("S")
            textFont.pixelSize: 12
            accentButton: soloed
            onClicked: root.soloClicked()
         }

         StyledSlider {
            id: slider
            x: 64
            y: 50
            width: 142
            height: 16
         }

         StyledDial {
            id: dial
            x: 214
            y: 43
            width: 30
            height: 30
         }

         FlatButton {
            id: add
            x: 12
            y: 84
            width: 232
            height: 28
            text: qsTr("Add effects")
            textFont.pixelSize: 12
            onClicked: root.addClicked()
         }

         Rectangle {
            id: verticalSeparator
            x: 255
            width: 1
            height: root.height
            color: UiTheme.strokeColor
         }

         TrackVolumeMeter {
            id: trackVolumeMeter
            height: root.height - horizontalSeparator.height
            channels: TrackVolumeMeter.Channels.Stereo
            anchors.left: verticalSeparator.right
         }
      }
   }

   Rectangle {
      id: horizontalSeparator
      y: root.height - horizontalSeparator.height
      height: 2
      width: root.width
      color: UiTheme.strokeColor
   }
}
