// Generated by gencpp from file ros_socket_adaptor/data.msg
// DO NOT EDIT!


#ifndef ROS_SOCKET_ADAPTOR_MESSAGE_DATA_H
#define ROS_SOCKET_ADAPTOR_MESSAGE_DATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_socket_adaptor
{
template <class ContainerAllocator>
struct data_
{
  typedef data_<ContainerAllocator> Type;

  data_()
    : m_x(0.0)
    , m_y(0.0)
    , m_z(0.0)
    , m_backup(0.0)  {
    }
  data_(const ContainerAllocator& _alloc)
    : m_x(0.0)
    , m_y(0.0)
    , m_z(0.0)
    , m_backup(0.0)  {
  (void)_alloc;
    }



   typedef float _m_x_type;
  _m_x_type m_x;

   typedef float _m_y_type;
  _m_y_type m_y;

   typedef float _m_z_type;
  _m_z_type m_z;

   typedef float _m_backup_type;
  _m_backup_type m_backup;





  typedef boost::shared_ptr< ::ros_socket_adaptor::data_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_socket_adaptor::data_<ContainerAllocator> const> ConstPtr;

}; // struct data_

typedef ::ros_socket_adaptor::data_<std::allocator<void> > data;

typedef boost::shared_ptr< ::ros_socket_adaptor::data > dataPtr;
typedef boost::shared_ptr< ::ros_socket_adaptor::data const> dataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_socket_adaptor::data_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_socket_adaptor::data_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_socket_adaptor::data_<ContainerAllocator1> & lhs, const ::ros_socket_adaptor::data_<ContainerAllocator2> & rhs)
{
  return lhs.m_x == rhs.m_x &&
    lhs.m_y == rhs.m_y &&
    lhs.m_z == rhs.m_z &&
    lhs.m_backup == rhs.m_backup;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_socket_adaptor::data_<ContainerAllocator1> & lhs, const ::ros_socket_adaptor::data_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_socket_adaptor

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_socket_adaptor::data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_socket_adaptor::data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_socket_adaptor::data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_socket_adaptor::data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_socket_adaptor::data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_socket_adaptor::data_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_socket_adaptor::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "18b65fca28e689e673861f7058ed3547";
  }

  static const char* value(const ::ros_socket_adaptor::data_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x18b65fca28e689e6ULL;
  static const uint64_t static_value2 = 0x73861f7058ed3547ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_socket_adaptor::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_socket_adaptor/data";
  }

  static const char* value(const ::ros_socket_adaptor::data_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_socket_adaptor::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 m_x\n"
"float32 m_y\n"
"float32 m_z\n"
"\n"
"float32 m_backup\n"
;
  }

  static const char* value(const ::ros_socket_adaptor::data_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_socket_adaptor::data_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.m_x);
      stream.next(m.m_y);
      stream.next(m.m_z);
      stream.next(m.m_backup);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct data_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_socket_adaptor::data_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_socket_adaptor::data_<ContainerAllocator>& v)
  {
    s << indent << "m_x: ";
    Printer<float>::stream(s, indent + "  ", v.m_x);
    s << indent << "m_y: ";
    Printer<float>::stream(s, indent + "  ", v.m_y);
    s << indent << "m_z: ";
    Printer<float>::stream(s, indent + "  ", v.m_z);
    s << indent << "m_backup: ";
    Printer<float>::stream(s, indent + "  ", v.m_backup);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_SOCKET_ADAPTOR_MESSAGE_DATA_H