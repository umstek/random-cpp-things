#include <iostream>
#include <stdio.h>
#include <string.h>

char *copy(char *original)
{
    char *copy1 = new char[10];
    strncpy(copy1, original, 10);
    copy1[10] = '\0';

    return copy1;
}

int main(int argc, char const *argv[])
{
    std::cout << copy("test") << std::endl;
    return 0;
}
