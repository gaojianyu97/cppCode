#include<iostream>
#include<string>
#include<list>

using namespace std;

class Subject;

//观察者 基类（内部实例化了被观察对象的sub）
class Observer
{
protected:
    string name;
    Subject *sub;
public:
    Observer(string name,Subject *sub){
        this->name = name;
        this->sub = sub;
    }

    virtual void update() = 0;
};

class StockObserver : public Observer
{
public:
    StockObserver(string name,Subject *sub):Observer(name,sub){}
    void update();
};

class NBAObserver : public Observer
{
public:
    NBAObserver(string name,Subject *sub):Observer(name,sub){}
    void update();
};

//被观察者，基类（内部存放了所有的观察者对象，一边状态发生改变时，给观察者发通知）

class Subject
{
protected:
    list<Observer *> observers;
public:
    string action;
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class Secretary : public Subject
{
    void attach(Observer *observer){
        observers.push_back(observer);
    }

    void detach(Observer *observer){
        list<Observer *>::iterator it = observers.begin();
        while(it != observers.end()){
            if(*it == observer){
                observers.erase(it);
                return;
            }
            it++;
        }
    }

    void notify(){
        list<Observer *>::iterator it = observers.begin();
        while(it != observers.end()){
            (*it)->update();
            it++;
        }
    }
};

void StockObserver::update(){
    cout << name << "收到消息：" << sub->action << endl;
    if(sub->action=="有内鬼！"){
        cout << "停止交易！" << endl;
    }
}

void NBAObserver::update(){
    cout << name << "收到消息：" << sub->action << endl;
    if(sub->action=="有内鬼！"){
        cout << "把货收好，赶紧撤！" << endl;
    }
}

int main(){
    Subject *Neigui=new Secretary();
    Observer *ha=new NBAObserver("ha",Neigui);
    Observer *hb=new NBAObserver("hb",Neigui);
    Observer *hc=new StockObserver("hc",Neigui);

    Neigui->attach(ha);
    Neigui->attach(hb);
    Neigui->attach(hc);

    Neigui->action = "无内鬼！";
    Neigui->notify();
    cout << endl;

    Neigui->action = "有内鬼！";
    Neigui->notify();
    cout << endl;
    return 0;
}