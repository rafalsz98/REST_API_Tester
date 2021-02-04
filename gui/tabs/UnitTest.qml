import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15

import "../components"

Item
{
    property var runButton
    property var returned_codes
    property var methodLoader

    Connections
    {
        target: runButton
        function onClicked(_)
        {
            UnitTestManager.runTests(UnitTestModel.getList());
        }
    }
    Connections
    {
        target: UnitTestManager
        function onFinished()
        {
            returned_codes=UnitTestManager.getUnitTestResults();
            methodLoader.setSource("UnitTest.qml", {"runButton": runButton, "methodLoader": methodLoader});
        }
    }
    Component.onCompleted: function()
    {
        returned_codes=UnitTestManager.getUnitTestResults();
    }

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
            spacing: 10

            Text
            {
                Layout.leftMargin: 10
                Layout.fillWidth:true
                font.pixelSize: 17
                text: "Add method"
                color: "#F3F3F3"
            }

            RoundButton
            {
                text: "+"
                onClicked: function()
                {
                    UnitTestModel.insertRow();
                }
            }
            Text
            {
                Layout.fillWidth:true
                font.pixelSize: 17
                text: "Remove methods"
                color: "#F3F3F3"
            }
            RoundButton
            {
                icon.source: "../resources/clear.png"
                icon.width: 15
                onClicked: function()
                {
                    UnitTestModel.clearRow();
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
        clip: true
        spacing: 10

        model:UnitTestModel

        delegate: ColumnLayout
        {
            width: parent.width
            property var parameters_count : UnitTestModel.parametersCount(model.id)
            property var method_id : model.id
            property var xd: model

            RowLayout
            {
                Layout.preferredWidth: parent.width

                ComboBox
                {
                    id:choice
                    Layout.leftMargin: 10
                    model: ["GET", "POST", "PUT","DELETE"]
                    onCurrentIndexChanged: xd.method = currentIndex
                }

                CustomTextField
                {
                    placeholderText:"ENTER IP"
                    Layout.fillWidth:true
                    Layout.preferredHeight: 40
                    text:model.ip
                    onEditingFinished: model.ip =text
                }
                CustomTextField
                {
                    placeholderText:"ENTER EXPECTED STATUS CODE"
                    Layout.fillWidth:true
                    Layout.preferredHeight: 40
                    text: model.resStatusCode
                    onEditingFinished: model.resStatusCode = text
                    color_rec : (returned_codes[method_id]===1)?"red":((returned_codes[method_id]===0)?"green":"white");
                    color_text: (returned_codes[method_id]===1 || returned_codes[method_id]===0 )?"white":"#707070";
                }
                RoundButton
                {
                    visible: (choice.currentText=="DELETE")?false:true
                    text: "+"
                    onClicked: function()
                    {
                        UnitTestModel.insertParameterRow(model.id);
                    }
                }
                RoundButton
                {
                    visible: (choice.currentText=="DELETE")?false:true
                    icon.source: "../resources/clear.png"
                    icon.width: 15
                    onClicked: function()
                    {
                        UnitTestModel.clearParameterRow(model.id);
                    }
                }
                Layout.rightMargin:10

            }

            Repeater
            {
                model:(choice.currentText==="DELETE")?1:parameters_count;
                Layout.fillWidth:true

                delegate: RowLayout
                {
                    CustomTextField
                    {
                        placeholderText:"KEY"
                        Layout.leftMargin: 40
                        Layout.preferredHeight: 40
                        Layout.fillWidth:true
                        text:UnitTestModel.getParameter(method_id,index,0)
                        onEditingFinished: UnitTestModel.setParameter(method_id,index,0,text)
                        Layout.rightMargin:10
                    }
                    CustomTextField
                    {
                        placeholderText:"VALUE"
                        visible: (choice.currentText=="DELETE")?false:true
                        Layout.fillWidth:true
                        Layout.rightMargin: 40
                        Layout.preferredHeight: 40
                        text:UnitTestModel.getParameter(method_id,index,1)
                        onEditingFinished: UnitTestModel.setParameter(method_id,index,1,text)
                    }
                }
            }
        }
    }
}

