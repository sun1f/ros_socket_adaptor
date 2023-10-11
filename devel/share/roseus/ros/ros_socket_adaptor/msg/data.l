;; Auto-generated. Do not edit!


(when (boundp 'ros_socket_adaptor::data)
  (if (not (find-package "ROS_SOCKET_ADAPTOR"))
    (make-package "ROS_SOCKET_ADAPTOR"))
  (shadow 'data (find-package "ROS_SOCKET_ADAPTOR")))
(unless (find-package "ROS_SOCKET_ADAPTOR::DATA")
  (make-package "ROS_SOCKET_ADAPTOR::DATA"))

(in-package "ROS")
;;//! \htmlinclude data.msg.html


(defclass ros_socket_adaptor::data
  :super ros::object
  :slots (_m_x _m_y _m_z _m_backup ))

(defmethod ros_socket_adaptor::data
  (:init
   (&key
    ((:m_x __m_x) 0.0)
    ((:m_y __m_y) 0.0)
    ((:m_z __m_z) 0.0)
    ((:m_backup __m_backup) 0.0)
    )
   (send-super :init)
   (setq _m_x (float __m_x))
   (setq _m_y (float __m_y))
   (setq _m_z (float __m_z))
   (setq _m_backup (float __m_backup))
   self)
  (:m_x
   (&optional __m_x)
   (if __m_x (setq _m_x __m_x)) _m_x)
  (:m_y
   (&optional __m_y)
   (if __m_y (setq _m_y __m_y)) _m_y)
  (:m_z
   (&optional __m_z)
   (if __m_z (setq _m_z __m_z)) _m_z)
  (:m_backup
   (&optional __m_backup)
   (if __m_backup (setq _m_backup __m_backup)) _m_backup)
  (:serialization-length
   ()
   (+
    ;; float32 _m_x
    4
    ;; float32 _m_y
    4
    ;; float32 _m_z
    4
    ;; float32 _m_backup
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _m_x
       (sys::poke _m_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _m_y
       (sys::poke _m_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _m_z
       (sys::poke _m_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _m_backup
       (sys::poke _m_backup (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _m_x
     (setq _m_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _m_y
     (setq _m_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _m_z
     (setq _m_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _m_backup
     (setq _m_backup (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ros_socket_adaptor::data :md5sum-) "18b65fca28e689e673861f7058ed3547")
(setf (get ros_socket_adaptor::data :datatype-) "ros_socket_adaptor/data")
(setf (get ros_socket_adaptor::data :definition-)
      "float32 m_x
float32 m_y
float32 m_z

float32 m_backup
")



(provide :ros_socket_adaptor/data "18b65fca28e689e673861f7058ed3547")


