#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& profession) : _name(name), _profession(profession) {}

    virtual void Walk(const string& destination) const {
        cout << _profession << ": " << _name << " walks to: " << destination << endl;
    }

    const string GetName() const { return _name; }

    const string GetProfession() const { return _profession; }

private:
    const string _name;
    const string _profession;
};

class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) : Person(name, "Student"),
        _favouriteSong(favouriteSong) {}

    void Learn() const {
        cout << GetProfession() << ": " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << GetProfession() << ": " << GetName() << " sings a song: " << _favouriteSong << endl;

    }

private:
    const string _favouriteSong;
};

class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), _subject(subject) {}

    void Teach() const {
        cout << GetProfession() << ": " << GetName() << " teaches: " << _subject << endl;
    }

private:
    const string _subject;
};

class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& p) const {
        cout << GetProfession() << ": " << GetName() << " checks " << p.GetProfession() << ". " << p.GetProfession()
            << "' s name is " << p.GetName() << endl;
    }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}