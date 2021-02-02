import QtQuick 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import "./components"

ApplicationWindow {
    width: 640
    height: 580
    visible: true
    title: qsTr("REST API Tester")
    color: "#36413E"
    Component.onCompleted: function() {
        methodLoader.setSource("tabs/ResultsTab.qml", {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader});
    }

    Rectangle {
        id: upperBar
        width: parent.width
        height: 100
        color: "#5D5E60"
    }

    DropShadow {
        anchors.fill: upperBar
        source: upperBar
        horizontalOffset: 0
        verticalOffset: 3
        opacity: 0.2
        radius: 6
        samples: 8
    }

    RowLayout {
        anchors.verticalCenter: upperBar.verticalCenter
        spacing: 40
        CustomTextField {
            id: ipField
            Layout.leftMargin: 60
            Layout.preferredWidth: 300
            Layout.preferredHeight: 40
            placeholderText: "IP"
            onEditingFinished: console.log(text)
        }

        Rectangle {
            Layout.preferredHeight: 30
            Layout.preferredWidth: 30
            color: "#8AC926"
            radius: 10
            Image {
                source: "resources/enter_key.png"
                anchors.centerIn: parent
            }
            MouseArea {
                id: runButton
                anchors.fill: parent
            }
        }
    }

    DropShadow {
        anchors.fill: tabsBar
        source: tabsBar
        horizontalOffset: 3
        verticalOffset: 0
        opacity: 0.2
        radius: 6
    }

    Rectangle {
        id: tabsBar
        anchors.bottom: parent.bottom
        width: parent.width / 4
        height: parent.height - upperBar.height
        color: "#8D8D92"
    }

    ColumnLayout {
        anchors.top: tabsBar.top
        width: tabsBar.width
        spacing: -1
        TabOption{
            methodLoader: methodLoader
            name: "GET"
            address: "tabs/GetTab.qml"
            properties: {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader}
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width
        }
        TabOption{
            methodLoader: methodLoader
            name: "POST"
            address: "tabs/PostTab.qml"
            properties: {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader}
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width
        }
        TabOption{
            methodLoader: methodLoader
            name: "DELETE"
            address: "tabs/DeleteTab.qml"
            properties: {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader}
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width
        }
        TabOption{
            methodLoader: methodLoader
            name: "PUT"
            address: "tabs/PutTab.qml"
            properties: {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader}
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width
        }
        TabOption{
            methodLoader: methodLoader
            name: "Unit Tests"
            address: "tabs/UnitTest.qml"
            properties: {"runButton": runButton, "ipField": ipField, "methodLoader": methodLoader}
            Layout.preferredHeight: 30
            Layout.preferredWidth: parent.width
        }
        TabOption{
            methodLoader: methodLoader
            name: "Results"
            address: "tabs/ResultsTab.qml"
            properties: {"x": "x"}
            Layout.preferredHeight: 50
            Layout.preferredWidth: parent.width
        }
    }

    Item {
        width: 3 * parent.width / 4
        height: tabsBar.height
        anchors.left: tabsBar.right
        anchors.bottom: parent.bottom
        Loader {
            width: parent.width
            height: parent.height
            id: methodLoader
        }
    }

}
