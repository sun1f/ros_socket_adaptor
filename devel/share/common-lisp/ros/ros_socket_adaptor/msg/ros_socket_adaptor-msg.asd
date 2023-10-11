
(cl:in-package :asdf)

(defsystem "ros_socket_adaptor-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "data" :depends-on ("_package_data"))
    (:file "_package_data" :depends-on ("_package"))
  ))