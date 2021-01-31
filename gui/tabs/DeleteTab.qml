import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import ParameterModel 1.0
import Delete 1.0

import "../components"

Item
{
    property var runButton
    property var ipField

    Delete
    {
        id:del
    }

    Connections
    {
        target: runButton
        function onClicked(_)
        {
            //https://reqbin.com/
            del.setUrl(ipField.text);
            del.parseParameters(parameters.getList());
            del.run();
        }
    }

    Rectangle {
        id: titleBar
        width: parent.width
        height: 30
        color: "transparent"
        Text {
            anchors.verticalCenter: titleBar.verticalCenter
            anchors.horizontalCenter: titleBar.horizontalCenter
            text: "DELETE"
            font.pixelSize: 20
            color: "#F3F3F3"
        }
    }

    Rectangle {
        id: labels
        anchors.top: titleBar.bottom
        width: parent.width
        height: 50
        color: "transparent"
        RowLayout {
            width: parent.width
            spacing: 0
            Text {
                Layout.topMargin: 13
                Layout.leftMargin: 10
                font.pixelSize: 17
                text: "Key"
                color: "#F3F3F3"
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
            anchors.bottomMargin: 10
            width: parent.width
            spacing: 30
            CustomTextField {
                width: parent.width-20
                Layout.preferredHeight: 40
                Layout.bottomMargin: 10
                Layout.leftMargin: 10
                text: model.key
                onEditingFinished: model.key = text
            }
        }
    }
}
