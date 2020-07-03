#include <iostream>
#include <string>

using namespace std;

struct A
{
    int id;

    A(int id);
    ~A();
    A(const A &a);
};

A::A(int id)
{
    this->id = id;
    cout << "A" << id << "\n";
}

A::~A()
{
    cout << "~A" << id << "\n";
}

A::A(const A &a) : id(a.id * 10)
{
    cout << "A" << id << "\n";
}

class Test
{
private:
    A a;
    A aa;

public:
    Test(A a);
    ~Test();
};

Test::Test(A a) : a(a), aa(2)
{
    cout << "Test\n";
}

Test::~Test()
{
    cout << "~Test\n";
}

int main(int argc, char const *argv[])
{
    Test test(A(1));
    A aaa = A(3);

    return 0;
}

// A1
// A10      {
// A2       (
// Test     [
// ~A1
// A3
// ~A3
// ~Test    ]
// ~A2      )
// ~A10     }