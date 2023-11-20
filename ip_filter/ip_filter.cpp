#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <ranges>

#include "ip.h"

template <typename F>
std::vector<Ip> filter(const std::ranges::range auto& source, F func) {
    std::vector<Ip> filtered;
    std::copy_if(source.begin(), source.end(), std::back_inserter(filtered), func);
    return filtered;
}

int main(int argc, char const *argv[])
{
    try
    {
        const uint8_t FILTER_ONE    = 1;
        const uint8_t FILTER_TWO[2] = {46, 70};
        const uint8_t FILTER_THREE  = 46;

        std::multiset<Ip, std::greater<Ip>> ip_pool;

        auto printIps = [](const auto& ips) -> void {for (const Ip& ip: ips) ip.Print();};

        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.insert(Ip(v.at(0)));
        }

        printIps(ip_pool);

        // filter by first byte and output // 1
        auto filter_one = [FILTER_ONE](const auto& ip) {return ip[0] == FILTER_ONE;};
        std::vector<Ip>  filtered_one = filter(ip_pool, filter_one);
        printIps(filtered_one);

        // filter by first and second bytes and output // 47 && 70
        auto filter_two = [FILTER_TWO](const auto& ip) {return ip[0] == FILTER_TWO[0] && ip[1] == FILTER_TWO[1];};
        std::vector<Ip>  filtered_two = filter(ip_pool, filter_two);
        printIps(filtered_two);

        // filter by any byte and output // 46
        auto filter_three = [FILTER_THREE](const auto& ip) {return ip.Find(FILTER_THREE);};
        std::vector<Ip>  filtered_three = filter(ip_pool, filter_three);
        printIps(filtered_three);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
