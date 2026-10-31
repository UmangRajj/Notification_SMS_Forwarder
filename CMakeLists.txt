cmake_minimum_required(VERSION 3.19)
project(Notification_SMS_Forwarder LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Quick)

qt_standard_project_setup()

qt_add_executable(Notification_SMS_Forwarder
    WIN32 MACOSX_BUNDLE
    main.cpp
)

set_source_files_properties(Theme.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

if (ANDROID)
    qt_add_qml_module(Notification_SMS_Forwarder
        URI SMSForwarder
        QML_FILES
            Main.qml
            PageButton.qml
            Theme.qml
            Pages/ServicePage.qml
            Pages/SettingsPage.qml
            Pages/SmsPage.qml
        SOURCES
            ServiceManager.cpp
            ServiceManager.h

    )
    set_target_properties(Notification_SMS_Forwarder PROPERTIES
       QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    qt_add_qml_module(Notification_SMS_Forwarder
        URI SMSForwarder
        QML_FILES
            Main.qml
            PageButton.qml
            Theme.qml
            Pages/ServicePage.qml
            Pages/SettingsPage.qml
            Pages/SmsPage.qml
    )
endif()


target_link_libraries(Notification_SMS_Forwarder
    PRIVATE
        Qt::Core
        Qt6::Quick
)

install(TARGETS Notification_SMS_Forwarder
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Notification_SMS_Forwarder
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
