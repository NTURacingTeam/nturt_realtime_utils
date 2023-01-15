/**
 * @file scheduling.hpp
 * @author QuantumSpawner jet22854111@gmail.com
 * @brief ROS2 package containing utilities for real-time priority scheduling.
 * 
 * The real-time priority scheduling functions are adopted from
 * [ros-realtime/ros2-realtime-examples](https://github.com/ros-realtime/ros2-realtime-examples).
 * For detailed explantion and examples, please refer to
 * [minimal_scheduling](https://github.com/ros-realtime/ros2-realtime-examples/blob/rolling/minimal_scheduling/README.md).
 */

#ifndef SCHEDULING_HPP
#define SCHEDULING_HPP

// glibc include
#include <pthread.h>
#include <string.h>
#include <sys/types.h>

// std include
#include <stdexcept>
#include <string>
#include <thread>

void set_thread_scheduling(std::thread::native_handle_type thread, int policy, int priority);

#endif // SCHEDULING_HPP
