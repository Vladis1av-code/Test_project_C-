#include <iostream>
#include "ConsoleApplication21.cpp"
#include "Source.cpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    UserPtr userPtr(new User("Владислав Ващенко", 30));
   cout << "Имя пользователя: " << userPtr->getName() << endl;
   cout << "Возраст пользователя: " << userPtr->getAge() << endl;
    UserPtr anotherUserPtr = move(userPtr); 
   cout << "После перемещения unique() " << userPtr.unique() << " (should be true)" << endl;
    cout << "После перемещения unique() " << anotherUserPtr.unique() << " (should be true)" << endl;
    SharedUserPtr sharedUserPtr(new User("Jane Doe", 25));
 cout << "Имя пользователя: " << sharedUserPtr->getName() << endl;
    cout << "Возраст пользователя: " << sharedUserPtr->getAge() << endl;
   cout << "Количество ссылок: " << sharedUserPtr.use_count() << " (should be 1)" << endl;
    SharedUserPtr anotherSharedPtr(sharedUserPtr);
    cout << "Имя пользователя (otherSharedPtr): " << anotherSharedPtr->getName() << endl;
    cout << "Количество ссылок после копирования: " << sharedUserPtr.use_count() << " (should be 2)" << endl;

 
}