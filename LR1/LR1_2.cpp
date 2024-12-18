#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Book {
public:
    enum Type {
        FICTION,
        TECHNICAL
    };

private:
    string author;
    string title;
    Type type;

public:
    Book(string author, string title, Type type)
        : author(author), title(title), type(type) {
        if (author.empty() or title.empty()) {
            throw invalid_argument("Author and title cannot be empty");
        }
    }

    Type getType() const {
        return type;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void countBooks() const {
        int fictionCount = 0;
        int technicalCount = 0;

        for (Book book : books) {
            switch (book.getType()) {
            case Book::FICTION:
                fictionCount++;
                break;
            case Book::TECHNICAL:
                technicalCount++;
                break;
            }
        }

        cout << "FICTION: " << fictionCount << endl;
        cout << "TECHNICAL: " << technicalCount << endl;
    }

    void countBooksWithoutSwitch() const {
        int counts[2] = { 0, 0 }; // [FICTION, TECHNICAL]

        for (Book book : books) {
            counts[book.getType()]++;
        }

        cout << "FICTION: " << counts[Book::FICTION] << endl;
        cout << "TECHNICAL: " << counts[Book::TECHNICAL] << endl;
    }
};

int main() {
    Library library;

    library.addBook(Book("Author 1", "Book1", Book::FICTION));
    library.addBook(Book("Author 2", "Book2", Book::FICTION));
    library.addBook(Book("Author 3", "Book3", Book::TECHNICAL));
    library.addBook(Book("Author 4", "Book4", Book::TECHNICAL));
    library.addBook(Book("Author 5", "Book5", Book::TECHNICAL));
    cout << "using switch:" << endl;
    library.countBooks();

    cout << "no using switch:" << endl;
    library.countBooksWithoutSwitch();

    return 0;
}
