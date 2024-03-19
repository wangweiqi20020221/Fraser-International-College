#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Node {
typedef Node* NodePtr;
private:
	int data;
	NodePtr link;
public:
	Node();
	Node(const int &);
	Node(const Node &);
	int getData() const;
	NodePtr getLink() const;
	void setData(const int &);
	void setLink(const NodePtr &);
	friend ostream& operator << (ostream &, const Node &);
};

typedef Node* NodePtr;

Node::Node() : data(0), link(nullptr) {}

Node::Node(const int &d) : data(d), link(nullptr){}

Node::Node(const Node &n) : data(n.data), link(n.link){}

int Node::getData() const {
    return data;
}

NodePtr Node::getLink() const {
    return link;
}

void Node::setData(const int &d) {
    data = d;
}

void Node::setLink(const NodePtr &p) {
    link = p;
}

ostream& operator << (ostream& out, const Node& n) {
	out << n.data;
	return out;
}

typedef Node* NodePtr;

class LinkedList {
private:
	NodePtr head;
public:
    //default constructor: assigns the head pointer member variable a nullptr value
	LinkedList(); 
    //copy constructor (deep copy)
	LinkedList(const LinkedList &); 
    //destructor (must delete all the nodes from the heap)
	~LinkedList(); 
    //Assignment operator (deep copy)
	LinkedList& operator= (const LinkedList &); 
    //return true if the length of the calling object is 0 and false otherwise
	bool isEmpty() const;
    //return the head member variable of the calling object
	NodePtr getHeadPtr() const; 
    //return the number of nodes in the calling object
	int getLength() const; 
    //as described in the supplementary material
	void head_insert(const int &); 
    //as described in the supplementary material
	NodePtr search_node(const int &) const; 
    //as described in the supplementary material
	void insert_after(const NodePtr &, const int &) const; 
    //as described in the supplementary material
	void remove_node(const NodePtr &); 
    //as described in the supplementary material
	void remove_node(const int &); 
    //as described in the supplementary material
	void remove_all(const int &); 
    //as described in the supplementary material
	void tail_insert(const int &); 
    //as described in the supplementary material
	void insert_before(const NodePtr &, const int &); 
    //Implemented for you
	friend ostream& operator << (ostream&, const LinkedList &); 
};

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(const LinkedList &l) {
    this->head = l.getHeadPtr();
    NodePtr nextNode = this->head->getLink();
    while (nextNode != nullptr) {
        nextNode = new Node(*nextNode->getLink());
    }
}

LinkedList::~LinkedList() {
    while (this->head->getLink() != nullptr) {
        NodePtr tempNode = this->head->getLink()->getLink();
		delete this->head->getLink();
		this->head->setLink(tempNode);
    }
    delete head;
    this->head = nullptr;
}

LinkedList& LinkedList::operator= (const LinkedList &l) {
    *this = LinkedList(l);
    return *this;
}

bool LinkedList::isEmpty() const {
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

NodePtr LinkedList::getHeadPtr() const{
    return this->head;
}

int LinkedList::getLength() const{
    int length = 0;
    NodePtr nextNode = this->head;
    if (nextNode != nullptr) {
        length++;
        while (this->head->getLink() != nullptr) {
            length++;
            nextNode = this->head->getLink();
        }
    }
    return length;
} 

void LinkedList::head_insert(const int &i) {
    NodePtr headNode = new Node(i);
    headNode->setLink(this->head);
    this->head = headNode;
}

NodePtr LinkedList::search_node(const int &i) const {
    NodePtr nodePointer = this->getHeadPtr();
    while (nodePointer->getLink() != nullptr) {
        if (nodePointer->getData() == i) {
            return nodePointer->getLink();
        } else {
            nodePointer = nodePointer->getLink();
        }
    }
    return nullptr;
}

void LinkedList::insert_after(const NodePtr &n, const int &i) const {
    NodePtr n2 = new Node(i);
    n2->setLink(n->getLink());
    n->setLink(n2);
}

void LinkedList::remove_node(const NodePtr &n) {
    // The node can be middle of two nodes,
    // if so then need to repoint the pointer to the node after it,
    // else repoint to NULL
    NodePtr previousNodePointer = this->head;
    while (previousNodePointer != n) {
        previousNodePointer = previousNodePointer->getLink();
    }

    NodePtr temp_link = nullptr;
    if (previousNodePointer->getLink()->getLink() != nullptr) {
        temp_link = previousNodePointer->getLink()->getLink();
    }
    delete previousNodePointer->getLink();
    previousNodePointer->setLink(temp_link);
}

void LinkedList::remove_node(const int &i) {
    NodePtr n = this->search_node(i);
    if (n != nullptr) {
        this->remove_node(n);
    }
}

void LinkedList::remove_all(const int &i) {
    NodePtr n = this->search_node(i);
    while (n != nullptr) {
        this->remove_node(n);
        n = this->search_node(i);
    } 
}

void LinkedList::tail_insert(const int &i) {
    NodePtr nodePointer = this->getHeadPtr();
    while (nodePointer->getLink() != nullptr) {
        nodePointer = nodePointer->getLink();
    }
    this->insert_after(nodePointer, i);
}

void LinkedList::insert_before(const NodePtr &n, const int &i) {
    NodePtr newNodePointer = new Node(i);
    newNodePointer->setLink(n);
    NodePtr previousNodePointer = this->getHeadPtr();
    while (previousNodePointer->getLink() != nullptr) {
        if (previousNodePointer->getLink() == n) {
            previousNodePointer->setLink(newNodePointer);
        } else {
            previousNodePointer = previousNodePointer->getLink();
        }
    }
}

ostream& operator << (ostream &out, const LinkedList &LL) {
	if (LL.isEmpty())
		out << "EMPTY LINKED LIST";
	else
	{
		NodePtr temp = LL.head;
		while(temp != nullptr)
		{
			out << *temp << " ";
			temp = temp->getLink();
		}
	}
	return out;
}

/////////////////////////////////////////////////////////////////////////////

LinkedList computeUnsignedBinary(const int &num, const int &bit_pattern_size) {
	/*
	 * This function first asserts that num is a non-negative integer and then
     * computes and stores the unsigned binary representation of num in
     * bit_pattern_size bits in a linked list object in such a way that the
     * head node stores the most significant bit while the tail node stores the
     * least significant bit. The function then returns the linked list object.
	 */

	assert(num >= 0);

	//Put your remaining code here
	LinkedList unsignedBinary;
	int tempNum = num;
	for (int i = 0; i < bit_pattern_size; i++) {
		unsignedBinary.tail_insert(tempNum%2);
		tempNum = tempNum / 2;
	}
	return unsignedBinary;
}

void flipBits(LinkedList &LL) {
	/*
	 * This function flips the bits stored in the nodes of the linked list object parameter LL.
	 * Assume the data in each node of the linked list is a bit (0 or 1).
	 */
	NodePtr tempNode = LL.getHeadPtr();
	LinkedList tempList;
	for (int i = 0; i < LL.getLength(); i++) {
		assert(tempNode->getData()!=0 || tempNode->getData()!=1);
		tempList.tail_insert(tempNode->getData()==0?1:0);
	}
	LL = tempList;
}

void reverse(LinkedList &LL) {
	/*
	 * This function reverses the linked list object parameter LL.
	 * 8 Reversing a linked list means the order of the nodes in the linked list is reversed.
	 */

	//Put your code here
	NodePtr lastNode, currentNode, nextNode;
	currentNode = LL.getHeadPtr();
	nextNode = currentNode->getLink();
	while (currentNode->getLink() != nullptr) {
		currentNode->setLink(lastNode->getLink());
		lastNode = currentNode;
		currentNode = nextNode;
		nextNode = currentNode->getLink();
	}
}

LinkedList operator + (const LinkedList &LL1, const LinkedList &LL2) {
	/*
	 * This function first asserts that the lengths of the linked list object parameters LL1 and LL2
	 * are equal and then adds the bits in LL1 with the bits in LL2 the way we add binary numbers in
	 * mathematics. The function stores the sum in a linked list object and then returns the linked
	 * list object. Assume the data in each node of the linked lists is a bit (0 or 1).
	 */

	assert(LL1.getLength() == LL2.getLength());

	//Put your remaining code here
	LinkedList reverseLL1 = LL1;
	reverse(reverseLL1);
	LinkedList reverseLL2 = LL2;
	reverse(reverseLL2);
	LinkedList reverseReturn;
	NodePtr reverseLL1Node = reverseLL1.getHeadPtr();
	NodePtr reverseLL2Node = reverseLL2.getHeadPtr();
	int reminder = 0;
	for (int i = 0; i < LL1.getLength(); i++) {
		if (reverseLL1Node->getData() + reverseLL1Node->getData() + reminder >= 2) {
			reverseReturn.tail_insert(reverseLL1Node->getData()+reverseLL1Node->getData()+reminder-2);
			reminder = 1;
		} else {
			reverseReturn.tail_insert(reverseLL1Node->getData()+reverseLL1Node->getData()+reminder);
			reminder = 0;
		}
		reverseLL1Node = reverseLL1Node->getLink();
		reverseLL2Node = reverseLL2Node->getLink();
	}
	reverse(reverseReturn);
	return reverseReturn;
}

void addOne(LinkedList &LL) {
	/*
	 * This function first asserts that the linked list object parameter LL is not empty
	 * and then adds 1 to the bits stored in the nodes of the linked list the way we add
	 * binary numbers in mathematics. Assume the data in each node of the linked list is
	 * a bit (0 or 1).
	 */

	assert(!LL.isEmpty());

	//Put your remaining code here
	LinkedList one;
	for (int i = 0; i < LL.getLength()-1; i++) {
		one.tail_insert(0);
	}
	one.tail_insert(1);
	LL = LL + one;
}

LinkedList computeTwosComplementBinary(const int &num, const int &bit_pattern_size)
{
	/*
	 * This function computes and stores the two's complement binary representation
	 * of num in bit_pattern_size bits in a linked list object in such a way that
	 * the head node stores the most significant bit while the tail node stores the
	 * least significant bit. The function then returns then linked list object.
	 */

	//Put your code here
	LinkedList signedBinary = computeUnsignedBinary(num, bit_pattern_size);
	if (num < 0) {
		flipBits(signedBinary);
		addOne(signedBinary);
	}
	return signedBinary;
}

int twosComplementBinaryToDecimal(const LinkedList &LL)
{
	/*
	 * This function first asserts that the linked list object parameter LL is not
	 * empty and then computes and returns the decimal value represented by the bits
	 * of the nodes of the linked list assuming two's complement binary representation.
	 * Assume the data in each node of the linked list is a bit (0 or 1).
	 */

	assert(!LL.isEmpty());

	//Put your remaining code here
	int decimal = 0;
	LinkedList tempLL = LL;
	NodePtr binary = LL.getHeadPtr();

	if (binary->getData() == 1) {
		int reminder = 0;
		reverse(tempLL);
		NodePtr tempLLBinary = tempLL.getHeadPtr();
		if (tempLLBinary->getData() == 0) {
			tempLLBinary->setData(1);
			reminder = 1;
		} else {
			tempLLBinary->setData(0);
		}
		for (int i = 1; i < tempLL.getLength(); i++) {
			if (tempLLBinary->getData() - reminder < 0) {
				tempLLBinary->setData(1);
				reminder = 1;
			} else {
				tempLLBinary->setData(tempLLBinary->getData() - reminder);
				reminder = 0;
			}
		}
		reverse(tempLL);
		flipBits(tempLL);
	}

	for (int i = tempLL.getLength(); i>0; i--) {
		decimal += binary->getData() * pow(2, i);
		binary = binary->getLink();
	}
	return decimal;
}


int selectComputation() {
	cout << "Select your computation" << endl;
	cout << "   1. Unsigned Binary Representation Computation" << endl;
	cout << "   2. Two's Complement Representation Computation" << endl;
	cout << "   3. Exit Program" << endl;
	int selection;
	cout << "Enter your selection (1, 2, or 3): ";
	cin >> selection;
	while (selection != 1 && selection != 2 && selection != 3) {
		cout << "Please enter a correct choice: ";
		cin >> selection;
	}
	return selection;
}

int main() {
	cout << "This program demonstrates the Linked List Data Structure in C++" << endl;
	cout << "Linked Lists will be used for numeric information representation using" << endl;
	cout << " *** Unsigned Binary Representation, and" << endl;
	cout << " *** Two's Complement Binary Representation" << endl << endl;
	cout << "In addition, the program demonstrates" << endl;
	cout << " *** Two's complement binary addition, and" << endl;
	cout << " *** Conversion from two's complement to decimal." << endl << endl;
	do {
		int selection = selectComputation();
		if (selection == 1) {
			int bit_pattern_size, num;
			cout << endl << "Enter a positive integer for the bit pattern size: ";
			cin >> bit_pattern_size;
			while (bit_pattern_size <= 0) {
				cout << "You must enter a positive integer. Enter again please: ";
				cin >> bit_pattern_size;
			}
			cout << "Enter a non-negative integer: ";
			cin >> num;
			while (num < 0) {
				cout << "You must enter a non-negative integer. Enter again please: ";
				cin >> num;
			}
			LinkedList LL = computeUnsignedBinary(num, bit_pattern_size);
			cout << "The unsigned binary representation of " << num << " in " << bit_pattern_size << " bit is " << LL << endl;
			cout << endl;
		} else if (selection == 2) {
			int bit_pattern_size, num1, num2;
			cout << endl << "Enter a positive integer for the bit pattern size: ";
			cin >> bit_pattern_size;
			while (bit_pattern_size <= 0) {
				cout << "You must enter a positive integer. Enter again please: ";
				cin >> bit_pattern_size;
			}
			cout << "Enter an integer: ";
			cin >> num1;
			LinkedList LL1 = computeTwosComplementBinary(num1, bit_pattern_size);
			cout << "The two's complement binary representation of " << num1 << " in " << bit_pattern_size << " bit is " << LL1 << endl;
			cout << endl;
			cout << "Enter a second integer: ";
			cin >> num2;
			LinkedList LL2 = computeTwosComplementBinary(num2, bit_pattern_size);
			cout << "The two's complement binary representation of " << num2 << " in " << bit_pattern_size << " bit is " << LL2 << endl;
			cout << endl;
			LinkedList LL3 = LL1 + LL2;
			cout << "The binary sum of " << LL1 << " and " << LL2 << " is " << LL3 << endl;
			int sum = twosComplementBinaryToDecimal(LL3);
			cout << "The integer value of the binary sum is " << sum << endl;
			if (sum == num1 + num2) {
				cout << "This is a correct result." << endl;
            } else {
				cout << "This is not correct result because our bit pattern is too small to store the result." << endl;
            }
		} else {
			break;
        }
		system("Pause");
		cout << endl << endl;
	} while (true);
	

	system("Pause");
	return 0;
}