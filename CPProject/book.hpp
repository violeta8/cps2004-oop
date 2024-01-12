#ifndef BOOK_HPP_
#define BOOK_HPP_

#include "product.hpp"
#include "fecha.hpp"

class Book : public Product
{
      public:
            Book(int id, double price, std::string title);
            
            void setAuthor(std::string author);
            void setTitle(std::string title);
            void setGenre(std::string genre);
            void setPages(int pages);

            std::string getAuthor() const;
            std::string getTitle() const;
            std::string getGenre() const;
            int getPages() const;

            void updateProduct(std::string what, std::string change)override;

            virtual std::string display_product_info()=0;
            double calculate_discount(int quantity) const;

            ~Book();

      private:
            std::string title_;
};

class Novel : public Book
{
      public:
            Novel(int id, double price, std::string title, std::string genre);
            
            std::string getGenre() const;

            void updateProduct(std::string what, std::string change)override;

            std::string display_product_info();

            ~Novel();

      private:
            std::string genre_;
};

class Textbook : public Book
{
      public:
            Textbook(int id, double price, std::string title, std::string subject);
            
            std::string getSubject() const;
            
            void updateProduct(std::string what, std::string change)override;

            std::string display_product_info();

            ~Textbook();

      private:
            std::string subject_;
};


#endif // BOOK_HPP_