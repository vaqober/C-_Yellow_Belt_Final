#include <iostream>
#include <vector>
#include <map>

template <typename T> T Sqr(T x);
template <typename Item> std::vector<Item> operator * (const std::vector<Item>& v1, const std::vector<Item>& v2);
template <typename First, typename Second> std::pair<First, Second> operator * (const std::pair<First, Second>& p1, const std::pair<First, Second>& p2);
template <typename Key, typename Value> std::map<Key, Value> operator * (const std::map<Key, Value>& m1, const std::map<Key, Value>& m2);


template <typename Item>
std::vector<Item> operator * (const std::vector<Item>& v1, const std::vector<Item>& v2) {
    std::vector<Item> result;
    for (int i = 0; i < v1.size(); ++i) {
        result.push_back(v1[i] * v2[i]);
    }
    return result;
}

template <typename First, typename Second>
std::pair<First, Second> operator * (const std::pair<First, Second>& p1, const std::pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return std::make_pair(f, s);
};

template <typename Key, typename Value>
std::map<Key, Value> operator * (const std::map<Key, Value>& m1, const std::map<Key, Value>& m2) {
    std::map<Key, Value> result;
    for (auto& p : m1) {
        auto second_value = m2.at(p.first);
        result[p.first] = p.second * second_value;
    }
    return result;
};

template <typename T>
T Sqr(T x) {
    return x * x;
}