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

#include "typedefs.h"
#include <QString>

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
            
            GUID m_pluginID;
    };
    
    
    ConfigurationTO::ConfigurationTO()
        : d(new Private())
    {
    }

    ConfigurationTO::~ConfigurationTO()
    {
    }
    
    QString ConfigurationTO::getLogin()
    {
        return d->m_login;
    }

    void ConfigurationTO::setLogin(QString val)
    {
        d->m_login = val;
    }
        
    QString ConfigurationTO::getPassword()
    {
        return d->m_password;
    }

    void ConfigurationTO::setPassword(QString val)
    {
        d->m_password = val;
    }

    QString ConfigurationTO::getWebsiteUrl()
    {
        return d->m_websiteUrl;
    }

    void ConfigurationTO::setWebsiteUrl(QString val)
    {
        d->m_websiteUrl = val;
    }
    
    GUID ConfigurationTO::getPluginId()
    {
        return d->m_pluginID;
    }
    
    void ConfigurationTO::setPluginId(GUID val)
    {
        d->m_pluginID = val;
    }
};
