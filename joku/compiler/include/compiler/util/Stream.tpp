#ifndef __STREAM_TPP__
#define __STREAM_TPP__

#include <stdexcept>
#include <functional>
#include <optional>

using namespace joku::compiler;

template<typename Item>
Stream<Item> *Stream<Item>::from_ptr(Item *items, long len)
{
    Stream<Item> *stream = new Stream();
    std::vector<Item> itemss = std::vector<Item>(items, items + len);
    stream->buff.assign(itemss.begin(), itemss.end());
    return stream;
}

template<typename Item>
Stream<Item> *Stream<Item>::from_vector(std::vector<Item> items)
{
    // this is a little hacky cause we already have the buffer, we can just move the buffer
    Stream<Item> *stream = Stream();
    stream->buff = std::deque{items};

    return stream;
}

template<typename Item> Stream<Item>::Stream()
{
    this->position = 0;
    this->ilen = 0;
    this->unique_id = -1;
    this->last_item = std::nullopt;
    this->allow_resize = true;
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
        this->last_item = this->buff.front();
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
    return this->buff.size() == 0;
}

template<typename Item>
int Stream<Item>::consumed()
{
    return this->ilen - this->buff.size();
}

template<typename Item>
std::vector<Item> Stream<Item>::consume_while(std::function<bool(Item)> predicate)
{
    std::vector<Item> consumed;

    while (this->first() != nullptr && (predicate(*(this->first())) == true) && !this->is_eof())
    {
        if (this->first() == nullptr)
        {
            break;
        }
        Item item = this->peek().value();
        consumed.push_back(item);
    }

    return consumed;
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
    if (this->buff.size() == 0)
    {
        return nullptr;
    }
    else
    {
        return &this->buff.at((unsigned int) n);
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