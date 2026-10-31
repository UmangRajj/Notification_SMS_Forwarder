#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include <jni.h>
#include <QDebug>
#include <QGuiApplication>

// Worker java classes ke jni handle
Q_DECLARE_JNI_CLASS(JNotifListener, "worker/NotificationListener")


class ServiceManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit ServiceManager(QObject *parent = nullptr);

    //--NATIVE FUNCTIONS CALLED FROM JAVA!
    static void listenerConnected(JNIEnv *env, jobject thiz)
    {
        qWarning() << "Listner Connected!";
    }
    static void listenerDisconnected(JNIEnv *env, jobject thiz)
    {
        qWarning() << "Listner Disconnected!";
    }
    static void notificationReceived(JNIEnv *env, jobject thiz, jstring title, jstring text, jlong time)
    {
        qWarning() << "Notificatoin received and catched by listener!";
        if (serviceMgr)
            emit serviceMgr->notifReceived(QJniObject(title).toString(), QJniObject(text).toString(), time);
    }

    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(listenerConnected);
    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(listenerDisconnected);
    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(notificationReceived);

    //--Work Functions
    void parseNotification(QString notif);
    void sendSms(QString text);

public slots:
    // the slot for processing the signal
    void notifProcess(const QString &title, const QString &text, long time);
signals:
    // special signal for queued connection, because
    // the main native call comes from other thread
    void notifReceived(const QString &title, const QString &text, long time);

private:
    inline static ServiceManager *serviceMgr {nullptr};
    QString notificationCache;
};
#endif // SERVICEMANAGER_H
