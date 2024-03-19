#include <iostream>
#include <vector>
#include <cassert>

class Stack {
private:

public:
    virtual ~Stack();
    virtual void push(const double &item) = 0;
    virtual double pop() = 0;
    virtual double peek() = 0;
    void pop_all();
    virtual bool isEmpty() const = 0;
};

Stack :: ~Stack() {

}

void Stack::pop_all() {
    while (!this->isEmpty()) {
        this->pop();
    }
}

class Vec_Stack : public Stack {
private:
    vector<double> v;

public:
    Vec_Stack();
    ~Vec_Stack();
    void push(const double &item);
    double pop();
    double peek() const;
    bool isEmpty() const;
    friend ostream& operator << (ostream &, const Vec_Stack &);
};

Vec_Stack::Vec_Stack() {

}

Vec_Stack::~Vec_Stack() {
    this->v.~vector();
}

void Vec_Stack::push(const double item) {
    this ->v.insert(this->v.begin(), item);
}

double Vec_Stack::pop() {
    assert(!this->isEmpty());
    double item = v[0];
    this->v.erase(this->v.begin());
    return item;
}

double Vec_Stack::peek() const{
    assert(!this->isEmpty());
    return v[0];
}

bool Vec_Stack::isEmpty() const {
    return v.size() == 0;
}

ostream& operator << (ostream &out, const Vec_Stack &s) {
    out << "[";
    for (int i = 0; i < static_cast<int>(s.v.size()) - 1; i++) {
        out << s.v[i] << ", ";
    }
    if (s.v.size() > 0) {
        out << s.v[s.v.size()-1];
    }
    out << "]";
    return out;
}

class Node {
typedef Node* NodePtr;
private:
    double data;
    NodePtr link;
public:
    Node();
    Node(const double &);
    Node(const Node &);
    double getData() const;
    NodePtr getLink() const;
    void setData(const double &);
    void setLink(const NodePtr &);
    friend ostream& operator << (ostream &, const Node &);
};
typedef Node* NodePtr;
Node::Node() : data(0), link(nullptr) {}
Node::Node(const double &d) : data(d), link(nullptr){}
Node::Node(const Node &n) : data(n.data), link(n.link) {}
double Node::getData() const {return data;}
NodePtr Node::getLink() const {return link;}
void Node::setData(const double &d) {data = d;}
void Node::setLink(const NodePtr &p) {link = p;}
ostream& operator << (ostream& out, const Node& n) { out << n.data; return out; }
typedef Node* NodePtr;


class LL_Stack : public Stack {
private:
    NodePtr head;
public:
    LL_Stack();
    ~LL_Stack();
    void push(const double &item);
    double pop();
    double peek() const;
    bool isEmpty() const;
    friend ostream& operator << (ostream &, const LL_Stack &);
};

LL_Stack::LL_Stack() : head(nullptr) {}
LL_Stack::~LL_Stack() {
    while (!this->isEmpty()) {
        this->pop();
    }
}

void LL_Stack::push(const double &item) {
    NodePtr n = new Node(item);
    n->setLink(this->head);
    this->head = n;
}

double LL_Stack::pop() {
    assert(!this->isEmpty());
    double item = this->head->getData();
    NodePtr temp = this->head;
    this->head = this->head->getLink();
    delete temp;
    return item;
}

double LL_Stack::peek() const {
    assert(!this->isEmpty());
    return this->head->getData();
}

bool LL_Stack::isEmpty() const {
    return this->head == nullptr;
}

ostream& operator << (ostream &out, const LL_Stack &s) {
    NodePtr temp = s.head;
    if (temp == nullptr) {
        out << "[]";
    } else {
        out << "[";
        while (temp->getLink() != nullptr) {
            out << *temp << ", ";
            temp = temp->getLink();
        }
        out << *temp;
        out << "]";
    }
    return out;
}

int main() {
    // Vec_stack s;
    LL_Stack s;
    cout << "At the beginning, the stack is " << s << endl;
    assert(s.isEmpty());

    s.push(5.4);
    cout << "Now, the stack is " << s << endl;
    assert(!s.isEmpty());
    assert(abs(s.peek() - 5.4) < 0.0001);

    double top = s.pop();
    assert(abs(top - 5.4) < 0.0001);
    assert(s.isEmpty());

    s.push(2);
    cout << "Now, the stack is " << s << endl;
    s.push(3);
    cout << "Now, the stack is " << s << endl;
    s.push(4);
    cout << "Now, the stack is " << s << endl;
    assert(!s.isEmpty());
    double x = s.peek();
    assert(abs(s.peek() - 4) < 0.0001);
    s.pop();
    cout << "Now, the stack is " << s << endl;
    assert(!s.isEmpty());
    assert(abs(s.peek() - 3) < 0.0001);

    s.pop();
    cout << "Now, the stack is " << s << endl;
    assert(!s.isEmpty());
    assert(abs(s.peek() - 2) < 0.0001);

    s.pop();
    cout << "Now, the stack is "<< s << endl;
    assert(s.isEmpty());

    s.push(5);
    cout << "Now, the stack is " << s << endl;
    s.push(6);
    cout << "Now, the stack is " << s << endl;
    s.pop_all();
    cout << "Now, the stack is " << s << endl;
    assert(s.isEmpty());

    cout << "All ListStack tests passed" << endl;

    system("Pause");
    return 0;
}
