#include <bits/stdc++.h>
using namespace std;

typedef struct _Student {
    int rollno;
    char name[16];
    char div;
    char address[32];
} Student;

class StudentDB {
private:
    vector<Student> data;
    string filename;

public:
    StudentDB(const string& filename): filename(filename) {}

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

    void readFromFile() {
        fstream db(filename, ios::in | ios::binary);
        Student temp;
        while (db.read((char*)&temp, sizeof(Student))) {
            db.peek();
            data.push_back(temp);
        }
        db.close();
    }

    void display() {
        cout << "ROLLNO\t\tNAME\t\tDIV\t\tADDRESS" << endl;
        for (const auto& elem : data) {
            cout << elem.rollno << "\t\t\t" << elem.name << "\t\t" << elem.div << "\t\t" << elem.address << endl;
        }
    }
};

int main() {
    StudentDB db("temp.dat");

    db.addRecord(15, "Nikhil", 'S', "Nashik");
    db.addRecord(24, "Gunjan", 'S', "Sambhaji Nagar");
    db.addRecord(54, "Yash", 'S', "Jalgaon");
    db.addRecord(50, "Saksham", 'S', "Delhi");

    db.readFromFile();
    db.display();

    return 0;
}
