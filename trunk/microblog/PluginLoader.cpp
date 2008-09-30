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

#include "PluginLoader.h"

class PluginLoader::Private
{
public:
    Private() {}
    ~Private() {}
    QString prefix; // program's folder
};

PluginLoader::PluginLoader()
: d(new Private)
{
    
} 


PluginLoader * PluginLoader::getInstance()
{
    if (!mInstance) {
        mInstance = new PluginLoader();
        mInstance->scanDisk();
    }

    return (mInstance);
}


void PluginLoader::scanDisk()
{
    QDir dir(d->prefix);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        loadDesktop(d->prefix + fileInfo.fileName());
    }
}


QStringList PluginLoader::listPlugins()
{
    return (groups.keys());
}