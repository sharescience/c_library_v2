#pragma once
// MESSAGE STREAM_SPEED PACKING

#define MAVLINK_MSG_ID_STREAM_SPEED 8

MAVPACKED(
typedef struct __mavlink_stream_speed_t {
 uint32_t speed_1; /*< 8 streams*/
 uint32_t speed_2; /*< 8 streams*/
 uint8_t bitmask; /*< bit0-SR0, bit1-SR1, bit2-SR2...*/
}) mavlink_stream_speed_t;

#define MAVLINK_MSG_ID_STREAM_SPEED_LEN 9
#define MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN 9
#define MAVLINK_MSG_ID_8_LEN 9
#define MAVLINK_MSG_ID_8_MIN_LEN 9

#define MAVLINK_MSG_ID_STREAM_SPEED_CRC 226
#define MAVLINK_MSG_ID_8_CRC 226



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STREAM_SPEED { \
    8, \
    "STREAM_SPEED", \
    3, \
    {  { "speed_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_stream_speed_t, speed_1) }, \
         { "speed_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_stream_speed_t, speed_2) }, \
         { "bitmask", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_stream_speed_t, bitmask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STREAM_SPEED { \
    "STREAM_SPEED", \
    3, \
    {  { "speed_1", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_stream_speed_t, speed_1) }, \
         { "speed_2", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_stream_speed_t, speed_2) }, \
         { "bitmask", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_stream_speed_t, bitmask) }, \
         } \
}
#endif

/**
 * @brief Pack a stream_speed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param speed_1 8 streams
 * @param speed_2 8 streams
 * @param bitmask bit0-SR0, bit1-SR1, bit2-SR2...
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_stream_speed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t speed_1, uint32_t speed_2, uint8_t bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STREAM_SPEED_LEN];
    _mav_put_uint32_t(buf, 0, speed_1);
    _mav_put_uint32_t(buf, 4, speed_2);
    _mav_put_uint8_t(buf, 8, bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STREAM_SPEED_LEN);
#else
    mavlink_stream_speed_t packet;
    packet.speed_1 = speed_1;
    packet.speed_2 = speed_2;
    packet.bitmask = bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STREAM_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STREAM_SPEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
}

/**
 * @brief Pack a stream_speed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param speed_1 8 streams
 * @param speed_2 8 streams
 * @param bitmask bit0-SR0, bit1-SR1, bit2-SR2...
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_stream_speed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t speed_1,uint32_t speed_2,uint8_t bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STREAM_SPEED_LEN];
    _mav_put_uint32_t(buf, 0, speed_1);
    _mav_put_uint32_t(buf, 4, speed_2);
    _mav_put_uint8_t(buf, 8, bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STREAM_SPEED_LEN);
#else
    mavlink_stream_speed_t packet;
    packet.speed_1 = speed_1;
    packet.speed_2 = speed_2;
    packet.bitmask = bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STREAM_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STREAM_SPEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
}

/**
 * @brief Encode a stream_speed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param stream_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_stream_speed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_stream_speed_t* stream_speed)
{
    return mavlink_msg_stream_speed_pack(system_id, component_id, msg, stream_speed->speed_1, stream_speed->speed_2, stream_speed->bitmask);
}

/**
 * @brief Encode a stream_speed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param stream_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_stream_speed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_stream_speed_t* stream_speed)
{
    return mavlink_msg_stream_speed_pack_chan(system_id, component_id, chan, msg, stream_speed->speed_1, stream_speed->speed_2, stream_speed->bitmask);
}

/**
 * @brief Send a stream_speed message
 * @param chan MAVLink channel to send the message
 *
 * @param speed_1 8 streams
 * @param speed_2 8 streams
 * @param bitmask bit0-SR0, bit1-SR1, bit2-SR2...
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_stream_speed_send(mavlink_channel_t chan, uint32_t speed_1, uint32_t speed_2, uint8_t bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STREAM_SPEED_LEN];
    _mav_put_uint32_t(buf, 0, speed_1);
    _mav_put_uint32_t(buf, 4, speed_2);
    _mav_put_uint8_t(buf, 8, bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STREAM_SPEED, buf, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
#else
    mavlink_stream_speed_t packet;
    packet.speed_1 = speed_1;
    packet.speed_2 = speed_2;
    packet.bitmask = bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STREAM_SPEED, (const char *)&packet, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
#endif
}

/**
 * @brief Send a stream_speed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_stream_speed_send_struct(mavlink_channel_t chan, const mavlink_stream_speed_t* stream_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_stream_speed_send(chan, stream_speed->speed_1, stream_speed->speed_2, stream_speed->bitmask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STREAM_SPEED, (const char *)stream_speed, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_STREAM_SPEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_stream_speed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t speed_1, uint32_t speed_2, uint8_t bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, speed_1);
    _mav_put_uint32_t(buf, 4, speed_2);
    _mav_put_uint8_t(buf, 8, bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STREAM_SPEED, buf, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
#else
    mavlink_stream_speed_t *packet = (mavlink_stream_speed_t *)msgbuf;
    packet->speed_1 = speed_1;
    packet->speed_2 = speed_2;
    packet->bitmask = bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STREAM_SPEED, (const char *)packet, MAVLINK_MSG_ID_STREAM_SPEED_MIN_LEN, MAVLINK_MSG_ID_STREAM_SPEED_LEN, MAVLINK_MSG_ID_STREAM_SPEED_CRC);
#endif
}
#endif

#endif

// MESSAGE STREAM_SPEED UNPACKING


/**
 * @brief Get field speed_1 from stream_speed message
 *
 * @return 8 streams
 */
static inline uint32_t mavlink_msg_stream_speed_get_speed_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field speed_2 from stream_speed message
 *
 * @return 8 streams
 */
static inline uint32_t mavlink_msg_stream_speed_get_speed_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field bitmask from stream_speed message
 *
 * @return bit0-SR0, bit1-SR1, bit2-SR2...
 */
static inline uint8_t mavlink_msg_stream_speed_get_bitmask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a stream_speed message into a struct
 *
 * @param msg The message to decode
 * @param stream_speed C-struct to decode the message contents into
 */
static inline void mavlink_msg_stream_speed_decode(const mavlink_message_t* msg, mavlink_stream_speed_t* stream_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    stream_speed->speed_1 = mavlink_msg_stream_speed_get_speed_1(msg);
    stream_speed->speed_2 = mavlink_msg_stream_speed_get_speed_2(msg);
    stream_speed->bitmask = mavlink_msg_stream_speed_get_bitmask(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_STREAM_SPEED_LEN? msg->len : MAVLINK_MSG_ID_STREAM_SPEED_LEN;
        memset(stream_speed, 0, MAVLINK_MSG_ID_STREAM_SPEED_LEN);
    memcpy(stream_speed, _MAV_PAYLOAD(msg), len);
#endif
}
