//
// Created by edmond on 24.11.24.
//
#pragma once

#include <iostream>

template<typename T>
class dynamic_array {
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for(size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    };

public:
    //Konstruktoren mit Wertinitialisierung
    dynamic_array() : data(nullptr), size(0), capacity(0) {};

    explicit dynamic_array(const T& val) : size(1), capacity(1) {
        data = new T[capacity];
        data[0] = val;
    }

    explicit dynamic_array(T&& val) : size(1), capacity(1) {
        data = new T[capacity];
        data[0] = std::move(val);
    }

    explicit dynamic_array(const T& val, size_t len) : size(len), capacity(len) {
        data = new T[capacity];
        for(size_t i = 0; i < size; ++i)
            data[i] = val;
    }

    //---------------------------------//

    //Destruktor
    ~dynamic_array() {
        delete[] data;
    }

    //---------------------------------//

    //Kopie-Konstruktor
    dynamic_array(const dynamic_array& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for(size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    //Kopiezuweisung
    dynamic_array& operator=(const dynamic_array& other) {
        if(this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];
            for(size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    //---------------------------------//

    //Move-Konstruktor
    dynamic_array(dynamic_array&& other)  noexcept : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = other.capacity = 0;
    }

    //Movezuweisung
    dynamic_array& operator=(dynamic_array&& other) noexcept {
        if(this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = other.capacity = 0;
        }
        return *this;
    }

    //---------------------------------//

    void push_back(const T& val) {
        if(size == capacity) resize(capacity == 0 ? 1 : capacity * 2);
        data[size] = val;
        ++size;
    }

    void push_back(T&& val) {
        if(size == capacity) resize(capacity == 0 ? 1 : capacity * 2);
        data[size] = std::move(val);
        ++size;
    }

    //---------------------------------//

    const T& operator[](size_t idx) const {
        if(idx >= size) throw std::out_of_range("Index out of range");
        return data[idx];
    }

    T& operator[](size_t idx) {
        if(idx >= size) throw std::out_of_range("Index out of range");
        return data[idx];
    }

    //---------------------------------//

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    //---------------------------------//

    friend std::ostream& operator<<(std::ostream& os, const dynamic_array& obj) {
        os << "[ ";
        for(size_t i = 0; i < obj.size; ++i) {
            if(i == obj.size - 1) {
                os << obj[i];
            } else {
                os << obj[i] << ", ";
            }
        }
        os << " ]";
        return os;
    }
};
