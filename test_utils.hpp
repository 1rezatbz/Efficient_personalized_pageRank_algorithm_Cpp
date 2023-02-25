#pragma once

#include <cassert>
#include <chrono>
#include <cmath>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace test_utility {

    constexpr double ABSOLUTE_ERROR_EPSILON{10e-4};
    constexpr double AVERAGE_ABSOLUTE_ERROR_EPSILON{10e-5};

/**
 * @brief Compares two vectors of arithmetic type and returns true if they are equal within the defined tolerance.
 * @tparam T The arithmetic type of the vectors.
 * @param result The vector that stores calculated values.
 * @param correct The vector that stores accurate values.
 * @param absolute_error The maximum allowed absolute error.
 * @param average_error The maximum allowed average absolute error.
 * @return true if the maximum absolute error is less than `absolute_error`
 * and the average absolute error is less than `average_error`, false otherwise.
 */
    template <typename T>
    bool TestEqualVectors(const std::vector<T>& result, const std::vector<T>& correct,
                          double absolute_error = ABSOLUTE_ERROR_EPSILON,
                          double average_error = AVERAGE_ABSOLUTE_ERROR_EPSILON) {
        static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type!");

        return MaxAbsoluteError(result, correct) < absolute_error &&
               AverageAbsoluteError(result, correct) < average_error;
    }

}  // namespace test_utility
