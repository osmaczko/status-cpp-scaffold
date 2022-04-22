import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

import Chat 1.0 as ChatPlugin
import Wallet 1.0 as WalletPlugin

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RowLayout {
        id: layout
        anchors.fill: parent
        anchors.margins: 4

        ColumnLayout {
            Layout.minimumWidth: 100
            Layout.preferredWidth: layout.width / 8
            Layout.maximumWidth: 200

            spacing: 2

            Button {
                Layout.fillWidth: true
                text: qsTr("Chat")
                onClicked: swipeView.currentIndex = 0
            }

            Button {
                Layout.fillWidth: true
                text: qsTr("Wallet")
                onClicked: swipeView.currentIndex = 1
            }

            Item {
                Layout.fillHeight: true
            }
        }

        SwipeView {
            id: swipeView

            Layout.fillWidth: true
            Layout.fillHeight: true

            interactive: false
            orientation: Qt.Vertical

            ChatPlugin.ChatView {
            }

            WalletPlugin.WalletView {
            }
        }
    }
}
