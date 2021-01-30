import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0

import "../components"


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
            spacing: 0
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
                onClicked: function() {
                    parameters.insertRow();
                }
            }
            RoundButton {
                icon.source: "../resources/clear.png"
                icon.width: 15
                onClicked: function() {
                    parameters.clearRows();
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
            Layout.bottomMargin: 10

            Text {
                Layout.leftMargin: 10
                font.pixelSize: 17
                color: "#F3F3F3"
                text: model.id + 1 + "."
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
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
