#ifndef NUMBER_H
#define NUMBER_H

template<typename T>
class Number {
public:
    void setNum(T n);         
    T plus1() const;          
private:
    T num;                   
};

template<typename T>
void Number<T>::setNum(T n) {
    num = n;
}

template<typename T>
T Number<T>::plus1() const {
    return num + 1;
}

#endif