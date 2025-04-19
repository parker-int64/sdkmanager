import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtWebEngine
import QtWebChannel
import com.seeed.wsl
import com.seeed.appctrl

Window {
    id: app
    width: 800
    height: 600
    visible: true
    title: qsTr("SDK Manager")
    minimumWidth: 640

    WSLManager {
        id: manager
        WebChannel.id: "wslManager"
    }

    AppController {
        id: appctrl
        WebChannel.id: "appController"
    }

    WebEngineView {
        id: webview
        anchors.fill: parent
        url: "http://localhost:5173/"
        webChannel: channel
        onLoadingChanged: {
            if (webview.loading) {
                busyIndicator.running = true;  // 显示 BusyIndicator
            } else {
                busyIndicator.running = false; // 隐藏 BusyIndicator
            }
        }
    }

    WebChannel {
        id: channel
        registeredObjects: [manager, appctrl]
    }

    BusyIndicator {
        id: busyIndicator
        running: true
        anchors.centerIn: parent
        width: 50
        height: 50
    }
}
