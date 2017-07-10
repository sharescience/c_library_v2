#pragma once
// MESSAGE ELASTICITY PACKING

#define MAVLINK_MSG_ID_ELASTICITY 3

MAVPACKED(
typedef struct __mavlink_elasticity_t {
 uint32_t data[8]; /*< Data received*/
}) mavlink_elasticity_t;

#define MAVLINK_MSG_ID_ELASTICITY_LEN 32
#define MAVLINK_MSG_ID_ELASTICITY_MIN_LEN 32
#define MAVLINK_MSG_ID_3_LEN 32
#define MAVLINK_MSG_ID_3_MIN_LEN 32

#define MAVLINK_MSG_ID_ELASTICITY_CRC 148
#define MAVLINK_MSG_ID_3_CRC 148

#define MAVLINK_MSG_ELASTICITY_FIELD_DATA_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ELASTICITY { \
    3, \
    "ELASTICITY", \
    1, \
    {  { "data", NULL, MAVLINK_TYPE_UINT32_T, 8, 0, offsetof(mavlink_elasticity_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ELASTICITY { \
    "ELASTICITY", \
    1, \
    {  { "data", NULL, MAVLINK_TYPE_UINT32_T, 8, 0, offsetof(mavlink_elasticity_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a elasticity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data Data received
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_elasticity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELASTICITY_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELASTICITY_LEN);
#else
    mavlink_elasticity_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELASTICITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELASTICITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
}

/**
 * @brief Pack a elasticity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data Data received
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_elasticity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELASTICITY_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELASTICITY_LEN);
#else
    mavlink_elasticity_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELASTICITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELASTICITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
}

/**
 * @brief Encode a elasticity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param elasticity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_elasticity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_elasticity_t* elasticity)
{
    return mavlink_msg_elasticity_pack(system_id, component_id, msg, elasticity->data);
}

/**
 * @brief Encode a elasticity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param elasticity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_elasticity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_elasticity_t* elasticity)
{
    return mavlink_msg_elasticity_pack_chan(system_id, component_id, chan, msg, elasticity->data);
}

/**
 * @brief Send a elasticity message
 * @param chan MAVLink channel to send the message
 *
 * @param data Data received
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_elasticity_send(mavlink_channel_t chan, const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELASTICITY_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELASTICITY, buf, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
#else
    mavlink_elasticity_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELASTICITY, (const char *)&packet, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
#endif
}

/**
 * @brief Send a elasticity message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_elasticity_send_struct(mavlink_channel_t chan, const mavlink_elasticity_t* elasticity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_elasticity_send(chan, elasticity->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELASTICITY, (const char *)elasticity, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_ELASTICITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_elasticity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint32_t_array(buf, 0, data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELASTICITY, buf, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
#else
    mavlink_elasticity_t *packet = (mavlink_elasticity_t *)msgbuf;

    mav_array_memcpy(packet->data, data, sizeof(uint32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELASTICITY, (const char *)packet, MAVLINK_MSG_ID_ELASTICITY_MIN_LEN, MAVLINK_MSG_ID_ELASTICITY_LEN, MAVLINK_MSG_ID_ELASTICITY_CRC);
#endif
}
#endif

#endif

// MESSAGE ELASTICITY UNPACKING


/**
 * @brief Get field data from elasticity message
 *
 * @return Data received
 */
static inline uint16_t mavlink_msg_elasticity_get_data(const mavlink_message_t* msg, uint32_t *data)
{
    return _MAV_RETURN_uint32_t_array(msg, data, 8,  0);
}

/**
 * @brief Decode a elasticity message into a struct
 *
 * @param msg The message to decode
 * @param elasticity C-struct to decode the message contents into
 */
static inline void mavlink_msg_elasticity_decode(const mavlink_message_t* msg, mavlink_elasticity_t* elasticity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_elasticity_get_data(msg, elasticity->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ELASTICITY_LEN? msg->len : MAVLINK_MSG_ID_ELASTICITY_LEN;
        memset(elasticity, 0, MAVLINK_MSG_ID_ELASTICITY_LEN);
    memcpy(elasticity, _MAV_PAYLOAD(msg), len);
#endif
}
