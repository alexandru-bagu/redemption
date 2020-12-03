/*
    This program is free software; you can redistribute it and/or modify it
     under the terms of the GNU General Public License as published by the
     Free Software Foundation; either version 2 of the License, or (at your
     option) any later version.

    This program is distributed in the hope that it will be useful, but
     WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
     Public License for more details.

    You should have received a copy of the GNU General Public License along
     with this program; if not, write to the Free Software Foundation, Inc.,
     675 Mass Ave, Cambridge, MA 02139, USA.

    Product name: redemption, a FLOSS RDP proxy
    Copyright (C) Wallix 2020
    Author(s): 
*/

#pragma once

#include <cstdint>

#include <PCSC/wintypes.h>
#include <PCSC/winscard.h>


///////////////////////////////////////////////////////////////////////////////


typedef DWORD               SCARD_PACK_NATIVE_DWORD;
typedef LONG                SCARD_PACK_NATIVE_LONG;
typedef SCARDCONTEXT        SCARD_PACK_NATIVE_CONTEXT;
typedef SCARDHANDLE         SCARD_PACK_NATIVE_HANDLE;
typedef SCARD_IO_REQUEST    SCARD_PACK_NATIVE_PCI_HEADER;