import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import  "qml"

Window {
    id: window
    visible: true
    width: 400
    height: 600
    title: qsTr("CardGame")
    color: "#400808"

    // result display
    Rectangle{
        id:resultDisplay
        width: parent.width
        height: 50
        visible: false
        anchors.bottom: modelPlayerCards.top
        Row{
            anchors.fill: parent
            antialiasing: true
            Rectangle{
                height: parent.height
                width: parent.width/2
                color: "#b01010"
                Text {
                    id:result
                    anchors.fill: parent
                    color: "white"
                    text: ""
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Microsoft New Tai Lue"
                    font.bold: true
                    fontSizeMode: Text.Fit
                    font.pixelSize: 23
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Rectangle{
                height: parent.height
                width: parent.width/2
                color: "#b01010"
                border{
                    color:  continueButton.pressed? "white":""
                    width: continueButton.pressed? 1:0
                }
                MouseArea{
                    id: continueButton
                    anchors.fill: parent
                    onClicked: {
                        resultDisplay.visible=false
                        Logic.restart()
                        //activate the bottom menu
                        dillerCards.text="Diller:-"
                        mouseTake.enabled=true
                        doubleBet.enabled=true
                        mouseStop.enabled=true
                    }
                }
                Text {
                    color: "white"
                    anchors.fill: parent
                    text: "     Continue"
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Microsoft New Tai Lue"
                    font.bold: true
                    fontSizeMode: Text.Fit
                    font.pixelSize: 23
                    horizontalAlignment: Text.AlignLeft
                }
            }
        }
    }

    // top menu
    Row{
        anchors.top: parent.top
        width: parent.width
        height: 50
        Rectangle{
            color: "#b01010"
            width: parent.width*0.5
            height: parent.height
            Text {
                anchors.fill: parent
                text: qsTr("  BlackJack")
                fontSizeMode: Text.Fit
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
        }
        Rectangle{
            color: "#b01010"
            width: parent.width*0.3
            height: parent.height
            border{
                color:  startButton.pressed? "white":""
                width: startButton.pressed? 1:0
            }
            Text {
                anchors.fill: parent
                text: qsTr("Start")
                font.bold: true
                font.family: "Microsoft New Tai Lue"
                color: "white"
                font.pixelSize: 23
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea{
                id: startButton
                anchors.fill: parent
                onClicked:{
                    startButton.enabled=false
                    Logic.startGame()
                    //activate the bottom menu
                    mouseTake.enabled=true
                    doubleBet.enabled=true
                    mouseStop.enabled=true
                }
            }
        }
        Rectangle{
            color: "#b01010"
            width: parent.width*0.2
            height: parent.height
            border{
                color:  exitButton.pressed? "white":""
                width: exitButton.pressed? 1:0
            }
            Text {
                anchors.fill: parent
                text: qsTr("Exit")
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea{
                id: exitButton
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }
    }

    Row{
        width: parent.width
        height: 40
        anchors.topMargin: 20
        anchors.top: modelDillerCards.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        antialiasing: true
        Text {
            id: dillerCards
            height: parent.height
            width: parent.width/2
            color: "white"
            text: "Diller: - "
            verticalAlignment: Text.AlignVCenter
            font.family: "Microsoft New Tai Lue"
            font.bold: true
            fontSizeMode: Text.Fit
            font.pixelSize: 23
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id:  playerCards
            height: parent.height
            width: parent.width/2
            color: "white"
            text: "     Player: "+ Logic.playerScore
            verticalAlignment: Text.AlignVCenter
            font.family: "Microsoft New Tai Lue"
            font.bold: true
            fontSizeMode: Text.Fit
            font.pixelSize: 23
            horizontalAlignment: Text.AlignLeft
        }
    }

    ModelViewCards{
        id: modelDillerCards
        width: parent.width-20
        height: 130
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100
        listView.model: SecondModel
    }

    ModelViewCards{
        id: modelPlayerCards
        height: 130
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 100
        width: parent.width-20
        anchors.bottom: parent.bottom
        listView.model: FirstModel
    }
    // bottom menu
    Row{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: parent.width
        height: 50
        Rectangle{
            height: parent.height
            width: parent.width/3
            color: "#b01010"
            border{
                color:  mouseTake.pressed? "white":""
                width: mouseTake.pressed? 1:0
            }
            Text {
                anchors.fill: parent
                text: qsTr("Hit")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
                MouseArea{
                    id: mouseTake
                    enabled: false
                    anchors.fill: parent
                    onClicked: {
                        doubleBet.enabled=false
                        if(Logic.playerScore<21)
                        {Logic.takeCard()}else{
                            mouseTake.enabled=false
                        }
                    }
                }
            }
        }
        Rectangle{
            height: parent.height
            width: parent.width/3
            color: "#b01010"
            border{
                color:  mouseStop.pressed? "white":""
                width: mouseStop.pressed? 1:0
            }
            Text {
                id: stop
                anchors.fill: parent
                text: qsTr("Stand")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
                MouseArea{
                    id:mouseStop
                    enabled: false
                    anchors.fill: parent
                    onClicked: {
                        Logic.stopGame()
                        mouseTake.enabled=false
                        mouseStop.enabled=false
                        dillerCards.text="Diller:"+Logic.dillerScore
                        resultDisplay.visible=true
                        result.text=Logic.result
                    }
                }

            }
        }
        Rectangle{
            height: parent.height
            width: parent.width/3
            color: "#b01010"
            border{
                color:  doubleBet.pressed? "white":""
                width: doubleBet.pressed? 1:0
            }
            Text {
                anchors.fill: parent
                text: qsTr("Double")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
            }
            MouseArea{
                id: doubleBet
                enabled: false
                anchors.fill: parent
                onClicked: {
                    doubleBet.enabled=false
                    Logic.bet+=10
                }
            }
        }
    }

    // money/bet display
    Row{
        anchors.bottom: parent.bottom
        width: parent.width
        height: 50
        anchors.bottomMargin: 50
        Rectangle{
            height: parent.height
            width: parent.width/2
            color: "transparent"
            Text {
                anchors.fill: parent
                text: qsTr("Money: ")+Logic.money
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
            }
        }
        Rectangle{
            height: parent.height
            width: parent.width/2
            color: "transparent"
            Text {
                anchors.fill: parent
                text: qsTr("     Bet:")+Logic.bet
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.family: "Microsoft New Tai Lue"
                font.bold: true
                color: "white"
                font.pixelSize: 23
            }
        }
    }
}




