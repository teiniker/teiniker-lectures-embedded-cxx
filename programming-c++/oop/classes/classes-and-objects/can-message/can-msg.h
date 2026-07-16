#pragma once

#include <cstdint>
#include <string>

class CanMsg
{
    private:
        uint32_t _id;
        uint8_t _dlc;
        uint8_t _data[8];

    public:
        CanMsg(uint32_t id, uint8_t dlc, const uint8_t *data);
        
        // Accessor methods
        uint32_t id() const { return _id; }
        uint8_t dlc() const { return _dlc; }
        uint8_t data(uint8_t index) const;

        // Methods
        std::string asString() const;
};
