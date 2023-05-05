#ifndef ZAKOPANEZAPIEKANKA_H
#define ZAKOPANEZAPIEKANKA_H

#include "../Zapiekanka.hpp"

class ZakopaneZapiekanka : public Zapiekanka {
public:
    ZakopaneZapiekanka() {
        setDough(ThinCrustDough());
        setCheese(OscypekCheese());
        setSauce(PlumTomatoSauce());
        addTopping(BoczekTopping());
        addTopping(OlivesTopping());
        m_name = "Zakopane";
    }
};

#endif // ZAKOPANEZAPIEKANKA_H
