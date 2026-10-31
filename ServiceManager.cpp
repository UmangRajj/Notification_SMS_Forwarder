#include "ServiceManager.h"

#include <QApplication>

ServiceManager::ServiceManager(QObject *parent)
    : QObject(parent)
{
    serviceMgr = this;
}

void ServiceManager::parseNotification(QString notif)
{

}

void ServiceManager::sendSms(QString text)
{

}

Q_DECL_EXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    QJniEnvironment env;
    bool registerResult = env.registerNativeMethods<QtJniTypes::JNotifListener>({
        Q_JNI_NATIVE_SCOPED_METHOD(listenerConnected, ServiceManager),
        Q_JNI_NATIVE_SCOPED_METHOD(listenerDisconnected, ServiceManager),
        Q_JNI_NATIVE_SCOPED_METHOD(notificationReceived, ServiceManager)
    });

    qWarning () << "Java native functions" << ((registerResult)? "successfully" : "couldn't be") << "registered!";

    // documentation kehta hai ki return the
    // version of jni used in JNI_OnLoad func
    return JNI_VERSION_1_6;
}

void ServiceManager::notifProcess(const QString &title, const QString &text, long time)
{
    //QMessageBox::information(this, title, text);

}
