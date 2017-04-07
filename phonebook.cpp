#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unique_ptr;

class Person
{
    public:
        Person(string &myfname, string &mylname, string &myphonenum)
        {
            fname = myfname;
            lname = mylname;
            phonenum = myphonenum;
        }
        string getPhonenum()
        {
            return phonenum;
        }
        string getFname()
        {
            return fname;
        }
        string getLname()
        {
            return lname;
        }
        void print()
        {
            cout << getFname() << " " << getLname() << "_" << getPhonenum() << endl;
        }
    private:
        string fname;
        string lname;
        string phonenum;
};

class Work : public Person
{
    public:
        Work(string &myfname, string &mylname, string &myphonenum, string &myteam) : Person(myfname, mylname, myphonenum)
        {
            team = myteam;
        }
        string getTeam()
        {
            return team;
        }
        void print()
        {
            cout << getFname() << " " << getLname() << "_" << getPhonenum() << " _" << getTeam() << endl;
        }
    private:
        string team;
};

class Friend : public Person
{
    public:
        Friend(string &myfname, string &mylname, string &myphonenum, int &myage) : Person(myfname, mylname, myphonenum)
        {
            age = myage;
        }
        int getAge()
        {
            return age;
        }
        void print()
        {
            cout << getFname() << " " << getLname() << "_" << getPhonenum() << " _" << getAge() << endl;
        }
    private:
        int age;
};

class Family : public Person
{
    public:
        Family(string &myfname, string &mylname, string &myphonenum, string &mybday) : Person(myfname, mylname, myphonenum)
        {
            bday = mybday;
        }
        string getBday()
        {
            return bday;
        }

        int dates_of_month(int month)
        {
            if (month == 2)
                return 28;
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            else
                return 31;
        }

        int dDay()
        {
//          int bY = (bday[0]-48)*10 + (bday[1]-48) + 1900;
            int bM = (bday[2]-48)*10 + (bday[3]-48);
            int bD = (bday[4]-48)*10 + (bday[5]-48);

            time_t t = time(0);
            struct tm *now = localtime(&t);
//          int cY = now->tm_year + 1900;
            int cM = now->tm_mon + 1;
            int cD = now->tm_mday;

//          int dday = 365 * (cY - bY - 1);
            int dday = 0;
            int i;
            for (i=bM; i<=12; i++)
                dday = dday + dates_of_month(i);
            for (i=1; i<cM; i++)
                dday = dday + dates_of_month(i);
            dday = dday - bD + cD;
            if (dday>=365)
                dday = dday - 365;
            return dday;
        }

        void print()
        {
            cout << getFname() << " " << getLname() << "_" << getPhonenum() << "_" << getBday() << "_" <<  dDay() << endl;
        }

    private:
        string bday;
};

class Console
{
    public:
        void initialState()
        {
            cout << "Phone Book" << endl;
            cout << "1. Add person" << endl;
            cout << "2. Remove person" << endl;
            cout << "3. Print phone book" <<endl;
        }
        int print_addPerson()
        {
            int type;
            cout << "Select Type" << endl;
            cout << "1. Person" << endl;
            cout << "2. Work" << endl;
            cout << "3. Family" << endl;
            cout << "CP-2016-19702>";
            cin >> type;
            return type;
        }
        Person* addPerson()
        {
            string fname, lname, phonenum;
            cout << "Name: ";
            cin >> fname >> lname;
            cout << "Phone_number: ";
            cin >> phonenum;
            Person *ptr;
            ptr = new Person(Person(fname, lname, phonenum));
            cout << "Succesfully added new person." << endl;
            return ptr;
        }
        Work* addWork()
        {
            string fname, lname, phonenum, team;
            cout << "Name: ";
            cin >> fname >> lname;
            cout << "Phone_number: ";
            cin >> phonenum;
            cout << "Team ";
            cin >> team;
            Work *ptr;
            ptr = new Work(Work(fname, lname, phonenum, team));
            cout << "Succesfully added new person." << endl;
            return ptr;
        }
        Family* addFamily()
        {
            string fname, lname, phonenum, birthday;
            cout << "Name: ";
            cin >> fname >> lname;
            cout << "Phone_number: ";
            cin >> phonenum;
            cout << "Birthday: ";
            cin >> birthday;
            Family *ptr;
            ptr = new Family(Family(fname, lname, phonenum, birthday));
            cout << "Succesfully added new person." << endl;
            return ptr;
        }
        Friend* addFriend()
        {
            string fname, lname, phonenum;
            int age;
            cout << "Name: ";
            cin >> fname >> lname;
            cout << "Phone_number: ";
            cin >> phonenum;
            cout << "Age: ";
            cin >> age;
            Friend *ptr;
            ptr = new Friend(Friend(fname, lname, phonenum, age));
            cout << "Succesfully added new person." << endl;
            return ptr;
        }
        int rmPerson()
        {
            int index;
            cout << "Enter index of person: ";
            cin >> index;
            return index;
        }
};




int main()
{
   vector<unique_ptr<Person*>> phonebook;
    //    phonebook.emplace_back(new Derived());
   while (1)
    {
        cout << "CP-2016-19702>";
        string command;
        cin >> command;
        Console c;
        while (command == "\n")
        {
            c.initialState();
            cout << "CP-2016-19702>";
            cin >> command;
        }
        if (command == "1")
        {
            int type = c.print_addPerson();
            switch (type)
            {
                case '1' :
                    phonebook.emplace_back(c.addPerson());
                    break;
                case '2' :
                    phonebook.emplace_back(c.addWork());
                    break;
                case '3' :
                    phonebook.emplace_back(c.addFamily());
                    break;
                case '4' :
                    phonebook.emplace_back(c.addFriend());
                    break;
            }
        }
        else if (command == "2")
        {
            int index = c.rmPerson();
            if (phonebook.size()<index)
                cout << "Person does not exist!" << endl;
            else
            {
                phonebook.erase(index-1);
                cout << "A person is successfully deleted from the Phone Book!" << endl;
            }
        }
        else if (command == "3")
        {
            cout << "Phone Book Print" << endl;
            int i;
            for (i=0; i<phonebook.size(); i++)
            {
                cout << i+1 << ". ";
                phonebook[i]->print();
            }
        }
        else if (command == "exit")
            break;
    }
}
