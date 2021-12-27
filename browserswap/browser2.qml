/******************************************************************************
 **
 ** Copyright (C) 2014 - 2020 Weintek, Inc. All rights reserved.
 ** Contact: http://www.weintek.com
 **
 ** This file is part of the Weintek Browser.
 **
 ** $BEGIN_LICENSE:COMM$
 **
 ** Commercial License Usage
 **
 ** Licensees holding a valid Commercial License for this product from
 ** Weintek, Inc. may use this file in accordance with the
 ** Commercial License Agreement provided with the Software.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
 ** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 ** PURPOSE.
 **
 ** $END_LICENSE$
 **
 ******************************************************************************/

import QtQuick 2.0
import QtQuick.Layouts 1.0
import Weintek.Browser 1.0

Rectangle {
    width: 1024
    height: 768
    property int loading: 0

    BrowserView {
        id: browser
        x:100
        y:100
        width:1700
        height:800
    }

    Component.onCompleted: {
        console.log("onCompleted")
        browser.url = "https://tw.yahoo.com"
        browser.home = "https://www.webkit2gtk.org"
        browser.show()
    }
    
    Component.onDestruction: {
        console.log("Destruction Beginning!")
    }
}
