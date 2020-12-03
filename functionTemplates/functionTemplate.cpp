#include <iostream>

/*Finds the maximum of values of the same type*/
template<typename T>
T max(T a, T b){
    return a > b? a : b; // the  return type will be deducted T
}

/*Overloaded max*/
template<typename T1, typename T2>
T1 max(T1 a, T2 b){
    return a > b? a : b; // return type if the deducted T1
}

/* This will invalidate the second test
 * template<typename T1,typename T2>
auto max(T1 a, T2 b) -> decltype(a>b? a:b) {
    return a > b? a : b; // return type if the deducted
}*/

template<typename T1, typename T2, typename RT>
RT max(T1 a, T2 b){
    return a > b? a : b;
}

/*
 * This also invalidates the second test
template<typename T1, typename T2>
std::common_type<T1,T2> max(T1 a , T2 b){
    return a > b? a : b;
}*/
int main(){
    /* works well for non-overloaded max function*/
    std::cout  << ::max(7,8) << '\n'; // integers
    std::cout  << ::max(8.9 , 9.5) << '\n';// floats
    std::cout  << ::max('a','S') << '\n'; // characters
    /* Works for the  overloaded max*/
    std::cout  << ::max(7,'S') << '\n';
    std::cout  << ::max(8.9 , 9) << '\n';
    std::cout  << ::max('a',9.5) << '\n';

}