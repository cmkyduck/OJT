import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 360
    height: 480
    visible: true
    title: qsTr("계산기")

    ColumnLayout {
        id: columnLayout
        spacing: 5
        anchors.fill: parent

        Text {
            id: calculator_text
            height: 120
            Layout.fillWidth: true
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 20
            rightPadding: 15
        }
    
        GridLayout{
            id: gridLayout
            width: 360
            height: 360
            Layout.fillWidth: true
            Layout.fillHeight: true
            rows: 4
            columns: 4
    
            Button {
                id: button_7
                width: 80
                height: 80
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("7")
                onClicked: {
                    calculator_text.text += "7"
                }
            }
    
            Button {
                id: button_8
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("8")
                onClicked: {
                    calculator_text.text += "8"
                }
            }
    
            Button {
                id: button_9
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("9")
                onClicked: {
                    calculator_text.text += "9"
                }
            }
    
            Button {
                id: button_add
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("+")
                onClicked: {
                    calculator_text.text += "+"
                }
            }
    
            Button {
                id: button_4
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("4")
                onClicked: {
                    calculator_text.text += "4"
                }
            }
    
            Button {
                id: button_5
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("5")
                onClicked: {
                    calculator_text.text += "5"
                }
            }
    
            Button {
                id: button_6
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("6")
                onClicked: {
                    calculator_text.text += "6"
                }
            }
    
            Button {
                id: button_subtract
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("-")
                onClicked: {
                    calculator_text.text += "-"
                }
            }
    
            Button {
                id: button_1
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("1")
                onClicked: {
                    calculator_text.text += "1"
                }
            }
    
            Button {
                id: button_2
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("2")
                onClicked: {
                    calculator_text.text += "2"
                }
            }
    
            Button {
                id: button_3
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("3")
                onClicked: {
                    calculator_text.text += "3"
                }
            }
    
            Button {
                id: button_multiply
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("*")
                onClicked: {
                    calculator_text.text += "*"
                }
            }
    
            Button {
                id: button_clear
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("clear")
                onClicked: {
                    calculator_text.text -= " "
                }
            }
    
    
            Button {
                id: button_0
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("0")
                onClicked: {
                    calculator_text.text += "0"
                }
            }
    
            Button {
                id: button_equal
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("=")
                onClicked: {
                    calculator_text.text += "="
                }
            }
    
            Button {
                id: button_divide
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 20
                text: qsTr("/")
                onClicked: {
                    calculator_text.text += "/"
                }
            }
        }
    }
}
