/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   Product name: redemption, a FLOSS RDP proxy
   Copyright (C) Wallix 2012
   Author(s): Christophe Grosjean, Javier Caverni, Xavier Dunat

   Front object API (server),
   used to communicate with RDP client or other drawing backends
*/


#pragma once

#include "acl/auth_api.hpp"
#include "gdi/screen_info.hpp"
#include "gdi/capture_probe_api.hpp"
#include "utils/sugar/bytes_view.hpp"
#include "utils/sugar/noncopyable.hpp"


namespace CHANNELS {
    class ChannelDefArray;
    class ChannelDef;
}

class MonitorLayoutPDU;

class FrontAPI : public gdi::CaptureProbeApi /*, private noncopyable*/
{
public:
    virtual bool can_be_start_capture(SessionLogApi & session_log) = 0;
    virtual bool must_be_stop_capture() = 0;
    [[nodiscard]] virtual bool is_capture_in_progress() const = 0;
    virtual void must_flush_capture() = 0;

    [[nodiscard]] virtual const CHANNELS::ChannelDefArray & get_channel_list() const = 0;
    virtual void send_to_channel( const CHANNELS::ChannelDef & channel, bytes_view chunk_data
                                , std::size_t total_length, int flags) = 0;

    enum class ResizeResult {
        no_need = 0,
        done    = 1,
        fail    = -1,
        instant_done = 2,
        remoteapp = 3,
        remoteapp_done = 4
    };
    virtual ResizeResult server_resize(ScreenInfo screen_server) = 0;

    virtual void server_relayout(MonitorLayoutPDU const& monitor_layout_pdu_ref) { (void)monitor_layout_pdu_ref; }

    virtual void update_pointer_position(uint16_t x, uint16_t y) { (void)x; (void)y; }

    virtual void set_keyboard_indicators(uint16_t LedFlags) { (void)LedFlags; }

    ////////////////////////////////
    // Session Probe.

    virtual void session_probe_started(bool /*unused*/) {}
    virtual void set_keylayout(int LCID) { (void)LCID; }
    virtual void set_focus_on_password_textbox(bool /*unused*/) {}
    virtual void set_focus_on_unidentified_input_field(bool /*unused*/) {}
    virtual void set_consent_ui_visible(bool /*unused*/) {}
    virtual void set_session_locked(bool /*unused*/) {}

    ////////////////////////////////
    // RemoteApp.
    virtual void send_savesessioninfo() {}

    /// \return  -1 is an error
    [[nodiscard]] virtual int get_keylayout() const { return -1; }

    virtual ~FrontAPI() = default;
};
