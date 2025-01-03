#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BorrowManager
{
private:
    unordered_map<string, int> stock;
public:
    void initiallizeStock(Book& book, int quantity = 3)
    {

    }
    void borrowBook(const string& title)
    {

    }
    void returnBook(const string& title)
    {

    }
    void displayStock()
    {

    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // å ���� string ��ȯ �޼���
    string infoBook(const Book& book)
    {
        return book.title + " by " + book.author;
    }

    // �������� å �˻� �޼���
    Book* findBookByTitle(const string& title)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                cout << "�˻� ���: " << infoBook(books[i]) << endl;
                return &(books[i]);
            }
        }
        cout << "�˻� ����� �� �̻� �����ϴ�." << endl;
    }

    // �۰��� å �˻� �޼���
    Book* findBookByAuthor(const string& author)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].author == author)
            {
                cout << "�˻� ���: " << infoBook(books[i]) << endl;
                return &(books[i]);
            }
        }
        cout << "�˻� ����� �� �̻� �����ϴ�." << endl;
    }
};

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�" << endl; // ���� å ��Ͽ� �ִ� å �˻�
        cout << "4. å �뿩" << endl; // ���� å ��� �� �뿩
        cout << "5. å �ݳ�" << endl; // ���� �뿩�� å �ݳ�
        cout << "6. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            bookManager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            bookManager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: å �˻�
            // ���� BookManager�� ����� å �߿��� ����ڰ� �Է��� �����̳� ���ڸ��� ���� å�� �˻��մϴ�.
            while (true)
            {
                cout << "\n1. �������� å �˻�" << endl;
                cout << "2. ���ڸ����� å �˻�" << endl;
                cout << "3. �ڷ� ���ư���" << endl;
                cout << "����: ";

                int choice1;
                cin.ignore();
                cin >> choice1;

                if (choice1 == 1) {
                    string title;
                    cout << "å ����: ";
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, title); // ���� �Է� (���� ����)
                    bookManager.findBookByTitle(title);
                    break;
                }
                else if (choice1 == 2) {
                    string author;
                    cout << "å ���ڸ�: ";
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, author); // ���� �Է� (���� ����)
                    bookManager.findBookByAuthor(author);
                    break;
                }
                else if (choice1 == 3) {
                    cout << "�޴��� ���ư��ϴ�." << endl;
                    break;
                }
                else {
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                }
            }
        }
        else if (choice == 4) {
            // 4�� ����: å �뿩
            // ���� å ��� �� ������ ���� å�� �뿩�մϴ�.
            cout << "���� �������� �ʾҽ��ϴ�." << endl;
        }
        else if (choice == 5) {
            // 5�� ����: å �ݳ�
            // ���� å �� �ϳ��� �ݳ��մϴ�.
            cout << "���� �������� �ʾҽ��ϴ�." << endl;
        }
        else if (choice == 6) {
            // 7�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
