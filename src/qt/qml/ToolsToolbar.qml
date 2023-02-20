import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Audacity
import Audacity.UiComponents

Rectangle {
   id: root
   height: 48
   width: parent.width
   color: appConfig.backgroundColor1

   property bool isPlaying: false
   property var workspaceMode: Workspace.Mode.Classic

   signal updateStatusBar(status: string)

   ToolsToolbarHandler {
      id: toolbarHandler

      onUpdateStatusBar: function(status) {
         root.updateStatusBar(status)
      }

      onPlayStateChanged: function(isPlaying) {
         root.isPlaying = isPlaying
      }
   }

   RowLayout {
      spacing: 12

      ToolbarGrip {
         id: grip
      }

      RowLayout {
         Layout.alignment: Qt.AlignHCenter
         spacing: 8

         RowLayout {
            spacing: 2

            FlatButton {
               id: play
               icon: isPlaying ? IconCode.SOLID_PAUSE : IconCode.SOLID_PLAY
               iconColor: isPlaying ? "black" : appConfig.playColor
               onClicked: toolbarHandler.play()
            }

            FlatButton {
               id: stop
               icon: IconCode.SOLID_STOP
               onClicked: toolbarHandler.stop()
            }

            FlatButton {
               id: record
               icon: IconCode.SOLID_RECORD
               iconColor: appConfig.recordColor
               visible: root.workspaceMode === Workspace.Mode.Classic
               onClicked: toolbarHandler.record()
            }

            FlatButton {
               id: rewind
               icon: IconCode.SOLID_REWIND
               visible: root.workspaceMode !== Workspace.Mode.SimpleRecording
               onClicked: toolbarHandler.rewind()
            }

            FlatButton {
               id: fastForward
               icon: IconCode.SOLID_FAST_FORWARD
               visible: root.workspaceMode !== Workspace.Mode.SimpleRecording
               onClicked: toolbarHandler.fastForward()
            }

            FlatButton {
               id: record2
               icon: IconCode.SOLID_RECORD
               iconColor: appConfig.recordColor
               visible: root.workspaceMode !== Workspace.Mode.Classic
               onClicked: toolbarHandler.record()
            }

            FlatButton {
               id: loop
               icon: IconCode.LOOP
               visible: root.workspaceMode !== Workspace.Mode.SimpleRecording
               onClicked: toolbarHandler.loop()
            }
         }

         ToolbarSeparator {}

         FlatButton {
            id: automation
            icon: IconCode.AUTOMATION
            visible: root.workspaceMode === Workspace.Mode.Classic ||
                     root.workspaceMode === Workspace.Mode.AudioEditing
            onClicked: toolbarHandler.automation()
         }

         RowLayout {
            spacing: 1

            FlatButton {
               id: zoomIn
               icon: IconCode.ZOOM_IN
               onClicked: toolbarHandler.zoomIn()
            }

            FlatButton {
               id: zoomOut
               icon: IconCode.ZOOM_OUT
               onClicked: toolbarHandler.zoomOut()
            }

            FlatButton {
               id: fitSelection
               icon: IconCode.ZOOM_FIT_SELECTION
               visible: root.workspaceMode === Workspace.Mode.Classic ||
                        root.workspaceMode === Workspace.Mode.SpectralEditing
               onClicked: toolbarHandler.fitSelection()
            }

            FlatButton {
               id: fitProject
               icon: IconCode.ZOOM_FIT_PROJECT
               visible: root.workspaceMode === Workspace.Mode.Classic ||
                        root.workspaceMode === Workspace.Mode.SpectralEditing
               onClicked: toolbarHandler.fitProject()
            }

            FlatButton {
               id: zoomToggle
               icon: IconCode.ZOOM_TOGGLE
               visible: root.workspaceMode === Workspace.Mode.Classic ||
                        root.workspaceMode === Workspace.Mode.SpectralEditing
               onClicked: toolbarHandler.zoomToggle()
            }
         }

         RowLayout {
            spacing: 1
            visible: root.workspaceMode !== Workspace.Mode.SimpleRecording

            FlatButton {
               id: trim
               icon: IconCode.TRIM
               onClicked: toolbarHandler.trim()
            }

            FlatButton {
               id: silence
               icon: IconCode.SILENCE
               onClicked: toolbarHandler.silence()
            }
         }

         ToolbarSeparator {}
      }
   }

   FlatButton {
      x: parent.width - implicitWidth - 12
      id: setup
      icon: IconCode.SETUP
      onClicked: toolbarHandler.setup()
      anchors.verticalCenter: parent.verticalCenter
   }

   Rectangle {
      anchors.top: root.bottom
      height: 1
      width: parent.width
      color: appConfig.strokeColor1
   }
}
