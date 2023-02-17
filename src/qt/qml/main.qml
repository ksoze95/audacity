import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes

import Audacity
import Audacity.UiComponents

ApplicationWindow {
   id: root
   width: 640
   height: 480
   visible: true
   title: qsTr("Audacity")

   required property ApplicationConfiguration appConfig
   required property ToolsToolBarModel toolsToolbarModel

   menuBar: MenuBar {
      Menu {
         title: qsTr("File")
         MenuItem {
            text: qsTr("Exit")
            onTriggered: Qt.quit()
         }
      }
   }

   header: ToolBar {
      id: toolsToolBar
      height: 52
      ListView {
         id: listView
         interactive: false
         contentWidth: parent.width
         spacing: 2
         width: parent.width
         height: parent.height
         orientation: ListView.Horizontal
         model: toolsToolbarModel;

         delegate: FlatButton {
            icon: model.icon
            iconColor: model.iconColor
            anchors.verticalCenter: parent.verticalCenter

            onClicked: {
               toolsToolbar.handleClickEvent(model.id)
            }
         }
      }
   }
}
