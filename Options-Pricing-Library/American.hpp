#include <numeric>

// Helper function for option payoff (customizable for put or call)
inline float put_payoff(const float strike, const float spot_price) {
    return std::max(strike - spot_price, 0.0f);
}

inline float call_payoff(const float strike, const float spot_price) {
    return std::max(spot_price - strike, 0.0f);
}