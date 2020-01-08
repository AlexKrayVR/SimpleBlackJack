import QtQuick 2.0

Rectangle{
    height: 200
    width: parent.width
    color: "transparent"
    border.color: "white"
    border.width: 2
    radius: 15

    property alias listView: listView

    ListView{
        id: listView
        width: parent.width-20
        anchors.centerIn: parent
        height: parent.height-25
        orientation: ListView.Horizontal
        spacing: -25
        //If clipping is enabled, an item will clip its own painting, as well as the painting of its children, to its bounding rectangle.
        clip:true
        delegate: DelegateCard{
        id:delegate
        }       
    }









}


