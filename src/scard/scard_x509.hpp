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

#include <string>

#include "utils/sugar/bytes_view.hpp"


///////////////////////////////////////////////////////////////////////////////


///
enum scard_x509_name_type
{
    unknown = 0,
    dns,
    email,
    ms_upn,
    uri
};

///
struct scard_x509_name
{
    ///
    scard_x509_name_type type;

    ///
    std::string value;
};

typedef std::vector<scard_x509_name> scard_x509_name_list;

///
class scard_x509_identity
{
public:
    ///
    scard_x509_identity(const std::string_view& module_name,
        const std::string_view& slot_id, const std::string_view& token_label,
        const std::string_view& certificate_id);

    ///
    std::string string() const;

private:
    ///
    const std::string _module_name;

    ///
    const std::string _slot_id;

    ///
    const std::string _token_label;

    ///
    const std::string _certificate_id;
};

///
typedef std::vector<scard_x509_identity> scard_x509_identity_list;

///
class scard_x509_exception : public std::runtime_error
{
public:
    ///
    scard_x509_exception(const char *message)
        : std::runtime_error(message)
    {
    }

    ///
    scard_x509_exception(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

///
scard_x509_name_list extract_subject_alt_names(bytes_view certificate);

///
std::string name_type_to_string(const scard_x509_name_type& type);