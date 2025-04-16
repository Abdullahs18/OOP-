#include <iostream>
#include <string>
using namespace std;

unsigned long hashPassword(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}

class User {
protected:
    string name, id, email;
    unsigned long hashed_password;
    string permissions[3];

public:
    User(string n, string i, string e, string p, string perm[]) : name(n), id(i), email(e), hashed_password(hashPassword(p)) {
        for (int j = 0; j < 3; j++) permissions[j] = perm[j];
    }
    bool authenticate(string p) { return hashed_password == hashPassword(p); }
    virtual void display() { cout << "User: " << name << " (" << id << ")\nEmail: " << email << endl; }
    virtual void accessLab() { cout << "Access denied." << endl; }
};

class Student : public User {
protected:
    int assignments[5];

public:
    Student(string n, string i, string e, string p, string perm[]) : User(n, i, e, p, perm) { for (int j = 0; j < 5; j++) assignments[j] = 0; }
    void display() override { cout << "Student: " << name << " (" << id << ")\n"; }
    void submitAssignment(int index) { if (index >= 0 && index < 5) assignments[index] = 1; }
};

class TA : public Student {
    string students[10];
    string projects[2];
    int studentCount, projectCount;

public:
    TA(string n, string i, string e, string p, string perm[]) : Student(n, i, e, p, perm), studentCount(0), projectCount(0) {}
    void display() override { cout << "TA: " << name << " (" << id << ")\n"; }
    void assignStudent(string student) { if (studentCount < 10) students[studentCount++] = student; }
    void startProject(string project) { if (projectCount < 2) projects[projectCount++] = project; }
};

class Professor : public User {
public:
    Professor(string n, string i, string e, string p, string perm[]) : User(n, i, e, p, perm) {}
    void display() override { cout << "Professor: " << name << " (" << id << ")\n"; }
};

void authenticateAndPerformAction(User* user, string action) {
    if (action == "submit_assignment") {
        Student* s = dynamic_cast<Student*>(user);
        if (s) s->submitAssignment(0);
    } else if (action == "assign_project") {
        Professor* p = dynamic_cast<Professor*>(user);
        if (p) cout << "Professor assigning project." << endl;
    }
}

int main() {
    string studentPerm[] = {"submit_assignment", "", ""};
    string taPerm[] = {"view_projects", "manage_students", ""};
    string profPerm[] = {"assign_projects", "full_lab_access", ""};

    Student s("Ali", "S123", "ali@uni.edu", "pass123", studentPerm);
    TA t("Sara", "T456", "sara@uni.edu", "ta456", taPerm);
    Professor p("Dr. Ahmed", "P789", "ahmed@uni.edu", "prof789", profPerm);

    s.display();
    t.display();
    p.display();

    authenticateAndPerformAction(&s, "submit_assignment");
    authenticateAndPerformAction(&p, "assign_project");
    
    return 0;
}
