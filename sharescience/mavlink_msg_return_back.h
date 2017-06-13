#pragma once
// MESSAGE RETURN_BACK PACKING

#define MAVLINK_MSG_ID_RETURN_BACK 3

MAVPACKED(
typedef struct __mavlink_return_back_t {
 uint32_t data[8]; /*< Data received*/
}) mavlink_return_back_t;

#define MAVLINK_MSG_ID_RETURN_BACK_LEN 32
#define MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN 32
#define MAVLINK_MSG_ID_3_LEN 32
#define MAVLINK_MSG_ID_3_MIN_LEN 32

#define MAVLINK_MSG_ID_RETURN_BACK_CRC 62
#define MAVLINK_MSG_ID_3_CRC 62

#define MAVLINK_MSG_RETURN_BACK_FIELD_DATA_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RETURN_BACK { \
    3, \
    "RETURN_BACK", \
    1, \
    {  { "data", NULL, MAVLINK_TYPE_UINT32_T, 8, 0, offsetof(mavlink_return_back_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RETURN_BACK { \
    "RETURN_BACK", \
    1, \
    {  { "data", NULL, MAVLINK_TYPE_UINT32_T, 8, 0, offsetof(mavlink_return_back_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a return_back message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data Data received
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_return_back_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_BACK_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RETURN_BACK_LEN);
#else
    mavlink_return_back_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RETURN_BACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RETURN_BACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
}

/**
 * @brief Pack a return_back message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data Data received
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_return_back_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_BACK_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RETURN_BACK_LEN);
#else
    mavlink_return_back_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RETURN_BACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RETURN_BACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
}

/**
 * @brief Encode a return_back struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param return_back C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_return_back_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_return_back_t* return_back)
{
    return mavlink_msg_return_back_pack(system_id, component_id, msg, return_back->data);
}

/**
 * @brief Encode a return_back struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param return_back C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_return_back_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_return_back_t* return_back)
{
    return mavlink_msg_return_back_pack_chan(system_id, component_id, chan, msg, return_back->data);
}

/**
 * @brief Send a return_back message
 * @param chan MAVLink channel to send the message
 *
 * @param data Data received
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_return_back_send(mavlink_channel_t chan, const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RETURN_BACK_LEN];

    _mav_put_uint32_t_array(buf, 0, data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_BACK, buf, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
#else
    mavlink_return_back_t packet;

    mav_array_memcpy(packet.data, data, sizeof(uint32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_BACK, (const char *)&packet, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
#endif
}

/**
 * @brief Send a return_back message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_return_back_send_struct(mavlink_channel_t chan, const mavlink_return_back_t* return_back)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_return_back_send(chan, return_back->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_BACK, (const char *)return_back, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_RETURN_BACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_return_back_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint32_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint32_t_array(buf, 0, data, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_BACK, buf, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
#else
    mavlink_return_back_t *packet = (mavlink_return_back_t *)msgbuf;

    mav_array_memcpy(packet->data, data, sizeof(uint32_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RETURN_BACK, (const char *)packet, MAVLINK_MSG_ID_RETURN_BACK_MIN_LEN, MAVLINK_MSG_ID_RETURN_BACK_LEN, MAVLINK_MSG_ID_RETURN_BACK_CRC);
#endif
}
#endif

#endif

// MESSAGE RETURN_BACK UNPACKING


/**
 * @brief Get field data from return_back message
 *
 * @return Data received
 */
static inline uint16_t mavlink_msg_return_back_get_data(const mavlink_message_t* msg, uint32_t *data)
{
    return _MAV_RETURN_uint32_t_array(msg, data, 8,  0);
}

/**
 * @brief Decode a return_back message into a struct
 *
 * @param msg The message to decode
 * @param return_back C-struct to decode the message contents into
 */
static inline void mavlink_msg_return_back_decode(const mavlink_message_t* msg, mavlink_return_back_t* return_back)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_return_back_get_data(msg, return_back->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RETURN_BACK_LEN? msg->len : MAVLINK_MSG_ID_RETURN_BACK_LEN;
        memset(return_back, 0, MAVLINK_MSG_ID_RETURN_BACK_LEN);
    memcpy(return_back, _MAV_PAYLOAD(msg), len);
#endif
}
