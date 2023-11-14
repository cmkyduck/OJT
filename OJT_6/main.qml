import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 360
    height: 480
    visible: true
    title: "계산기"

    ColumnLayout {
        id: column_layout
        anchors.fill: parent
        spacing: 5

        TextInput {
            // 정규표현식으로 숫자와 특수기호만 작성되게 제한
            validator: RegExpValidator { regExp: /^[0-9+\\-*/]*$/ }

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
            focus: true

            // 엔터키를 눌렀을 경우 "="버튼을 눌렀을 경우와 똑같이 작동
            onAccepted: {
                Calculator.input_string = button_text.text;
                var result = Calculator.calculate();
                var error = Calculator.calculate();
                // 에러코드가 반환되었을 경우 입력값을 지움
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
                onClicked: {
                    button_text.text += 6
                    button_text.forceActiveFocus()
                }
            }

            Button {
                id: button_subtract
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "-"
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                focus: true
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
                onClicked: {
                    button_text.text += "/"
                    button_text.forceActiveFocus()
                }
            }
        }
    }
}
