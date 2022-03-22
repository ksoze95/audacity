import QtQuick 2.0

Item {
    id: root
    width: 60
    height: 60

    signal clicked()

    property string text: ""
    property string image: ""

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "#C0C0C0"
        radius: 10

        Image {
            source: root.image
            anchors.fill: parent
        }

        Text {
            id: text
            text: root.text
            anchors.centerIn: parent
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onPressed: parent.color = "green"
            onReleased: parent.color = "#C0C0C0"
            onEntered: parent.color = "purple"
            onExited: parent.color = "#C0C0C0"
        }

        Component.onCompleted: {
            mouseArea.clicked.connect(clicked)
        }
    }
}
