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

#include "typedefs.h"
#include <QString>
#include <QUuid>

#include "ConfigurationTO.h"

namespace MicroBlogEngine
{
    class ConfigurationTO::Private
    {
        public:
            Private() {}
            ~Private() {}
            
            QString m_login;
            QString m_password;
            QString m_websiteUrl;
            
            QUuid m_pluginID;
    };
    
    
    ConfigurationTO::ConfigurationTO()
        : d(new Private())
    {
    }

    ConfigurationTO::~ConfigurationTO()
    {
        delete d;
    }
    
    QString ConfigurationTO::getLogin() const
    {
        return d->m_login;
    }

    void ConfigurationTO::setLogin(const QString &val)
    {
        d->m_login = val;
    }
        
    QString ConfigurationTO::getPassword() const
    {
        return d->m_password;
    }

    void ConfigurationTO::setPassword(const QString &val)
    {
        d->m_password = val;
    }

    QString ConfigurationTO::getWebsiteUrl() const
    {
        return d->m_websiteUrl;
    }

    void ConfigurationTO::setWebsiteUrl(const QString &val)
    {
        d->m_websiteUrl = val;
    }
    
    QUuid ConfigurationTO::getPluginId() const
    {
        return d->m_pluginID;
    }
    
    void ConfigurationTO::setPluginId(const QUuid &val)
    {
        d->m_pluginID = val;
    }
};
