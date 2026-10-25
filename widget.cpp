#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Q_DECLARE_JNI_CLASS(JNotifListener, "notifListen/NotificationListener")

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    widgetInst = this;
    ui->setupUi(this);
    ui->repeatTime->setTime(QTime(1, 30));
    ui->repeatTime->setMaximumTime(QTime(24, 0));

    connect(ui->serviceToggleBtn, &QPushButton::toggled, [this] (const bool &checked) {
        if (checked) {
            ui->serviceToggleBtn->setText("Stop Service");
        } else {
            ui->serviceToggleBtn->setText("Start Service");
        }
    });
    connect(this, &Widget::notifReceived, this, &Widget::notifProcess, Qt::QueuedConnection);
}

Widget::~Widget()
{
    delete ui;
}

Q_DECL_EXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    QJniEnvironment env;
    bool registerResult = env.registerNativeMethods<QtJniTypes::JNotifListener>({
        Q_JNI_NATIVE_SCOPED_METHOD(listenerConnected, Widget),
        Q_JNI_NATIVE_SCOPED_METHOD(listenerDisconnected, Widget),
        Q_JNI_NATIVE_SCOPED_METHOD(notificationReceived, Widget)
    });

    qWarning () << "Java native functions" << ((registerResult)? "successfully" : "couldn't be") << "registered!";

    // google says that this function should return
    // the version of jni used
    return JNI_VERSION_1_6;
}

void Widget::notifProcess(const QString &pkg, const QString &text, long time)
{
    QMessageBox::information(this, pkg, text);
}
