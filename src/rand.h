#pragma once
#include <random>

class RNG
{
    inline static std::random_device device;

    public:
    static double nextDouble(const double a, double b)
    {
        return (std::generate_canonical<double,
                                        std::numeric_limits<double>::digits,
                                        std::random_device>(device) * (b - a)) + a;
    }

    static float nextFloat(const float a, const float b)
    {
        return (std::generate_canonical<float,
                                        std::numeric_limits<float>::digits,
                                        std::random_device>(device) * (b - a)) + a;
    }
};