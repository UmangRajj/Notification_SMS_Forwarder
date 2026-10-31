import QtQuick
import QtQuick.Controls

TabButton {
    id: tabBtn

    property real sideRadius: 30

    readonly property bool isFirst: TabBar.index == 0
    readonly property bool isLast: TabBar.index == TabBar.tabBar.count-1

    height: tabBtn.checked? 35: 31

    contentItem: Text {
        color: tabBtn.checked ? "white" : "black"
        text: tabBtn.text
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        color: tabBtn.checked ? Theme.accent : Theme.secondary

        topLeftRadius: tabBtn.isFirst ? tabBtn.sideRadius : 0
        //bottomLeftRadius: tabBtn.isFirst ? tabBtn.sideRadius : 0
        topRightRadius: tabBtn.isLast ? tabBtn.sideRadius : 0
        //bottomRightRadius: tabBtn.isLast ? tabBtn.sideRadius : 0
    }
}
