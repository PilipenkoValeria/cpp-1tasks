#include <iostream>
using namespace std;

using namespace std;

class DynamicIntArray {
private:
    int* array;
    int size;

public:
    DynamicIntArray();
    DynamicIntArray(int size);
    DynamicIntArray(int size, int n);
    DynamicIntArray(const DynamicIntArray& dynamic);
    DynamicIntArray(DynamicIntArray&& dynamic);
    ~DynamicIntArray();

    int getSizeOfArray();
    void resize(int newsize);

    int& operator[](const int index);

    DynamicIntArray& operator=(const  DynamicIntArray& diname);
    DynamicIntArray& operator=(DynamicIntArray&& dynamic);

    friend bool operator == (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator != (const DynamicIntArray& d1, const DynamicIntArray& d2);

    friend bool operator> (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator<= (const DynamicIntArray& d1, const DynamicIntArray& d2);

    friend bool operator< (const DynamicIntArray& d1, const DynamicIntArray& d2);
    friend bool operator>= (const DynamicIntArray& d1, const DynamicIntArray& d2);

    friend DynamicIntArray operator+(DynamicIntArray& d1, DynamicIntArray& d2);

    friend ostream& operator<<(ostream& out, const DynamicIntArray& d1);
    friend istream& operator>>(istream& in, DynamicIntArray& d1);
};

class incorrectLength :public std::exception {
    const char* message;
public:
    incorrectLength(const char* cmessage) : message(cmessage) { }
    const char* what() const noexcept { return message; }
};