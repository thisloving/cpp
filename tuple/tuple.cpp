#include <iostream>                                                              
#include <tuple>                                                                 
#include <complex>                                                               
#include <string>                                                                

using namespace std;                                                             

template<typename T>                                                             
void print_tuple(T t) {                                                          
	cout << get<0>(t) << " ";                                                    
	cout << get<1>(t) << " ";                                                    
	cout << get<2>(t) << " ";                                                    
	cout << endl;                                                                
}                                                                                

int main()                                                                       
{                                                                                
	tuple<string, int, int, complex<double>> t;                                  

	tuple<int, float, string> t1(41, 6.3, "nico");                               
	print_tuple(t1);                                                             

	auto t2 = make_tuple(22, 44, "nico");                                        
	print_tuple(t2);                                                             

	get<1>(t1) = get<1>(t2);                                                     
	print_tuple(t1);                                                             

	if (t1 > t2) {                                                                                                                                                  
		t1 = t2;                                                                 
		print_tuple(t1);                                                         
	}                                                                            
} 
// g++ -std=c++11 -g tuple.cpp -o tuple
