import QtQuick 2.15
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 320
    height: 240
    title: qsTr("QAudacity")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    property var middle: (height / 2) - play.height

    CustomButton {
        id: browse
        x: 40
        y: middle
        text: "Browse"

        onClicked: {
            new_audacity.Browse()
        }
    }

    CustomButton {
        id: play
        x: (parent.width / 2) - (width / 2)
        y: middle
        image: "qrc:/images/Play.png"
        onClicked: {
            new_audacity.Play()
        }
    }

    CustomButton {
        id: stop
        x: parent.width - (width + 40)
        y: middle
        image: "qrc:/images/Stop.png"

        onClicked: {
            new_audacity.Stop()
        }
    }
}
