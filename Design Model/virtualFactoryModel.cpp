#include<iostream>
#include<pthread.h>

using namespace std;

class Product
{
public:
    Product(){};
    virtual void show()=0;
};

class Factory
{
public:
    virtual Product* CreateProduct()=0;
};

class ProductA:public Product
{
public:
    ProductA(){};
    void show(){cout<<"product A is created"<<endl;}
};

class ProductB:public Product
{
public:
    ProductB(){};
    void show(){cout<<"product B is created"<<endl;}
};

class FactoryA:public Factory
{
public:
    Product* CreateProduct(){
        ProductA* product_ = nullptr;
        product_ = new ProductA();
        return product_;
    }
};

class FactoryB:public Factory
{
public:
    Product* CreateProduct(){
        ProductB* product_ = nullptr;
        product_ = new ProductB();
        return product_;
    }
};

int main(){
    Product* product_ = nullptr;
    auto MyFactoryA = new FactoryA();
    product_ = MyFactoryA->CreateProduct();
    product_->show();
    delete product_;

    auto MyFactoryB = new FactoryB();
    product_ = MyFactoryB->CreateProduct();
    product_->show();
    delete product_;

    return 0;
}