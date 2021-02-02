import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0
import UnitTestModel 1.0

import "../components"


Item
{
    property var runButton
    property var ipField
    property var methodLoader


//    Get {
//        id: get
//        onReplyReady: function() {
//            AppManager.body = get.getBody();
//            AppManager.headers = get.getHeaders();
//            AppManager.statusCode = get.getStatusCode();
//            methodLoader.setSource("ResultsTab.qml", {"x": "x"});
//        }
//        onAlreadyRunning: function() {
//            console.log("already running!");
//        }
//    }

//    Connections {
//        target: runButton
//        function onClicked(_) {
//            get.setUrl(ipField.text);
//            get.parseParameters(parameters.getList());
//            get.run();
//        }
//    }

    Rectangle
    {
        id: titleBar
        width: parent.width
        height: 30
        color: "transparent"
        Text
        {
            anchors.verticalCenter: titleBar.verticalCenter
            anchors.horizontalCenter: titleBar.horizontalCenter
            text: "Unit Tests"
            font.pixelSize: 20
            color: "#F3F3F3"
        }
    }


    Rectangle
    {
        id: labels
        anchors.top: titleBar.bottom
        width: parent.width
        height: 50
        color: "transparent"
        RowLayout
        {
            width: parent.width
            spacing: 0
            Text
            {
                Layout.leftMargin: 10
                font.pixelSize: 17
                text: "METHOD"
                color: "#F3F3F3"
            }
            Text
            {
                font.pixelSize: 17
                text: "IP"
                color: "#F3F3F3"
            }
            Text
            {
                font.pixelSize: 17
                text: "STATUS CODE?"
                color: "#F3F3F3"
            }
            //ADDING ROWS OF METHODS
            RoundButton {
                text: "+"
                onClicked: function()
                {
                    methods.insertRow();
                }
            }
            RoundButton
            {
                icon.source: "../resources/clear.png"
                icon.width: 15
                onClicked: function()
                {
                    methods.clearRow();
                }
            }
        }
    }

    ListView
    {
        id:list1
        anchors.top: labels.bottom
        width: parent.width
        height: parent.height
        clip: false
        spacing: 10

        model: UnitTestModel
        {
            id: methods
        }


        delegate: ColumnLayout
        {
            property var paramters_count : methods.parametersCount(model.id)
            property var method_id : model.id

            RowLayout
            {
                ComboBox
                {
                    id:choice
                    Layout.leftMargin: 10
                    model: ["GET", "POST", "PUT","DELETE"]
                    onCurrentIndexChanged: model.method=currentText
                }

                CustomTextField
                {
                    Layout.preferredWidth: 100
                    Layout.preferredHeight: 40
                    text:model.ip
                    onEditingFinished: model.ip =text
                }
                CustomTextField
                {
                    Layout.preferredWidth: 100
                    Layout.preferredHeight: 40
                    text: model.resStatusCode
                    onEditingFinished: model.resStatusCode = text
                }
                RoundButton
                {
                    visible: (choice.currentText=="DELETE")?false:true
                    text: "+"
                    onClicked: function()
                    {
                        methods.insertParameterRow(model.id);
                    }
                }
                RoundButton
                {
                    visible: (choice.currentText=="DELETE")?false:true
                    icon.source: "../resources/clear.png"
                    icon.width: 15
                    onClicked: function()
                    {
                        methods.clearParameterRow(model.id);
                    }
                }
            }

            Repeater
            {
                model:(choice.currentText==="DELETE")?1:paramters_count;

                delegate: RowLayout
                {
                    CustomTextField
                    {
                        Layout.leftMargin: 40
                        Layout.preferredWidth: 160
                        Layout.preferredHeight: 40
                        text:method_id
                        onEditingFinished: methods.setParameter(method_id,index,0,text)
                    }
                    CustomTextField
                    {
                        visible: (choice.currentText=="DELETE")?false:true
                        Layout.leftMargin: 10
                        Layout.preferredWidth: 160
                        Layout.preferredHeight: 40
                        text:index
                        onEditingFinished: methods.setParameter(method_id,index,1,text)
                    }
                }
            }
        }
    }
}

