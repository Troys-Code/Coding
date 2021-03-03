#include <iostream>

// A function to check if an array of nums is palindrome 
void isPalindrome(int *nums, int length) 
{ 
    // Start from leftmost and rightmost corners of str 
    int low = 0; 
    int high = length - 1; 
  
    // Keep comparing characters while they are same 
    while (high > low) 
    { 
        low++;
        high--;
        if ( *(nums + low) != *(nums + high) ) 
        { 
            printf("%s is not palindrome\n", nums); 
            return; 
        } 
    } 
    printf("%s is palindrome\n", nums); 
}

int main() 
{
    //int nums[4] = {1,3,2,1};
    int nums[4] = {1,2,2,1};
    isPalindrome(nums,4); 
    return 0;
}
