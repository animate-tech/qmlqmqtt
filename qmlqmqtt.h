#ifndef QMLQMQTT_H
#define QMLQMQTT_H
#include <qmqtt.h>
#include <qmqtt_message.h>

class QmlQMQTT : public  QMQTT::Client
{
    Q_OBJECT
    Q_DISABLE_COPY(QmlQMQTT)

public:
    QmlQMQTT(QObject *parent = nullptr);
    ~QmlQMQTT();

    Q_INVOKABLE int qmlpublish(const QString &topic, const QString &message, const int qos = 0, const bool retain = false);

signals:
    void qmlreceived(const QString &topic, const QString &message);
};

#endif // QMLQMQTT_H
