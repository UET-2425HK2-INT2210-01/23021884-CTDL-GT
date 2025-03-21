#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[101];
    char className[31];
};

Student students[1000]; 
int countStudent = 0;  

void insertStudent(int id, char name[], char className[]) {
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            int j = 0;
            while (name[j]) {
                students[i].name[j] = name[j];
                j++;
            }
            students[i].name[j] = '\0';

            j = 0;
            while (className[j]) {
                students[i].className[j] = className[j];
                j++;
            }
            students[i].className[j] = '\0';
            return;
        }
    }

    students[countStudent].id = id;

    int j = 0;
    while (name[j]) {
        students[countStudent].name[j] = name[j];
        j++;
    }
    students[countStudent].name[j] = '\0';

    j = 0;
    while (className[j]) {
        students[countStudent].className[j] = className[j];
        j++;
    }
    students[countStudent].className[j] = '\0';

    countStudent++;
}

void deleteStudent(int id) {
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            for (int j = i; j < countStudent - 1; j++) {
                students[j] = students[j + 1];
            }
            countStudent--;
            return;
        }
    }
}

void infor(int id) {
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            cout << students[i].name << "," << students[i].className << endl;
            return;
        }
    }
    cout << "NA,NA" << endl;
}

int main() {
    char command[200];

    while (cin.getline(command, 200)) {
        if (command[0] == 'I' && command[1] == 'n') {
            int id = 0, i = 7;
            while (command[i] != ',') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            i++;

            char name[101], className[31];
            int j = 0;

            while (command[i] != ',') {
                name[j++] = command[i++];
            }
            name[j] = '\0';
            i++;
            j = 0;
            while (command[i] != ')') {
                className[j++] = command[i++];
            }
            className[j] = '\0';

            insertStudent(id, name, className);
        }

        else if (command[0] == 'D') {
            int id = 0, i = 7;
            while (command[i] != ')') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            deleteStudent(id);
        }

        else if (command[0] == 'I' && command[1] == 'n' && command[2] == 'f') {
            int id = 0, i = 6;
            while (command[i] != ')') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            infor(id);
        }
    }

    return 0;
}
