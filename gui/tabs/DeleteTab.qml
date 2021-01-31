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
        onClicked:()=>
                  {
                      //https://reqbin.com/
                      del.setUrl(ipField.text);
                      del.parseParameters(parameters.getList());
                      del.run();
                  }
    }

    Rectangle {
        id: labels
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
