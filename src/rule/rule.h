#include "IRule.h"

#include <vector>
namespace griddler
{
    /** Implementation of the IRule interface. */
    class Rule : public IRule
    {
    public:
        /** Create rule and set width. */
        explicit Rule (uint8_t width);
        /** Default destructor. */
        ~Rule ();

        /** Add rule. */
        void addRule (uint8_t rule);
        /** {@inheritDoc} */
        virtual uint64_t getSize () const override;
        /** {@inheritDoc} */
        virtual uint64_t getValue (uint64_t index) const override;
        /** {@inheritDoc} */
        virtual uint8_t getWidth () const override;
    private:
        /** Calculate binomial coefficient. */
        uint64_t getComb (uint8_t n, uint8_t k) const;

        /** Width of the rule. */
        uint8_t m_width;
        /** Count of used rules. */
        uint8_t m_count;
        /** Sum of the rules. */
        uint8_t m_sum;
        /** Collection of rules. */
        std::vector<uint8_t> m_rules;
    };
}
