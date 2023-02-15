import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes

import Audacity.UiComponents
import qml

ApplicationWindow {
   id: root
   width: 640
   height: 480
   visible: true
   title: qsTr("Audacity")

   required property ApplicationConfiguration appConfig
   required property ToolsToolBarModel toolsModel

   menuBar: MenuBar {
      Menu {
         title: qsTr("File")
         MenuItem {
            text: qsTr("Exit")
            onTriggered: Qt.quit()
         }
      }
   }

   ListView {
      id: listView
      spacing: 2
      width: parent.width
      height: 100
      orientation: ListView.Horizontal
      model: toolsModel;

      delegate: FlatButton {
         icon: model.icon
         iconColor: model.iconColor
      }
   }
}
