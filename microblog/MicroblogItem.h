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

#ifndef MICROBLOGITEM_H_
#define MICROBLOGITEM_H_

#include "ItemInterface.h"
#include <config.h>

class QImage;

namespace MicroBlogEngine
{

    class VISIBLE_SYM MicroblogItem : public ItemInterface
    {
    public:
	    MicroblogItem();
	    ~MicroblogItem();
        
        GUID Id() const;
        void Id(const GUID &val);
        
        QDateTime time() const;
        void time(const QDateTime &val);
        
        QString from() const;
        void from(const QString &val);
        
        QString who() const;
        void who(const QString &val);
        
        QImage picture() const;
        void picture(const QImage &val);
        
        QString message() const;
        void message(const QString &val);
        
    private:
        class Private;
        Private *d;
};

}

#endif /*MICROBLOGITEM_H_*/
