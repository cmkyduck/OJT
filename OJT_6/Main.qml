import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 360
    height: 480
    visible: true
    title: qsTr("cal")

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Text {
            id: calculator_text
            Layout.fillWidth: true
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 20
            rightPadding: 15
            height: 120
            Layout.preferredWidth: 360
            Layout.preferredHeight: 120
        }

        GridLayout{
            id: gridLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            rows: 4
            columns: 4
            //Layout.alignment: bottom
            Layout.preferredWidth: 360
            Layout.preferredHeight: 360

            Button {
                id: button_7
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "7"
            }

            Button {
                id: button_8
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "8"
            }

            Button {
                id: button_9
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "9"
            }

            Button {
                id: button_add
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "+"
            }

            Button {
                id: button_4
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "4"
            }

            Button {
                id: button_5
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "5"
            }

            Button {
                id: button_6
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "6"
            }

            Button {
                id: button_subtract
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "-"
            }

            Button {
                id: button_1
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "1"
            }

            Button {
                id: button_2
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "2"
            }

            Button {
                id: button_3
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "3"
            }

            Button {
                id: button_multiply
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "*"
            }

            Button {
                id: button_clear
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "clear"
            }


            Button {
                id: button_0
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "0"
            }

            Button {
                id: button_equal
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "="
            }

            Button {
                id: button_divide
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: "/"
            }
        }
    }
}
