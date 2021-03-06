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
            x: 0
            anchors.top: titleBar.bottom
            anchors.topMargin: 0
            width: parent.width
            height: 50
            color: "transparent"
            RowLayout {
                y: 8
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                spacing: 30
                Text {
                    Layout.leftMargin: 10
                    font.pixelSize: 17
                    Layout.preferredWidth: 20
                    text: "ID"
                    color: "#F3F3F3"
                }
                Text {

                    font.pixelSize: 17
                    Layout.fillWidth: false
                    Layout.preferredWidth: 150
                    text: "Key"
                    color: "#F3F3F3"
                }
                Text {


                    font.pixelSize: 17
                    Layout.fillWidth: false
                    Layout.preferredWidth: 150
                    text: "Value"
                    color: "#F3F3F3"
                }
            }
        }

        Rectangle {
            id: buttons
            x: 0
            anchors.top: titleBar.bottom
            anchors.topMargin: -30
            width: parent.width
            height: 50
            color: "transparent"
            RowLayout {
                height: 48
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.rightMargin: 0
                spacing: 0
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
            height: 400
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
                    Layout.preferredWidth: 20
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


