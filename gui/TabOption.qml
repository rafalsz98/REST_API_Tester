import QtQuick 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15

Item {
    required property var methodLoader
    property string name: "test"

    Rectangle {
        anchors.fill: parent
        color: "#8D8D92"
        border.color: "#707070"
        border.width: 1
        Text {
            anchors.centerIn: parent
            text: qsTr(name)
            color: "#F3F3F3"
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: function() {
                console.log(name);
                console.log(methodLoader.sourceComponent);
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
