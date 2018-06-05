#ifndef BLOCK_TYPE_H_INCLUDED
#define BLOCK_TYPE_H_INCLUDED

#include <string>

#include "../Block_Data.h"

namespace Block
{
    class Type
    {
    public:
        const Data& getData() const;

    protected:
        Type(const std::string& fileName);

    private:
        Data m_data;
    };
}

#endif // BLOCK_TYPE_H_INCLUDED
