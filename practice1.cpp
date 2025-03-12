#include <iostream>
using namespace std;

class Employee{
    public:
    const int Max_salary=45000;
    int salary;
    string name;
    Employee(){
        salary=0;
        name="";
    }
    static int nextEmployeeId;

    static int generateemployeeid(){
        
        return nextEmployeeId;
    }
    Employee(int s,string n):salary(s),name(n){
        nextEmployeeId++;
    }

    int set_salary(){
        if(salary>Max_salary){
            salary=Max_salary;
        }
        else{
            salary=salary;
        }
        return salary;
    }


    void displayfunction(){
        cout <<"Name:"<<name;
        cout <<"Salary" <<set_salary();
        cout <<"Employee ID" <<generateemployeeid();
    }

};
int Employee::nextEmployeeId=0;
int main(){
    Employee e1(35000,"Abdullah");
    Employee e2(50000,"Omer");
    e1.displayfunction();
    e2.displayfunction();

}