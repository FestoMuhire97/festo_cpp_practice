/* Answer 1:
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    double price;

public:
    // Default constructor
    Book() : title(""), author(""), isbn(""), price(0.0) {}

    // Parameterized constructor
    Book(std::string t, std::string a, std::string i, double p) 
        : title(t), author(a), isbn(i), price(p) {}

    // Destructor
    ~Book() {
        std::cout << "Book object destroyed" << std::endl;
    }

    // Copy constructor
    Book(const Book &other) 
        : title(other.title), author(other.author), isbn(other.isbn), price(other.price) {}

    // Assignment operator
    Book& operator=(const Book &other) {
        if (this == &other) return *this;
        title = other.title;
        author = other.author;
        isbn = other.isbn;
        price = other.price;
        return *this;
    }

    // Equality operator
    bool operator==(const Book &other) const {
        return (isbn == other.isbn);
    }

    // Method to display book details
    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author 
                  << "\nISBN: " << isbn << "\nPrice: " << price << std::endl;
    }
};
*/

/* Answer 2: 
#include <vector>

// Function to add a book to the collection
void addBook(std::vector<Book>& books, const Book& book) {
    books.push_back(book);
}

// Function to remove a book by ISBN
void removeBook(std::vector<Book>& books, const std::string& isbn) {
    books.erase(std::remove_if(books.begin(), books.end(), 
                [&isbn](const Book& book) { return book.getISBN() == isbn; }), books.end());
}

// Function to display all books
void displayBooks(const std::vector<Book>& books) {
    for (const auto& book : books) {
        book.display();
        std::cout << std::endl;
    }
}
*/

/* Answer 3: 
#include <fstream>
#include <sstream>

// Function to read books from a file
void readBooksFromFile(const std::string& filename, std::vector<Book>& books) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string title, author, isbn;
        double price;
        if (!(iss >> title >> author >> isbn >> price)) { break; }
        books.emplace_back(title, author, isbn, price);
    }
}

// Function to write books to a file
void writeBooksToFile(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream outfile(filename);

    for (const auto& book : books) {
        outfile << book.getTitle() << " " << book.getAuthor() << " " << book.getISBN() << " " << book.getPrice() << std::endl;
    }
}

Main function:

int main() {
    std::vector<Book> books;
    
    // Read books from file
    readBooksFromFile("books.txt", books);
    
    // Display all books
    displayBooks(books);
    
    // Add a new book
    Book newBook("New Title", "New Author", "1234567890", 29.99);
    addBook(books, newBook);
    
    // Remove a book by ISBN
    removeBook(books, "1234567890");

    // Write books to file
    writeBooksToFile("output_books.txt", books);

    return 0;
}

*/