#include "supplier.hpp"
#include <list>
#include <iostream>

class supplierRepository
{
      public:
            supplierRepository();
            static int nextIdSupplier();
            static void addSupplier(Supplier Supplier);
            static void removeSupplier(Supplier Supplier);
            static void updateSupplier(int id, std::string what, std::string change);
            static void updateSupplier(int id, Product& p);
            static Supplier getSupplierbyId(int idSupplier) ;
            friend std::ostream& operator<< (std::ostream& os, const supplierRepository& supplierRepository);
            ~supplierRepository();
      
      private:
            static std::list<Supplier> repository;
            static int nextId;
};

supplierRepository::supplierRepository(){
      repository = std::list<Supplier>();
      nextId = 0;
}

int supplierRepository::nextIdSupplier()
{
      return nextId++;
}

void supplierRepository::addSupplier(Supplier Supplier)
{
      repository.push_back(Supplier);
}

void supplierRepository::removeSupplier(Supplier Supplier)
{
      repository.remove(Supplier);
}

void supplierRepository::updateSupplier(int id, std::string what, std::string change)
{
     for(std::list<Supplier>::iterator it = repository.begin(); it != repository.end(); ++it)
     {
           if (it->getId() == id)
           {
                  if (what == "name")
                  {
                        it->setName(change);
                  }
                  else if (what == "address")
                  {
                        it->setAddress(change);
                  }
                  else if (what == "phone")
                  {
                        it->setPhone(change);
                  }
                  else if (what == "email")
                  {
                        it->setEmail(change);
                  }
           }
     }
}

void supplierRepository::updateSupplier(int id, Product& p)
{
      for(std::list<Supplier>::iterator it = repository.begin(); it != repository.end(); ++it)
      {
             if (it->getId() == id)
             {
                     it->addProduct(p);
             }
      }
}

Supplier supplierRepository::getSupplierbyId(int idSupplier) 
{
      for (std::list<Supplier>::const_iterator it = repository.begin(); it != repository.end(); ++it)
      {
            if (it->getId() == idSupplier)
            {
                  return *it;
            }
      }
      return Supplier("","","","");
}

std::ostream& operator<< (std::ostream& os, const supplierRepository& SupplierRepository)
{
      for (std::list<Supplier>::const_iterator it = SupplierRepository.repository.begin(); it != SupplierRepository.repository.end(); ++it)
      {
            os << *it << std::endl;
      }
      return os;
}

supplierRepository::~supplierRepository()
{
      
}