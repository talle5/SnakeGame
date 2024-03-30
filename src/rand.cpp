module;

import <random>;

export module rng;

export class RNG {
    std::random_device device;
public:
    double nextDouble(const double a, double b) {
        return (std::generate_canonical<double,
                std::numeric_limits<double>::digits,
                std::random_device>(device) *
                (b - a)) + a;
    }
};