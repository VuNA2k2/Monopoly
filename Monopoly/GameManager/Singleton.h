#pragma once
template <class T>
class Singleton {
private:
    static T* instance;
public:
    static T* getInstance() {
        if (instance == nullptr) {
            instance = new T();
        }
        return instance;
    }
    static void removeInstance() {
        if (instance) {
            delete instance;
        }
    }
protected:
    Singleton() {}
    virtual ~Singleton() {
        delete instance;
    }
};

template <class T> T* Singleton<T>::instance = nullptr;
