#include "Product.h"
#include <iostream>
#include <string>

Product::Product(std::string Pname,std::string Pid,std::string C,int S,int R,double Pr){
    ProductName=Pname;
    ProductId=Pid;
    Category = C;
    if(S<0){
        StockQuantity = 0;
    }else{
        StockQuantity = S;
    }
    if(R<0){
        ReorderLevel = int(StockQuantity/2.0);
    }else{
        ReorderLevel = R;
    }
    if(Pr<0){
        ProductPrice =0;
    }else{
        ProductPrice=Pr;
    }
}

int Product::GetStock(){
    return StockQuantity;
}
int Product::GetReorderLevel(){
    return ReorderLevel;
}
double Product::GetPrice(){
    return ProductPrice;
}
std::string Product::GetProductName(){
    return ProductName;
}
std::string Product::GetProductId(){
    return ProductId;
}
std::string Product::GetProductCategory(){
    return Category;
}
bool Product::AddToStock(int Quantity){
    if(Quantity<=0){
        return false;
    }else{
        StockQuantity+=Quantity;
        return true;
    }
}
bool Product::RemoveFromStock(int Quantity){
    if(Quantity>StockQuantity){
        return false;
    }else{
        StockQuantity-=Quantity;
        return true;
    }
}
bool Product::SetStockLevel(int Quantity){
    if(Quantity<0){
        return false;
    }else{
        StockQuantity = Quantity;
        return true;
    }
}
bool Product::SetReorderLevel(int R){
    if(R<0){
        return false;
    }else{
        ReorderLevel = R;
        return true;
    }
}
bool Product::SetProductPrice(double price){
    if(price<0){
        return false;
    }else{
        ProductPrice=price;
        return true;
    }
}
void Product::ChangeProductName(std::string name){
    ProductName=name;
}
void Product::ChangeProductId(std::string id){
    ProductId = id;
}
void Product::ChangeProductCategory(std::string c){
    Category = c; 
}
