#pragma once
// MESSAGE ANGLE_TRACE PACKING

#define MAVLINK_MSG_ID_ANGLE_TRACE 9

MAVPACKED(
typedef struct __mavlink_angle_trace_t {
 float target; /*< target angle in rad*/
 float sensor; /*< sensor in rad*/
}) mavlink_angle_trace_t;

#define MAVLINK_MSG_ID_ANGLE_TRACE_LEN 8
#define MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN 8
#define MAVLINK_MSG_ID_9_LEN 8
#define MAVLINK_MSG_ID_9_MIN_LEN 8

#define MAVLINK_MSG_ID_ANGLE_TRACE_CRC 170
#define MAVLINK_MSG_ID_9_CRC 170



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ANGLE_TRACE { \
    9, \
    "ANGLE_TRACE", \
    2, \
    {  { "target", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_angle_trace_t, target) }, \
         { "sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_angle_trace_t, sensor) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ANGLE_TRACE { \
    "ANGLE_TRACE", \
    2, \
    {  { "target", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_angle_trace_t, target) }, \
         { "sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_angle_trace_t, sensor) }, \
         } \
}
#endif

/**
 * @brief Pack a angle_trace message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target target angle in rad
 * @param sensor sensor in rad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_angle_trace_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float target, float sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANGLE_TRACE_LEN];
    _mav_put_float(buf, 0, target);
    _mav_put_float(buf, 4, sensor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANGLE_TRACE_LEN);
#else
    mavlink_angle_trace_t packet;
    packet.target = target;
    packet.sensor = sensor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANGLE_TRACE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANGLE_TRACE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
}

/**
 * @brief Pack a angle_trace message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target target angle in rad
 * @param sensor sensor in rad
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_angle_trace_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float target,float sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANGLE_TRACE_LEN];
    _mav_put_float(buf, 0, target);
    _mav_put_float(buf, 4, sensor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANGLE_TRACE_LEN);
#else
    mavlink_angle_trace_t packet;
    packet.target = target;
    packet.sensor = sensor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANGLE_TRACE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANGLE_TRACE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
}

/**
 * @brief Encode a angle_trace struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param angle_trace C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_angle_trace_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_angle_trace_t* angle_trace)
{
    return mavlink_msg_angle_trace_pack(system_id, component_id, msg, angle_trace->target, angle_trace->sensor);
}

/**
 * @brief Encode a angle_trace struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param angle_trace C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_angle_trace_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_angle_trace_t* angle_trace)
{
    return mavlink_msg_angle_trace_pack_chan(system_id, component_id, chan, msg, angle_trace->target, angle_trace->sensor);
}

/**
 * @brief Send a angle_trace message
 * @param chan MAVLink channel to send the message
 *
 * @param target target angle in rad
 * @param sensor sensor in rad
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_angle_trace_send(mavlink_channel_t chan, float target, float sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANGLE_TRACE_LEN];
    _mav_put_float(buf, 0, target);
    _mav_put_float(buf, 4, sensor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANGLE_TRACE, buf, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
#else
    mavlink_angle_trace_t packet;
    packet.target = target;
    packet.sensor = sensor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANGLE_TRACE, (const char *)&packet, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
#endif
}

/**
 * @brief Send a angle_trace message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_angle_trace_send_struct(mavlink_channel_t chan, const mavlink_angle_trace_t* angle_trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_angle_trace_send(chan, angle_trace->target, angle_trace->sensor);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANGLE_TRACE, (const char *)angle_trace, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
#endif
}

#if MAVLINK_MSG_ID_ANGLE_TRACE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_angle_trace_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float target, float sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, target);
    _mav_put_float(buf, 4, sensor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANGLE_TRACE, buf, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
#else
    mavlink_angle_trace_t *packet = (mavlink_angle_trace_t *)msgbuf;
    packet->target = target;
    packet->sensor = sensor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANGLE_TRACE, (const char *)packet, MAVLINK_MSG_ID_ANGLE_TRACE_MIN_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_LEN, MAVLINK_MSG_ID_ANGLE_TRACE_CRC);
#endif
}
#endif

#endif

// MESSAGE ANGLE_TRACE UNPACKING


/**
 * @brief Get field target from angle_trace message
 *
 * @return target angle in rad
 */
static inline float mavlink_msg_angle_trace_get_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field sensor from angle_trace message
 *
 * @return sensor in rad
 */
static inline float mavlink_msg_angle_trace_get_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a angle_trace message into a struct
 *
 * @param msg The message to decode
 * @param angle_trace C-struct to decode the message contents into
 */
static inline void mavlink_msg_angle_trace_decode(const mavlink_message_t* msg, mavlink_angle_trace_t* angle_trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    angle_trace->target = mavlink_msg_angle_trace_get_target(msg);
    angle_trace->sensor = mavlink_msg_angle_trace_get_sensor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ANGLE_TRACE_LEN? msg->len : MAVLINK_MSG_ID_ANGLE_TRACE_LEN;
        memset(angle_trace, 0, MAVLINK_MSG_ID_ANGLE_TRACE_LEN);
    memcpy(angle_trace, _MAV_PAYLOAD(msg), len);
#endif
}
