#include <iostream>
#include <ctime>

using namespace std;

class List {
    /**
     * 列表在main栈里创建了一个指针变量，指向堆里的一个内存地址
     * 每次对列表进行增删元素时，程序都会在堆里创建一个新的内存地址用来存储新的列表，通过重新更改指针指向的方式对列表进行修改
     * 更改指针以后要删除旧有的列表
     */
    private:
        // A dynamic arrey member variable to store elements
        int *A;
        // A member variable to keep track of number of elements
        int size;

    public:
        // Constructors
        List(/* args */);

        ~List();

        // Getters
        // returns the number of elements
        int length() const;

        // Setters
        // appends a value into the container
        void append(const int &);

        // Friend functions
        friend ostream& operator << (ostream &, const List &);
};

List::List(/* args */) {
    this->A = nullptr;
    this->size = 0;
}

List::~List() {

}

int List::length() const {
    return this->size;
}

void List::append(const int &value) {
    // Copy existing elements and the value to a new dynamic arrey
    int *temp = new int[this->size + 1];
    for(int i = 0; i < this->size; i++) {
        temp[i] = this->A[i];
    }
    temp[this->size] = value;

    // Delete the existing elements from the heap (if any)
    if(this->A != nullptr) {
        delete[] this->A;
    }

    // Point the pointer to the new dynamic arrey and increase the size
    this->A = temp;
    this->size += 1;
}

ostream& operator << (ostream &out, const List &L) {
    out << "[";
    for(int i = 0; i < L.size; i++) {
        out << L.A[i] << ", ";
    }
    // delete the last comma and space printed in the loop
    if(L.size > 0) {
        out << "\b\b";
    }
    out << "]";
    return out;
}

int main() {
    srand(time(0));

    // Create an empty list and print the list
    List L1;
    cout << "The list has " << L1.length() << " elements in it" << endl;
    cout << "The list is L1 = " << L1 << endl << endl;

    system("Pause");
    return 0;
}
