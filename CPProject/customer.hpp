#ifndef CUTOMER_HPP_
#define CUTOMER_HPP_


#include <iostream>


class Customer{
      public:
            Customer(std::string name, std::string address, std::string phone, std::string email);
            
            void setName(std::string name);
            void setAddress(std::string address);
            void setPhone(std::string phone);
            void setEmail(std::string email);
            void setWarehouseDistance(double warehouseDistance);

            int getId() const;
            std::string getName() const;
            std::string getAddress() const;
            std::string getPhone() const;
            std::string getEmail() const;
            double getWarehouseDistance() const;

            friend std::ostream& operator<< (std::ostream& os, const Customer& customer);
      
            ~Customer();
      
      private:
            static int idCustomer_;//todo incrementar
            std::string name_;
            std::string address_;
            std::string phone_;
            std::string email_;
            double warehouseDistance_;
};

#endif