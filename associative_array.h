//
// Created by edmond on 24.11.24.
//
#pragma once

#include <iostream>
#include "dynamic_array.h"
#include "pair.h"

template<typename key, typename val>
class associative_array {
    dynamic_array<pair<key, val>> arr;

public:
    associative_array() = default;

    explicit associative_array(const key& k, const val& v) {
        pair<key, val> new_pair(k,v);
        arr.push_back(new_pair);
    }

    explicit associative_array(key&& k, val&& v) {
        pair<key, val> new_pair(std::move(k),std::move(v));
        arr.push_back(std::move(new_pair));
    }


    const val& operator[](const key& k) const {
        for(size_t i = 0; i < arr.get_size(); ++i) {
            if(arr[i].first == k) {
                return arr[i].second;
            }
        }
        throw std::out_of_range("key not found");
    }

    val& operator[](const key& k) {
        for(size_t i = 0; i < arr.get_size(); ++i) {
            if(arr[i].first == k) {
                return arr[i].second;
            }
        }
        arr.push_back(pair<key,val>(k));
        return arr[arr.get_size() - 1].second;
    }

    val& operator[](key&& k) {
        for(size_t i = 0; i < arr.get_size(); ++i) {
            if(arr[i].first == k) {
                return arr[i].second;
            }
        }
        arr.push_back(std::move(pair<key,val>(std::move(k))));
        return arr[arr.get_size() - 1].second;
    }

    size_t get_size() {
        return arr.get_size();
    }


    friend std::ostream& operator<<(std::ostream& os, const associative_array& obj) {
        os << "{ ";
        for (size_t i = 0; i < obj.arr.get_size(); ++i) {
            os << obj.arr[i].first << ": " << obj.arr[i].second;
            if (i != obj.arr.get_size() - 1)
                os << ", ";
        }
        os << " }";
        return os;
    }
};