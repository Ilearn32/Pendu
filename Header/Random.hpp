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
