// Generated by gencpp from file rm_msgs/Arm_Analog_Output.msg
// DO NOT EDIT!


#ifndef RM_MSGS_MESSAGE_ARM_ANALOG_OUTPUT_H
#define RM_MSGS_MESSAGE_ARM_ANALOG_OUTPUT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rm_msgs
{
template <class ContainerAllocator>
struct Arm_Analog_Output_
{
  typedef Arm_Analog_Output_<ContainerAllocator> Type;

  Arm_Analog_Output_()
    : num(0)
    , voltage(0.0)  {
    }
  Arm_Analog_Output_(const ContainerAllocator& _alloc)
    : num(0)
    , voltage(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _num_type;
  _num_type num;

   typedef float _voltage_type;
  _voltage_type voltage;





  typedef boost::shared_ptr< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> const> ConstPtr;

}; // struct Arm_Analog_Output_

typedef ::rm_msgs::Arm_Analog_Output_<std::allocator<void> > Arm_Analog_Output;

typedef boost::shared_ptr< ::rm_msgs::Arm_Analog_Output > Arm_Analog_OutputPtr;
typedef boost::shared_ptr< ::rm_msgs::Arm_Analog_Output const> Arm_Analog_OutputConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rm_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'rm_msgs': ['/home/nvidia/catkin_ws/src/RM_Robot/rm_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1daa7069f6c6dbf96541a8c8a3620c76";
  }

  static const char* value(const ::rm_msgs::Arm_Analog_Output_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1daa7069f6c6dbf9ULL;
  static const uint64_t static_value2 = 0x6541a8c8a3620c76ULL;
};

template<class ContainerAllocator>
struct DataType< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rm_msgs/Arm_Analog_Output";
  }

  static const char* value(const ::rm_msgs::Arm_Analog_Output_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 num\n\
float32 voltage\n\
";
  }

  static const char* value(const ::rm_msgs::Arm_Analog_Output_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num);
      stream.next(m.voltage);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Arm_Analog_Output_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rm_msgs::Arm_Analog_Output_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rm_msgs::Arm_Analog_Output_<ContainerAllocator>& v)
  {
    s << indent << "num: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.num);
    s << indent << "voltage: ";
    Printer<float>::stream(s, indent + "  ", v.voltage);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RM_MSGS_MESSAGE_ARM_ANALOG_OUTPUT_H