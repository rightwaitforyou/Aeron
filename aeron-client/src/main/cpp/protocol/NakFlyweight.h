//
// Created by Michael Barker on 24/11/2015.
//

#ifndef INCLUDED_AERON_COMMAND_NAKFLYWEIGHT__
#define INCLUDED_AERON_COMMAND_NAKFLYWEIGHT__

#include <cstdint>
#include <string>
#include <stddef.h>
#include <command/Flyweight.h>
#include <concurrent/AtomicBuffer.h>
#include <util/Index.h>
#include "HeaderFlyweight.h"

namespace aeron { namespace protocol {

/**
 * Data recovery retransmit message:
 *
 * https://github.com/real-logic/Aeron/wiki/Protocol-Specification#data-recovery-via-retransmit-request
 */

#pragma pack(push)
#pragma pack(4)
struct NakDefn
{
    HeaderDefn headerDefn;
    std::int32_t sessionId;
    std::int32_t streamId;
    std::int32_t termId;
    std::int32_t termOffset;
    std::int32_t length;
};
#pragma pack(pop)

class NakFlyweight : public HeaderFlyweight
{
public:
    typedef NakFlyweight this_t;

    NakFlyweight(concurrent::AtomicBuffer& buffer, std::int32_t offset)
        : HeaderFlyweight(buffer, offset), m_struct(overlayStruct<NakDefn>(0))
    {
    }

    inline std::int32_t sessionId() const
    {
        return m_struct.sessionId;
    }

    inline this_t& sessionId(std::int32_t value)
    {
        m_struct.sessionId = value;
        return *this;
    }

    inline std::int32_t streamId() const
    {
        return m_struct.streamId;
    }

    inline this_t& streamId(std::int32_t value)
    {
        m_struct.streamId = value;
        return *this;
    }

    inline std::int32_t termId() const
    {
        return m_struct.termId;
    }

    inline this_t& termId(std::int32_t value)
    {
        m_struct.termId = value;
        return *this;
    }

    inline std::int32_t termOffset()
    {
        return m_struct.termOffset;
    }

    inline this_t& termOffset(std::int32_t value)
    {
        m_struct.termOffset = value;
        return *this;
    }

    inline std::int32_t length() const
    {
        return m_struct.length;
    }

    inline this_t& length(std::int32_t value)
    {
        m_struct.length = value;
        return *this;
    }

    inline static std::int32_t headerLength()
    {
        return sizeof(NakDefn);
    }

private:
    NakDefn& m_struct;
};

}}

#endif //INCLUDED_AERON_COMMAND_NAKFLYWEIGHT__
