/*this project should be reviewed, it will give a general understanding of different functions for linkedLists */
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string firstname;
    string lastname;
public:
    void setFirstName(string f)
    {
        firstname = f;
    }

    void setLastName(string l)
    {
        lastname = l;
    }

    string getFirstName() const
    {
        return firstname;
    }
    string getLastName() const
    {
        return lastname;
    }

    Student(string f, string l)
    {
        firstname = f;
        lastname = l;
    }

    Student()
    {
        firstname = "";
        lastname = "";
    }

};

class Nodetype : public Student {

public:
    Student data;
    Nodetype* next;

    Nodetype() {
        next = nullptr;
    }
};


class LinkedListException {
private:
    string message;
public:
    string what() {
        return message;
    }
    LinkedListException(string m) {
        message = m;
    }
};


class LinkedList : public Nodetype {
private:
    int size;
    Nodetype* first;
    Nodetype* last;
public:

    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    bool isEmpty() const
    {
        if (first == nullptr && last == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize() const
    {
        return size;
    }

    const void display()
    {
        Nodetype* currentNode = first;
        while (currentNode != NULL)
        {
            cout << currentNode->data.getFirstName() << " " << currentNode->data.getLastName() << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
    void addLast(Student studentData)
    {
        Nodetype* newNode = new Nodetype();
        newNode->data = studentData;

        if (isEmpty()) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    void addFirst(const Student studentData)
    {

        Nodetype* newNode = new Nodetype();
        newNode->data = studentData;

        if (isEmpty())
        {
            first = newNode;
            last = newNode;
        }
        else {
            newNode->next = first;
            first = newNode;
        }
        size++;
    }

    Student getFirst()
    {
        if (isEmpty()) {
            throw LinkedListException("The list is empty.");
        }
        else
        {
            return first->data;
        }
    }

    Student getLast() {
        if (isEmpty()) {
            throw LinkedListException("The list is empty.");
        }
        else
        {
            return last->data;
        }

    }

    void deleteFirst()
    {
        if (isEmpty()) {
            throw LinkedListException("The list is empty.");
        }
        else if (size == 1) {
            delete first;
            first = NULL;
            last = NULL;
            size--;
        }
        else {
            Nodetype* temp;
            temp = first; // we assign temp to be the first value in the list [4, 6 ,7 8]
            first = first->next; // we move the 1st value in the list to now point to the 2nd value in the list, 
                                 // [ 6,7,8] the variable first pointed to 4, but now it points to 6
            delete temp; // we delete temp, thus we remove the first value in the list, and we still retain every other value found within the list 
            size--;
        }
    }

    void deleteLast()
    {
        if (isEmpty()) {
            throw LinkedListException("The list is empty.");
        }
        else if (size == 1) {
            delete first;
            first = NULL;
            last = NULL;
            size--;
        }
        else
        {
            Nodetype* previous = first;
            while (previous->next != last)
            {
                previous = previous->next;
            }
            delete last;
            previous->next = NULL;
            last = previous;
            size--;
        }
    }

};




int main() {


    Student student1 = *new Student("Jamil", "Ali");
    Student student2 = *new Student("Naeema", "Ali");
    Student student3 = *new Student("Peter", "Parker");

    LinkedList linkedList = *new LinkedList();
    linkedList.addFirst(student1);
    linkedList.addFirst(student2);
    linkedList.addFirst(student3);
    linkedList.display();

    try {
        Student firstElement = linkedList.getFirst();
        cout << "First Element: " << firstElement.getFirstName() << " " << firstElement.getLastName() << endl;
    }

    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }

    try {
        Student lastElement = linkedList.getLast();
        cout << "Last Element : " << lastElement.getFirstName() << " " << lastElement.getLastName() << endl;
    }

    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }


    try {
        cout << "Remove first:" << endl;
        linkedList.deleteFirst();
        linkedList.display();
        cout << endl;
    }
    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }

    try {
        cout << "Remove last:" << endl;
        linkedList.deleteLast();
        linkedList.display();
        cout << endl;
    }
    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }
    

    try {
        cout << "Remove last:" << endl;
        linkedList.deleteLast();
        linkedList.display();
        cout << endl;
    }
    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }

    try {
        cout << "Remove last:" << endl;
        linkedList.deleteLast();
        linkedList.display();
    }
    catch (LinkedListException obj) {
        cout << obj.what() << endl;
    }


    return 0;

}