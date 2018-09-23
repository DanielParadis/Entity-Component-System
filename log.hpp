#ifndef LOG_HPP
#define LOG_HPP
constexpr bool LOGGING{true};
template <typename T>
void log(T str)
{
    if(LOGGING)
    {
        std::cout << "log: " << str << std::endl;
    }
}
#endif // LOG_HPP
