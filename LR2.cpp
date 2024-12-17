#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter the name of publication: ";
        cin >> ws; // убирает пробелы перед вводом
        getline(cin, title);
        cout << "Enter the price of publication: ";
        cin >> price;
    }

    void putdata() {
        cout << "Name: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Sales {
protected:
    float salesData[3];

public:
    void getSalesData() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter the total price of books, that have been sold this month: " << i + 1 << ": ";
            cin >> salesData[i];
        }
    }

    void putSalesData() {
        for (int i = 0; i < 3; i++) {
            cout << "Month total " << i + 1 << ": " << salesData[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pages;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter amount of pages in book: ";
        cin >> pages;
        getSalesData();
    }
    void putdata() {
        Publication::putdata();
        cout << "Amount of pages: " << pages << endl;
        putSalesData();
    }
};

class Type : public Publication, public Sales {
private:
    float duration;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter recording time in minutes: ";
        cin >> duration;
        getSalesData();
    }

    void putdata() {
        Publication::putdata();
        cout << "Recording time in minutes: " << duration << endl;
        putSalesData();
    }
};

int main() {
    Book book;
    book.getdata();
    cout << "Information about the book";
    book.putdata();

    cout << endl;

    Type type;
    type.getdata();
    cout << "Information about the type";
    type.putdata();

    return 0;
}
