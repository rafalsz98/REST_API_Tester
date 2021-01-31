import QtQuick 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15

Item {
    required property var methodLoader
    property string name: "test"
    property string address: ""
    property var properties

    Button {
        id: button
        anchors.fill: parent
        contentItem: Text {
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            text: qsTr(name)
            color: "#F3F3F3"
        }
        background: Rectangle {
            anchors.fill: parent
            //color: name == currentlyActive ? "#6E6E72" : "#8D8D92"
            color: "#8D8D92"
            border.color: "#707070"
        }

        onClicked: function() {
            //currentlyActive = name;
            //console.log(currentlyActive);
            methodLoader.setSource("../" + address, properties)
        }
    }
}
