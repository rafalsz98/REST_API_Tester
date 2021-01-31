import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0

import "../components"


Item {
    Column {
        id: cols
        anchors.fill: parent
        anchors.margins: 10
        spacing: 3

        Rectangle {
            id: statusLabel
            width: parent.width
            height: 25
            color: "transparent"
            RowLayout {
                Text {
                    font.pixelSize: 17
                    text: "Status Code"
                    color: "#F3F3F3"
                }
            }
        }

        Rectangle {
            id: statusData
            width: parent.width - 50
            height: 33
            color: "black"
            anchors.top: statusLabel.bottom;
            x: 20
            TextEdit {
                id: statusDataText
                readOnly: true
                focus: true
                selectByMouse: true
                font.pointSize: 8;
                wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere;
                color: "white";
                anchors {
                    top: parent.top;
                    topMargin: 8;
                    left: parent.left;
                    leftMargin: 10;
                    right: parent.right;
                    rightMargin: 10;
                }
                text: AppManager.statusCode
            }
        }

        Rectangle {
            id: headerLabel
            width: parent.width
            height: 25
            color: "transparent"
            anchors.top: statusData.bottom;
            RowLayout {
                Text {
                    font.pixelSize: 17
                    text: "Header"
                    color: "#F3F3F3"
                }
            }
        }

        Rectangle {
            id: headerData
            width: parent.width - 50
            height: 110
            color: "black"
            anchors.top: headerLabel.bottom;
            x: 20

            ScrollView {
                id: scrollheader
                anchors.fill: parent
                clip : true

                TextEdit {
                    id: headerDataText
                    readOnly: true
                    focus: true
                    selectByMouse: true
                    font.pointSize: 8;
                    wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere;
                    color: "white";
                    anchors {
                        top: scrollheader.top;
                        topMargin: 8;
                        left: parent.left;
                        leftMargin: 10;
                        right: parent.right;
                        rightMargin: 10;
                    }
                    text: AppManager.headers
                }
            }
        }

        Rectangle {
            id: bodyLabel
            width: parent.width
            height: 25
            color: "transparent"
            anchors.top: headerData.bottom;
            RowLayout {
                Text {
                    font.pixelSize: 17
                    text: "Body"
                    color: "#F3F3F3"
                }
            }
        }

        Rectangle {
            id: bodyData
            width: parent.width - 50
            height: 200
            color: "black"
            anchors.top: bodyLabel.bottom;
            x: 20

            ScrollView {
                id: scrollbody
                anchors.fill: parent
                clip: true

                TextEdit {
                    id: bodyDataText
                    readOnly: true
                    focus: true
                    selectByMouse: true
                    font.pointSize: 8;
                    wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere;
                    color: "white";
                    anchors {
                        top: parent.top;
                        topMargin: 8;
                        left: parent.left;
                        leftMargin: 10;
                        right: parent.right;
                        rightMargin: 10;
                    }
                    text: AppManager.body
                }
            }
        }
    }
}
