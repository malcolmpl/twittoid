/*******************************************************************************
* This file is part of twittoid.
*  Maintained by : Dariusz Mikulski <dariusz.mikulski@gmail.com>
*  Authored By  : Rafael Muñoz Cárdenas <bymenda@gmail.com>
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

#ifndef PLUGININTERFACE_H_
#define PLUGININTERFACE_H_

#include <QString>
#include <QObject>

namespace MicroBlogEngine
{
    /**
    * All plugins made should inherit this class
    */
    class PluginInterface : public QObject
    {
        Q_OBJECT
    public:
        virtual ~PluginInterface() {};
        virtual PluginInterface *instance() = 0;
        virtual void getFriendsTimeline() = 0;
        virtual void login(const QString &username, const QString &password) = 0;
    };
}

Q_DECLARE_INTERFACE(MicroBlogEngine::PluginInterface, "com.microblogengine.Plugin.PluginInterface/1.0");

#endif
