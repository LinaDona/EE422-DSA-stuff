#include <iostream>
#include <ctime>
using namespace std;

long fib(int nb){
    if(nb < 0 ){
        cout << "You have to enter a non negative number.";
    }
    if(nb == 0){
        return 0;
    }
    if(nb == 1){
        return 1;
    }
    else {
        return (fib(nb - 1) + fib(nb - 2));
    }
}

int main(int argc, char const *argv[])
{
    int input;
    cout << "Enter your fibonacci input: ";
    cin >> input;
    clock_t start = clock(), finish;
    long output = fib(input);
    finish = clock();
    cout << "Your fibonacci number is: " << output << "\n";
    long double time = ((finish - start)/CLOCKS_PER_SEC)*1000;
    cout << "Time elapsed is: " << time << " millisecond";
    return 0;
}