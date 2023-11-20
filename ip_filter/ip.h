#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#include "helpers.h"


class Ip {
public:
    Ip(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
        m_ip = {a, b, c , d};
    }

    Ip(const std::string& str) {
        ParseIp(str);
    }

    bool Find(uint8_t num) const {
        return std::find(m_ip.begin(), m_ip.end(), num) != m_ip.end();
    }

    std::string GetStrIp() const {
        std::string str;
        for (int num: m_ip) {
            str += std::to_string(num) + ".";
        }
        str.pop_back();
        return str;
    }

    void Print() const {
        std::cout << +m_ip[0] << "." << +m_ip[1] << "."
                  << +m_ip[2] << "." << +m_ip[3] << std::endl;
    }

    const bool operator < (const Ip &other) const {
        return m_ip[0] != other.m_ip[0] ? (m_ip[0] < other.m_ip[0]) :
               m_ip[1] != other.m_ip[1] ? (m_ip[1] < other.m_ip[1]) :
               m_ip[2] != other.m_ip[2] ? (m_ip[2] < other.m_ip[2]) :
              (m_ip[3] < other.m_ip[3]);
    }

    const bool operator > (const Ip &other) const {
        return !(*this < other);
    }

    uint8_t operator [](size_t i) const {
        return i < 5 ? m_ip[i] : -1;
    }

private:
    std::array<uint8_t, 4> m_ip;

    void ParseIp(const std::string &str)
    {
        auto tmp_vec = split(str, '.');
        for (size_t i = 0; i < tmp_vec.size(); i++) {
            m_ip[i] = stoi(tmp_vec[i]);
        }
    }

};