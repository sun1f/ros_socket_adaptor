; Auto-generated. Do not edit!


(cl:in-package ros_socket_adaptor-msg)


;//! \htmlinclude data.msg.html

(cl:defclass <data> (roslisp-msg-protocol:ros-message)
  ((m_x
    :reader m_x
    :initarg :m_x
    :type cl:float
    :initform 0.0)
   (m_y
    :reader m_y
    :initarg :m_y
    :type cl:float
    :initform 0.0)
   (m_z
    :reader m_z
    :initarg :m_z
    :type cl:float
    :initform 0.0)
   (m_backup
    :reader m_backup
    :initarg :m_backup
    :type cl:float
    :initform 0.0))
)

(cl:defclass data (<data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_socket_adaptor-msg:<data> is deprecated: use ros_socket_adaptor-msg:data instead.")))

(cl:ensure-generic-function 'm_x-val :lambda-list '(m))
(cl:defmethod m_x-val ((m <data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_socket_adaptor-msg:m_x-val is deprecated.  Use ros_socket_adaptor-msg:m_x instead.")
  (m_x m))

(cl:ensure-generic-function 'm_y-val :lambda-list '(m))
(cl:defmethod m_y-val ((m <data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_socket_adaptor-msg:m_y-val is deprecated.  Use ros_socket_adaptor-msg:m_y instead.")
  (m_y m))

(cl:ensure-generic-function 'm_z-val :lambda-list '(m))
(cl:defmethod m_z-val ((m <data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_socket_adaptor-msg:m_z-val is deprecated.  Use ros_socket_adaptor-msg:m_z instead.")
  (m_z m))

(cl:ensure-generic-function 'm_backup-val :lambda-list '(m))
(cl:defmethod m_backup-val ((m <data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_socket_adaptor-msg:m_backup-val is deprecated.  Use ros_socket_adaptor-msg:m_backup instead.")
  (m_backup m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <data>) ostream)
  "Serializes a message object of type '<data>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'm_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'm_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'm_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'm_backup))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <data>) istream)
  "Deserializes a message object of type '<data>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm_backup) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<data>)))
  "Returns string type for a message object of type '<data>"
  "ros_socket_adaptor/data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'data)))
  "Returns string type for a message object of type 'data"
  "ros_socket_adaptor/data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<data>)))
  "Returns md5sum for a message object of type '<data>"
  "18b65fca28e689e673861f7058ed3547")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'data)))
  "Returns md5sum for a message object of type 'data"
  "18b65fca28e689e673861f7058ed3547")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<data>)))
  "Returns full string definition for message of type '<data>"
  (cl:format cl:nil "float32 m_x~%float32 m_y~%float32 m_z~%~%float32 m_backup~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'data)))
  "Returns full string definition for message of type 'data"
  (cl:format cl:nil "float32 m_x~%float32 m_y~%float32 m_z~%~%float32 m_backup~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <data>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <data>))
  "Converts a ROS message object to a list"
  (cl:list 'data
    (cl:cons ':m_x (m_x msg))
    (cl:cons ':m_y (m_y msg))
    (cl:cons ':m_z (m_z msg))
    (cl:cons ':m_backup (m_backup msg))
))
