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
        leftPadding: 15
        anchors.fill: parent
        placeholderText: item1.placeholderText
        text: item1.text
        placeholderTextColor: "#707070"
        color: "#707070"
        background: Rectangle
        {
            id: innerRect
            radius:10
        }
        onEditingFinished: () => {
             item1.editingFinished(txt.text);
        }
    }
}