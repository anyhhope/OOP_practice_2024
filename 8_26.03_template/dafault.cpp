#include<iostream> 
using namespace std; 

template<typename T, typename U = char> 
class A { 
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