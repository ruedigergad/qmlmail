/*
 *  Copyright 2012 Ruediger Gad
 *
 *  This file is part of qmlmail.
 *
 *  qmlmail is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  qmlmail is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with QZeeControl.  If not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 1.1
import com.nokia.meego 1.0
import qmlmail 1.0

Page{
    id: accountListPage

    tools: accountListPageTools
    orientationLock: PageOrientation.LockPortrait

    ToolBarLayout {
        id: accountListPageTools
        visible: true

        ToolIcon {
            id: iconAdd

            platformIconId: "toolbar-add"
            opacity: enabled ? 1 : 0.5

            onClicked: editAccountSheet.open()
        }

        ToolIcon {
            id: iconMarkDone

            platformIconId: "toolbar-edit"
            opacity: enabled ? 1 : 0.5
        }

        ToolIcon {
            id: iconMenu

            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            opacity: enabled ? 1 : 0.5

            onClicked: (accountListPageMenu.status === DialogStatus.Closed) ? accountListPageMenu.open() : accountListPageMenu.close()
        }
    }

    Menu {
        id: accountListPageMenu
        visualParent: pageStack

        MenuLayout {
            MenuItem {
                text: "About"
            }
        }
    }

    AccountSortFilterModel{
        id: accountModel
    }

    EditAccountSheet{
        id: editAccountSheet
    }

    Rectangle {
        anchors.fill: parent
        color: "lightgray"

        Rectangle {
            id: header
            height: 72
            color: "#a30085"
            anchors{left: parent.left; right: parent.right; top: parent.top}
            z: 48

            Text {
                text: "E-Mail"
                color: "white"
                font{pixelSize: 32; family: "Nokia Pure Text Light"}
                anchors{left: parent.left; leftMargin: 20; verticalCenter: parent.verticalCenter}
            }
        }

        ListView{
            id: accountListView

            anchors {
                top: header.top
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            model: accountModel
        }
    }
}
