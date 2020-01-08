import QtQuick 2.0

Rectangle{
    color: "transparent"
    property alias areaButtonShuffle: areaButtonShuffle
    width: 180
    height:  40
    MouseArea{
        id: areaButtonShuffle
        anchors.fill: parent
        onClicked:  Logic.shuffleTheDeck()

    }
    Row{
        anchors.fill: parent
        Rectangle {
            id: mixButton
            width: 40
            height: 40
            color: "transparent"
            Image {
                width: 30
                height: 30
                anchors.centerIn: parent
                source: areaButtonShuffle.pressed ? "/Icons/IconsApp/shuffle2.png" : "/Icons/IconsApp/shuffle1.png"
            }
        }
        Text {
            id: name
            width: parent.width-mixButton.width
            height: parent.height
            text: qsTr("Extra shuffle")
            font.bold: true
             color:   areaButtonShuffle.pressed ? "#cecece" :"#0c198d"
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
    }
}
