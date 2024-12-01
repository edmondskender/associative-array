//
// Created by edmond on 24.11.24.
//
#pragma once

#include <iostream>

template<typename key, typename value>
struct pair {
    key first;
    value second;

    //Konstruktoren
    pair() : first(), second() {};

    pair(const key& k, const value& v) : first(k), second(v) {};
    pair(key&& k, value&& v) : first(std::move(k)), second(std::move(v)) {};

    //-------------------//


    //Kopiersemantik
    pair(const pair& other) : first(other.first), second(other.second) {};

    pair& operator=(const pair& other) {
        if(this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    //-----------------//

    //Movesemantik
    pair(pair&& other)  noexcept : first(std::move(other.first)), second(std::move(other.second)) {}

    pair& operator=(pair&& other)  noexcept {
        if(this != &other) {
            first = std::move(other.first);
            second = std::move(other.second);
        }
        return *this;
    }

};