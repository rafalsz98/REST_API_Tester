import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParametersModel 1.0


Item {
    ListView {
        implicitWidth: 250
        implicitHeight: 250
        anchors.fill: parent
        clip: false

        model: ParametersModel {
            id: parameters
        }

        delegate: Text {
//            required property string key
//            required property string value
            text: "AAA" + key + " " + value
        }
    }
    Rectangle {
        width: 100
        height: 100
        MouseArea {
            anchors.fill: parent
            onClicked: function() {
                console.log(parameters.getList());
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
