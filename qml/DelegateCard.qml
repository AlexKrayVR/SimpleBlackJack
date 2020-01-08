import QtQuick 2.0


Rectangle {
    height: 100
    width: 100
    color:"transparent"   
        Image {
            id: image            
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            width: parent.height
            source: imagePath
        }
}
