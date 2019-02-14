/*
 David Ortiz
 11/1/2017
 
 Program will sort integers read from a file using the bubble sort and print to an output file.
 
 */
#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

int arraySize(string); //prototype, explained below
int main() {
    
    int nums; //will hold each int read from the input file.
    int count=0; //will keep track of how many ints have been read, used to insert into array
    int swaps = 0; //will keep track of how many swaps there were, incremented when the bubble sort performs a swap
    
    string fileName; //will store the name of the file, entered by the user.
    cout << "Enter the name of the file: ";
    cin >> fileName;
    
    //ifstream, set to string fullName or fileName, depending on operating system, to be used to read from throughout the program.
    ifstream file(fileName); //if others
    
    //if file not found
    if(file.fail()){
        cout << "Not a valid file name, program ended." << endl;
        return 0;
    }
    
    //ofstream, set to output, in order to be used throughout the program. Depending on operating system:
    ofstream output("BubbleOutput.txt"); //if others

    //arraySize(), depending on operating system:
    //int size will hold the returned value from the arraySize function, which will be an int. This will be used to determine the size of the array.
    int size = arraySize(fileName); //for others
    
    int numbers[size]; //numbers array will hold all the int nums read from the input file, to be used to loop through and sort.
    
    while(!file.eof()){
        
        file>>nums;
        
        if(!file.eof()){
        
            count++;
            numbers[count]=nums;
            
        } //end of if
    } //end of while
    
    //sorting algorithm
    for(int i = 1; i<=size; i++){
        for(int j=i+1; j<=size; j++){
            
            if(numbers[i]>numbers[j]){
                int temp = numbers[i]; //will temporarily hold the item in numbers[i] to help swap the itemms
                numbers[i]=numbers[j];
                numbers[j]=temp;
                swaps++;
            }//end of if
        } //end of j for loop
    }//end of i for loop
    
    //output rearranged ints
    output << "Digits in ascending order: \n\n";
    for(int i=1; i<=size; i++){
        output << setw(5) << numbers[i];
        if(i%10==0) output << endl;
    }
    
    cout << "\nOutput is in file: \"BubbleOutput.txt\"\nNumber of swaps: " << swaps << "\nNumber of integers in input file: " << size <<endl <<endl;
    
    //close both files
    file.close();
    output.close();
    
}//end of main

//arraySize() will return int count, which will be the total of how many ints there are in the input file. string fileName is passed into it to read from the file.
// each int read will be stored in nums, one at a time. Each time an int is read, int count is incremented by 1. Then count is returned.
int arraySize(string fileName){
    ifstream file(fileName);
    int nums; //explained above
    int count=0; //explained above
    while(!file.eof()){
        file>>nums;
        
        if(!file.eof()){
            
            count++;
        
        }//end of if
    }//end of while
    
    return count;
} //end of arraySize()


