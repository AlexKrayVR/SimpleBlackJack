import QtQuick 2.0


Rectangle{
    width: 50
    height: 50
    color: "transparent"
    Image {
        id: name
        anchors.fill: parent
        source: exitArea.pressed ? "/Icons/IconsApp/exit2.png" : "/Icons/IconsApp/exit1.png"
    }
    MouseArea{
        id:exitArea
        anchors.fill: parent
        onClicked: Qt.quit()
    }

}
