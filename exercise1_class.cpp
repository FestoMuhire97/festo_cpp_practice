#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class Book
{
    private:
        std::string title_;
        std::string author_;
        int isbn_num_;
        double price_;

    public:
    Book()
    : title_(""), author_(""), isbn_num_(0), price_(0.0)
    {}
    
    Book(std::string title, std::string author, int isbn_num, double price)
        : title_(title), author_(author), isbn_num_(isbn_num), price_(price)
    {}

    Book(const Book &other)
    : title_(other.title_), author_(other.author_), isbn_num_(other.isbn_num_), price_(other.price_)
    {}

    Book& operator=(const Book &other)
    {
        if(this != &other)
        {
            title_ = other.title_;
            author_ = other.author_;
            isbn_num_ = other.isbn_num_;
            price_ = other.price_;
        }
        return *this;
    }

    void display () const
    {
        std::cout << "The book details are: " << std::endl;
        std::cout << 
        "The title: " << title_ << 
        "The author: " << author_ << 
        "The isbn number is: " << isbn_num_ <<
        "The price: " << price_ << 
        std::endl;
    }

    bool operator==(const Book &other) const
    {
        if (this->title_ == other.title_)
        {
            std::cout << this->title_ << " and " << other.title_ << "are the same books" << std::endl;
            return true;
        }
        else
        {
            std::cout << "These two books are different" << std::endl;
            return false;
        }
    }

    void add_book(std::vector<Book> &books, const Book& book1)
    {
        return books.push_back(book1);
    }

    /*
    std::vector<Book> remove_book(std::vector<Book> &books, const std::string &isbn)
    {

        books.erase(std::remove_if(books.begin(), books.end(), [&isbn](const Book& book) {
            return std::to_string(book.isbn_num_) == isbn;
        }), books.end());
        return books;
    }
    */

    void display_books (std::vector<Book> &books)
    {
        for (const auto & book: books)
        {
        book.display();
        }
    }

    void read_from_file(std::string file)
    {
        std::string line;
        std::ifstream infile(file);
        while(std::getline(infile, line).good())
        {
            std::cout << line << std::endl;
        }

    }

    void write_to_file(std::vector<Book> &books, std::string filename)
    {
        std::ofstream outfile(filename, std::ofstream::trunc);
        
        for (const auto &book: books)
        {
            outfile << book.title_ << " " << book.author_ << " " << book.isbn_num_ << " " << book.price_ << std::endl;
        }
        outfile.close();
    }

    ~Book()
    {
        //std::cout << "Book object is destroyed" << std::endl;
    }

};


int main (void)
{
    Book book1("The art of Imagination", "Paul Hunter", 1234, 23.89);
    Book book2("The art of football", "Festo Muhire", 1235, 67.89);
    //book1.display();
    //book2.display();

    //Book book3("The art of volleyball", "Felix Muhire", 1237, 69.89);
    //book3 = book1;
    //book3.display();
    
    std::vector<Book> books;
    book1.add_book(books, book1);
    book2.add_book(books, book2);

    Book book_read;
    book_read.read_from_file("books.txt");

    Book book_write;
    book_write.write_to_file(books, "festo.txt");

    //book1.display_books(books);

    return 0;
}