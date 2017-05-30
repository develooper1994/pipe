#pragma once

namespace pipe { namespace algorithm {

template <typename Generator, typename UnaryFunction>
void for_each(Generator gen, UnaryFunction func)
{
	for (auto&& item : gen)
		func(item);
}

template <typename UnaryFunction>
auto for_each(UnaryFunction func)
{
	return [=](auto gen) { return for_each(std::move(gen), func); };
}

}} // namespace pipe::algorithm
