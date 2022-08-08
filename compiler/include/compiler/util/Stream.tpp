#ifndef __STREAM_TPP__
#define __STREAM_TPP__

#include <stdexcept>
#include <optional>

using namespace joku::compiler;

template<typename Item>
Stream<Item>* Stream<Item>::from_ptr(Item *items, long len)
{
    // I would normally do a for loop here, but i believe that
    // this initialization is faster than a for loop

    // THIS IS A VERY BAD IDEA
    // if (len == 0)
    // {
    //     // this is a hack to try and determine the length of the array
    //     // because this array has no length specified, therefore we are
    //     // this is super hacky, and you should pass the length of the array
    //     len = (sizeof(items) / sizeof(items[0]));
    // }

    Stream<Item> *stream = new Stream();
    stream->buff = std::deque<Item>(items, items + len);
    return stream;
}

template<typename Item>
Stream<Item>* Stream<Item>::from_deque(std::deque<Item> items)
{
    // this is a little hacky cause we already have the buffer, we can just move the buffer
    Stream<Item> *stream = new Stream();
    stream->buff = items;

    return stream;
}

template<typename Item> Stream<Item>::Stream()
{
    this->position = 0;
    this->ilen = 0;
    this->unique_id = -1;
    this->last_item = nullptr;
    this->buff = std::deque<Item>();
}

template<typename Item> Stream<Item>::~Stream()
{
}

template<typename Item>
Item Stream<Item>::peek_internal()
{
    if (this->allow_resize == true)
    {
        this->allow_resize = false;
    }

    // we need to make sure that we can peek at the next Item
    if (this->buff.size() < 1)
    {
        throw new std::exception();
    }
    else
    {
        this->position++;
        Item front = this->buff.front();
        this->buff.pop_front();
        return front;
    }
}

template<typename Item>
std::optional<Item> Stream<Item>::peek()
{
    try
    {
        Item item = this->peek_internal();
        return item;
    }
    catch (std::exception &e)
    {
        return std::nullopt;
    }
}

template<typename Item>
Stream<Item>* Stream<Item>::peek(int amt)
{
    if (this->buff.size() < amt)
    {
        return nullptr;
    }
    else
    {
        Stream<Item> *stream = new Stream();
        for (int i = 0; i < amt; i++)
        {
            std::optional<Item> item = this->peek();
            if (!item.has_value())
            {
                break;
            }
            stream->buff.push_back(item.value());
        }

        if (stream->size() == 0)
        {
            delete stream;
            return nullptr;
        }
        else
        {
            return stream;
        }
    }
}

template<typename Item>
bool Stream<Item>::push(Item item)
{
    if (this->allow_resize)
    {
        this->buff.push_back(item);
        return true;
    }
    else
    {
        return false;
    }
}

template<typename Item>
bool Stream<Item>::is_eof()
{
    return this->buff.size() == 0 && this->position == this->ilen;
}

template<typename Item>
int Stream<Item>::consumed()
{
    return this->ilen - this->buff.size();
}

template<typename Item>
int Stream<Item>::size()
{
    return this->buff.size();
}

template<typename Item>
Item *Stream<Item>::nth()
{
    if (this->buff.size() < 1)
    {
        return nullptr;
    }
    else
    {
        return &this->buff.front();
    }
}

template<typename Item>
Item* Stream<Item>::nth(int n)
{
    if (this->buff.size() < n)
    {
        return nullptr;
    }
    else
    {
        return &this->buff.at(n);
    }
}

template<typename Item>
Stream<Item>* Stream<Item>::sub_items(int from, int to)
{
    if (this->buff.size() < to || this->buff.size() < from)
    {
        return nullptr;
    }
    else
    {
        Stream *stream = new Stream();
        for (int i = from; i < to; i++)
        {
            stream->buff.push_back(this->buff.at(i));
        }
        return stream;
    }
}

template<typename Item>
std::vector<Item> Stream<Item>::items()
{
    std::vector<Item> items = std::vector<Item>();
    for (int i = 0; i < this->buff.size(); i++)
    {
        items.push_back(this->buff.at(i));
    }
    return items;
}

#endif