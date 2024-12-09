/*1)
template <typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}

    virtual ~List() {
        clear();
    }

    void insert(const T& value) {
        head = new ListCell(value, head);
        if (tail == nullptr) {
            tail = head;
        }
        ++theCount;
    }

    void append(const T& value) {
        ListCell* newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        }
        else {
            head = newCell;  
        }
        tail = newCell;
        ++theCount;
    }

    int is_present(const T& value) const {
        ListCell* current = head;
        while (current) {
            if (current->val == value) {
                return 1;  
            }
            current = current->next;
        }
        return 0;  
    }

    int is_empty() const {
        return head == nullptr;  
    }

    int count() const {
        return theCount;  
    }

    void clear() {
        ListCell* current = head;
        while (current) {
            ListCell* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        theCount = 0;
    }

private:
    class ListCell {
    public:
        ListCell(const T& value, ListCell* cell = nullptr)
            : val(value), next(cell) {}

        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};
*/
/*2)
#include <iostream>

class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}

    virtual ~List() {
        clear();
    }

    void insert(int value) {
        head = new ListCell(value, head);
        if (tail == nullptr) {
            tail = head;
        }
        ++theCount;
    }

    void append(int value) {
        ListCell *newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        } else {
            head = newCell;  
        }
        tail = newCell;
        ++theCount;
    }

    int is_present(int value) const {
        ListCell *current = head;
        while (current) {
            if (current->val == value) {
                return 1;  
            }
            current = current->next;
        }
        return 0;  
    }

    int is_empty() const {
        return head == nullptr;  
    }

    int count() const {
        return theCount;  
    }

    void clear() {
        ListCell *current = head;
        while (current) {
            ListCell *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        theCount = 0;
    }

private:
    class ListCell {
    public:
        ListCell(int value, ListCell *cell = nullptr) 
            : val(value), next(cell) {}

        int val;
        ListCell *next;
    };

    ListCell *head;
    ListCell *tail;
    int theCount;
};

int main() {
    List list;

    list.insert(10);
    list.append(20);
    list.append(30);
    
    std::cout << "List contains 20? " << (list.is_present(20) ? "Yes" : "No") << std::endl;
    std::cout << "List contains 40? " << (list.is_present(40) ? "Yes" : "No") << std::endl;
    
    std::cout << "Number of elements: " << list.count() << std::endl;
    std::cout << "Is the list empty? " << (list.is_empty() ? "Yes" : "No") << std::endl;

    list.clear();
    std::cout << "Number of elements after clearing: " << list.count() << std::endl;

    return 0;
}
*/
/*3)
#include <iostream>
#include <string>


class Cat {
public:
    Cat(const std::string& name) : name(name) {}
    void speak() const {
        std::cout << name << " says Meow!" << std::endl;
    }
private:
    std::string name;
};



#include <iostream>
#include <string>

class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}

    virtual ~List() {
        clear();
    }

    void insert(int value) {
        head = new ListCell(value, head);
        if (tail == nullptr) {
            tail = head;
        }
        ++theCount;
    }

    void append(int value) {
        ListCell* newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        }
        else {
            head = newCell;  
        }
        tail = newCell;
        ++theCount;
    }

    int is_present(int value) const {
        ListCell* current = head;
        while (current) {
            if (current->val == value) {
                return 1;  
            }
            current = current->next;
        }
        return 0;  
    }

    int is_empty() const {
        return head == nullptr;  
    }

    int count() const {
        return theCount;  
    }

    void clear() {
        ListCell* current = head;
        while (current) {
            ListCell* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        theCount = 0;
    }

private:
    class ListCell {
    public:
        ListCell(int value, ListCell* cell = nullptr)
            : val(value), next(cell) {}

        int val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

class Cat {
public:
    Cat(const std::string& name) : name(name) {}
    void speak() const {
        std::cout << name << " says Meow!" << std::endl;
    }
private:
    std::string name;
};

int main() {
    
    List stringList;   
    List catList;      
    List intList;      

    
    intList.append(10);
    intList.append(20);
    intList.append(30);

    return 0;
}
*/
/*6)
#include <iostream>
#include <string>
using namespace std;

class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}
    virtual ~List() {
        clear();
    }

    void append(int value) {
        ListCell *newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        } else {
            head = newCell;  
        }
        tail = newCell;
        ++theCount;
    }

    void clear() {
        ListCell *current = head;
        while (current) {
            ListCell *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        theCount = 0;
    }

    bool is_empty() const {
        return head == nullptr;  
    }

    int count() const {
        return theCount;  
    }

    friend bool operator==(const List& lhs, const List& rhs) {
        if (lhs.theCount != rhs.theCount) {
            return false;  
        }

        ListCell* currentLHS = lhs.head;
        ListCell* currentRHS = rhs.head;

        while (currentLHS && currentRHS) {
            if (currentLHS->val != currentRHS->val) {
                return false;  
            }
            currentLHS = currentLHS->next;
            currentRHS = currentRHS->next;
        }
        return true;  

private:
    class ListCell {
    public:
        ListCell(int value, ListCell* cell = nullptr)
            : val(value), next(cell) {}

        int val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};

int main() {
    List list1;
    List list2;

    list1.append(10);
    list1.append(20);
    list1.append(30);

    list2.append(10);
    list2.append(20);
    list2.append(30);

    if (list1 == list2) {
        cout << "Lists are equal!" << endl;
    } else {
        cout << "Lists are not equal!" << endl;
    }

    list2.append(40);

    if (list1 == list2) {
        cout << "Lists are equal!" << endl;
    } else {
        cout << "Lists are not equal!" << endl;
    }

    return 0;
}
*/
/*7)
#include <iostream>
using namespace std;

class List {
public:
    List() : head(nullptr), tail(nullptr), theCount(0) {}
    virtual ~List() {
        clear();
    }

    void append(int value) {
        ListCell* newCell = new ListCell(value);
        if (tail) {
            tail->next = newCell;
        } else {
            head = newCell;  
        }
        tail = newCell;
        ++theCount;
    }

    void clear() {
        ListCell* current = head;
        while (current) {
            ListCell* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        theCount = 0;
    }

    bool is_empty() const {
        return head == nullptr;  
    }

    int count() const {
        return theCount; 
    }

   
    friend bool operator==(const List& lhs, const List& rhs) {
        // Перевірка на кількість елементів у списках
        if (lhs.theCount != rhs.theCount) {
            return false;  
        }

        
        ListCell* currentLHS = lhs.head;
        ListCell* currentRHS = rhs.head;

        while (currentLHS && currentRHS) {
            if (currentLHS->val != currentRHS->val) {
                return false;  
            }
            currentLHS = currentLHS->next;
            currentRHS = currentRHS->next;
        }
        return true;  
    }

private:
    class ListCell {
    public:
        ListCell(int value, ListCell* cell = nullptr)
            : val(value), next(cell) {}

        int val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;
};


int main() {
    List list1;
    List list2;

    
    list1.append(10);
    list1.append(20);
    list1.append(30);

    
    list2.append(10);
    list2.append(20);
    list2.append(30);

    
    if (list1 == list2) {
        cout << "Lists are equal!" << endl;
    } else {
        cout << "Lists are not equal!" << endl;
    }

   
    list2.append(40);

   
    if (list1 == list2) {
        cout << "Lists are equal!" << endl;
    } else {
        cout << "Lists are not equal!" << endl;
    }

    return 0;
}
*/
/*9)
#include <iostream>
using namespace std;

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;  
    a = b;        
    b = temp;     
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    float a = 1.1f, b = 2.2f;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValues(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}
*/