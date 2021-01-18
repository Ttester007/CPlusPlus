// Example program
#include <iostream>
#include <cassert>

using namespace std;

template <typename T> class DynamicArray
{
    private:
    int iArraySize;
    int iMaxCapacity;
    T *pArrayPointer;
    
    public:
    DynamicArray() //Ctor
    {
        this->iArraySize = 0;
        this->iMaxCapacity = 1;
        this->pArrayPointer = new T[this->iMaxCapacity];
    }
    ~DynamicArray() //Dtor
    {
        delete [] this->pArrayPointer;
    }
    
    int capacity()
    {
        return this->iMaxCapacity;
    }
    
    int size()
    {
        return this->iArraySize;
    }
    T& operator[](T i) 
    {
        assert(i < this->iArraySize);
        return this->pArrayPointer[i];
    }
    
    void pushBack(T newdata)  //Add element to dynamicArray
    {
        if (this->iMaxCapacity == this->iArraySize + 1) 
        {
            this->iMaxCapacity *= 2; //double the capacity
            T *tempArr = new T[this->iMaxCapacity]; // temporary array
            for(int i=0; i< this->iArraySize; i++)
            {
                tempArr[i] = pArrayPointer[i]; // copy data to temporary array
            }
            delete [] this->pArrayPointer;
            this->pArrayPointer = tempArr;
        }
        this->pArrayPointer[this->iArraySize] = newdata;
        this->iArraySize+=1;
    }
    
    void pushAtIndex(T newData, int index)
    {
        
        if (this->iMaxCapacity == this->iArraySize) 
        {
            pushBack(newData);
        }
        else
        {
            if(index>=0)
            {
                if(index < this->iArraySize)
                    this->pArrayPointer[index]=newData;
                else
                    cout << "Index out of range! Max Array Size is : " << this->iArraySize << endl;
            }
            else
            {
                cout << "Index is negative and invalid! " << endl;
            }
        }
    }
    
    T getDataAtIndex(int index)
    {
        if(index>=0)
        {
            if(index < this->iArraySize)
                return this->pArrayPointer[index];
            else
                cout << "Index out of range!" << endl;
        }
        else
        {
            cout << "Index is negative and invalid! " << endl;
        }
    }
    
    void popBack()
    {
        this->iArraySize--;
    }
    
    void print()
    {
        for (int i = 0; i <  this->iArraySize; i++) {
            cout << this->pArrayPointer[i] << " ";
        }
        cout << endl;
    }
    
};


int main()
{
    DynamicArray<char> darray;

    for (size_t i = 0; i < 5; i++)
    {
        darray.pushBack((char)('a'+i));
    }
    cout << "Vector size : " << darray.size() << endl;
    cout << "Vector capacity : " << darray.capacity() << endl;
    darray.print();
    
    cout<< darray.getDataAtIndex(-1) << endl;
    darray.pushAtIndex('z', 5);
    darray.popBack();
    cout << "Vector size : " << darray.size() << endl;
    cout << "Vector capacity : " << darray.capacity() << endl;
    darray.print();
    
    return 0;
}
