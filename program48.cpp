//c++ program to perform a linear search for a given number and print the results
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,a,b;bool check;
    cout<<"Enter the length of array: ";
    cin>>n;
    //making an array of integers of size n(which is user defined)
    int arr[n];
    for (int i=0;i<n;i++)
    {
        //entering an element in an array of integers in each index
        cout<<"Enter element: ";
        cin>>a;
        arr[i]=a;
    }
    // Display the elements of the array
    cout << "Elements in the array: |";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"|";
    cout << endl;
    //ask the user to enter a number to search for in the array
    cout<<"Enter number to search for: ";
    cin>>b;
    for (int i=0;i<n;i++)
    {
        //searching for the given number in each index of the array
        if (arr[i]==b)
        {
            //using a boolean variable check to determine whether element is found in the array
            cout<<"Element "<<b<<" found at index "<<i<<endl;
            check=true;
        }
    }
    if (check==false)
    {
        cout<<"Element not found"<<endl;
    }
    return 0;
}