# Bookstore Management System

A simple and efficient Bookstore Management System built in C++ that allows users to manage their book inventory with ease. The system provides functionalities to add new books, display all books, modify existing book details, delete books, and search for books by title or author. The inventory data is stored in a binary file to ensure persistence across sessions.

## Features

- **Add Book**: Add new books to the inventory by providing details such as Book ID, Title, Author, Genre, and Quantity.
- **Display All Books**: View the complete list of books available in the inventory along with their details.
- **Modify Book**: Update the details of an existing book using its Book ID.
- **Delete Book**: Remove a book from the inventory by its Book ID.
- **Search Book**: Search for a book in the inventory by entering the title or author's name.

## How It Works

1. **Data Storage**: The inventory data is stored in a binary file named `book_inventory.dat`. This ensures that all books added to the system are saved and can be retrieved in future sessions.
2. **File Handling**: The system uses file handling to read and write book data, enabling the persistence of the inventory.
3. **User Interface**: The system operates through a console-based interface, where users can input their choices and interact with the system.

## Getting Started

### Prerequisites

To compile and run the program, you need:

- A C++ compiler (like g++ or MSVC)
- A command-line interface or terminal

### Compilation and Execution

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/Bookstore-Management-System.git
    cd Bookstore-Management-System
    ```

2. **Compile the program**:
    ```bash
    g++ -o bookstore BookstoreManagementSystem.cpp
    ```

3. **Run the program**:
    ```bash
    ./bookstore
    ```

### Usage

Upon running the program, you will be presented with a menu that allows you to choose from various options like adding a book, displaying all books, modifying a book, deleting a book, or searching for a book.

### Example Usage

- **Adding a Book**:
Enter Book ID: 101\
Enter Title: The C++ Programming Language\
Enter Author: Bjarne Stroustrup\
Enter Genre: Programming\
Enter Quantity: 5\
Book added successfully!


- **Searching for a Book**:
Enter the title or author to search: Bjarne\
Book ID: 101\
Title: The C++ Programming Language\
Author: Bjarne Stroustrup\
Genre: Programming\
Quantity: 5


## Contributing

Contributions are welcome! If you have any ideas or suggestions to improve the system, feel free to fork the repository and submit a pull request.

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/YourFeature`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgements

- Inspired by the need for simple inventory management solutions for small bookstores.

---

*Happy coding!*\
Brought by,\
Pratirath Gupta
