#include "CentralSystem.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void CentralSystem::DisplayAllProduct(){
    for(auto it=List.begin();it<List.end();it++){
        std::cout << "||=====||\n";
        std::cout << "PRODUCT_NAME===>" << (*it).GetProductName() << '\n';
        std::cout << "PRODUCT_ID===>" << (*it).GetProductId() << '\n'; 
        std::cout << "PRODUCT_CATEGORY===>" << (*it).GetProductCategory() << '\n';
        std::cout << "PRODUCT_PRICE===>" << (*it).GetPrice() << '\n';
        std::cout << "STOCK===>" << (*it).GetStock() << " UNITS"<<'\n';
        std::cout << "REORDER_LEVEL===>" << (*it).GetReorderLevel() << " UNITS" << '\n';
        std::cout << "||=====||\n";
    }
}

void CentralSystem::AddToinventory(Product P){
    List.push_back(P);
}
bool CentralSystem::DeleteProduct(const std::string &id){
    bool flag = false;
    for(auto it=List.begin();it!=List.end();){
        if((*it).GetProductId() == id){
            List.erase(it);
            return true;
        }else{
            it++;
        }
    }
    return false;
}
Product* CentralSystem::SearchSpecificProduct(const std::string &id){
    Product* FoundProduct;
    for(auto it=List.begin();it!=List.end();it++){
        if((*it).GetProductId() == id){
            return &(*it);
        }
    }
    return nullptr;
}
bool CentralSystem::DetectLowStock(const std::string &id){
    bool Flag;
    Product* Found = SearchSpecificProduct(id);
    if(Found == nullptr){
        Flag = false;
    }else{
        if((*Found).GetStock()<=(*Found).GetReorderLevel()){
            Flag = true;
        }else{
            Flag = false;
        }
    }
    return Flag;
}
double CentralSystem::TotalInventoryValue(){
    double Total=0.00;

    for(auto it=List.begin();it!=List.end();it++){
        Total += (*it).GetStock() * (*it).GetPrice();
    }

    return Total;
}
void CentralSystem::SaveToFile(const std::string &path){
    std::ofstream file(path,std::ios::app);
    if(!file.is_open()){
        std::cout << "ERROR!!! INVALID FILE PATH!!!\n";
        return;
    }else{
        for(auto it=List.begin();it!=List.end();it++){
            file << (*it).GetProductName()<<';';
            file << (*it).GetProductId()<<';';
            file << (*it).GetProductCategory()<<';';
            file << (*it).GetStock()<<';';
            file << (*it).GetPrice()<<';';
            file << (*it).GetReorderLevel()<<';';
            file << "\n";
        }
    }
    file.close();
}