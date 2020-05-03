#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Human {
public:
	Human (const string& name, const string& type):_Name(name),_Type(type){}

	virtual void Walk(const string& destination) const{
		cout << Occupation()<<": " << Name() << " walks to: " << destination << endl;
	}

	string Name() const{
		return _Name;
	}
	string Occupation()const{
		return _Type;
	}

private:
	const string _Name,_Type;
};

class Student: public Human {
	public:

		Student(const string& name, const string& favouriteSong):Human(name,"Student"),FavouriteSong(favouriteSong) {
		}

		void Learn() {
			cout << Occupation()<<": " << Name() << " learns" << endl;
		}
		void Walk(const string& destination) const override{
			cout << Occupation()<<": " << Name() << " walks to: " << destination << endl;
			cout << Occupation()<<": " << Name() << " sings a song: " << FavouriteSong << endl;
		}
		void SingSong() {
			cout << Occupation()<<": " << Name() << " sings a song: " << FavouriteSong << endl;
		}


	private:
		const string FavouriteSong;
};


class Teacher: public Human {
	public:

		Teacher(const string&  name, const string&  subject):Human(name,"Teacher"),Subject(subject) {
		}

		void Teach() {
			cout << Occupation()<<": " << Name() << " teaches: " << Subject << endl;
		}

	private:
		const string Subject;
};


class Policeman: public Human {
	public:
		Policeman(const string&  name):Human(name,"Policeman") {}

		void Check(const Human& h) {
			cout << Occupation()<<": " << Name() << " checks "<<h.Occupation()<<". "<<h.Occupation()<<"'s name is: " << h.Name() << endl;
		}
};

void VisitPlaces(Human& h, const vector<string> places){
    for (const string& p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

