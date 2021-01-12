#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;
//Problems based on recursion lecture 1, 1b, 2 and Time and Space complexity in coding ninjas

//Recursion lecture 1

//Finding 'x'raise to 'n'
int power(int x, int n) {
  
    if(n==0){
        return 1;
    }
    int ans = x * power(x, n-1);
    return ans;
}


//print number from 1 to n
void print(int n){
    if(n==1){
        cout << 1 << " ";
        return;
    }
    print(n-1);
    cout << n << " ";
    return;
}

//Count the number of digits in a given number
int count(int n){
    if(n/10==0){
        return 1;
    }
    
    int ans = 1+count(n/10);
    return ans;
}

//Print the nth fibonacci number.
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    
    int ans = fibonacci(n-1) + fibonacci(n-2);
    return ans;
}

//Check if array is sorted.
bool arraysorted(int * p, int size){
    if(size==1){
        return true;
    }
    if(p[0] > p[1]){
        return false;
    }
    return arraysorted(p+1, size-1);
}

//Return sum of an array
int sum(int input[], int n){
    if(n==1){
        return *input;
    }
    int ans = sum(input+1, n-1);
    return ans+(*input);
}

//Bool check number
bool checkNumber(int input[], int size, int x){
    if(size==0){
        return false;
    }
    
    bool result = checkNumber(input+1, size-1, x);
    
    if (result==true) {
        return result;
    }
    
    if(input[0]==x){
        return true;
    }
    else {
        return false;
    }
}

//Return the first index of a given number in the array
int firstIndex(int input[], int size, int x) {
    if(size==0){
        return -1;
    }
    
    if(input[0]==x){
        return 0;
    }
    
    int ans = firstIndex(input+1, size-1, x);
    
    if(ans==-1) return -1;
    else return ans+1;
}

//Return the last index of a given number in the array
int lastIndex(int input[], int size, int x) {
    if (size==0) {
        return -1;
    }
    
    if (input[size-1]==x) {
        return size-1;
    }
    
    int ans = lastIndex(input, size-1, x);
    
    return ans;
}

//Return all the indices of a given number in the array.
int allIndexes(int input[], int size, int x, int output[]) {
    if (size==0) {
        return 0;
    }
    
    int outputsize = allIndexes(input, size-1, x, output);
    
    if (input[size-1]==x) {
        output[outputsize]=size-1;
        return ++outputsize;
    }
    
    return outputsize;
}

//Calcuate the multiplication of two numbers using only subtraction or addition operators.
int multiplyNumbers(int m, int n) {
    if (m==0 || n==0) {
        return 0;
    }
    
    int ans = m + multiplyNumbers(m, n-1);
    return ans;
}

//Return the number of zeroes present in a given number.
int countZeros(int n){
    if (n/10==0) {
        return 0;
    }
    
    int ans = countZeros(n/10);
    
    if (n%10==0) {
        return ans+1;
    } else return ans;
}

//Calculate geometric sum for given n
double geometricSum(int k){
    if (k==0) {
        return 1;
    }
    
    double ans = (1/(pow(2, k))) + geometricSum(k-1);
    return ans;
}

//Check if a string is pallindrome or not
bool checkPalindrome(char input[]){
    if (strlen(input) <= 1) {
        return true;
    }
    
    if (input[0]!=input[strlen(input)-1]) {
        return false;
    }
    
    input[strlen(input)-1]='\0';
    int ans = checkPalindrome(input+1);
    
    return ans;
    
}

//Recursion lecture1b

//Replace any occurences of 'pi' in a string with '3.14'
void replacePi(char input[]){
    if (strlen(input) <= 1) {
        return;
    }
    
    if (input[0]=='p' && input[1]=='i') {
        for (int i=strlen(input) ; i>=2; i--){
            input[i+2]=input[i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);
}

//Remove all occurences of 'x'from the string.
void removeX(char input[]){
    if (strlen(input)==0) {
        return;
    }
    
    if (input[0]=='x') {
        for (int i=1; i<=strlen(input); i++) {
            input[i-1]=input[i];
        }
    }
    
    removeX(input+1);
}


int stringToNumber(char input[]){
    //stringToNumberHelper(input,1);
    if (strlen(input)==0) {
        return 0;
    }
    
    input[0] -= '0';
    int ans = input[0] * (pow(10, strlen(input)-1));
    return ans+stringToNumber(input+1);
}

//Adjacent identical characters in the string must be replace by a star in between eg. hello -> hel*lo
void pairStar(char input[]){
    if (strlen(input)==1) {
        return;
    }
    
    if (input[0]==input[1]) {
        for (int i=strlen(input); i >= 1; i--) {
            input[i+1]=input[i];
        }
        input[1]='*';
    }
    
    pairStar(input+1);
}

//Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    
    if (n==0) {
        return;
    }
    
    towerOfHanoi(n-1, source, destination, auxiliary);
    cout << source << " " <<destination << endl;
    towerOfHanoi(n-1, auxiliary, source, destination);
    
    
}

//Recursion 2

//Replcae the chracter c1 with c2 in a given string eg. input -> abacd a x .output-> xbxcd
void replaceCharacter(char input[], char c1, char c2){
    if (strlen(input)==0) {
        return;
    }
    
    if (input[0]==c1) {
        input[0]=c2;
    }
    
    replaceCharacter(input+1, c1, c2);
}

//Remove consecutive duplicates from a string
void removeConsecutiveDuplicates(char *input){
    if (strlen(input) == 0) {
        return;
    }
    
    int count = 0; int i; int f = 0;
    for (i = 0 ; input[i] != '\0' ; i++) {
        if (input[i + 1] != input[i] && f == 0) {
            for (int j = i + 1 ; j <= strlen(input) ; j++) {
                input[j - count] = input[j];
                f = 1;
            }
        } else count++;
        
    }
    
    removeConsecutiveDuplicates(input+1);
}



//Merge Sort
void merge_two_arrays(int * arr, int si, int ei) {
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    int * out = new int[size];
    int i = si;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            out[k++] = arr[i];
            i++;
        }
        else {
            out[k++] = arr[j];
            j++;
        }
    }
    
    while (i <= mid) {
        out[k++] = arr[i];
        i++;
    }
    
    while (j <= ei) {
        out[k++] = arr[j];
        j++;
    }
    
    //Copy the output array back to the original array
    k = 0;
    for (int i = si; i <= ei; i++) {
        arr[i] = out[k++];
    }
    
    delete [] out;
}
void my_merge_sort(int * arr, int si, int ei){
    if (si >= ei) {
        return;
    }
    
    int mid = (si + ei) / 2;
    
    my_merge_sort(arr, si, mid);
    my_merge_sort(arr, mid + 1, ei);
    merge_two_arrays(arr, si, ei);
}
void mergeSort(int * arr, int size) {
    my_merge_sort(arr, 0, size - 1);
}



//QuickSort
int place_pivot_element(int * input, int si, int ei) {
    //Place pivot in the right place
    int count = 0;
    for (int i = si + 1; i <= ei; i++) {
        //Find how many elements are smaller than the pivot and then swap.
        if (input[si] > input[i]) {
            count++;
        }
    }
    int pivot_index = count + si;
    int t = input[si];
    input[si] = input[pivot_index];
    input[pivot_index] = t;
    
    //Place elements smaller than pivot on the left and bigger elements on the right.
    int i = si;
    int j = ei;
    while (i < pivot_index && j > pivot_index) {
        
        if (input[i] < input[pivot_index]) {
            i++;
        }
        else if (input[j] >= input[pivot_index]) {
            j--;
        }
        else {
            int t = input[i];
            input[i] = input[j];
            input[j] = t;
            i++;
            j--;
        }
    }
    
    return pivot_index;
}
void my_quickSort(int * input, int si, int ei) {
    
    //Base case, i.e if the size of array is 1 or 0.
    if (si >= ei) {
        return;
    }
    
    int pivot_index = place_pivot_element(input, si, ei);
    
    
    //Call quick sort on the left and the right side.
    my_quickSort(input, si, pivot_index - 1);
    my_quickSort(input, pivot_index + 1, ei);
}
void quickSort(int input[], int size) {
    my_quickSort(input, 0, size - 1);
}

//Return subsequences of a string
int subsequence(string input, string output[]) {
    if (input.empty()) {
        output[0] = " ";
        return 1;
    }
    
    int size = subsequence(input.substr(1), output);
    for (int i = 0; i < size; i++) {
        output[i + size] = input[0] + output[i];
    }
    
    return 2 * size;
}

//Return keypad approach
string keyfunc(int my_num) {
    
    if (my_num == 2) {
        return "abc";
    }
    
    if (my_num == 3) {
        return "def";
    }
    
    if (my_num == 4) {
        return "ghi";
    }
    
    if (my_num == 5) {
        return "jkl";
    }
    
    if (my_num == 6) {
        return "mno";
    }
    
    if (my_num == 7) {
        return "pqrs";
    }
    
    if (my_num == 8) {
        return "tuv";
    }
    
    else
        return "wxyz";
}

int keypad(int num, string output[]) {
    if (num == 0 || num == 1) {
        output[0] = "";
        return 1;
    }
    
    int my_num = num%10;
    int size = keypad(num/10, output);
    int size_duplicate = size;
    string my_num_key = keyfunc(my_num);
    
    
    
    
    //Determine the no. of copies to make
    int i = 0, j = 0;
    for (i = 0; i <= my_num_key.size() - 2; i++) {
        for (j = 0; j <= size_duplicate - 1; j++) {
            output[size + j] = output[j];
        }
        size += size_duplicate;
    }
    
    size = size_duplicate;
     for (i = 0; i <= my_num_key.size() - 1; i++) {
         for (j = 0; j <= size - 1; j++) {
             output[j + (i * size)] = output[j + (i * size)] + my_num_key[i];
         }
     }
    
    return size * my_num_key.size();
}

//Print the keypad approach
void printKeypad_helper(int input, string output) {
    if (input == 0) {
        cout << output << endl;
        return;
    }
    
    int last_digit = input%10;
    string keydial = keyfunc(last_digit);
    
    for (int i = 0; i <= keydial.size() - 1; i++) {
        printKeypad_helper(input/10, output + keydial[i]);
    }
    
    
}
void printKeypad(int input) {
    printKeypad_helper(input, "");
}

//Check AB
//a. The string begins with an 'a'
//b. Each 'a' is followed by nothing or an 'a' or "bb"
//c. Each "bb" is followed by nothing or an 'a'
bool checkAB_helper(char * input) {
    if (strlen(input) == 0) {
        return true;
    }
    
    if ((input[0] == 'a' && input[1] == 'a') || (input[0] == 'a' && input[1] == '\0')) {
        return checkAB_helper(input + 1);
    }
    else if (input[0] == 'a' && (input[1] == 'b')) {
        if (input[2] == 'b') {
            return checkAB_helper(input + 2);
        }
        else {
            return false;
        }
    }
    else if ((input[0] == 'b' && input[1] == 'a') || (input[0] == 'b' && input[1] == '\0')) {
        return checkAB_helper(input + 1);
    }
    else {
        return false;
    }
    
}
bool checkAB(char input[]) {
    if (input[0] == 'b') {
        return false;
    }
    else {
        return checkAB_helper(input);
    }
}

//Staircase
int staircase(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

//Binary Search
int binarySearch_helper(int * input, int si, int ei, int x) {
    if (si >= ei) {
        return -1;
    }
    
    int mid = (si + ei) / 2;
    
    if (input[mid] == x) {
        return mid;
    }
    else if (input[mid] < x) {
        return binarySearch_helper(input, mid + 1, ei, x);
    }
    else {
        return binarySearch_helper(input, si, mid - 1, x);
    }
    
}
int binarySearch(int input[], int size, int element) {
    return binarySearch_helper(input, 0, size - 1, element);
}

//Return Subset of an array
int subset(int input[], int n, int output[][20]) {
    if (n == 0) {
        output[0][0] = 0;
        return 1; //Maybe return 0 as well.
    }

    int first_element = input[0];
    int output_row_size = subset(input + 1, n - 1, output);

    //Copy the elements in the 2D array
    for (int i = 0; i <= output_row_size - 1; i++) {
        for (int j = 1; j <= output[i][0]; j++) {
            output[i + output_row_size][j + 1] = output[i][j];
        }
        output[i + output_row_size][1] = first_element;
        output[i + output_row_size][0] = output[i][0] + 1;
    }

    return output_row_size * 2;
    
}

//Print Subsets of Array
void printSubsetsOfArray_helper_print_output(int * output, int output_size) {
    for (int i = 0; i < output_size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}
void printSubsetsOfArray_helper(int * input, int input_size, int * output, int output_size) {
    if (input_size == 0) {
        printSubsetsOfArray_helper_print_output(output, output_size);
        return;
    }
    
    //Don't include input[0].
    printSubsetsOfArray_helper(input + 1, input_size - 1, output, output_size);
    
    
    //Include input[0].
    output[output_size] = input[0];
    printSubsetsOfArray_helper(input + 1, input_size - 1, output, output_size + 1);
    
}
void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    printSubsetsOfArray_helper(input, size, output, 0);
}

//Return subsets sum to k.
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if (n == 0) {
        if (k == 0) {
            output[0][0] = 0;
            return 1;
        } else
            return 0;
    }
    
    //Don't include the first element.
    int o1[10000][50], o2[10000][50];
    int s1 = subsetSumToK(input + 1, n - 1, o1, k);
    int s2 = subsetSumToK(input + 1, n - 1, o2, k - input[0]);
    
    //Append the first element in o2.
    for (int i = 0; i < s2; i++) {
        for (int j = o2[i][0]; j >= 1 ; j--) {
            o2[i][j + 1] = o2[i][j];
        }
        o2[i][1] = input[0];
        o2[i][0] += 1;
    }
    
    //Copy o1 into output.
    for (int i = 0; i < s1; i++) {
        for (int j = 1; j <= o1[i][0]; j++) {
            output[i][j] = o1[i][j];
        }
        output[i][0] = o1[i][0];
    }
    
    //Copy o2 into output.
    for (int i = 0; i < s2; i++) {
        for (int j = 1; j <= o2[i][0]; j++) {
            output[i + s1][j] = o2[i][j];
        }
        output[i + s1][0] = o2[i][0];
    }
    
    return s1 + s2;
    
}


//Print subset sum to k
bool printSubsetSumToK_helper_arraysum_to_k_checker(int * output, int output_size, int k) {
    int x = 0;
    for (int i = 0; i < output_size; i++) {
        x += output[i];
    }
    
    if (x == k) {
        return true;
    } else {
        return false;
    }
}

void printSubsetSumToK_helper_outputprinter(int * output, int output_size) {
    for (int i = 0; i < output_size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}
void printSubsetSumToK_helper(int input[], int input_size, int k, int output[], int output_size) {
    if (input_size == 0) {
        if (printSubsetSumToK_helper_arraysum_to_k_checker(output, output_size, k)) {
            printSubsetSumToK_helper_outputprinter(output, output_size);
            return;
        }
        else {
            return;
        }
    }
    
    printSubsetSumToK_helper(input + 1, input_size - 1, k, output, output_size);
    output[output_size] = input[0];
    printSubsetSumToK_helper(input + 1, input_size - 1, k, output, output_size + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    printSubsetSumToK_helper(input, size, k, output, 0);
}



//Return all codes - String
char getCodes_integer_to_char(int num) {
    char c = 96 + num;
    return c;
}

int getCodes_helper(string input, string output[], string str[][100]) {
    if (input.size() == 1) {
        str[0][0] = "1";
        str[0][1] = input[0];
        return 1;
    }
    
    int size = getCodes_helper(input.substr(1), output, str);
    int ei = size - 1;
    int max = -1, si = -1;
    for (int i = ei; i >= 0; i--) {
        if (stoi(str[i][0]) > max) {
            max = stoi(str[i][0]);
            si = i;
        }
    }
    
    int k = size;
    for (int i = si; i <= ei; i++) {
        for (int j = 1; j <= stoi(str[i][0]); j++) {
            str[k][j + 1] = str[i][j];
        }
        str[k][1] = input[0];
        str[k][0] = to_string(stoi(str[i][0]) + 1);
        k++;
        
        string s = str[i][1];
        if (s.size() == 1 && stoi(input[0] + s) <= 26) {
            str[k][1] = input[0] + s; //Check if its the other way around.
            for (int j = 2; j <= stoi(str[i][0]); j++) {
                str[k][j] = str[i][j];
            }
            str[k][0] = str[i][0];
            k++;
        }
    }
    
    return k;
}

int getCodes(string input, string output[10000]) {
    string str[10000][100];
    int size =  getCodes_helper(input, output, str);
    int ei = size - 1;
    int max = -1, si = -1;
    for (int i = ei; i >= 0; i--) {
        if (stoi(str[i][0]) > max) {
            max = stoi(str[i][0]);
            si = i;
        }
    }

    int output_index = 0;
    for (int i = si; i <= ei; i++) {
        string s = "";
        for (int j = 1; j <= stoi(str[i][0]); j++) {
            s += getCodes_integer_to_char(stoi(str[i][j]));
        }
        output[output_index] = s;
        output_index++;
    }
    return output_index;
}

//Print all codes of a string.
void printAllPossibleCodes_helper(string input, string output) {
    if (input.size() <= 0) {
        cout << output << endl;
        return;
    }
    
    int temp = input[0] - '0';
    char c1 = getCodes_integer_to_char((temp));
    printAllPossibleCodes_helper(input.substr(1), output + c1);
    
    if (input.size() > 1) {
        string s = input.substr(0,2);
        int sum = stoi(s);
        if (sum >= 10 && sum <= 26) {
            char c2 = getCodes_integer_to_char(sum);
            printAllPossibleCodes_helper(input.substr(2), output + c2);
        }
    }
}

void printAllPossibleCodes(string input) {
    string output = "";
    printAllPossibleCodes_helper(input, output);
}

//Return permutations of a string
int returnPermutations(string input, string output[]){
    if (input.size() == 1) {
        output[0] = input[0];
        return 1;
    }

    int size = returnPermutations(input.substr(1), output);
    int len = input.size();
    
    //Make copies.
    for (int i = size; i < size * len; i = i + size) {
        for (int j = 0; j < size; j++) {
            output[i + j] = output[j];
        }
    }
    
    //Append the first char accordingly.
    int idex = 0;
    for (int i = 0; i < size * len; i = i + size) {
        for (int j = 0; j < size; j++) {
            output[i + j] = (output[i + j]).substr(0,idex) + input[0] + (output[i + j]).substr(idex);
        }
        idex++;
    }
    return size * len;
}

//Print permutations of a string.
void printPermutations_helper(string input, string output){
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    
    for (int i = 0; i <= output.size(); i++) {
        string output_temp = output.substr(0,i) + input[0] + output.substr(i);
        printPermutations_helper(input.substr(1), output_temp);
    }
}
void printPermutations(string input){
    printPermutations_helper(input, "");
}





//Problems based on time and space complexity.



//Find the unique element.
int FindUnique(int arr[], int size){
    int x_or = 0;
    for (int i = 0; i < size; i++) {
        x_or = x_or ^ arr[i];
    }
    return x_or;
}

//Find duplicate in an array.
int DuplicateNumber(int arr[], int size) {
    sort(arr, arr + size);
    for (int i = 0; i < size - 1; i++) {
        if (arr[i + 1] == arr[i]) {
            return arr[i];
        }
    }
    return -1;
}


//Print array intersection.
void intersection(int input1[], int input2[], int size1, int size2) {
    sort(input1, input1 + size1);
    sort(input2, input2 + size2);
    
    //Now apply merge two sorted arrays logic.
    int * output = new int[size1 + size2];
    int i = 0, j = 0, idex = 0;
    
    while (i < size1 && j < size2) {
        
        if (input1[i] < input2[j]) {
            i++;
        }
        else if (input1[i] > input2[j]) {
            j++;
        }
        else {
            output[idex] = input1[i];
            idex++;
            i++;
            j++;
        }
    }
    
    for (int i = 0; i < idex; i++) {
        cout << output[i] << endl;
    }
}


//Pair sum in an array.
void pairSum(int input[], int size, int x) {
    //Step - 1 :- Sort the array
    sort(input, input + size);
    
    //Initialize the 2 iterators at the arrays extreme ends si, ei.
    int si = 0;
    int ei = size - 1;
    
    while (si < ei) {
        
        //Step - 2 :- If sum of si's and ei's elements  are not equal to x.
        if (input[si] + input[ei] != x) {
            //If the sum is greater than x.
            if (input[si] + input[ei] > x) {
                ei--;
            }
            //else if the sum is less than x.
            else {
                si++;
            }
        }
        
        //Step - 3 :- If the sum is equal to x.
        else {
            //If the elements at si and ei are not the same,
            if (input[si] != input[ei]) {
                //then do this :-
                //Count the no. of si elements which have the same value.
                int si_count = 0;
                int si_number_whose_count_has_to_be_kept = input[si];
                while (input[si] == si_number_whose_count_has_to_be_kept) {
                    si_count++;
                    si++;
                }
                
                //Count the no. of ei elements which have the same value.
                int ei_count = 0;
                int ei_number_whose_count_has_to_be_kept = input[ei];
                while (input[ei] == ei_number_whose_count_has_to_be_kept) {
                    ei_count++;
                    ei--;
                }
                
                //Print the si and the ei elements (si_count x ei_count) times.
                for (int i = 0; i < (si_count * ei_count); i++) {
                    cout << si_number_whose_count_has_to_be_kept << " " << ei_number_whose_count_has_to_be_kept << endl;
                }
            }
            
            //Else if the elements at si and ei are the same,
            else {
                //Find the size of the sub-array which has all elements identical.
                int sub_size = ei - si + 1;
                
                //Find the natural sum of the fist sub_size elements.
                int natural_sub_size = ((sub_size) * (sub_size - 1)) / 2;
                
                //Print till the natural sub size.
                for (int i = 0; i < natural_sub_size; i++) {
                    cout << input[si] << " " << input[si] << endl;
                }
                
                //After this no more elements in the whole array need to be checked.
                //Because this condition is only reached at the end.
                break;
            }
        }
    }
}

//Triplet sum in an array.
void FindTriplet(int arr[], int size, int x) {
    sort(arr, arr + size);
    
    for (int i = 0; i <= size - 3; i++) {
        for (int j = i + 1; j <= size - 2; j++) {
            for (int k = j + 1; k <= size - 1; k++) {
                if (arr[i] + arr[j] + arr[k] == x) {
                    if (arr[i] < arr[j] < arr[k]) {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                    }
                }
            }
        }
    }
}

//Rotate array.
void rotate(int *input, int d, int n)
{
    int * output = new int[n];
    
    for (int i = 0; i <= n - 1; i++) {
        int index = i - d;
        if (index < 0) {
            index += n;
        }
        output[index] = input[i];
    }
    
    for (int i = 0; i <= n - 1; i++) {
        input[i] = output[i];
    }
}


//Check array rotation.
int arrayRotateCheck(int *input, int size)
{
    int smallest = input[0];
    int idex = 0;
    for (int i = 1; i <= size - 1; i++) {
        if (input[i] < smallest) {
            smallest = input[i];
            idex = i;
        }
    }
    return idex;
}

//Does S contain T?
bool checksequenece(char large[] , char*small) {
    string s = "";
    
    int small_index = 0;
    for (int i = 0; large[i] != '\0'; i++) {
        if (large[i] == small[small_index]) {
            s = s + large[i];
            small_index++;
        }
    }
    
    if (small == s) {
        return true;
    }
    return false;
}

//Split array
bool helper(int* arr, int n, int start, int lsum, int rsum)
{
  
    // If reached the end
    if (start == n)
        return lsum == rsum;
  
    // If divisible by 5 then add to the left sum
    if (arr[start] % 5 == 0)
        lsum += arr[start];
  
    // If divisible by 3 but not by 5
    // then add to the right sum
    else if (arr[start] % 3 == 0)
        rsum += arr[start];
  
    // Else it can be added to any of the sub-arrays
    else
  
        // Try adding in both the sub-arrays (one by one)
        // and check whether the condition satisfies
        return helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start]);
  
    // For cases when element is multiple of 3 or 5.
    return helper(arr, n, start + 1, lsum, rsum);
}
  
// Function to start the recursive calls
bool splitArray(int* arr, int n)
{
    // Initially start, lsum and rsum will all be 0
    return helper(arr, n, 0, 0, 0);
}



int main() {
    
    int size;

    int x;
    cin>>size;
    
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    cin>>x;

    FindTriplet(input,size,x);
        
    return 0;
}



