#include <iostream>

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
        "\nThe author: " << author_ << 
        "\nThe isbn number is: " << isbn_num_ <<
        "\nThe price: " << price_ << 
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

    ~Book()
    {
        std::cout << "Book object is destroyed" << std::endl;
    }

};


int main (void)
{
    Book book1("The art of Imagination", "Paul Hunter", 1234, 23.89);
    Book book2("The art of football", "Festo Muhire", 1235, 67.89);
    book1.display();
    book2.display();

    Book book3("The art of volleyball", "Felix Muhire", 1237, 69.89);
    book3 = book1;
    book3.display();
    
    return 0;
}