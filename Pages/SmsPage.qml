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
            text: "Set up message receipients\n(Disabled when Service is Active!)"
            Layout.alignment: Qt.AlignHCenter
            horizontalAlignment: Text.AlignHCenter
        }
        RowLayout {
            spacing: 10
            Label {
                text: "SMS Recipients"
                Layout.fillWidth: true
            }
            SpinBox {
                id: recipientCount
                value: 1
            }
        }

        Item /*Spacer*/ {
            Layout.fillHeight: true
        }
    }
}