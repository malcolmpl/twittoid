#include "test_configurationto.h"

#include <microblog/ConfigurationTO.h>


void TestConfigurationTO::login()
{
    MicroBlogEngine::ConfigurationTO config;
    config.setLogin("test");
    QCOMPARE(config.getLogin(), QString("test"));
}

void TestConfigurationTO::password()
{
    MicroBlogEngine::ConfigurationTO config;
    config.setPassword("test");
    QCOMPARE(config.getPassword(), QString("test"));
}

void TestConfigurationTO::websiteurl()
{
    MicroBlogEngine::ConfigurationTO config;
    config.setWebsiteUrl("test");
    QCOMPARE(config.getWebsiteUrl(), QString("test"));
}

void TestConfigurationTO::pluginid()
{
    MicroBlogEngine::ConfigurationTO config;
    config.setPluginId("");
    QCOMPARE(config.getPluginId().toString(), QUuid().toString());
}


QTEST_MAIN(TestConfigurationTO)

#include "test_configurationto.moc"