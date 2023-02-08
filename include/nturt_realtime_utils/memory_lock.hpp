/**
 * @file memory_lock.hpp
 * @author QuantumSpawner jet22854111@gmail.com
 * @brief ROS2 package containing utilities for memory locking.
 *
 * The memory locking functions are adopted from
 * [ros-realtime/ros2-realtime-examples](https://github.com/ros-realtime/ros2-realtime-examples).
 * For detailed explantion and examples, please refer to
 * [minimal_memory_lock](https://github.com/ros-realtime/ros2-realtime-examples/blob/rolling/minimal_memory_lock/README.md).
 */

#ifndef MEMORY_LOCK_HPP
#define MEMORY_LOCK_HPP

// glibc include
#include <malloc.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

// std include
#include <iostream>
#include <stdexcept>
#include <string>

void lock_memory();

void preallocate_memory(size_t memory_size);

void set_default_thread_stacksize(size_t stacksize);

#endif  // MEMORY_LOCK_HPP
