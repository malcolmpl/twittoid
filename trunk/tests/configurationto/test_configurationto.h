#ifndef TEST_CONFIGURATIONTO_H_
#define TEST_CONFIGURATIONTO_H_

#include <QtTest/QtTest>

class TestConfigurationTO : public QObject
{
    Q_OBJECT
private slots:
    void login();
    void password();
    void websiteurl();
    void pluginid();
};

#endif //TEST_CONFIGURATIONTO_H_
