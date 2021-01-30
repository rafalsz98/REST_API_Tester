import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0
import "../"


Item {
    property var runButton
    property var ipField

    Rectangle {
        id: labels
        width: parent.width
        height: 50
        color: "transparent"
        RowLayout {
            width: parent.width
            Text {
                Layout.leftMargin: 10
                font.pixelSize: 17
                text: "ID"
                color: "#F3F3F3"
            }
            Text {
                font.pixelSize: 17
                text: "Key"
                color: "#F3F3F3"
            }
            Text {
                font.pixelSize: 17
                text: "Value"
                color: "#F3F3F3"
            }
            RoundButton {
                text: "+"
                palette.button: "#FF1B1C"
                Layout.rightMargin: 10
                onClicked: function() {
                    parameters.insertRow();
                }
            }
        }
    }

    ListView {
        anchors.top: labels.bottom
        width: parent.width
        height: parent.height - 50
        clip: true

        model: ParameterModel {
            id: parameters
        }

        delegate: RowLayout {
            width: parent.width
            spacing: 30
            Text {
                Layout.leftMargin: 10
                font.pixelSize: 17
                color: "#F3F3F3"
                text: model.id + "."
            }
            CustomTextField {
                Layout.preferredWidth: 150
                Layout.preferredHeight: 30
                text: model.key
                onEditingFinished: model.key = text
            }
            CustomTextField {
                Layout.preferredWidth: 150
                Layout.preferredHeight: 30
                text: model.value
                onEditingFinished: model.value = text
            }
            RoundButton {
                text: "-"
                palette.button: "#FF1B1C"
                Layout.rightMargin: 10
                onClicked: function() {
                    parameters.removeRow(model.id - 1);
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
