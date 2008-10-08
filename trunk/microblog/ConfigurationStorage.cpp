/*******************************************************************************
* This file is part of twittoid.
*  Maintained by : Dariusz Mikulski <dariusz.mikulski@gmail.com>
*  Authored By  : Dariusz Mikulski <dariusz.mikulski@gmail.com>
*
*  Twittoid is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  Twittoid is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with twittoid. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/

#include "ConfigurationStorage.h"
#include <typedefs.h>
#include <QSettings>

namespace MicroBlogEngine
{
    class ConfigurationStorage::Private
    {
        public:
            Private()
            {
                settings = new QSettings(QSettings::IniFormat, QSettings::UserScope,
                    "Twittoid", "MicroBlog");
            }
            ~Private()
            {
                delete settings;
            }

            QSettings *settings;
    };
    
    ConfigurationStorage::ConfigurationStorage()
        : d(new Private())
    {
    }

    ConfigurationStorage::~ConfigurationStorage()
    {
        delete d;
    }

    ConfigurationTO ConfigurationStorage::load(const QUuid& id) const
    {
        QString pluginId = id.toString() + "/";
        ConfigurationTO config;
        QUuid bla(d->settings->value(pluginId + "pluginId").toString());
        config.setPluginId(bla);
        config.setLogin(d->settings->value(pluginId + "login").toString());
        config.setPassword(d->settings->value(pluginId + "password").toString());
        config.setWebsiteUrl(d->settings->value(pluginId + "websiteUrl").toString());

        return config;
    }

    void ConfigurationStorage::save(const ConfigurationTO &val)
    {
        QString pluginId = val.getPluginId() + "/";
        d->settings->setValue(pluginId + "pluginId", val.getPluginId().toString());
        d->settings->setValue(pluginId + "login", val.getLogin());
        d->settings->setValue(pluginId + "password", val.getLogin());
        d->settings->setValue(pluginId + "websiteUrl", val.getWebsiteUrl());
    }
};
