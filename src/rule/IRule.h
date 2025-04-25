#pragma once

#include <memory>

namespace griddler
{
    /** An interface for creating line rules. */
    class IRule
    {
    public:
        /** Virtual interface destructor. */
        virtual ~IRule () = default;

        /** Get the count of the values in the collection. */
        virtual uint64_t getSize () const = 0;
        /** Get the value from the specific position. */
        virtual uint64_t getValue (uint64_t index) const = 0;
        /** Get the width of the rule. */
        virtual uint8_t getWidth() const = 0;
    };

    /** Factory class to create rule. */
    IRule* createNewRule (uint8_t width, const char* rule);

    /** Helper function wrapping newly created instance of rule by a smart pointer. */
    inline auto createRule (uint8_t width, const char* rule)
    {
        return std::unique_ptr<IRule> {createNewRule (width, rule)};
    }
}
