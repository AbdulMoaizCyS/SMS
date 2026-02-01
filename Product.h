#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product{
    private:
        std::string ProductName;
        std::string ProductId;
        std::string Category;
        int StockQuantity;
        int ReorderLevel;
        double ProductPrice;
    public:
        Product(std::string Pname,std::string Pid,std::string C,int S,int R,double Pr);
        int GetStock();
        int GetReorderLevel();
        double GetPrice();
        std::string GetProductName();
        std::string GetProductId();
        std::string GetProductCategory();

        bool AddToStock(int Quantity);
        bool RemoveFromStock(int Quantity);
        bool SetStockLevel(int Quantity);
        bool SetReorderLevel(int R);
        bool SetProductPrice(double price);
        void ChangeProductName(std::string name);
        void ChangeProductId(std::string id);
        void ChangeProductCategory(std::string c);
};

#endif //PRODUCT_H