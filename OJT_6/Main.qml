import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 360
    height: 480
    visible: true
    title: "계산기"

    ColumnLayout {
        id: column_Layout
        anchors.fill: parent
        spacing: 5

        TextInput {
            id: button_text
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 360
            Layout.preferredHeight: 120
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 20
            rightPadding: 15
            leftPadding: 15
        }

        GridLayout {
            id: gridLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 360
            Layout.preferredHeight: 360
            rows: 4
            columns: 4

            Button {
                id: button_7
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "7"
                onClicked: button_text.text += 7777777777777
            }

            Button {
                id: button_8
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "8"
                onClicked: button_text.text += 8
            }

            Button {
                id: button_9
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "9"
                onClicked: button_text.text += 9
            }

            Button {
                id: button_add
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "+"
                onClicked: button_text.text += "+"
            }

            Button {
                id: button_4
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "4"
                onClicked: button_text.text += 4
            }

            Button {
                id: button_5
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "5"
                onClicked: button_text.text += 5
            }

            Button {
                id: button_6
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "6"
                onClicked: button_text.text += 6
            }

            Button {
                id: button_subtract
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "-"
                onClicked: button_text.text += "-"
            }

            Button {
                id: button_1
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "1"
                onClicked: button_text.text += 1
            }

            Button {
                id: button_2
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "2"
                onClicked: button_text.text += 2
            }

            Button {
                id: button_3
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "3"
                onClicked: button_text.text += 3
            }

            Button {
                id: button_multiply
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "*"
                onClicked: button_text.text += "*"
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                Button {
                    anchors.fill: parent
                    id: button_clear
                    text: "clear"
                }
            }

            Button {
                id: button_0
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "0"
                onClicked: button_text.text += 0
            }

            Button {
                id: button_equal
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "="
            }

                Button {
                id: button_divide
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "/"
                onClicked: button_text.text += "/"
            }
        }
    }
}
