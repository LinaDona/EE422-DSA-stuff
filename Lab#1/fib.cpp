#include <iostream>
#include <ctime>
using namespace std;

long fibiter(int nb)
{
    if (nb == 0)
    {
        return 0;
    }
    if (nb == 1)
    {
        return 1;
    }
    else
    {
        long fib0 = 0, fib1 = 1, temp;
        for (int i = 2; i <= nb; i++)
        {
            temp = fib0 + fib1;
            fib0 = fib1;
            fib1 = temp;
        }
        return temp;
    }
}

long fibrec(int nb){
    if(nb == 0){
        return 0;
    }
    if(nb == 1){
        return 1;
    }
    else {
        return (fibrec(nb - 1) + fibrec(nb - 2));
    }
}

int main(int argc, char const *argv[])
{
    int input;
    do {
    cout << "Enter a positive input: ";
    cin >> input;
    } while(input < 0);
    clock_t start1 = clock(), start2, finish1, finish2;
    long output = fibrec(input);
    finish1 = clock();
    cout << "Your fibonacci number is: " << output << "\n";
    long double time1 = ((finish1 - start1)/CLOCKS_PER_SEC)*1000;
    cout << "Time elapsed with recursion is: " << time1 << " milliseconds\n";
    start2 = clock();
    for(int i=0; i<1000; i++){
        output = fibiter(input);
    }
    finish2 = clock();
    cout << "Your fibonacci number is: " << output << "\n";
    long double time2 = ((finish2 - start2)/CLOCKS_PER_SEC)*1000;
    cout << "Time elapsed with iteration is: " << time2 << " milliseconds\n";
    // cout << start1 << " " << start2 << " " << finish1 << " " << finish2 << " " << endl ;
    return 0;
}
