#pragma once
#include <string>

namespace joku::error
{
    enum class LabelType
    {
        PRIMARY,
        SECONDARY
    };

    class Label
    {
        private:
            /**
             * @brief The name of the label.
             */
            std::string name;
            /**
             * @brief The start position of the label
             */
            int start;
            /**
             * @brief The end position of the label
             */
            int to;
            /**
             * @brief The length of the label.
             */
            int length;
            /**
             * @brief The type of the label.
             */
            LabelType type;
        public:
    };
}