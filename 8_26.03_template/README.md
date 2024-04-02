# Обобщенное программирование, шаблоны (template)

Если возникает необходимость написать функцию, которая сможет работать с параметрами разного типа, то без шаблонов нужно будет для каждого типа написать свою такую функцию. 

```cpp
int func(int a, int b) {return 0;}
int func(double a, double b) {return 0;}
int func(float a, float b) {return 0;}
int func(char a, char b) {return 0;}
int func(std::string a, std::string b) {return 0;}
```
## Шаблоны функций

Однако **использование шаблонов (template)** позволяет не дублировать код, а прописать один раз некий шаблон функции, подстановка типа в который порождает свою версию функции для этого типа. Таким образом, исходный код содержит всего лишь одну функцию, а скомпилированный может содержать несколько копий этой функции, но для разных типов.

```cpp
template<typename T>
int func(T a, T b) {return 0;}
```

* template - ключевое слово, указывает на определение шаблона
* В <> скобках передается через запятую *список параметров шаблонов* - **не может быть пустым**     
Например, template<typename T, typename U>

## Использование шаблонной функции происходит посредством подстановки необходимого типа в <> скобки:

```cpp
double a = 1.2;
double b = 3.1;
int result = func<double>(a, b);
```

## Параметры шаблона: параметры типа и параметры значения

Итак, в угловые скобки необходимо передать параметры: <параметры шаблона>. 

* Существуют параметры типа template<typename T>, который можно использовать как и встроенный тип: как тип возвращаемого значения, как параметр функцииб объявление переменных

```cpp
template<typename T>
T func(T a, T b){
    T m(0);
    return a + m;
}
```

* Существуют параметры значения template<int M> - константное значение, к примеру можно задавать размер контейнера

Ограничения на параметр значения включают в себя:

1. Тип данных: Параметр значения может быть целочисленного типа, указателем на объект или функцию, ссылкой на объект или функцию, ссылкой на функцию-член, перечислением или объектом в стиле C++. Он не может быть вещественного типа, типом класса, массивом или указателем на член класса.

2. Константность: Параметр значения должен быть известным на этапе компиляции и должен быть константой.

```cpp
#include <iostream>
#include <string>

template <int N>
void printNTimes(const std::string& str) {
    std::cout << N << " times: " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << str << std::endl;
    }
}

template<typename T, T value>
T addToValue(T x) {
    return x + value;
}

int main() {
    printNTimes<5>("Hello");
    printNTimes<3>("World"); 

    int result1 = addToValue<int, 5>(10); 
    double result2 = addToValue<double, 3.14>(2.0); //ошибка

    std::cout << "Result: " << result1 << std::endl; 
}
```

## Template Argument Deduction
Компилятор может определять параметры шаблона на основе параметров, переданных функции.

```cpp
template<typename T>
T multiply (T num1,T num2) { return num1*num2; }

int main(){
    multiply<int> (25, 5);
    multiply (25, 5); //в этом случае так как 25 и 5 это int, компилятор опрделит T как int
    multiply<int> (25, 5.2); //ошибка, так как параметры разного типа и компилятор не определит что есть T
}
```

## Шаблоны классов

Аналогично шаблону функции параметр типа класса заменяется во время компиляции. Таким образом один и тот же класс можно использовать для нескольких типов.



## Специализация
Можно явно задать реализацию версии шаблонной функции/класса для определенного типа, в случае если в зависимости от типа появляются *особенности реализации*

```cpp
template<class T>
T Min(T a, T b){
  return a>=b?b:a;
}

template<>
string Min<string>(string a, string b){
    auto m = a.length();
    auto n = b.length();
    return    m>=n?b:a;
}

int main()
{
  int a=2;
  int b=4;
  string x = "Hello";
  string y = "Hi";
  std::cout<< Min(a,b) << std::endl;// 2
  std::cout<< Min(x,y) << std::endl; // Hi
}
```

## Дефолтный тип
Для параметров шаблона так же можно задать дефолтный тип, и при создании экземпляра класса уже не прописывать этот тип

```cpp
#include<iostream> 
using namespace std; 

template<class T, class U = char> class A 
{ 
public: 
	T x; 
	U y; 
}; 

int main() 
{ 
	A<char> a; //второе поле - char по умолчанию
	A<int, int> b; 
	cout<<sizeof(a)<<endl; //2
	cout<<sizeof(b)<<endl; //8
	return 0; 
} 
```

# Разделение на файлы объявления и определения

Обычно разделяем на .hpp и .cpp. Компилятор создает класс из шаблона только тогда, когда **он видит специализацию шаблона или создание экземпляра класса.**

```cpp
//file sample.hpp
template<class T>
struct Sample
{
	T Compute();
};

//file sample.cpp
#include "sample.h"

template<class T>
T Sample<T>::Compute(){

	return T();
}

//file main.cpp
#include "sample.h"
using namespace std;

int main()
{
	Sample<int> s;
	
	std::cout << s.Compute();
	return 0;
}
```

Когда компилируется sample.cpp, компилятор не в курсе что в main мы используем Sample<int>, следовательно эта версия класса не создается.

Что делать?
а) Оставляем и объявление, и определение в заголовочном файле (мы будем так делать)  
б) Указываем в файле реализации, на ту версию класса которую будем использовать template class Sample<int>;  (так не будеь делать)  


# Тестирование шаблонного класса doctest

```cpp
TEST_CASE_TEMPLATE("Constructor default", T, int, float, double, long long) {
	Sample<T> a;
    T value(0);
	for (int i = 0; i < 10; i++) {
        //как вариант протестировать контейнер 
        value += 1;
	}
}
```

# Домашнее задание

Написать шаблонный класс StackArrT 
* Объявление и определение в одном заголовочном файле
* Через new delete
* Написать тесты на doctest, подходящие для тестирования шаблонного класса
* Обратите внимание на необходимость реализации дополнительных методов

**Рекомендация** - сначала реализовать класс для определенного типа (например, int), протестировать, что логика верная. Потом переделать на шаблонный класс

```cpp
template <typename T>
class StackArrT {
public:
	StackArrT();
	~StackArrT();
	StackArrT(const StackArrT<T>& other);
	StackArrT(StackArrT<T>&& other);
	StackArrT(const std::initializer_list<T>& list);

	void push(const T& value);
	void pop();
	T& top() const;
	void swap(StackArrT<T>& other);
	void merge(StackArrT<T>& other);

	bool empty() const;
	std::ptrdiff_t size() const;

	bool operator==(const StackArrT<T>& rhs) const;
	bool operator!=(const StackArrT<T>& rhs) const;

	StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
	StackArrT<T>& operator=(StackArrT<T>&& other);
private:
    std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
    std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
    T* data_ = nullptr;   //!< элементы стека
};

```
