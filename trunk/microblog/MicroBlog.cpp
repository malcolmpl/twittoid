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

#include "MicroBlog.h"
#include "PluginLoader.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<MicroBlogEngine::PluginLoader> PluginLoaderPtr;

class MicroBlog::Private
{
public:
    Private() {}
    ~Private() {}

    void init();

    PluginLoaderPtr m_loader;
};

void MicroBlog::Private::init()
{
    if(!m_loader)
        m_loader = PluginLoaderPtr(new MicroBlogEngine::PluginLoader());

    m_loader->scanDisk();
}

MicroBlog::MicroBlog(bool init /*= true*/)
: d(new Private)
{
    d->init();
}

MicroBlog::~MicroBlog()
{

}

void MicroBlog::init()
{
    d->init();
}
