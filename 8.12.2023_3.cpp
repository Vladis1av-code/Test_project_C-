#include <iostream>
#include "ConsoleApplication21.cpp"
#include "Source.cpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    UserPtr userPtr(new User("��������� �������", 30));
   cout << "��� ������������: " << userPtr->getName() << endl;
   cout << "������� ������������: " << userPtr->getAge() << endl;
    UserPtr anotherUserPtr = move(userPtr); 
   cout << "����� ����������� unique() " << userPtr.unique() << " (should be true)" << endl;
    cout << "����� ����������� unique() " << anotherUserPtr.unique() << " (should be true)" << endl;
    SharedUserPtr sharedUserPtr(new User("Jane Doe", 25));
 cout << "��� ������������: " << sharedUserPtr->getName() << endl;
    cout << "������� ������������: " << sharedUserPtr->getAge() << endl;
   cout << "���������� ������: " << sharedUserPtr.use_count() << " (should be 1)" << endl;
    SharedUserPtr anotherSharedPtr(sharedUserPtr);
    cout << "��� ������������ (otherSharedPtr): " << anotherSharedPtr->getName() << endl;
    cout << "���������� ������ ����� �����������: " << sharedUserPtr.use_count() << " (should be 2)" << endl;

 
}