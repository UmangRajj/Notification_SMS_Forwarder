#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <jni.h>
#include <QDebug>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
public slots:
    // the slot for processing the signal
    void notifProcess(const QString &pkg, const QString &text, long time);
signals:
    // special signal for queued connection, because
    // the main native call comes from other thread
    void notifReceived(const QString &pkg, const QString &text, long time);

public:
    static void listenerConnected(JNIEnv *env, jobject thiz)
    {
        qWarning() << "Listner Connected!";
    }
    static void listenerDisconnected(JNIEnv *env, jobject thiz)
    {
        qWarning() << "Listner Disconnected!";
    }
    static void notificationReceived(JNIEnv *env, jobject thiz, jstring pkg, jstring text, jlong time)
    {
        qWarning() << "Notificatoin received and catched by listener!";
        if (widgetInst)
            emit widgetInst->notifReceived(QJniObject(pkg).toString(), QJniObject(text).toString(), time);
    }

    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(listenerConnected);
    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(listenerDisconnected);
    Q_DECLARE_JNI_NATIVE_METHOD_IN_CURRENT_SCOPE(notificationReceived);
private:
    Ui::Widget *ui;
    inline static Widget *widgetInst {nullptr};
};
#endif // WIDGET_H
