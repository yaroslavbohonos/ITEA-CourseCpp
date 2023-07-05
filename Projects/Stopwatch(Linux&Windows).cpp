/* Task in Replit(Compiler) - https://replit.com/@Bgns/Stopwatch-or-66#main.cpp

Task: Write the Stopwatch for the Windows and Linux */

#include <iostream>
#include <chrono>
#include <thread> 

#ifdef _WIN32
  #include<conio.h>
  #include<Windows.h>
#endif

#ifdef __linux
  #include <sys/ioctl.h>
  #include <termios.h>
  #include <fcntl.h>
#endif

#define ESC 27

class Watch
{
private:
    int sec, min, hour;

public:
    Watch() : sec(0), min(0), hour(0) {}
    Watch(int seconds, int minutes, int hours) : sec(seconds), min(minutes), hour(hours) {}
    Watch(const Watch& other) : sec(other.sec), min(other.min), hour(other.hour) {}

    void countTime()
    {
        std::cout << *this;
        sec++;
        if (sec == 60)
        {
            min++;
            sec = 0;
        }
        if (min == 60)
        {
            hour++;
            min = 0;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    friend std::ostream& operator<<(std::ostream& out, const Watch& obj)
    {
        out << "Program running time\nsec: " << obj.sec
            << "\tmin: " << obj.min << "\thour: " << obj.hour << std::endl;
        return out;
    }
};

#ifdef _WIN32
void counter(Watch& watch)
{
    while (!_kbhit())
    {
        system("cls");
        watch.countTime();
    }
}
#endif

#ifdef __linux
int _kbhit(void)
{
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(0, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newt);
    oldf = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(0, TCSANOW, &oldt);
    fcntl(0, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void counter(Watch& watch)
{
    while (!_kbhit())
    {
        std::system("clear");
        std::cout << "Press ESC at any time to exit.\n";
        watch.countTime();
    }
}
#endif

int main()
{
#ifdef _WIN32
    Watch watch;
    counter(watch);
#endif

#ifdef __linux
    Watch watch;
    counter(watch);
#endif

    return 0;
}
