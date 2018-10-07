#pragma once
#include <utility>
#include <pipe/traits.h>

namespace pipe { 
	namespace algorithm { 
		namespace details {
			template <typename Generator, typename Algorithm, typename = std::enable_if<pipe::is_generator<Generator>::value>::type>
			auto operator|(Generator& gen, Algorithm&& algorithm)
			{
				return algorithm(std::move(gen));
			}
		}
	}
} // namespace pipe::algorithm::details
