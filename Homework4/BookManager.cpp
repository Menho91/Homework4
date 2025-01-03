#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장
public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 정보 string 변환 메서드
    string infoBook(const Book& book)
    {
        return book.title + " by " + book.author;
    }

    // 제목으로 책 검색 메서드
    string findBookByTitle(const string& title)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                cout << "검색 결과: " << infoBook(books[i]) << endl;
                return books[i].title;
            }
        }
        cout << "검색 결과가 없습니다." << endl;
        return " ";
    }

    // 작가로 책 검색 메서드
    string findBookByAuthor(const string& author)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].author == author)
            {
                cout << "검색 결과: " << infoBook(books[i]) << endl;
                return books[i].title;
            }
        }
        cout << "검색 결과가 없습니다." << endl;
        return " ";
    }
};

class BorrowManager
{
private:
    unordered_map<string, int> stock;
    BookManager manager;
public:
    BorrowManager(BookManager& bm) : manager(bm) {}

    void initializeStock(const string& title, int quantity = 3)
    {
        stock[title] = quantity;
    }
    void borrowBook(const string& title)
    {
        if (manager.findBookByTitle(title) != " ")
        {
            if (stock[title] > 0)
            {
                stock[title]--;
                cout << title << "을 대여했습니다. 남은 권 수: " << stock[title] << endl;
            }
            else
            {
                cout << "현재 재고가 없어 대여할 수 없습니다." << endl;
            }
        }
        else {
            cout << "해당 책을 찾을 수 없습니다." << endl;
        }
    }
    void returnBook(const string& title)
    {
        if (manager.findBookByTitle(title) != " ")
        {
            if (stock[title] < 3)
            {
                stock[title]++;
                cout << title << "을 반납했습니다. 남은 권 수: " << stock[title] << endl;
            }
            else
            {
                cout << "대여하지 않은 책은 반납할 수 없습니다." << endl;
            }
        }
        else {
            cout << "해당 책을 찾을 수 없습니다." << endl;
        }
    }
    void displayStock()
    {
        cout << "\n현재 도서 재고 목록" << endl;
        for (auto it = stock.begin(); it != stock.end(); it++)
        {
            cout << "- " << it->first << ": " << to_string(it->second) << "권 남음" << endl;
        }
    }
};

int main() {
    BookManager bookManager;
    BorrowManager borrowManager(bookManager);

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 검색" << endl; // 현재 책 목록에 있는 책 검색
        cout << "4. 책 대여" << endl; // 현재 책 목록 중 대여
        cout << "5. 책 반납" << endl; // 현재 대여한 책 반납
        cout << "6. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            bookManager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock(title);
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            bookManager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 책 검색
            // 현재 BookManager에 저장된 책 중에서 사용자가 입력한 제목이나 저자명을 가진 책을 검색합니다.
            while (true)
            {
                cout << "\n1. 제목으로 책 검색" << endl;
                cout << "2. 저자명으로 책 검색" << endl;
                cout << "3. 뒤로 돌아가기" << endl;
                cout << "선택: ";

                int choice1;
                cin.ignore();
                cin >> choice1;

                if (choice1 == 1) {
                    string title;
                    cout << "책 제목: ";
                    cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                    getline(cin, title); // 제목 입력 (공백 포함)
                    bookManager.findBookByTitle(title);
                    break;
                }
                else if (choice1 == 2) {
                    string author;
                    cout << "책 저자명: ";
                    cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                    getline(cin, author); // 제목 입력 (공백 포함)
                    bookManager.findBookByAuthor(author);
                    break;
                }
                else if (choice1 == 3) {
                    cout << "메뉴로 돌아갑니다." << endl;
                    break;
                }
                else {
                    cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
                }
            }
        }
        else if (choice == 4) {
            // 4번 선택: 책 대여
            // 현재 책 목록 중 개수가 남은 책을 대여합니다.
            borrowManager.displayStock();
            cout << "대여할 책의 제목을 입력하세요: " << endl;
            string title;
            cin.ignore();
            getline(cin, title); // 제목 입력 (공백 포함)
            borrowManager.borrowBook(title);
        }
        else if (choice == 5) {
            // 5번 선택: 책 반납
            // 빌린 책 중 하나를 반납합니다.
            borrowManager.displayStock();
            cout << "반납할 책의 제목을 입력하세요: " << endl;
            string title;
            cin.ignore();
            getline(cin, title); // 제목 입력 (공백 포함)
            borrowManager.returnBook(title);
        }
        else if (choice == 6) {
            // 7번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
