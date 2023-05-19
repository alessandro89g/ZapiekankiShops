#ifndef MEMENTO_HPP
#define MEMENTO_HPP

/*  This class holds the information of older and current state of the order, i.e.
 *      the list of different zapiekanki
 *      the number for each different zapiekanki
 *      the timestamp of the state
 */

#include <iostream>
#include <vector>
#include <chrono>
#include "Zapiekanka.hpp"

class Memento {
public:
    Memento() = delete;
    Memento(const std::vector<Zapiekanka>& zapiekanki, const std::vector<int>& n_zapiekanki)
        : m_zapiekanki(zapiekanki), m_n_zapiekanki(n_zapiekanki) {
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        m_timestamp = ctime(&time);
    }

    std::string getTimeStamp() const {
        return m_timestamp;
    }
    std::vector<int> get_NumberZapiekankas() const {
        return m_n_zapiekanki;
    }
    std::vector<Zapiekanka> get_Zapiekankas() const {
        return m_zapiekanki;
    }

private:
    std::vector<Zapiekanka> m_zapiekanki;
    std::vector<int> m_n_zapiekanki;
    std::string m_timestamp;
};

#endif // MEMENTO_HPP
