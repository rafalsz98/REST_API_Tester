import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0

import Post 1.0

import "../components"


Item {
    property var runButton
    property var ipField
    property var methodLoader

    Post
    {
        id: post
        onReplyReady: function() {
            AppManager.body = post.getBody();
            AppManager.headers = post.getHeaders();
            AppManager.statusCode = post.getStatusCode();
            methodLoader.setSource("ResultsTab.qml", {"x": "x"});
        }
        onAlreadyRunning: function() {
            console.log("already running!");
        }
    }

    Connections {
        target: runButton
        function onClicked(_) {
            post.setUrl(ipField.text);
            post.parseParameters(parameters.getList());
            post.run();
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
            text: "POST"
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
            anchors.bottomMargin: 10
            width: parent.width
            spacing: 30

            Text {
                Layout.leftMargin: 10
                Layout.bottomMargin: 10
                font.pixelSize: 17
                color: "#F3F3F3"
                text: model.id + 1 + "."
            }
            CustomTextField {
                Layout.preferredWidth: 150
                Layout.preferredHeight: 40
                Layout.bottomMargin: 10
                text: model.key
                onEditingFinished: model.key = text
            }
            CustomTextField {
                Layout.preferredWidth: 150
                Layout.preferredHeight: 40
                Layout.bottomMargin: 10
                text: model.value
                onEditingFinished: model.value = text
            }
        }
    }
}
