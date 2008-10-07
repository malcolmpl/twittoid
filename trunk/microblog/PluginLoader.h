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

#ifndef PLUGINLOADER_H_
#define PLUGINLOADER_H_

#include <QDebug>
#include <QDir>
#include <QHash>
#include <QPluginLoader>
#include <QStringList>
#include "PluginInterface.h"

namespace MicroBlogEngine {

    /**
    * This class loads plugins like twitter, blip or jisko
    */
    class PluginLoader : public QObject
    {
        Q_OBJECT

    public:
        PluginLoader();
        virtual ~PluginLoader();
        static PluginLoader *getInstance();
        void scanDisk();
        QStringList listPlugins();
        PluginInterface *instance(const QString &pluginName);
        void load(const QString &pluginName);

        typedef QHash <QString, PluginInterface*> Interface;

    private:
        class Private;
        Private *d;
        static PluginLoader *mInstance;
    };

    PluginLoader *PluginLoader::mInstance = 0;

}

#endif
