#include "iostream"
using namespace std;

void* operator new(size_t size) {
    cout << "new" << endl;
    void* p = malloc(size);
    return p;
}
 
void operator delete(void* p) {
    cout << "delete" << endl;
    free(p);
}

void* operator new[](size_t size) {
    cout << "new[]" << endl;
    void* p = malloc(size);
    return p;
}
 
void operator delete[](void* p) {
    cout << "delete[]" << endl;
    free(p);
}

class Cls {
    public:
    int x;

    Cls() {
        cout << "constructor" << endl;
    }

    ~Cls() {
        cout << "destructor" << endl;
    }
};
 
int main() {
    int N = 2, n1;
    int* p = new int;
    int* parr = new int[N];
    Cls* carr = new Cls[N];
 
    *p = 1;
    for (n1 = 0; n1 < N; ++n1) {
        parr[n1] = n1;
        carr[n1].x = n1;
    }

    cout << "p: " << *p << endl;
 
    cout << "parr: ";
    for(n1 = 0; n1 < N; ++n1) {
        cout << parr[n1] << " ";
    }
    cout << endl;

    cout << "carr: ";
    for(n1 = 0; n1 < N; ++n1) {
        cout << carr[n1].x << " ";
    }
    cout << endl;
    
    delete p;
    delete [] parr;
    delete [] carr;

    return 0;
}
