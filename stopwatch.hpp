#include <iostream>
#include <chrono>

namespace stopwatch {

class StopWatch {
public:
    StopWatch() : saved_time(0), isRunning(false) {
        start_time = std::chrono::high_resolution_clock::now();
        previous_time = std::chrono::high_resolution_clock::now();
    }
    ~StopWatch() {
        std::cout << "total time: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start_time).count() / double(1000000) << "ms" << std::endl;
    }

    void start() {
        if(!isRunning) {
            previous_time = std::chrono::high_resolution_clock::now();
            isRunning = true;
        }
    }

    void stop() {
        if(isRunning) {
            const std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            saved_time += std::chrono::duration_cast<std::chrono::milliseconds>(now - previous_time);
            isRunning = false;
        }
    }

    void reset()
    {
        saved_time = std::chrono::milliseconds(0);
        isRunning = false;
    }

    std::chrono::microseconds elapsed() const
    {
        return isRunning ? saved_time + std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - previous_time) : saved_time;
    }

    double elapsed_ms() const
    {
        return elapsed().count() / double(1000000);
    }

    friend std::ostream& operator<<(std::ostream& out, const StopWatch& sw)
    {
        return out << sw.elapsed_ms() << "ms";
    }

public:
    std::chrono::high_resolution_clock::time_point previous_time;
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::microseconds saved_time;
    bool isRunning;
};

}
