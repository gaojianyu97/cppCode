#include <iostream>
#include <algorithm>

using namespace std;

class SingleInstance{
public:
    static SingleInstance* getInstance(){
        static SingleInstance ins;
        return &ins;
    }
    ~SingleInstance(){};

private:
    SingleInstance(){ cout << "SingleInstance() ehan" << endl; }
    SingleInstance(const SingleInstance& other){};
    SingleInstance& operator=(const SingleInstance& other){return *this;}
};

int main(){
    SingleInstance* ins = SingleInstance::getInstance();
    return 0;
}