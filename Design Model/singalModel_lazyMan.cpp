#include <iostream>
#include <pthread.h>
#include <algorithm>

using namespace std;

class SingleInstance {
public:
    static SingleInstance* GetInstance(){
        if(ins == nullptr){
            pthread_mutex_lock(&mutex);
            if(ins == nullptr){
                ins = new SingleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }
    ~SingleInstance(){};

    static pthread_mutex_t mutex;

private:
    SingleInstance() { cout << "SingleInstance() 懒汉" << endl; };
    SingleInstance(const SingleInstance &other){};
    SingleInstance& operator=(const SingleInstance &other){return *this;}

    static SingleInstance *ins;
};

SingleInstance* SingleInstance::ins = nullptr;
pthread_mutex_t SingleInstance::mutex;

int main(){
    SingleInstance *ins = SingleInstance::GetInstance();
    delete ins;
    return 0;
}