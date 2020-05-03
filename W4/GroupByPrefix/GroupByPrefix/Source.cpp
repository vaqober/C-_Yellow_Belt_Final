#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>



/*template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    string prefix) {

    auto left = lower_bound(range_begin, range_end, prefix);

    string upper_bound = prefix;

    ++upper_bound[upper_bound.size() - 1];

    auto right = lower_bound(range_begin, range_end, upper_bound);

    return { left, right };

};*/


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {

    auto left = lower_bound(range_begin, range_end, string(1, prefix));

   // cout << left;

    char next_prefix = static_cast<char>(prefix + 1);

    auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

    return { left, right };
}