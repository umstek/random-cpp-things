#include <iostream>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::stringstream ss;

    ss << "this is okay";
    ss.seekp(-4, std::ios_base::end);
    ss << "not okay" << std::endl;
    std::cout << ss.str();
    return 0;
}
