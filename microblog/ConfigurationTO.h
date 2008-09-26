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

#ifndef CONFIGURATIONTO_H_
#define CONFIGURATIONTO_H_

class QString;
class QUuid;

namespace MicroBlogEngine
{
    typedef QString GUID;
    
    class ConfigurationTO
    {
    public:
        ConfigurationTO();
        virtual ~ConfigurationTO();
        
        QString getLogin();
        void setLogin(QString val);
        QString getPassword();
        void setPassword(QString val);
        QString getWebsiteUrl();
        void setWebsiteUrl(QString val);
        GUID getPluginId();
        void setPluginId(GUID val);
        
    private:
        class Private;
        Private *d;
    };
};

#endif /*CONFIGURATIONTO_H_*/
