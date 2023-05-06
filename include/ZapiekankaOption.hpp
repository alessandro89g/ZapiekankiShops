#ifndef ZAPIEKANKAOPTION_H
#define ZAPIEKANKAOPTION_H

#include <string>

class ZapiekankaOption {
public:
    ZapiekankaOption () {}
    ZapiekankaOption(const std::string & name, unsigned int price) : m_name(name), m_price(price) {}
    unsigned int getPrice() const {
        return m_price;
    }
    std::string getName() const {
        return m_name;
    }

    bool operator == (const ZapiekankaOption& other) const {
        return (m_name == other.m_name);
    }

    bool operator != (const ZapiekankaOption& other) const {
        return (m_name != other.m_name);
    }
    virtual ~ZapiekankaOption () {}

protected:
    std::string m_name;
    unsigned int m_price;

};

#endif // ZAPIEKANKAOPTION_H
