/*******************************************************************************
* This file is part of twittoid.
*  Maintained by : Dariusz Mikulski <dariusz.mikulski@gmail.com>
*  Authored By  : Dariusz Mikulski <dariusz.mikulski@gmail.com>
*
*  PlexyDesk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  PlexyDesk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with twittoid. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/

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