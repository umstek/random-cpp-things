#include <fstream>
#include <string>

class Test
{
private:
    std::ofstream ofs;
    std::ofstream ofs1;

public:
    Test(/* args */);
    ~Test();
    void write(std::string);
};

Test::Test(/* args */)
{
    ofs.open("test.txt", std::ios::app);
    ofs1.open("test1.txt", std::ios::app);
    // Fix decimal places instead of precision
    ofs1.setf(std::ios_base::fixed, std::ios_base::floatfield);
    ofs1.precision(3);
}

Test::~Test()
{
}

void Test::write(std::string str)
{
    ofs << str << " " << 1.234567890 << " " << 1234.567890 << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        ofs << "x\n";
    }
    ofs1 << str << " " << 1.234567890 << " " << 1234.567890 << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        ofs1 << "y\n";
    }
    // ofs.flush(); // Not needed if we close the stream i.e.: delete.
}

int main(int argc, char const *argv[])
{
    Test *a = new Test();
    a->write("hello, world!");
    a->write("");

    exit(-1); // Premature termination

    delete a;

    return 0;
}
