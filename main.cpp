#include <iostream>
#include "stopwatch.hpp"

int main(int argc, char *argv[]) {
    stopwatch::StopWatch sw;
    sw.start();

    long long tmp = 0LL;
    for(int i=0;i<100000;++i) {
        tmp += i;
    }
    std::cout << tmp << std::endl;
    std::cout << sw << std::endl;

    return 0;
}
