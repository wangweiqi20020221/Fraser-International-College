#include <iostream>
#include <cstring>

using namespace std;

class CMPT125_String {
private:
    //This will be the dynamic array to hold the characters of the CMPT125_String
	char *buffer;	
    //This will be number of characters in the CMPT125_String
	int size;

public:
	//Default Constructor
	CMPT125_String();

	//Non-default Constructors
	CMPT125_String(const char &ch);
    //cStr is a cstring
	CMPT125_String(const char *cStr);

	//Copy Constructor
	CMPT125_String(const CMPT125_String &s);

	//Destructor
	~CMPT125_String();

	//Assignment operators
	CMPT125_String& operator = (const CMPT125_String &s);
	CMPT125_String& operator = (const char &ch);
    //*cStr is a cstring
	CMPT125_String& operator = (const char *cStr);

	//Getter member functions
	int length() const;
	char& operator[](const int &index) const;

	//Setter member functions
	void append(const CMPT125_String &s);
	void append(const char &ch);
    //*cStr is a cstring
	void append(const char *cStr);

	//Operator member functions
	CMPT125_String operator + (const CMPT125_String &s) const;
	CMPT125_String operator + (const char &ch) const;
    //*cStr is a cstring
	CMPT125_String operator + (const char *cStr) const;
	CMPT125_String& operator += (const CMPT125_String &s);
	CMPT125_String& operator += (const char &ch);
    //*cStr is a cstring
	CMPT125_String& operator += (const char *cStr); 
	bool operator == (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator == (const char *cStr) const; 
	bool operator != (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator != (const char *cStr) const; 
	bool operator < (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator < (const char *cStr) const; 
	bool operator > (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator > (const char *cStr) const; 
	bool operator <= (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator <= (const char *cStr) const; 
	bool operator >= (const CMPT125_String &s) const;
    //*cStr is a cstring
	bool operator >= (const char *cStr) const; 
	
	//Friend Functions (for operators)
	friend CMPT125_String operator + (const char &ch, const CMPT125_String &s);
    //*cStr is a cstring
	friend CMPT125_String operator + (const char *cStr, const CMPT125_String &s); 
    //*cStr a cstring
	friend bool operator == (const char *cStr, const CMPT125_String &s); 
    //*cStr is a cstring
	friend bool operator != (const char *cStr, const CMPT125_String &s); 
    //*cStr is a cstring
	friend bool operator < (const char *cStr, const CMPT125_String &s); 
    //*cStr is a cstring
	friend bool operator > (const char *cStr, const CMPT125_String &s); 
    //*cStr is a cstring
	friend bool operator <= (const char *cStr, const CMPT125_String &s); 
    //*cStr is a cstring
	friend bool operator >= (const char *cStr, const CMPT125_String &s); 
	friend ostream& operator << (ostream& outputStream, const CMPT125_String &s);
	friend istream& operator >> (istream& inputStream, CMPT125_String &s);
};

//Explanation of the member and friend functions
CMPT125_String::CMPT125_String() {
	/*
	 * This function constructs a default CMPT125_String object whose size is initialized
	 * to zero and whose pointer member variable is initialized to nullptr.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	this->size = 0;
	this->buffer = nullptr;
}

CMPT125_String::CMPT125_String(const char &ch) {
	/*
	 * This function constructs a non-default CMPT125_String whose size is 1 and 
	 * that contains one character (which is the argument).
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	this->size = 1;
	this->buffer = new char[size];
	this->buffer[0] = ch;
}

CMPT125_String::CMPT125_String(const char *cStr) {
	/*
	 * This function constructs a non-default CMPT125_String whose size is the number
	 * of characters in cStr and that contains all the characters of the argument.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	//*cStr is a cstring 
    //strlen is a built-in function that returns the length of a cstring
	int n = strlen(cStr); 
	this->size = n;
	if (this->size == 0) {
		this->buffer = nullptr;
	} else {
		this->buffer = new char[this->size];
		for (int i = 0; i < this->size; i++) {
			this->buffer[i] = cStr[i];
		}
	}
}

CMPT125_String::CMPT125_String(const CMPT125_String &s) {
	/*
	 * This function constructs a CMPT125_String object which is a copy of the argument s
	 */

    // this->buffer = s.buffer; is not a copy, it only changes the pointer of this->buffer to s.buffer.
	// If s.buffer deleted, this->buffer would be deleted; if this->buffer deleted, s.buffer would be
	// deleted. So we need to copy s.buffer to this->buffer word by word.
	char *new_buffer = new char[s.length()];
	for (int i = 0; i < s.length(); i++) {
		new_buffer[i] = s.buffer[i];
	}
	this->buffer = new_buffer;
	this->size = s.size;
}

CMPT125_String::~CMPT125_String() {
	/*
	 * This function destructs a CMPT125_String object. That is it deletes its buffer and 
	 * assigns the buffer a nullptr value and assigns size 0.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	if (this->size > 0) {
		delete[] this->buffer;
		this->buffer = nullptr;
		this->size = 0;
	}
}

CMPT125_String& CMPT125_String::operator = (const CMPT125_String &s) {
	/*
	 * This function assigns a copy of the argument s to the calling object
	 */

    // this->buffer = s.buffer; is not a copy, it only changes the pointer of this->buffer to s.buffer.
	// If s.buffer deleted, this->buffer would be deleted; if this->buffer deleted, s.buffer would be
	// deleted. So we need to copy s.buffer to this->buffer word by word.
	char *new_buffer = new char[s.length()];
	for (int i = 0; i < s.length(); i++) {
		new_buffer[i] = s.buffer[i];
	}
	delete[] this->buffer;
	this->buffer = new_buffer;
	this->size = s.size;
    return *this;
}

CMPT125_String& CMPT125_String::operator = (const char &ch) {
	/*
	 * This function assigns a copy of a CMPT125_String object constructed from the character argument
	 * to the calling object
	 */

    *this->buffer = ch;
    this->size = 1;
    return *this;
}

CMPT125_String& CMPT125_String::operator = (const char *cStr) {
	/*
	 * This function assigns a copy of a CMPT125_String object constructed from the cstring argument
	 * to the calling object
	 */

	//*cStr is a cstring

    // Can't assigned the value of cStr to the pointer buffer like *this->buffer = cStr, because cStr
    // is a const char while buffer is not, coder might change the value of cStr by the non-const
    // pointer buffer. To avoid this, complier asked the type of buffer an also const char.
    //
    // Can't use *this->buffer = *cStr as well, this won't cause an error, but *cStr would only
    // contains the first lettere of the char. Actually "This is cool" is an char arrey.
    //
    // Therefore, the only way is to use strcpy.
	//
    // strcpy(this->buffer, cStr);
    // this->size = strlen(cStr);
    // return *this;

	// Okay, I found Prof. Yonas has already done the codes in the constructor function
	int n = strlen(cStr); 
	this->size = n;
	if (this->size == 0) {
		this->buffer = nullptr;
	} else {
		this->buffer = new char[this->length()];
		for (int i = 0; i < this->length(); i++) {
			this->buffer[i] = cStr[i];
		}
	}
	// My work here
	return *this;
}

int CMPT125_String::length() const {
	/*
	 * This function returns the size
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	return this->size;
}

char& CMPT125_String::operator[](const int &index) const {
	/*
	 * This function returns the character at the given index of the calling object.
	 * If the index is out of the valid bounds, then a runtime error occurs.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	if (index < 0 || index >= this->size) {
		cout << "ERROR! Index out of bounds occured." << endl;
		abort();
	}
	return this->buffer[index];
}

void CMPT125_String::append(const CMPT125_String &s) {
	/*
	 * This function appends all the characters of the argument s to the calling object.
	 */
	char *new_buffer = new char[this->length()+s.length()];
	for (int i = 0; i < this->length(); i++) {
		new_buffer[i] = this->buffer[i];
	}
	for (int j = 0; j < s.length(); j++) {
		new_buffer[this->length()+j] = s[j];
	}
	delete[] this->buffer;
	this->buffer = new_buffer;
	this->size += s.length();
}

void CMPT125_String::append(const char &ch) {
	/*
	 * This function appends the character argument to the calling object
	 */

	CMPT125_String str2(ch);
	this->append(str2);
}

void CMPT125_String::append(const char *cStr) { 
	/*
	 * This function appends all the characters of the cstring argument cStr to the calling object.
	 */

	//*cStr is a cstring 
	CMPT125_String str2(cStr);
	this->append(str2);
}

CMPT125_String CMPT125_String::operator + (const CMPT125_String &s) const {
	/*
	 * This function returns a CMPT125_String object constructed from all the characters of the
	 * calling object followed by the characters of the argument s
	 */

	CMPT125_String str3(*this);
	str3.append(s);
	return str3;
}

CMPT125_String CMPT125_String::operator + (const char &ch) const {
	/*
	 * This function returns a CMPT125_String object constructed from all the characters of the
	 * calling object followed by the character argument ch
	 */

	CMPT125_String str3(*this);
	str3.append(ch);
	return str3;
}

CMPT125_String CMPT125_String::operator + (const char *cStr) const {
	/*
	 * This function returns a CMPT125_String object constructed from all the characters of the
	 * calling object followed by the characters of the cstring argument cStr
	 */

	//*cStr is a cstring 
	CMPT125_String str3(*this);
	str3.append(cStr);
	return str3;
}

CMPT125_String& CMPT125_String::operator += (const CMPT125_String &s) {
	/*
	 * This function appends the characters of s to the calling object and then
	 * returns the calling object
	 */

	this->append(s);
	return *this;
}

CMPT125_String& CMPT125_String::operator += (const char &ch) {
	/*
	 * This function appends the character ch to the calling object and then
	 * returns the calling object
	 */

	this->append(ch);
	return *this;
}

CMPT125_String& CMPT125_String::operator += (const char *cStr) { 
	/*
	 * This function appends the characters of the cstring argument cStr
	 * to the calling object and then returns the calling object
	 */

	//*cStr is a cstring
	this->append(cStr);
	return *this;
}

bool CMPT125_String::operator == (const CMPT125_String &s) const {
	/*
	This function tests if the calling object is equal to the argument s
	NOTE:- Two CMPT125_String are equal if they have the same length and characters of the
	calling object are equal to the characters of the argument s at the same indexes.
	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/

	if (this->size != s.size) {
		return false;
	} else {
		for (int i = 0; i < this->size; i++) {
			if (this->buffer[i] != s[i]) {
				return false;
			}
		}
		return true;
	}
}

bool CMPT125_String::operator == (const char *cStr) const { 
	/*
	 * This function tests if the calling object is equal to the cstring argument cStr.
	 * In other words, this function tests if the calling object is equal to a CMPT125_String object 
	 * constructed from the cstring argument
	 */

	//*cStr is a cstring
	CMPT125_String s2(cStr);
	if (*this == s2) {
		return true;
	} else {
		return false;
	}
}

bool CMPT125_String::operator != (const CMPT125_String &s) const {
	/*
	 * This function tests if the calling object is not equal to the argument s
	 */

	if(*this == s) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator != (const char *cStr) const { 
	/*
	 * This function tests if the calling object is not equal to the string argument cStr
	 */

	//*cStr is a cstring 
	if(*this == cStr) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator < (const CMPT125_String &s) const {
	/*
	 * This function tests if the calling object is less than the argument s
	 * NOTE:- Given two CMPT125_String objects s1 and s2, we compare them as follows:
	 * 	Step 1. Find the smallest valid index k such that s1[k] IS NOT EQUAL TO s2[k]
	 * 	Step 2. If such an index k is found, then
	 *		2.1 We say s1 < s2 if s1[k] < s2[k]
	 *		2.2 Otherwise s1 > s2
	 *	Step 3. If such an index k is not found, then
	 *		3.1 We say s1 < s2 if the length of s1 is less than the length of s2
	 *		3.2 We say s1 > s2 if the length of s1 is greater than the length of s2
	 *		3.3 We say s1 == s2 if the length of s1 is equal to the length of s2.
	 */

	int shorter_length;
	if (this->length() <= s.length()) {
		shorter_length = this->length();
	} else {
		shorter_length = s.length();
	}
	for (int k = 0; k < shorter_length; k++) {
		if (this->buffer[k] < s.buffer[k]) {
			return true;
		} else if (this->buffer[k] > s.buffer[k]) {
			return false;
		}
	}
	if (this->length() < s.length()) {
		return true;
	} else {
		return false;
	}
}

bool CMPT125_String::operator < (const char *cStr) const { 
	/*
	 * This function tests if the calling object is less than the cstring cStr
	 */

	//*cStr is a cstring
	CMPT125_String s2(cStr);
	if (*this < s2) {
		return true;
	} else {
		return false;
	}
}

bool CMPT125_String::operator > (const CMPT125_String &s) const {
	/*
	 * This function tests if the calling object is greater than the argument s
	 */

	if (*this < s || *this == s) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator > (const char *cStr) const {
	/*
	 * This function tests if the calling object is greater than the cstring cStr
	 */

	//*cStr is a cstring 
	if (*this < cStr || *this == cStr) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator <= (const CMPT125_String &s) const {
	/*
	 * This function tests if the calling object is less than or equal to the argument s
	 */

	if (*this > s) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator <= (const char *cStr) const { 
	/*
	 * This function tests if the calling object is less than or equal to the cstring argument cStr
	 */

	//*cStr is a cstring
	if (*this > cStr) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator >= (const CMPT125_String &s) const {
	/*
	 * This function tests if the calling object is greater than or equal to the argument s
	 */

	if (*this < s) {
		return false;
	} else {
		return true;
	}
}

bool CMPT125_String::operator >= (const char *cStr) const { 
	/*
	 * This function tests if the calling object is greater than or equal to the cstring argument cStr
	 */

	//*cStr is a cstring 
	if (*this < cStr) {
		return false;
	} else {
		return true;
	}
}

CMPT125_String operator + (const char &ch, const CMPT125_String &s) {
	/*
	 * This function returns a CMPT125_String object constructed from the character argument ch followed 
	 * by the characters of s
	 */

	CMPT125_String s1(ch);
	return s1 + s;
}

CMPT125_String operator + (const char *cStr, const CMPT125_String &s) {
	/*
	 * This function returns a CMPT125_String object constructed from the characters of the cstring
	 * argument cStr followed by the characters of s
	 */

	//*cStr is a cstring
	CMPT125_String s1(cStr);
	return s1 + s;
}

bool operator == (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is equal to s
	 */

	//*cStr a cstring
	return s == cStr;
}

bool operator != (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is not equal to s
	 */

	//*cStr is a cstring
	return s != cStr;
}

bool operator < (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is less than s
	 */

	//*cStr is a cstring
	return s > cStr;
}

bool operator > (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is greater than s
	 */

	//*cStr is a cstring
	return s < cStr;
}

bool operator <= (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is less than or equal 
	 * to s
	 */

	//*cStr is a cstring
	return s >= cStr;
}

bool operator >= (const char *cStr, const CMPT125_String &s) { 
	/*
	 * This function tests if the cstring argument cStr is greater than or equal to s
	 */

	//*cStr is a cstring
	return s <= cStr;
}

ostream& operator << (ostream& out, const CMPT125_String &s) {
	/*
	 * This function prints the characters in the CMPT125_String object.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	for (int i = 0; i < s.length(); i++)
		out << s.buffer[i];
	return out;
}

istream& operator >> (istream& in, CMPT125_String &s) {
	/*
	 * This function is designed to read ANY number of characters from the user.Reading will stop 
	 * when the user presses the Enter Key. In order to achieve this, we will read one character at a 
	 * time until end of line character ('\n') is read.
	 * This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	 */

	s.~CMPT125_String();
	char c;
	while (true)
	{
		in.get(c);
		if (c == '\n')
			break;
		else
			s.append(c);
	}
	return in;
}

//In addition you need to define the following non-member and non-friend functions
int findCharIndex(const CMPT125_String &s, const char &ch) {
	/*
	 * This function takes a CMPT125_String and a character arguments and returns the smallest valid
	 * index of the CMPT125_String argument such that the character of the CMPT125_String argument at 
	 * that index is equal to the character argument. If no such an index is found, then this function 
	 * must return -1.
	 */

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ch) {
			return i;
		}
	}
	return -1;
}

int reverseFindCharIndex(const CMPT125_String &s, const char &ch) {
	/*
	 * This function takes a CMPT125_String and a character arguments and returns the largest valid
	 * index of the CMPT125_String argument such that the character of the CMPT125_String argument at 
	 * that index is equal to the character argument. If no such an index is found, then this function 
	 * must return -1.
	 */

	for (int i = s.length()-1; i > -1; i--) {
		if (s[i] == ch) {
			return i;
		}
	}
	return -1;
}

int countChar(const CMPT125_String &s, const char &ch) {
	/*
	 * This function takes a CMPT125_String and a character arguments and returns the number of times the
	 * character argument is found in the CMPT125_String argument.
	 */

	int counter = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ch) {
			counter++;
		}
	}
	return counter;
}

CMPT125_String getSubString(const CMPT125_String &s, const int &startIndex, const int &length) {
	/*
	 * This function takes a CMPT125_String, a start index, and a length arguments and returns a
	 * CMPT125_String object with as many as length characters constructed from the characters of the
	 * CMPT125_String argument starting from the given start index. If there are no enough characters
	 * to copy as many as length characters from the CMPT125_String argument, then ONLY the available
	 * characters up to the end of the CMPT125_String argument are copied and a CMPT125_String with a
	 * shorter length is returned.
	 * 
	 * The returned object is known as a substring of the CMPT125_String argument.
	 */

	CMPT125_String new_str;
	int endIndex = s.length();
	if (startIndex+length <= s.length()) {
		endIndex = startIndex + length;
	}
	for (int i = startIndex; i < endIndex; i++) {
		new_str.append(s[i]);
	}
	return new_str;
}

bool isSubString(const CMPT125_String &s1, const CMPT125_String &s2) {
	/*
	 * This function takes two CMPT125_String objects s1 and s2 as arguments and returns true if there
	 * exists a substring of s2 that is equal to s1; otherwise it returns false.
	 */

	for (int index_s2 = 0; index_s2 < s2.length()-s1.length()+1; index_s2++) {
		if (s1[0] == s2[index_s2]) {
			for (int index_s1 = 0; index_s1 < s2.length(); index_s1++) {
				if (s1[index_s1] != s2[index_s2+index_s1]) {
					break;
				}
				if (index_s1 == s1.length()-1) {
					return true;
				}
			}
		}
	}
	return false;
}

CMPT125_String getReversedString(const CMPT125_String &s) {
	/*
	 * This function takes a CMPT125_String argument and returns a CMPT125_String object constructed from
	 * the characters of the CMPT125_String argument in reverse order.
	 */

	CMPT125_String new_str;
	for (int i = s.length()-1; i > -1; i--) {
		new_str.append(s[i]);
	}
	return new_str;
}

void removeChar(CMPT125_String &s, const char &ch) {
	/*
	 * This function takes a CMPT125_String and a character arguments and removes all the characters of the
	 * CMPT125_String argument that is equal to the character argument from the CMPT125_String argument.
	 */

	CMPT125_String new_str;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ch) {
			new_str.append(s[i]);
		}
	}
	s = new_str;
}

void replaceChar(CMPT125_String &s, const char &ch1, const char &ch2) {
	/*
	 * This function takes a CMPT125_String and two characters named ch1 and ch2 (in that order) as
	 * arguments and replaces every character in the CMPT125_String argument that is equal to ch1 by
	 * the character ch2.
	 */

	CMPT125_String new_str;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ch1) {
			new_str.append(s[i]);
		} else {
			new_str.append(ch2);
		}
	}
	s = new_str;
}

//Test Program
int main() {
	//Test default constructor and length member functions
	CMPT125_String s1;
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test non-default constructor and length member functions
	CMPT125_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.length() << endl;

	//Test non-default constructor and length member functions
	CMPT125_String s3 = "CMPT 125";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test copy constructor and length member functions
	CMPT125_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test destructor and length member functions
	s4.~CMPT125_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test indexing operator member function
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'a';
	cout << "s4[2] is " << s4[2] << endl;
	s4[3] = 't';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test append and length member functions
	s1.append(s4);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test append and length member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test append and length member functions
	s3.append("2023-02");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test findCharIndex non-member function
	char ch = '0';
	int k = findCharIndex(s3, ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = findCharIndex(s3, 'm');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test reverseFindCharIndex non-member function
	ch = '2';
	k = reverseFindCharIndex(s3, ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = reverseFindCharIndex(s3, 'm');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	
	//Test countChar non-member function
	ch = '2';
	k = countChar(s1, ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	//Test getSubString non-member function
	s1 = getSubString(s3, 10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	
	//Test isSubString non-member function
	if (isSubString(s1, s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902023-09010190";
	if (isSubString(s1, s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902023-029010190";
	if (isSubString(s1, x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;
	
	//Test getReversedString non-member function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	CMPT125_String rev = getReversedString(s1);
	cout << "The reverse of \"" << s1 << "\" is \"" << rev << "\"" << endl;
	
	//Test removeChar non-member function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	removeChar(s1, ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "22222222222222222";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	removeChar(s3, ch);
	cout << "\"" << s3 << "\"" << endl;
	
	//Test replaceChar non-member function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	replaceChar(s2, '1', '5');
	cout << s2 << endl;

	//Test + operator member function
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	//Test += operatror member function
	s2 = "Test";
	cout << "s1 is \"" << s1 <<"\", s2 is \"" << s2 << "\", and s3 is \"" << s3 << "\"" << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl; 
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	//Test relational operators member functions
	s1 = "Test1";
	s2 = "";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	//Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	//Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"TeSt2\" < s1 is " << ("TeSt2" < s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"TeSt2\" >= s1 is " << ("TeSt2" >= s1) << endl;

	//Test input streaming operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;

	system("pause");
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// Sample Run Output
// -----------------
// s1 is "" and its length is 0
// s2 is "Y" and its length is 1
// s3 is "CMPT 125" and its length is 8
// s4 is "CMPT 125" and its length is 8
// s4 is "" and its length is 0
// s4 is "Y" and its length is 1
// s4 is "A" and its length is 1
// s4 is "This is cool" and its length is 12
// s4[2] is i
// s4[2] is a
// s4 is "That is cool" and its length is 12
// s1 is "That is cool" and its length is 12
// s3 is "CMPT 125 " and its length is 9
// s3 is "CMPT 125 2023-02" and its length is 16
// The first index of '0' in "CMPT 125 2023-02" is 10
// The first index of 'm' in "CMPT 125 2023-02" is -1
// The last index of '2' in "CMPT 125 2023-02" is 15
// The last index of 'm' in "CMPT 125 2023-02" is -1
// '2' appears 0 times in "That is cool"
// s1 is "023" and its length is 3
// s1 is "023-0" and its length is 5
// s1 is "023-02" and its length is 6
// "023-02" is a substring of "CMPT 125 2023-02"
// "023-02" is not a substring of "01902023-09010190"
// "023-02" is a substring of "01902023-029010190"
// s1 is "023-02" and its length is 6
// The reverse of "023-02" is "20-320"
// After removing all the '2' characters from "023-02", we get "03-0"
// After removing all the '2' characters from "22222222222222222", we get ""
// After replacing 1 by 5 from "01902023-09010190", we get 05902023-09050590
// s1 is "03-0", s3 is "" and s1 + s3 is "03-0"
// s1 is "03-0 and s1 + "yonas" is "03-0yonas
// s1 is "03-0 and s1 + 'Y' is "03-0Y
// s1 is "03-0", s2 is "Test", and s3 is ""
// After s3 = s1 += s2, we get s1 is 03-0Test, s2 is Test, and s3 is 03-0Test
// s2 is "Test". After s2 += "FIC", we get "TestFIC"
// s2 is "TestFIC". After s2 += '!', we get "TestFIC!"
// s1 is "Test1", s2 is "" and s1 == s2 is 0
// s1 is "Test1", s2 is "" and s1 != s2 is 1
// s1 is "Test1", s2 is "" and s1 > s2 is 1
// s1 is "Test1", s2 is "" and s1 < s2 is 0
// s1 is "Test1", s2 is "" and s1 >= s2 is 1
// s1 is "Test1", s2 is "" and s1 <= s2 is 0
// "Yonas" + "Test1" is "YonasTest1"
// 'y' + "Test1" is "yTest1"
// s1 is "Test1" and "Test2" == s1 is 0
// s1 is "Test1" and "Test2" != s1 is 1
// s1 is "Test1" and "TeSt2" < s1 is 1
// s1 is "Test1" and "Test2" > s1 is 1
// s1 is "Test1" and "Test2" <= s1 is 0
// s1 is "Test1" and "TeSt2" >= s1 is 0
// Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): CMPT 125 is fun!
// You entered "CMPT 125 is fun!"
// Press any key to continue . . .