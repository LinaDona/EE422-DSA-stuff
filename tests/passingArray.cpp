#include <iostream>


using namespace std;

int sum(const int arr[], const int length){
    int sum = 0;
    for(int i=0; i<length; sum += arr[i++]);
    return sum;
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 5, 6};
    int summation = sum(arr, 5);
    cout << "Sum is: " << summation << endl;
    return 0;
}
