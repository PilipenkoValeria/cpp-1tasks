#include"DynamicIntArray.h"
#include <iostream>
using namespace std;

DynamicIntArray::DynamicIntArray() {
    size = 0;
    array = new int[size];
}

DynamicIntArray::DynamicIntArray(int size) {
    this->size = size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

DynamicIntArray::DynamicIntArray(int size, int n) {
    this->size = size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = n;
    }
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& dynamic) {
    int i;
    size = dynamic.size;
    array = new int[size];
    for (int i = 0; i < dynamic.size; i++) {
        array[i] = dynamic.array[i];
    }
}

DynamicIntArray::DynamicIntArray(DynamicIntArray&& dynamic)
    : array(dynamic.array), size(dynamic.size) {
    dynamic.array = nullptr;

}

DynamicIntArray::~DynamicIntArray() {
    delete[] array;
}

int& DynamicIntArray::operator[](const int index) {
    if (index < 0 || index >= size) {
        throw std::exception();
    }
    return array[index];
}

int DynamicIntArray::getSizeOfArray() {
    return size;
}

void DynamicIntArray::resize(int newsize) {
    int* newArray = new int[newsize];
    if (size >= newsize) {
        for (int i = 0; i < newsize; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        size = newsize;
        this->array = newArray;
    }
    if (size < newsize) {
        for (int i = 0; i < newsize; i++) {
            if (i < size) {
                newArray[i] = array[i];
            }
            else {
                newArray[i] = 0;
            }
        }
        delete[] array;
        size = newsize;
        this->array = newArray;
    }
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& dynamic) {
    delete[] array;
    size = dynamic.size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = dynamic.array[i];
    }

    return *this;
}
DynamicIntArray& DynamicIntArray::operator=(DynamicIntArray&& dynamic) {
    delete[] array;
    size = dynamic.size;
    array = dynamic.array;
    dynamic.array = nullptr;
    return *this;
}

bool operator== (const DynamicIntArray& d1, const DynamicIntArray& d2) {
    try
    {
        if (d1.size==d2.size) {
            for (int i = 0; i < d1.size; i++) {
                if (d1.array[i] != d2.array[i]) {
                    return false;
                }
            } return true;
        }
        else {
            cout << endl << "incorrectLength" << endl;
            return false;
        }
    }
    catch (incorrectLength& incorrect)
    {
        std::cerr << incorrect.what() << endl;
    }
}

bool operator != (const DynamicIntArray& d1, const DynamicIntArray& d2) {
    try
    {
        if (d1.size == d2.size) {
            for (int i = 0; i < d1.size; i++) {
                if (d1.array[i] == d2.array[i]) {
                    return false;
               }
            } return true;
        }
        else {
            cout << endl << "incorrectLength" << endl;
            return false;
        }
    }
    catch (incorrectLength& incorrect)
    {
        std::cerr << incorrect.what() << endl;
    }
}

bool operator> (const const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.array[i] <= d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator>= (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.array[i] < d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.array[i] >= d2.array[i]) {
            return false;
        }
    }
    return true;
}

bool operator<= (const DynamicIntArray& d1, const DynamicIntArray& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.array[i] > d2.array[i]) {
            return false;
        }
    }
    return true;
}

DynamicIntArray operator+(DynamicIntArray& d1, DynamicIntArray& d2) {

    DynamicIntArray result = DynamicIntArray(d1.size + d2.size);
    for (int i = 0; i < d1.size; i++) {
        result.array[i] = d1[i];
    }
    for (int i = d1.size; i < (d1.size + d2.size); i++) {
        result.array[i] = d2[i - d1.size];
    }
    return result;
}

ostream& operator<< (ostream& out, const DynamicIntArray& dynamic)
{
    out << "[";
    for (int i = 0; i < dynamic.size; i++) {
        out << dynamic.array[i];
        if (i < dynamic.size - 1) {
            out << " ";
        }
    }
    out << "]";

    return out;
}

istream& operator>> (istream& in, DynamicIntArray& dynamic)
{
    for (int i = 0; i < dynamic.size; i++) {
        in >> dynamic.array[i];
    }
    return in;
}