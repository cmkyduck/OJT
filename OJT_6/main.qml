import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 360
    height: 480
    visible: true
    title: "calculator"

    ColumnLayout {
        id: column_layout
        anchors.fill: parent

        TextInput {
            id: button_text
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 200
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 20
            rightPadding: 15
            leftPadding: 15

            validator: RegExpValidator { regExp: /^[0-9\\+*/-]*$/ }

            onAccepted: {
                Calculator.input_string = button_text.text;
                var result = Calculator.calculate();
                var error = Calculator.calculate();
                if (error === 1) {
                    button_text.text = "";
                } else {
                    button_text.text = result;
                }
                button_text.forceActiveFocus();
            }
        }

        GridLayout {
            id: grid_layout
            columnSpacing: 5
            rowSpacing: 5
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 360
            Layout.preferredHeight: 280
            rows: 4
            columns: 4

            Button {
                id: button_7
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "7"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 7
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_8
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "8"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 8
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_9
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "9"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 9
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_add
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "+"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += "+"
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_4
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "4"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 4
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_5
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "5"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 5
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_6
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "6"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 6
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_subtract
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "ㅡ"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += "-"
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_1
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "1"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 1
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_2
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "2"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 2
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_3
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "3"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 3
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_multiply
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "*"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += "*"
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_clear
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "clear"
                font.bold: true
                onClicked: {
                    button_text.text = ""
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_0
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "0"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += 0
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_equal
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "="
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    Calculator.input_string = button_text.text;
                    var result = Calculator.calculate();
                    var error = Calculator.calculate();
                    if (error === 1) {
                        button_text.text = "";
                    } else {
                        button_text.text = result;
                    }
                    button_text.forceActiveFocus();
                }
            }

            Button {
                id: button_divide
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "/"
                font.pixelSize: 20
                font.bold: true
                onClicked: {
                    button_text.text += "/"
                    button_text.forceActiveFocus()
                }
            }
        }
    }

    Switch {
        id: switch1
        x: 0
        y: 0

        onToggled: {
            if(checked) {
                button_0.highlighted = true;
                button_1.highlighted = true;
                button_2.highlighted = true;
                button_3.highlighted = true;
                button_4.highlighted = true;
                button_5.highlighted = true;
                button_6.highlighted = true;
                button_7.highlighted = true;
                button_8.highlighted = true;
                button_9.highlighted = true;
                button_add.highlighted = true;
                button_subtract.highlighted = true;
                button_multiply.highlighted = true;
                button_clear.highlighted = true;
                button_equal.highlighted = true;
                button_divide.highlighted = true;

                window.color = "#060505";
                button_text.color = "#ffffff";
            } else {
                button_0.highlighted = false;
                button_1.highlighted = false;
                button_2.highlighted = false;
                button_3.highlighted = false;
                button_4.highlighted = false;
                button_5.highlighted = false;
                button_6.highlighted = false;
                button_7.highlighted = false;
                button_8.highlighted = false;
                button_9.highlighted = false;
                button_add.highlighted = false;
                button_subtract.highlighted = false;
                button_multiply.highlighted = false;
                button_clear.highlighted = false;
                button_equal.highlighted = false;
                button_divide.highlighted = false;

                window.color = "#ffffff";
                button_text.color = "#060505";
            }
        }
    }
}


