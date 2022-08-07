#ifndef __STREAM_H__
#define __STREAM_H__

#include <deque>

template <class Item>
class Stream
{
    private:
        /**
         * @brief The initial length of the stream.
         */
        int ilen;

        /**
         * @brief Stores the position of the last item that was read.
         * @internal
         */
        int position;

        /**
         * @brief The ID of this stream. (this can be -1 if it is not relevant)
         */
        signed char unique_id;

        /**
         * @brief Whether or not to allow the Item buffer to be resized. (externally)
         */
        bool allow_resize;

        /**
         * @brief The last Item that was read.
         */
        Item *last_item;

        /**
         * @brief Consumes the Item in the stream, giving you the next Item.
         */
        Item peek_internal();

    public:
        /**
         * @brief A dynamically allocated array of Items.
         * This will change as the stream is parsed.
         *
         * It is advised that you use `items()` instead of accessing this directly.
         */
        std::deque<Item> buff;

        /**
         * @brief Construct a new Stream object from an array of items.
         */
        static Stream<Item>* from_ptr(Item *items, long len);

        /**
         * @brief Constructs a new Stream object from a deque of items.
         */
        static Stream<Item>* from_deque(std::deque<Item> items);

        /**
         * @brief Construct a new Stream object.
         */
        Stream<Item>();

        ~Stream<Item>();

        /**
         * @brief Consumes the Item in the stream, giving you the next Item.
         */
        Item* peek();

        Stream<Item>* peek(int amt);

        bool push(Item item);

        bool is_eof();

        /**
         * @brief Returns the amount of Items that have been consumed.
         * @return int
         */
        int consumed();

        int size();

        /**
         * @brief Return a Item at given position ahead. (nullptr if out of bounds)
         */
        Item *nth();

        /**
         * @brief Return the next Item in the stream.
         */
        Item* nth(int n);

        /**
         * @brief Returns the first item in the stream without consuming it.
         */
        Item *first() {
            return nth(0);
        }

        /**
         * @brief Returns the second item in the stream without consuming it.
         */
        Item *second() {
            return nth(1);
        }

        /**
         * @brief Returns the third item in the stream without consuming it.
         */
        Item *third() {
            return nth(2);
        }

        /**
         * @brief Similar to sub_str, but returns a stream of `Item`s.
         */
        Stream<Item> *sub_items(int from, int to);

        /**
         * @brief Returns the Item that are left in the stream.
         * This is COPIED, so you can't modify the actual buffer.
         */
        std::vector<Item> items();
};

#include "compiler/util/Stream.tpp"

#endif