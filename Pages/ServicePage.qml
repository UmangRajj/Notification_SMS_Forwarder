import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ".."

Rectangle {
    color: Theme.primary

    ColumnLayout {
        spacing: 40
        anchors.fill: parent
        anchors.margins: pageMargin

        Label {
            text: "Set up service and it's lifetime\n(Controls Disabled when Service is Active!)"
            Layout.alignment: Qt.AlignHCenter
            horizontalAlignment: Text.AlignHCenter
        }

        DelayButton {
            id: serviceToggle
            Layout.fillWidth: true
            checkable: true

            background: Rectangle {
                color: Theme.secondary
                radius: cornerRadius

                Rectangle {
                    width: parent.width * serviceToggle.progress
                    height: parent.height
                    color: Theme.accent
                    radius: cornerRadius
                    //color: Qt.hsva(1, 1, serviceToggle.progress * 0.5)
                }
            }

            text: this.progress == 1.0 ? "Stop Service" : "Start Service"
        }
        RowLayout {
            spacing: 10
            enabled: serviceToggle.progress == 1? false : true
            Label {
                text: "Service Lifespan"
                Layout.fillWidth: true
            }
            Frame {
                padding: 10
                background: Rectangle {
                    color: Theme.primary
                    border.color: Theme.secondary
                    border.width: 2.5
                    radius: cornerRadius
                }

                RowLayout {
                    Tumbler{
                        id: serviceLifespanHour
                        model: 12
                        currentIndex: 5
                        visibleItemCount: 3
                        Layout.preferredHeight: 80
                    }
                    Tumbler{
                        id: serviceLifespanMin
                        model: 50
                        visibleItemCount: 3
                        Layout.preferredHeight: 80
                    }
                }
            }
        }

        Item /*Spacer*/ {
            Layout.fillHeight: true
        }
    }
}