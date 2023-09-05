#include <iostream>
#include <string>
#include <memory>

using namespace std;

//抽象构建类Transform（变形金刚）
class Transform
{
public:
    virtual void move() = 0;
};

//具体构建类car
class Car:public Transform
{
public:
    Car(){cout<<"变形金刚是一辆车！"<<endl;}
    void move(){
        cout<<"在陆地上移动！"<<endl;
    }
};

//抽象装饰类
class Changer:public Transform
{
public:
    Changer(shared_ptr<Transform> transform){
        this->transform = transform;
    }
    void move(){
        transform->move();
    }
private:
    shared_ptr<Transform> transform;
};

//具体装饰类
class Robot:public Changer
{
public:
    Robot(shared_ptr<Transform> transform):Changer(transform){
        cout << "变成机器人！" << endl;
    }
    void say(){
        cout << "说话！" << endl;
    }
};

//具体装饰类
class Airplane:public Changer
{
public:
    Airplane(shared_ptr<Transform> transform):Changer(transform){
        cout << "变成飞机！" << endl;
    }
    void say(){
        cout << "在天空飞翔！" << endl;
    }
private:
    shared_ptr<Transform> transform;
};

int main(){
    shared_ptr<Transform> camaro=make_shared<Car>();
    camaro->move();
    cout << "---------------" << endl;

    shared_ptr<Robot> toRobot=make_shared<Robot>(camaro);
    toRobot->move();
    toRobot->say();
    return 0;
}


