#ifndef MEMENTOCARETAKER_HPP
#define MEMENTOCARETAKER_HPP

/*  As the names suggests, it takes care of saving and restoring the state
 *  of the order. It contains the vector of Memento objects saved that can be restored.
 */

#include <vector>
#include "Memento.hpp"

class MomentoCaretaker {
public:
    void saveState(const Memento& memento) {
        m_mementos.emplace_back(memento);
    }

    std::optional<Memento> loadLastState() {
        if (m_mementos.size()<2) {
            std::cout << "\n\n"
                         "Cannot restore previous state!\n\n";
            return std::nullopt;
        }
        m_mementos.pop_back();
        Memento m = m_mementos.back();
        return m;
    }

private:
    std::vector<Memento> m_mementos;
};

#endif // MEMENTOCARETAKER_HPP
