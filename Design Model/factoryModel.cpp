#include<iostream>
#include<pthread.h>

using namespace std;

class Product
{
public:
    Product(){};
    virtual void show() = 0;
};

class productA:public Product
{
public:
    productA(){}
    void show(){ cout << "product A is created!" << endl; };
    ~productA(){};
};

class productB:public Product
{
public:
    productB(){};
    void show(){ cout << "product B is created!" << endl; }
    ~productB(){};
};

class simpleFactory
{
public:
    simpleFactory(){};
    Product* product(const string str){
        if(str=="productA"){
            return new productA();
        }

        if(str=="productB"){
            return new productB();
        }
        return NULL;
    }
};

int main(){
    simpleFactory factory;
    Product* pro = factory.product("productA");
    pro->show();
    delete pro;

    pro = factory.product("productB");
    pro->show();
    delete pro;

    return 0;
}