import QtQuick 1.1
import com.nokia.meego 1.0

Sheet{
    id: editAccountSheet

    anchors.fill: parent
    visualParent: accountListPage

    property alias name: nameInput.text

    property bool edit: false

    acceptButtonText: "OK"
    rejectButtonText: "Cancel"

    content: Flickable {
        anchors.fill: parent
        contentHeight: sheetContent.height

        Column {
            id: sheetContent
            spacing: 12

            anchors{top: parent.top; left: parent.left; right: parent.right; margins: 15}

            Text {
                id: nameText
                text: qsTr("Name")
            }

            TextField{
                id: nameInput

                width: parent.width

                placeholderText: "Enter Name"
            }
        }
    }

    onAccepted: {
        if(edit) {
        } else {
            accountAdapter.addAccount(name)
        }

        editAccountSheet.close()
    }

    onRejected: editAccountSheet.close()
}

