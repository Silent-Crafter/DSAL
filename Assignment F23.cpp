#include <bits/stdc++.h>
using namespace std;

typedef struct Student {
    int rollno;
    char name[16];
    char div;
    char address[32];
} Student;

class StudentDB {
private:
    string filename;

public:
    StudentDB(): filename("student.dat") {}
    ~StudentDB() { remove("student.dat"); }

    void addRecord(int r, const char* n, char d, const char* a) {
        fstream db(filename, ios::app | ios::binary);
        Student temp;
        temp.rollno = r;
        temp.div = d;
        strncpy(temp.name, n, 16);
        strncpy(temp.address, a, 32);
        db.write((char*)&temp, sizeof(Student));
        db.flush();
        db.close();
    }

    void deleteRecord(int rollNo) {
        fstream infile(filename, ios::in | ios::binary);
        Student temp;
        vector<Student> data;

        while(infile.read((char*)&temp, sizeof(Student))) {
            if (temp.rollno == rollNo) {
                continue;
            }

            data.push_back(temp);
        }
        infile.close();

        fstream outfile(filename, ios::trunc | ios::out | ios::binary);
        for (auto student : data) {
            outfile.write((char*)&student, sizeof(Student));
        }
        outfile.close();
    }

    void display() {
        fstream infile(filename, ios::in | ios::binary);
        Student temp;

        while (infile.read((char*)&temp, sizeof(Student)))
            cout << temp.rollno << "\t\t\t" << temp.name << "\t\t" << temp.div << "\t\t" << temp.address << endl;

        infile.close();
    }

    void search(int rollNo) {
        Student temp;
        fstream infile(filename, ios::in | ios::binary);
        while (infile.read((char*)&temp, sizeof(Student))) {
            if (temp.rollno == rollNo) {
                cout << "\nStudent Record for roll no. " << rollNo << ":" << endl;
                cout << temp.rollno << "\t\t\t" << temp.name << "\t\t" << temp.div << "\t\t" << temp.address << endl;
                infile.close();
                return;
            }
        }

        cout << "\nStudent record for roll no. " << rollNo << " not found." << endl;
    }
};

int main() {
    StudentDB db;

    db.addRecord(15, "Nikhil", 'S', "Nashik");
    db.addRecord(24, "Gunjan", 'S', "Sambhaji Nagar");
    db.addRecord(54, "Yash", 'S', "Jalgaon");
    db.addRecord(50, "Saksham", 'S', "Delhi");

    db.display();
    db.search(24);
    db.deleteRecord(24);
    cout << "\nAfter Deletion:" << endl;
    db.display();

    db.search(24);

    return 0;
}
