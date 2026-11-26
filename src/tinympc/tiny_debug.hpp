/**
 * @file tiny_debug.hpp
 * @brief 嵌入式构建的调试输出开关。
 *
 * 默认 DEBUG_MODE == 1，保持与上游一致的 std::cout 行为。
 * 定义 -DDEBUG_MODE=0 可完全移除 iostream 依赖，适合不带 C++ 流支持的固件。
 * 无论开关取值如何都包含 <iostream>，因为关闭输出时仍需 std::string 等类型；
 * 真正省下的是各个输出表达式本身。
 */

#pragma once

#include <cstdio>
#include <iostream>

#ifndef DEBUG_MODE
#define DEBUG_MODE 1
#endif

/**
 * 调试输出宏：DEBUG_MODE 为 0 时展开为空语句，整条流表达式被预处理移除。
 * 用于替代直接书写的 std::cout 链式调用。
 */
#if DEBUG_MODE
#define TINY_DEBUG(expr) (expr)
#else
#define TINY_DEBUG(expr) ((void)0)
#endif
