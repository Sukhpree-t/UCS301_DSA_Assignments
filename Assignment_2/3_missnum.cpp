#include<iostream>
using namespace std;

int main() {
    int nums[] = {0,1, 2, 3 , 5};           //number from 0 to n
    int n = sizeof(nums) / sizeof(nums[0]);
    int allXOR = 0;
    for(int i=0; i <=n; i++) {
         allXOR ^=i;
    }

    for(int i=0; i<n; i++) {
        allXOR ^=nums[i];
    }
    
    cout<<"Missing number : "<< allXOR <<endl;
}



// #include<iostream>
// using namespace std;

// int main() {
//     int nums[] = {1, 2, 3 , 5};
//     int n = sizeof(nums)/sizeof(int);
//     int totalSum = n*(n+1)/2;
//     int sum=0;

//     for(int i=0;i<n;i++) {
//         sum+=i;
//         }
    
//     cout<<"Missing number : "<< totalSum-sum <<endl;
// }