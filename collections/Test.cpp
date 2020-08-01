#include <set>
#include <map>
#include <string>
#include <iostream>

typedef std::map<std::string, std::set<int> *> inner_t;
typedef std::map<std::string, inner_t *> outer_t;

int main(int argc, char const *argv[])
{
    outer_t o;

    o.insert(std::make_pair("k1", new inner_t()));

    outer_t::iterator oi = o.find("k1");
    if (oi == o.end())
    {
        std::cout << "o +" << std::endl;
        std::pair<outer_t::iterator, bool> r = o.insert(std::make_pair("k1", new inner_t()));
        oi = r.first;
    }

    oi->second->insert(std::make_pair("l1", new std::set<int>()));

    inner_t::iterator ii = oi->second->find("l1");
    if (ii == oi->second->end())
    {
        std::cout << "i +" << std::endl;
        oi->second->insert(std::make_pair("l1", new std::set<int>()));
    }
    else
    {
        std::cout << "i" << std::endl;
    }

    return 0;
}
