#include <map>
#include <unordered_map>
#include <random>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    auto u = new std::unordered_map<int, int>();
    auto o = new std::map<int, int>();

    std::chrono::steady_clock::time_point beginU = std::chrono::steady_clock::now();
    for (int i = 0; i < 250; i++)
    {
        u->insert(std::make_pair(std::rand(), std::rand()));
    }
    std::chrono::steady_clock::time_point endU = std::chrono::steady_clock::now();
    std::cout << "Time difference [unordered_map] = " << std::chrono::duration_cast<std::chrono::nanoseconds>(endU - beginU).count() << "[ns]" << std::endl;

    std::chrono::steady_clock::time_point beginO = std::chrono::steady_clock::now();
    for (int i = 0; i < 250; i++)
    {
        o->insert(std::make_pair(std::rand(), std::rand()));
    }
    std::chrono::steady_clock::time_point endO = std::chrono::steady_clock::now();
    std::cout << "Time difference [map] = " << std::chrono::duration_cast<std::chrono::nanoseconds>(endO - beginO).count() << "[ns]" << std::endl;

    delete u;
    delete o;
    return 0;
}
