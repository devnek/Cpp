// virtpers.cpp
// virtual functions with person class

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class person // person class
{
protected:
    char name[40];

public:
    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    void putName()
    {
        cout << "Name is: " << name << endl;
    }

    virtual void getData() = 0;           // pure virtual function
    virtual bool isOutstanding() = 0;     // pure virtual function
};

////////////////////////////////////////////////////////////////
class student : public person // student class
{
private:
    float gpa; // grade point average

public:
    void getData() override
    {
        person::getName();
        cout << "Enter student's GPA: ";
        cin >> gpa;
    }

    bool isOutstanding() override
    {
        return (gpa > 3.5);
    }
};

////////////////////////////////////////////////////////////////
class professor : public person // professor class
{
private:
    int numPubs; // number of papers published

public:
    void getData() override
    {
        person::getName();
        cout << "Enter number of professor's publications: ";
        cin >> numPubs;
    }

    bool isOutstanding() override
    {
        return (numPubs > 100);
    }
};

////////////////////////////////////////////////////////////////
int main()
{
    person* persPtr[100]; // array of pointers to persons
    int n = 0;            // number of persons on list
    char choice;

    do {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;

        if (choice == 's')
            persPtr[n] = new student;
        else
            persPtr[n] = new professor;

        persPtr[n++]->getData();

        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    for (int j = 0; j < n; j++) {
        persPtr[j]->putName();
        if (persPtr[j]->isOutstanding())
            cout << "This person is outstanding\n";
    }

    return 0;
}
