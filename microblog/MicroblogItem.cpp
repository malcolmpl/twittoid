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

#include "MicroblogItem.h"
#include "typedefs.h"

#include <QDateTime>
#include <QString>
#include <QImage>

namespace MicroBlogEngine
{
    class MicroblogItem::Private
    {
        public:
            Private() {}
            ~Private() {}
            
        GUID m_id;
        QDateTime m_time;
        QString m_from;
        QString m_who;
        QImage m_picture;
        QString m_message;
    };

    MicroblogItem::MicroblogItem()
        : d(new Private())
    {
    }

    MicroblogItem::~MicroblogItem()
    {
        delete d;
    }
    
    GUID MicroblogItem::Id() const
    {
        return d->m_id;
    }
    
    void MicroblogItem::Id(const GUID &val)
    {
        d->m_id = val;
    }
    
    QDateTime MicroblogItem::time() const
    {
        return d->m_time;
    }
    
    void MicroblogItem::time(const QDateTime &val)
    {
        d->m_time = val;
    }
    
    QString MicroblogItem::from() const
    {
        return d->m_from;
    }
    
    void MicroblogItem::from(const QString &val)
    {
        d->m_from = val;
    }
        
    QString MicroblogItem::who() const
    {
        return d->m_who;
    }
    
    void MicroblogItem::who(const QString &val)
    {
        d->m_who = val;
    }
    
    QImage MicroblogItem::picture() const
    {
        return d->m_picture;
    }
    
    void MicroblogItem::picture(const QImage &val)
    {
        d->m_picture = val;
    }
    
    QString MicroblogItem::message() const
    {
        return d->m_message;
    }
    
    void MicroblogItem::message(const QString &val)
    {
        d->m_message = val;
    }

}
