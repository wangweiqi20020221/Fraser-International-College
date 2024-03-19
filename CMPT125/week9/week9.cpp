#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> *a;
    a = new vector<double>;
    for(int i = 0; i < 5; i++) {
        a->push_back(1.0*rand()/RAND_MAX * 10 - 5);
    }
    cout << "The vector has " << a->size() << " elements." << endl;
    for(int i = 0; i < a->size(); i++) {
        cout << (*a)[i] << endl;
    }
    delete a;
    system("Pause");
    return 0;
}
