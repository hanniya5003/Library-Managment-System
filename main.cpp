#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    bool borrowed;
};

const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, books[bookCount].title);

    books[bookCount].borrowed = false;
    bookCount++;

    cout << "Book added successfully!\n";
}

void listBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- Book List ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". " << books[i].title;

        if (books[i].borrowed)
            cout << " [Borrowed]";
        else
            cout << " [Available]";

        cout << endl;
    }
}

void borrowBook() {
    int num;

    listBooks();

    cout << "\nEnter book number to borrow: ";
    cin >> num;

    if (num < 1 || num > bookCount) {
        cout << "Invalid book number!\n";
        return;
    }

    if (books[num - 1].borrowed) {
        cout << "Book is already borrowed.\n";
    } else {
        books[num - 1].borrowed = true;
        cout << "Book borrowed successfully!\n";
    }
}

void returnBook() {
    int num;

    listBooks();

    cout << "\nEnter book number to return: ";
    cin >> num;

    if (num < 1 || num > bookCount) {
        cout << "Invalid book number!\n";
        return;
    }

    if (!books[num - 1].borrowed) {
        cout << "This book was not borrowed.\n";
    } else {
        books[num - 1].borrowed = false;
        cout << "Book returned successfully!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. List Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                borrowBook();
                break;

            case 3:
                returnBook();
                break;

            case 4:
                listBooks();
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}