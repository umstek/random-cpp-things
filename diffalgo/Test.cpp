#include <string>
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<string> a;
    a.push_back("AAA");
    a.push_back("AAB");
    a.push_back("AAD");
    a.push_back("AAE");

    list<string> b;
    b.push_back("AAB");
    b.push_back("AAC");
    b.push_back("AAD");
    b.push_back("AAF");

    list<string>::iterator itrA = a.begin();
    list<string>::iterator itrB = b.begin();

    while (itrA != a.end() && itrB != b.end())
    {
        string as = *itrA;
        string bs = *itrB;

        int diff = strcmp(as.c_str(), bs.c_str());

        cout << as << ":" << bs << " " << diff << endl;

        if (diff < 0)
        {
            cout << as << " missing in B" << endl;
            itrA++;
        }
        else if (diff > 0)
        {
            cout << bs << " missing in A" << endl;
            itrB++;
        }
        else
        {
            itrA++;
            itrB++;
        }
    }

    while (itrA != a.end())
    {
        cout << *itrA << " missing in B" << endl;
        itrA++;
    }

    while (itrB != b.end())
    {
        cout << *itrB << " missing in A" << endl;
        itrB++;
    }

    return 0;
}
