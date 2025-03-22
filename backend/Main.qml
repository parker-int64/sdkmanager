import QtQuick
import QtQuick.Window
import QtWebEngine
import QtWebChannel
import com.seeed.wsl

Window {
    width: 800
    height: 600
    minimumWidth: 866
    minimumHeight: 600
    visible: true
    title: qsTr("SDK Manager")

    WSLManager {
        id: manager
        WebChannel.id: "wslmanager"
    }

    WebEngineView {
        anchors.fill: parent
        url: "http://localhost:5173/"
        webChannel: channel
    }

    WebChannel {
        id: channel
        registeredObjects: [manager]
    }
}
