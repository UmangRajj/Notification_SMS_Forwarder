package notifListen;

import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;
import android.app.Notification;


public class NotificationListener extends NotificationListenerService
{
    public native void listenerConnected();
    public native void listenerDisconnected();
    public native void notificationReceived(String pkg, String notification, long time);

    @Override
    public void onListenerConnected()
    {
        super.onListenerConnected();
        listenerConnected();
    }
    @Override
    public void onListenerDisconnected()
    {
        super.onListenerDisconnected();
        listenerDisconnected();
    }
    @Override
    public void onNotificationPosted(StatusBarNotification sbn, NotificationListenerService.RankingMap rank)
    {
        super.onNotificationPosted(sbn, rank);
        notificationReceived(sbn.getPackageName(), sbn.getNotification().extras.getCharSequence(Notification.EXTRA_TEXT).toString()
                             , sbn.getPostTime());
    }


}