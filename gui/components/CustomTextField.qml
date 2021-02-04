import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.15
import ParameterModel 1.0

Item {
    id: item1
    signal editingFinished(string text)
    property string placeholderText: "Placeholder text"
    property string text: ""
    property string color_rec: "white"
    property string color_text: "#707070"

    DropShadow {
        anchors.fill: txt
        source: txt
        horizontalOffset: 0
        verticalOffset: 3
        opacity: 0.2
        radius: 6
    }

    TextField
    {
        id: txt
        anchors.fill: parent
        placeholderText: item1.placeholderText
        text: item1.text
        placeholderTextColor: "#707070"
        color: item1.color_text
        background: Rectangle
        {
            id: innerRect
            color:item1.color_rec
            radius:10
        }
        onEditingFinished: () => {
                item1.editingFinished(txt.text)
                item1.text=txt.text
        }
        leftPadding: 10
        rightPadding: 10
        topPadding:10
        bottomPadding: 10
    }
}
