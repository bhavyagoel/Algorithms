/**
 * ? Given an array A (index starts at 1) consisting of N 
 * ? integers: A1, A2, ..., AN and an integer B. The integer 
 * ? B denotes that from any place (suppose the index is i) 
 * ? in the array A, you can jump to any one of the place 
 * ? in the array A indexed i+1, i+2, …, i+B if this place 
 * ? can be jumped to. Also, if you step on the index i, 
 * ? you have to pay Ai coins. If Ai is -1, it means you 
 * ? can’t jump to the place indexed i in the array.
 * 
 * ? Now, you start from the place indexed 1 in the array 
 * ? A, and your aim is to reach the place indexed N using 
 * ? the minimum coins. You need to return the path of indexes 
 * ? (starting from 1 to N) in the array you should take 
 * ? to get to the place indexed N using minimum coins.
 * 
 * ? If there are multiple paths with the same cost, return 
 * ? the lexicographically smallest such path.
 * 
 * ? If it's not possible to reach the place indexed N 
 * ? then you need to return an empty array.
**/

#include "iostream"

int *coinPath(int arr[], int n) {
    
}