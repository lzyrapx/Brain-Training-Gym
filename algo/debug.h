// debug.h
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string_view>
#include <utility>

// 调试输出控制
#ifndef DEBUG
#define DEBUG 1  // 默认为调试模式，可以在编译时定义 DEBUG=0 来关闭
#endif

#if DEBUG
#define del std::cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)

// 重载 << 操作符用于输出 pair
template <class X, class Y>
std::ostream& operator<<(std::ostream& os, std::pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// 重载 << 操作符用于输出容器
template <class Ch, class Tr, class Container>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int) std::distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}

// 调试输出函数
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    std::string_view s(names);
    std::cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((std::cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    std::cout << " }" << '\n';
}

#else
#define del 
#define debug(...) ((void)0)
#endif

#endif // DEBUG_H