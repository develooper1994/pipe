#pragma once

namespace pipe { namespace algorithm {

namespace details {

template <typename Predicate>
struct drop_while_t
{
    Predicate pred;

    template <typename Generator>
    static auto apply(Generator gen, drop_while_t algorithm) -> Generator
    {
        bool drop = true;

        for (auto&& item : gen)
        {
            if (drop)
                if (drop = algorithm.pred(item))
                    continue;

            co_yield item;
        }
    }
};

} // namespace details

template <typename Predicate>
auto drop_while(Predicate pred)
{
    return details::drop_while_t<Predicate> { pred };
}

template <typename Predicate>
auto drop_until(Predicate pred)
{
    return drop_while([pred](auto& item) { return !pred(item); });
}

inline auto drop_n(size_t n)
{
    return drop_while([n](auto&) mutable { return n-- > 0; });
}

}} // namespace pipe::algorithm