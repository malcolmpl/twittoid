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

#ifndef CONFIG_H_
#define CONFIG_H_

#define __SYSTEM_HAVE_GCC_VISIBILITY

#if defined(_WIN32) && !defined(__GNUC__)
#define VISIBLE_SYM __declspec(dllexport)
#else 
#ifdef __SYSTEM_HAVE_GCC_VISIBILITY
#define HIDDEN_SYM __attribute__ ((visibility("hidden")))
#define VISIBLE_SYM __attribute__ ((visibility("default")))
#endif
#endif 

#endif /*CONFIG_H_*/
