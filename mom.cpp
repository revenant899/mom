#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    size_t length;
    static int objectCount;

public:
    String() : String(80) {}

    String(size_t size) : length(size) {
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

    String(const char* userString) {
        length = strlen(userString);
        str = new char[length + 1];
        strcpy(str, userString);
        objectCount++;
    }

    ~String() {
        delete[] str;
        objectCount--;
    }

    void input() {
        cout << "������ ����� (�� " << length << " �������): ";
        cin.getline(str, length + 1);
    }

    void display() const {
        cout << "�����: " << str << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    String s1;
    s1.input();
    s1.display();

    String s2(50);
    s2.input();
    s2.display();

    String s3("�����������, ���� ������� ����� � �������� ����������, ��������� �� �����������.");
    s3.display();

    cout << "ʳ������ ��������� ��'����: " << String::getObjectCount() << endl;

    return 0;
}