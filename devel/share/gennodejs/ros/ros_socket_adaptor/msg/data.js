// Auto-generated. Do not edit!

// (in-package ros_socket_adaptor.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.m_x = null;
      this.m_y = null;
      this.m_z = null;
      this.m_backup = null;
    }
    else {
      if (initObj.hasOwnProperty('m_x')) {
        this.m_x = initObj.m_x
      }
      else {
        this.m_x = 0.0;
      }
      if (initObj.hasOwnProperty('m_y')) {
        this.m_y = initObj.m_y
      }
      else {
        this.m_y = 0.0;
      }
      if (initObj.hasOwnProperty('m_z')) {
        this.m_z = initObj.m_z
      }
      else {
        this.m_z = 0.0;
      }
      if (initObj.hasOwnProperty('m_backup')) {
        this.m_backup = initObj.m_backup
      }
      else {
        this.m_backup = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type data
    // Serialize message field [m_x]
    bufferOffset = _serializer.float32(obj.m_x, buffer, bufferOffset);
    // Serialize message field [m_y]
    bufferOffset = _serializer.float32(obj.m_y, buffer, bufferOffset);
    // Serialize message field [m_z]
    bufferOffset = _serializer.float32(obj.m_z, buffer, bufferOffset);
    // Serialize message field [m_backup]
    bufferOffset = _serializer.float32(obj.m_backup, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type data
    let len;
    let data = new data(null);
    // Deserialize message field [m_x]
    data.m_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [m_y]
    data.m_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [m_z]
    data.m_z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [m_backup]
    data.m_backup = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_socket_adaptor/data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '18b65fca28e689e673861f7058ed3547';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 m_x
    float32 m_y
    float32 m_z
    
    float32 m_backup
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new data(null);
    if (msg.m_x !== undefined) {
      resolved.m_x = msg.m_x;
    }
    else {
      resolved.m_x = 0.0
    }

    if (msg.m_y !== undefined) {
      resolved.m_y = msg.m_y;
    }
    else {
      resolved.m_y = 0.0
    }

    if (msg.m_z !== undefined) {
      resolved.m_z = msg.m_z;
    }
    else {
      resolved.m_z = 0.0
    }

    if (msg.m_backup !== undefined) {
      resolved.m_backup = msg.m_backup;
    }
    else {
      resolved.m_backup = 0.0
    }

    return resolved;
    }
};

module.exports = data;
