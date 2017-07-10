/** @file
 *  @brief MAVLink comm protocol generated from sharescience.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_SHARESCIENCE_H
#define MAVLINK_SHARESCIENCE_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_SHARESCIENCE.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 3

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{3, 148, 32, 0, 0, 0}, {8, 226, 9, 0, 0, 0}, {9, 170, 8, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_SHARESCIENCE

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_elasticity.h"
#include "./mavlink_msg_stream_speed.h"
#include "./mavlink_msg_angle_trace.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 3

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_ELASTICITY, MAVLINK_MESSAGE_INFO_STREAM_SPEED, MAVLINK_MESSAGE_INFO_ANGLE_TRACE}
# define MAVLINK_MESSAGE_NAMES {{ "ANGLE_TRACE", 9 }, { "ELASTICITY", 3 }, { "STREAM_SPEED", 8 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_SHARESCIENCE_H
