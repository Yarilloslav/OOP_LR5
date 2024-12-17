#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib> 
#include <ctime> 
using namespace std;
class Base {
public:
    virtual void show() const {
        cout << "Base class" << endl;
    }

    virtual ~Base() = default; // Виртуальный деструктор
};

class Derived : public Base {
public:
    void show() const override {
        cout << "Derived class" << endl;
    }
    virtual ~Derived() = default;
};

void add(vector<unique_ptr<Base>>& storage, unique_ptr<Base> obj) {
    storage.push_back(move(obj));// Используется move как альтернатива копированию, чтобы не пришлось использовать нестандартную оболочку для unique_ptr
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
    vector<unique_ptr<Base>> storage;
    for (int i = 0; i < rand() % 10 + 1; i++) {
        if (rand() % 2 == 0) {
            add(storage, make_unique<Base>());
        }
        else {
            add(storage, make_unique<Derived>());
        }
    }
    cout << "Objects in storage:" << endl;
    for (const auto& obj : storage) {
        obj->show();
    }
    // Ресурсы автоматически освобождаются благодаря unique_ptr
    return 0;
}
