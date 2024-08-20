#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    string genre;
    int quantity;

    void displayBookDetails() const {
        cout << "Book ID: " << bookId << "\nTitle: " << title << "\nAuthor: " << author << "\nGenre: " << genre << "\nQuantity: " << quantity << endl;
    }
};

class BookshopManagementSystem {
private:
    vector<Book> books;
    const string filename = "book_inventory.dat";

public:
    void addBook() {
        Book newBook;
        cout << "Enter Book ID: ";
        cin >> newBook.bookId;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, newBook.title);
        cout << "Enter Author: ";
        getline(cin, newBook.author);
        cout << "Enter Genre: ";
        getline(cin, newBook.genre);
        cout << "Enter Quantity: ";
        cin >> newBook.quantity;

        books.push_back(newBook);
        saveDataToFile();
        cout << "Book added successfully!" << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the inventory." << endl;
            return;
        }

        cout << "Book Inventory:\n";
        for (const Book& book : books) {
            book.displayBookDetails();
            cout << "========================\n";
        }
    }

    void modifyBook(int bookId) {
        for (Book& book : books) {
            if (book.bookId == bookId) {
                cout << "Modify Book ID " << bookId << ":\n";
                cout << "Enter New Title: ";
                getline(cin, book.title);
                cout << "Enter New Author: ";
                getline(cin, book.author);
                cout << "Enter New Genre: ";
                getline(cin, book.genre);
                cout << "Enter New Quantity: ";
                cin >> book.quantity;

                saveDataToFile();
                cout << "Book modified successfully!" << endl;
                return;
            }
        }

        cout << "Book with ID " << bookId << " not found." << endl;
    }
    void deleteBook(int bookId) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->bookId == bookId) {
                books.erase(it);
                saveDataToFile();
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }

        cout << "Book with ID " << bookId << " not found." << endl;
    }

    void searchBook() const {
        string searchTerm;
        cout << "Enter the title or author to search: ";
        cin.ignore();
        getline(cin, searchTerm);

        bool found = false;
        for (const Book& book : books) {
            if (book.title.find(searchTerm) != string::npos || book.author.find(searchTerm) != string::npos) {
                book.displayBookDetails();
                cout << "------------------------\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No books found matching the search term." << endl;
        }
    }


    void loadDataFromFile() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "No existing data file found. Starting with an empty inventory." << endl;
            return;
        }

        while (!inFile.eof()) {
            Book loadedBook;
            inFile.read(reinterpret_cast<char*>(&loadedBook), sizeof(Book));
            if (inFile.eof()) {
                break;
            }
            books.push_back(loadedBook);
        }

        inFile.close();
    }

    void saveDataToFile() const {
        ofstream outFile(filename, ios::binary);
        for (const Book& book : books) {
            outFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
        }
        outFile.close();
    }
    ~BookshopManagementSystem() {
        saveDataToFile();
    }
};

int main() {
    BookshopManagementSystem bookshop;
    bookshop.loadDataFromFile();

    char choice;
    do {
        cout << "\n=============================\n";
        cout << "  Bookshop Management System\n";
        cout << "=============================\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Modify Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Search Book\n";
        cout << "6. Exit\n";
        cout << "=============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            bookshop.addBook();
            break;
        case '2':
            bookshop.displayAllBooks();
            break;
        case '3': {
            int bookId;
            cout << "Enter Book ID to modify: ";
            cin >> bookId;
            cin.ignore();  
            bookshop.modifyBook(bookId);
            break;
        }
        case '4': {
            int bookId;
            cout << "Enter Book ID to delete: ";
            cin >> bookId;
            bookshop.deleteBook(bookId);
            break;
        }
        case '5':
            bookshop.searchBook();
            break;
        case '6':
            cout << "Exiting the Bookshop Management System. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
    }
    while (choice != '6');
    return 0;
}
