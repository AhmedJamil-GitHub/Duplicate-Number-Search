#include <iostream>
#include <vector>
using namespace std;

void DuplicatesSearch(int [], int size);
bool InVector(vector<int>& Duplicates,int value, int& onWhichIndex);

int main()
{

    const int SIZE = 10;
    int array[SIZE] = {5,5,5,5,5,6,5,5,5,1};
    DuplicatesSearch(array,SIZE);

    return 0;
}

void DuplicatesSearch(int arr[] , int size)
{
    vector<int> Duplicates(0);
    int index;
    int element;
    for(int i=0 ; i < size; i++)
    {
        element = arr[i];
        if( InVector(Duplicates,element,index) )
            Duplicates[index+1]++;
        else
        {
            Duplicates.push_back(element);
            Duplicates.push_back(1);
        }
    }

    for(int i=0; i<Duplicates.size();i=i+2)
    {
        cout << "ELEMENT-(" << Duplicates[i] << ") exists " << Duplicates[i+1] << " times" << endl;
    }
}

bool InVector(vector<int>& Duplicates ,int value, int& onWhichIndex)
{
    for(int i=0; i<Duplicates.size(); i=i+2)
    {
        if(Duplicates[i] == value)
        {
             onWhichIndex = i;
             return true;
        }
    }
    return false;
}
