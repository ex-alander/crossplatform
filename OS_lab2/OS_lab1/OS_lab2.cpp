#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex m;

void ThrFunc(std::string filename)
{
    m.lock();
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream in;
    std::string line = "1";
    in.open(filename);
    if (in.is_open())
    {
        while(line[0])
        {
            char a;
            //if (filename == "f1.txt" or filename == "f2.txt") a = '\t';
            //else a = '\n';
            getline(in, line);
            std::cout << line << '\t'; //that'll make things terribly slow
        }
    }
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli > elapsed = end - start;
    std::cout << "time consumption: " << elapsed.count() << " ms" << '\n';
    m.unlock();
}



int main(int argc, char** argv) {
    std::thread thr1(ThrFunc, argv[1]);
    std::thread thr2(ThrFunc, argv[2]);
    std::thread thr3(ThrFunc, argv[3]);
    thr1.join();
    thr2.join();
    thr3.join();
    std::cin.get();
    return 0;
}