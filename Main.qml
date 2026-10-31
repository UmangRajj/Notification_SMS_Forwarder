import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts
import "Pages"

ApplicationWindow {
    id: root
    visible: true
    width: 360
    height: 640
    title: "Notification SMS Forwarder"

    property real pageMargin: 10
    property real cornerRadius: 10

    SwipeView {
        id: swiper
        anchors.fill: parent
        onCurrentIndexChanged: pageTab.currentIndex = currentIndex

        ServicePage {
            id: servicePage
        }
        SmsPage {
            id: smsPage
        }

        SettingsPage {
            id: settingsPage
        }
    }

    TabBar {
        id: pageTab
        onCurrentIndexChanged: swiper.currentIndex = currentIndex
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            //margins: 15
        }
        background: Rectangle {
            color: "transparent"
        }

        // Pagebutton is custom, dosen't come from controls
        PageButton {
            text: "Service"
        }
        PageButton {
            text: "SMS"
        }
        PageButton {
            text: "Settings"
        }
    }
}
