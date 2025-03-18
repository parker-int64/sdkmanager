import QtQuick
import QtQuick.Window
import QtWebEngine

Window {
    width: 800
    height: 600
    minimumWidth: 866
    minimumHeight: 600
    visible: true
    title: qsTr("SDK Manager")
    WebEngineView {
            anchors.fill: parent
            url: "http://localhost:5173/"
        }
}
