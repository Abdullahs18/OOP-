#include <iostream>
using namespace std;

class Mentor; 

class Student {
private:
  int studentid;
  string studentname;
  int age;
  string sportsInterests[3];
  Mentor *mentorAssigned; 

public:
  Student(int id, string name, int age) {
    studentid = id;
    studentname = name;
    this->age = age;
    mentorAssigned = nullptr; 
  }

  int get_studentid() { return studentid; }
  string get_studentname() { return studentname; }

  void set_sportsInterests() {
    cout << "Enter 3 sports interests: ";
    for (int i = 0; i < 3; i++) {
      cin >> sportsInterests[i];
    }
  }

  string get_sportsInterests() {
    string interests = "";
    for (int i = 0; i < 3; i++) {
      interests += sportsInterests[i] + " ";
    }
    return interests;
  }

  void updateSportsInterest() {
    cout << "Update your sports interests: ";
    for (int i = 0; i < 3; i++) {
      cin >> sportsInterests[i];
    }
  }

  void registerForMentorship(Mentor &m);
  void viewMentorDetails();

  void removeMentor() { mentorAssigned = nullptr; }
};

class Mentor {
private:
  string mentorName;
  string mentorSportsExpertise[3];
  int maxLearners;
  int currentLearners;
  Student *assignedLearners[10]; 

public:
  Mentor(string name, int maxL) {
    mentorName = name;
    maxLearners = maxL;
    currentLearners = 0;
  }

  string get_name() { return mentorName; }

  void setExpertise() {
    cout << "Enter 3 areas of expertise: ";
    for (int i = 0; i < 3; i++) {
      cin >> mentorSportsExpertise[i];
    }
  }

  void assignLearner(Student &s) {
    if (currentLearners < maxLearners) {
      assignedLearners[currentLearners++] = &s;
      cout << s.get_studentname() << " has been assigned to " << mentorName
           << endl;
    } else {
      cout << "Mentor " << mentorName << " is at full capacity!" << endl;
    }
  }

  void removeLearner(Student &s) {
    bool found = false;
    for (int i = 0; i < currentLearners; i++) {
      if (assignedLearners[i] == &s) {
        found = true;
        s.removeMentor(); 

        for (int j = i; j < currentLearners - 1; j++) {
          assignedLearners[j] = assignedLearners[j + 1]; 
        }
        assignedLearners[currentLearners - 1] = nullptr;
        currentLearners--;

        cout << s.get_studentname() << " removed from mentorship." << endl;
        return;
      }
    }
    if (!found) {
      cout << "Learner not found." << endl;
    }
  }

  void viewLearners() {
    cout << "Mentor: " << mentorName << " - Assigned Learners:\n";
    for (int i = 0; i < currentLearners; i++) {
      cout << assignedLearners[i]->get_studentname() << endl;
    }
  }
};

void Student::registerForMentorship(Mentor &m) {
  if (mentorAssigned != nullptr) {
    cout << "Student already assigned to a mentor!" << endl;
  } else {
    mentorAssigned = &m;
    m.assignLearner(*this);
  }
}

void Student::viewMentorDetails() {
  if (mentorAssigned) {
    cout << "Mentor Name: " << mentorAssigned->get_name() << endl;
  } else {
    cout << "No mentor assigned.\n";
  }
}

int main() {
  Mentor mentor1("Ali", 3);
  mentor1.setExpertise();

  Student student1(101, "Saad", 20);
  Student student2(102, "Ahmed", 21);
  Student student3(103, "Zain", 19);
  Student student4(104, "Hassan", 22);

  student1.registerForMentorship(mentor1);
  student2.registerForMentorship(mentor1);
  student3.registerForMentorship(mentor1);
  student4.registerForMentorship(mentor1);

  mentor1.viewLearners();
  mentor1.removeLearner(student2);
  mentor1.viewLearners();

  return 0;
}
