import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Audacity
import Audacity.UiComponents
import Audacity.UiThemes

Item {
   id: root
   height: implicitHeight
   implicitHeight: 48
   implicitWidth: contents.width
   visible: toolbarHandler.toolbarVisible

   objectName: "TransportToolbar"

   property bool isPlaying: false
   property bool gripVisible: false
   property bool separatorVisible: true

   property var workspaceMode: Workspace.Mode.Classic

   signal playbackStarted()
   signal playbackStopped()
   signal playbackPaused()
   signal updateStatusBar(status: string)

   function registerToolbarConfiguration() {
      toolbarHandler.RegisterToolbarConfiguration()
   }

   TransportToolbarHandler {
      id: toolbarHandler

      onUpdateStatusBar: function(status) {
         root.updateStatusBar(status)
      }

      onPlayStateChanged: function(isPlaying) {
         if (isPlaying) {
            root.playbackStarted()
         } else {
            root.playbackPaused()
         }
         root.isPlaying = isPlaying
      }

      onPlaybackStopped: {
         root.playbackStopped()
      }
   }

   RowLayout {
      id: contents
      anchors.verticalCenter: parent.verticalCenter
      spacing: 8

      ToolbarGrip {
         id: grip
         visible: root.gripVisible
      }

      RowLayout {
         spacing: 2

         Rectangle {
            height: root.height
            width: root.gripVisible ? 2 : 6
            color: UiTheme.backgroundColor1
         }

         FlatButton {
            id: play
            icon: isPlaying ? IconCode.SOLID_PAUSE : IconCode.SOLID_PLAY
            iconColor: isPlaying ? UiTheme.fontColor1 : UiTheme.playColor
            visible: toolbarHandler.playVisible
            onClicked: toolbarHandler.Play()
         }

         FlatButton {
            id: stop
            icon: IconCode.SOLID_STOP
            visible: toolbarHandler.stopVisible
            onClicked: toolbarHandler.Stop()
         }

         FlatButton {
            id: record
            icon: IconCode.SOLID_RECORD
            iconColor: UiTheme.recordColor
            visible: toolbarHandler.recordVisible && root.workspaceMode === Workspace.Mode.Classic
            onClicked: toolbarHandler.Record()
         }

         FlatButton {
            id: rewind
            icon: IconCode.SOLID_REWIND
            visible: toolbarHandler.rewindVisible && root.workspaceMode !== Workspace.Mode.SimpleRecording
            onClicked: toolbarHandler.Rewind()
         }

         FlatButton {
            id: fastForward
            icon: IconCode.SOLID_FAST_FORWARD
            visible: toolbarHandler.fastForwardVisible && root.workspaceMode !== Workspace.Mode.SimpleRecording
            onClicked: toolbarHandler.FastForward()
         }

         FlatButton {
            id: record2
            icon: IconCode.SOLID_RECORD
            iconColor: UiTheme.recordColor
            visible: toolbarHandler.recordVisible && root.workspaceMode !== Workspace.Mode.Classic
            onClicked: toolbarHandler.Record()
         }

         FlatButton {
            id: loop
            icon: IconCode.LOOP
            visible: toolbarHandler.loopVisible && root.workspaceMode !== Workspace.Mode.SimpleRecording
            onClicked: toolbarHandler.Loop()
         }
      }

      ToolbarSeparator {
         visible: separatorVisible
      }
   }

   Component.onCompleted: {
      toolbarHandler.StoreToolbarManager(ToolbarManager)
   }
}
