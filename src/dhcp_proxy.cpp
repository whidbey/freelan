/*
 * libasiotap - A portable TAP adapter extension for Boost::ASIO.
 * Copyright (C) 2010-2011 Julien KAUFFMANN <julien.kauffmann@freelan.org>
 *
 * This file is part of libasiotap.
 *
 * libasiotap is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libasiotap is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libasiotap in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file dhcp_proxy.cpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief An DHCP proxy class.
 */

#include "osi/dhcp_proxy.hpp"

#include "osi/ethernet_helper.hpp"
#include "osi/ipv4_helper.hpp"
#include "osi/udp_helper.hpp"
#include "osi/bootp_helper.hpp"
#include "osi/dhcp_helper.hpp"

#include "osi/ethernet_builder.hpp"
#include "osi/ipv4_builder.hpp"
#include "osi/udp_builder.hpp"
#include "osi/bootp_builder.hpp"
#include "osi/dhcp_builder.hpp"

#include <boost/foreach.hpp>

namespace asiotap
{
	namespace osi
	{
		void proxy<dhcp_frame>::do_handle_frame(
				const_helper<ethernet_frame> ethernet_helper,
				const_helper<ipv4_frame> ipv4_helper,
				const_helper<udp_frame> udp_helper,
				const_helper<bootp_frame> bootp_helper,
				const_helper<dhcp_frame> dhcp_helper
				)
		{
			(void)ethernet_helper;
			(void)ipv4_helper;
			(void)udp_helper;
			(void)bootp_helper;

			builder<dhcp_frame> dhcp_builder(response_buffer());

			BOOST_FOREACH(dhcp_option_helper<const_helper_tag>& dhcp_option_helper, dhcp_helper)
			{
				switch (dhcp_option_helper.tag())
				{
					default:
						{
						}
				}
			}
		}
	}
}
