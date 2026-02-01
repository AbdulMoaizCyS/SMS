#ifndef CENTRAL_SYSTEM_H
#define CENTRAL_SYSTEM_H

#include "Product.h"
#include <string>
#include <vector>

class CentralSystem{
    private:
        std::vector<Product> List;
    public:
        void DisplayAllProduct();
        void AddToinventory(Product P);
        bool DeleteProduct(const std::string &id);
        Product* SearchSpecificProduct(const std::string &id); 
        bool DetectLowStock(const std::string &id);
        double TotalInventoryValue();
        void SaveToFile(const std::string &path);
};


#endif //CENTRAL_SYSTEM_H