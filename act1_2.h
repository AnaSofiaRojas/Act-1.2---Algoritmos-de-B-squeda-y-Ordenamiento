#ifndef sorter_h
#define sorter_h
#include <stdlib.h>
#include <vector>
template<typename T>
class Sorter
{
    public:
    Sorter(){};
    ~Sorter(){};

    void swap(int i,int j,std::vector<T>&arr)
    {
        T aux=arr[i];
        arr[i]=arr[j];
        arr[j]=aux;

    };

    virtual void sort(std::vector<T> &arr) {};
};

template<typename T>
class InsertionSort:public Sorter<T>
{
    public:
    InsertionSort(){};
    ~InsertionSort(){};
    void sort(std::vector<T> &arr)
    {
        T key;
        for (size_t i = 0; i < arr.size(); i++)
        {
            key= arr[i];
            int j=i-1;
            while (j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=key;

        } 

    };

};
template<typename T>
class BubbleSort:public Sorter<T>
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};
    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            bool no_swap= true;
            for (size_t j = 0 ; j < arr.size()-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    Sorter<T>::swap(j,j+1,arr);
                    no_swap=false;
                }
            }
            if (no_swap)
            {
                break;
            }
        }

    };
};
template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr)
    {
        quicksort(arr, 0, arr.size() - 1);
    };

    void quicksort(std::vector<T> &arr, int low, int high)
    {
        if (low < high)  
        {  
            int pi = partition(arr, low, high);  
       
            quicksort(arr, low, pi - 1);  
            quicksort(arr, pi + 1, high);  
        }  
    };

    int partition (std::vector<T> &arr, int low, int high)
    {  
        T pivot = arr[high]; // pivot  
        int i = (low - 1);     // Index of smaller element  
      
        for (int j = low; j <= high - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            if (arr[j] < pivot)  
            {  
                i++; // increment index of smaller element
                Sorter<T>::swap(i, j, arr);
            }  
        }  
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);  
    }; 
};

#endif 
