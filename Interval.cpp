/* O1Plot - fast time series dataset plotter
   Copyright (C) 2013  Michael Riss <Michael.Riss@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA */


#include "Interval.h"

using namespace O1Plot;

Interval::Interval()
{
    begin = 0;
    end = 1;
}

Interval::Interval ( quint64 begin = 0, quint64 end = 1 )
{
    this->begin = begin;
    this->end = end;
}


bool Interval::operator< ( const Interval& other ) const
{
    if ( begin == other.begin )
    {
        return end < other.end;
    }
    return begin < other.begin;
}

bool Interval::operator> ( const Interval& other ) const
{
    if ( begin == other.begin )
    {
        return end > other.end;
    }
    return begin > other.begin;
}


bool Interval::operator== ( const Interval& other ) const
{
    return ( begin == other.begin ) && ( end == other.end );
}

bool Interval::operator!= ( const Interval& other ) const
{
    return ( begin != other.begin ) || ( end != other.end );
}


QDebug& O1Plot::operator<< ( QDebug& debug, const Interval& b )
{
    debug << b.begin << " " << b.end;
    return debug;
}
// kate: indent-mode cstyle; space-indent on; indent-width 4; 