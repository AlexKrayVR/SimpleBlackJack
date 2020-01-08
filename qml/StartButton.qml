import QtQuick 2.0


Rectangle{
    id: startButton
    color: "transparent"
    width: 120
    height:  40

    property bool check: false

    MouseArea{
        id: areaStartButton
        anchors.fill: startButton
        onClicked: {
            Logic.shuffleTheDeck()
            check=true
        }
    }
    Row{
        anchors.fill: parent
        Rectangle{
            id:imageStart
            color: "transparent"
            height:  40
            width: 40
            Image {
                anchors.centerIn: parent
                height:  30
                width: 30
                source: if (check) {
                            areaStartButton.pressed ? "/Icons/IconsApp/refresh-button2.png" :"/Icons/IconsApp/refresh-button1.png"
                        }
            }
        }
        Rectangle {
            id: mixButton
            anchors.left:imageStart.right
            height: 40
            width: 80
            color: "transparent"

            Text {
                id: name
                anchors.fill:parent
                text: check ? "Restart" : "Start"
                font.bold: true
                color:   areaStartButton.pressed ? "#cecece" :"#0c198d"
                font.pointSize: 16
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
        }

    }
}
