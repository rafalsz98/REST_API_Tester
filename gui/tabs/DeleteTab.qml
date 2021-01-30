import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import Delete 1.0

Frame
{
    Delete{}

//    required property Button runButton

    Connections
    {
        target: runButton
        onClicked:()=>
                  {
                      Delete.setUrl("https://reqbin.com/");
                      Delete.setParameter("sample");
                      Delete.run();
                  }
    }

    ListView
    {
        implicitHeight: 250
        implicitWidth: 250
        anchors.fill: parent
        clip: true

        model: 1
        delegate: RowLayout
        {
            width: parent.width

            TextField
            {
                id: txt
                Layout.fillWidth: true
                x: 0
                y: 76
                width: 507
                height: 43
                text: qsTr("Text Field")
                color: "black"
                background: Rectangle
                {
                    radius:100
                }
                leftPadding: 10
                rightPadding: 10
                topPadding:15

//                text: model.description
//                onEditingFinished: model.description = text
            }

            RoundButton
            {
                id: roundButton
                x: 575
                y: 74
                text: "+"
                background: Rectangle
                {
                    color:"green"
                    radius:31.4
                }
                leftPadding:14
                rightPadding:14

                Layout.fillWidth: false

                onClicked:function()
                {
//                    onClicked: toDoList.appendItem()
                }
            }
        }
    }
}
