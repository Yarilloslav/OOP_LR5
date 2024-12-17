#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Detail {
protected:
    Detail() {}
public:
    virtual void show() const {
        cout << "This is a Detail." << endl;
    }
    static shared_ptr<Detail> create() {
        return shared_ptr<Detail>(new Detail());
    }
    virtual ~Detail() {}
};

class Assembly : public Detail {
protected:
    Assembly() {}
public:
    void show() const override {
        cout << "This is an Assembly." << endl;
    }

    static shared_ptr<Assembly> create() {
        return shared_ptr<Assembly>(new Assembly());
    }
};
// Шаблонная дружественная функция для добавления объектов
template<typename T>
void addToStorage(vector<shared_ptr<Detail>>& storage, shared_ptr<T> item) {
    storage.push_back(item);
}

int main() {
    vector<shared_ptr<Detail>> storage;
    addToStorage(storage, Detail::create());
    addToStorage(storage, Assembly::create());
    for (const auto& item : storage) {
        item->show();
    }

    return 0;
}
