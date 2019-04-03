#include "qmlqmqtt.h"

#include <QDebug>

QmlQMQTT::QmlQMQTT(QObject *parent): QMQTT::Client(QHostAddress::LocalHost, 1883, parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
    connect(this, &QmlQMQTT::received, this, [this](const QMQTT::Message& message){
            emit qmlreceived(message.topic(), QString(message.payload()));
     });
}

QmlQMQTT::~QmlQMQTT()
{
    qDebug()<<"delete Mqtt";
}
int QmlQMQTT::qmlpublish(const QString &topic, const QString &message, const int qos, const bool retain)
{
    QMQTT::Message mMessage;
    mMessage.setTopic(topic);
    mMessage.setPayload(message.toUtf8());
    mMessage.setQos(quint8(qos));
    mMessage.setRetain(retain);
    return publish(mMessage);
}
