//
//  main.cpp
//  Pair Sum in Array
//
//  Created by Souvik Saha on 04/09/20.
//  Copyright © 2020 Souvik Saha. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void pairSum_helper(vector<int> * input, int x) {
    //Step - 1 :- Sort the array
    sort(input->begin(), input->end());
    
    //Initialize the 2 iterators at the arrays extreme ends si, ei.
    int si = 0;
    int ei = input->size() - 1;
    
    while (si < ei) {
        //Step - 2 :- If sum of si's and ei's elements  are not equal to x.
        if (input->at(si) + input->at(ei) != x) {
            //If the sum is greater than x.
            if (input->at(si) + input->at(ei) > x) {
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
                int si_number_whose_count_has_to_be_kept = input->at(si);
                while (input->at(si) == si_number_whose_count_has_to_be_kept) {
                    si_count++;
                    si++;
                }
                
                //Count the no. of ei elements which have the same value.
                int ei_count = 0;
                int ei_number_whose_count_has_to_be_kept = input->at(ei);
                while (input->at(ei) == ei_number_whose_count_has_to_be_kept) {
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
                    cout << input->at(si) << " " << input->at(ei) << endl;
                }
                
                //After this no more elements in the whole array need to be checked.
                //Because this condition is only reached at the end.
                break;
            }
        }
    }
}
void pairSum(int input[], int size, int x) {
    
    vector<int> * v = new vector<int>();
    for (int i = 0; i < size; i++) {
        v->push_back(input[i]);
    }
    
    pairSum_helper(v, x);
    delete input;
}

int main() {

    int size;
    int x;

    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    cin>>x;
    pairSum(input,size,x);
        
    return 0;
}


