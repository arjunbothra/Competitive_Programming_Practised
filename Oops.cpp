#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//always read question carefully and prove your answer


class Teacher
{
    public:
        string name;
        string subject;
        int salary;
    
    
        Teacher(string s, string sub, int amt){
            cout << "Teacher called" << endl;
            name = s;
            subject = sub;
            salary = amt;
        }
    
    void printt() const{
        cout << name << " "<< subject << " " << salary << endl;
    }
};

class Person : public Teacher{
    public:

        Person(string s, string sub, int amt) : Teacher(s, sub, amt){
            cout << "Person class" << endl;
        }
        void p(){
            cout << "hello";
        }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Person t1( "Arjun", "Maths", 10000);
    t1.p();
    t1.printt();
    // t1.printt();

    // for (int i = 0; i < 8;++i)
    //     cout << i << " ";

    // Person p1;
    // p1.name = "Arjun";
    // p1.subject = "Maths";
    // p1.salary = 60000;

    return 0;
}




