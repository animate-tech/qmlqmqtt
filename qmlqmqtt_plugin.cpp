#include "qmlqmqtt_plugin.h"
#include "qmlqmqtt.h"

#include <qqml.h>

void QmlQMQTTPlugin::registerTypes(const char *uri)
{
    // @uri QmlQMQTT
    qmlRegisterType<QmlQMQTT>(uri, 1, 0, "QmlQMQTT");
}

