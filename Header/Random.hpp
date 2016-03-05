/*
 * Copyright (c) 2016 WU Zhenyu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following 
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DEF_RANDOM_HPP
#define DEF_RANDOM_HPP

#include <random>
#include <chrono>
#include <type_traits>

namespace
{
	template <typename T>
	T randomFloatUsingRandomDevice(T min, T max)
	{
		static std::random_device rd;
		static const auto seed = rd();
		static std::mt19937_64 generator{ seed };
		std::uniform_real_distribution<T> distribution{ min, max };
		
		return distribution(generator);
	}

	template <typename T>
	T randomFloatUsingTime(T min, T max)
	{
		static const unsigned long long int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::mt19937_64 generator{ seed };
		std::uniform_real_distribution<T> distribution{ min, max };

		return distribution(generator);
	}

	template <typename T>
	T randomIntUsingRandomDevice(T min, T max)
	{
		static std::random_device rd;
		static const auto seed = rd();
		static std::mt19937_64 generator{ seed };
		std::uniform_int_distribution<T> distribution{ min, max };

		return distribution(generator);
	}

	template <typename T>
	T randomIntUsingTime(T min, T max)
	{
		static const unsigned long long int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::mt19937_64 generator{ seed };
		std::uniform_int_distribution<T> distribution{ min, max };

		return distribution(generator);
	}
}

namespace Utilities
{
	template <typename T>
	T randomFloat(T min, T max)
	{
		static_assert(std::is_floating_point<T>::value, "Gived type isn't a floating point type");

		static std::random_device rd;
		if (rd.entropy() != 0)
		{
			return randomFloatUsingRandomDevice(min, max);
		}
		return randomFloatUsingTime(min, max);
	}

	template <typename T>
	T randomInt(T min, T max)
	{
		static_assert(std::is_integral<T>::value, "Gived type isn't an integer type");

		static std::random_device rd;
		if (rd.entropy() != 0)
		{
			return randomIntUsingRandomDevice(min, max);
		}
		return randomIntUsingTime(min, max);
	}
}

#endif
