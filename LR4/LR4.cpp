#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <stdexcept>// библиотека для добавления исключений
#include <memory>
#include <vector>
using namespace std;
class BaseError : public exception {
public:
    const char* what() const noexcept override {
        return "Base error occurred.";
    }
};

class InsufficientPrivileges : public BaseError {
public:
    const char* what() const noexcept override {
        return "Error: insufficient privileges.";
    }
};

class ConversionError : public BaseError {
public:
    const char* what() const noexcept override {
        return "Error: conversion error.";
    }
};

class ImpossibleConversion : public BaseError {
public:
    const char* what() const noexcept override {
        return "Error: impossible to convert the value.";
    }
};

class InterfaceCastError : public BaseError {
public:
    const char* what() const noexcept override {
        return "Error: impossible to cast to the interface.";
    }
};

// Шаблонный класс для хранения массива указателей
template <typename T>
class PointerArray {
private:
    vector<T*> pointers;

public:
    PointerArray() = default;

    void add(T* ptr) {
        pointers.push_back(ptr);
    }

    T* operator[](size_t index) {
        if (index >= pointers.size()) {
            throw out_of_range("Index out of range.");
        }
        return pointers[index];
    }

    size_t size() const {
        return pointers.size();
    }

    ~PointerArray() {
        for (T* ptr : pointers) {
            delete ptr; // Освобождаем память
        }
    }
};
// Пример класса с использованием
class PrimitiveClass {
public:
    void display() {
        cout << "Showing SampleClass object." << endl;
    }
};
int main() {
    try {
        PointerArray<PrimitiveClass> arr;

        // Динамическое создание объектов
        for (int i = 0; i < 5; i++) {
            arr.add(new PrimitiveClass());
        }

        // Использование перегрузки оператора []
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i]->display();
        }
        arr[-1]->display();// Попытка доступа к несуществующему индексу (вызываем исключение)  

    }
    catch (const runtime_error& e) {//обработка исключения
        cerr << e.what() << endl;
    }
    catch (const exception& e) {//используется класс exception, т.к. в классе BaseError по заданию не определяем нужную ошибку
        cerr << "An error occurred: " << e.what() << endl;
    }
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks(); //проверка утечки памяти
    return 0;
}
