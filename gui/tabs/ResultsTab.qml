import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0

import "../components"


Item {
    property var statusCodeProperty
    property var headerProperty
    property var bodyProperty

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
            color: "transparent"
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
                text: statusCodeProperty
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
            color: "transparent"
            anchors.top: headerLabel.bottom;
            x: 20
            TextEdit {
                id: headerDataText
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
                text: headerProperty
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
            height: 70
            color: "transparent"
            anchors.top: bodyLabel.bottom;
            x: 20
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
                text: bodyProperty
            }
        }
    }
}
