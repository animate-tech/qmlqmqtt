首先需要编译qmqtt库  然后再编译该插件 
Sourcecode taken from:
 - [qmqtt] (https://github.com/emqtt/qmqtt)
  qmake
  mingw32-make 
  mingw32-make install
  复制头文件到 QT安装目录include qmqtt下
 
编译步骤

1. 进入根目录
2. qmake
3. mingw32-make
4. mingw32-make install

使用

import QmlQMQTT 1.0

    QmlQMQTT {
        id:qmlqmqtt
        _hostName:'mqtt.huikezk.com'
        _clientId: 'qml_ttttt'
        _username:'admin'
        _password:'123456'
        _autoReconnect:true
        _cleanSession: true
        onConnected: {
            qmlqmqtt.subscribe("/北京华联回龙观/#");

        }
        onQmlreceived: {
                console.log("topic:",topic)
                console.log("payload:",message)
        }
        Component.onCompleted: qmlqmqtt.connectToHost()
    }

增加 信号 onQmlreceived(topic, message)
增加 函数 qmlpublish(const QString &topic, const QString &message, const int qos, const bool retain)

其他函数和qmqtt一样， 本例没有导入其他类型 所以只能使用string 等基本类型， 如果有特殊需要可以更改例子自己编译安装