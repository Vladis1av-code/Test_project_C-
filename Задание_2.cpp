#include <iostream>
using namespace std;
class Pet {
public:
    // Конструктор
    Pet(const string& name) : name(name) {}

   
    virtual void Sound() const = 0;

  
    void Show() const {
        cout << "Имя: " << name << endl;
    }

 
    virtual void Type() const {
        cout << "Вид: Домашня тварина" << endl;
    }

protected:
    string name; 
};

class Dog : public Pet {
public:
    Dog(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << name << ": Гав гав" << endl;
    }

    void Type() const override {
        cout << "Вид: Собаки" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << name << ":" << " Мяу" << endl;
    }

    void Type() const override {
        cout << "Вид: Кошки" << endl;
    }
};

class Parrot : public Pet {
public:
    Parrot(const string& name) : Pet(name) {}

    void Sound() const override {
        cout << name << ": Ке ке" << endl;
    }

    void Type() const override {
        cout << "Вид: Папугая" << endl;
    }
};

class Hamster : public Pet {
public:
    Hamster(const std::string& name) : Pet(name) {}

    void Sound() const override {
        cout << name << ": Пи пи" << endl;
    }

    void Type() const override {
        cout << "Вид: Хомяка" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Dog dog("Шарик");
    Cat cat("Ксюша");
    Parrot parrot("Кеша");
    Hamster hamster("Мурзик");

    dog.Show();
    dog.Sound();
    dog.Type();

    cout << "_______________________________________" <<endl;

    cat.Show();
    cat.Sound();
    cat.Type();

    cout <<"_______________________________________" <<endl;

    parrot.Show();
    parrot.Sound();
    parrot.Type();

    cout <<"_______________________________________" << endl;

    hamster.Show();
    hamster.Sound();
    hamster.Type();

    return 0;
}
