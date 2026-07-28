#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Document {
private:
    string content;
    string title;

public:
    Document(string title) : title(title) {}
    ~Document() {cout << "Document '" << title << "' destroyed!\n";}

    void appentText(string text) {content += text;}
    void print() const {cout << "[" << title << "]: " << content << "\n";}

    string getTitle() const {return title;}
};

class Editor {
private:
    string editorName;
    shared_ptr<Document> doc;

public:
    Editor(string editorName, shared_ptr<Document> doc) : editorName(editorName), doc(doc) {}
    ~Editor() {}

    void write(string text) {
        doc -> appentText(text);
        cout << editorName << " wrote to the document '" << doc -> getTitle() << "'.\n";
    }
};

int main() {
    shared_ptr<Document> doc1 = make_shared<Document>("Report");
    Editor e1("Alice", doc1);
    Editor e2("Bob", doc1);

    cout << "Use count after 2 editors created: " << doc1.use_count() << "\n";
    e1.write("Alice's notes. ");
    e2.write("Bob's additions.");
    doc1 -> print();

    weak_ptr<Document> wp = doc1;
    if (auto locked = wp.lock()) {cout << "\nWeak ptr check: Document exists!\n"; locked -> print();}
    else {cout << "\nWeak ptr check: Document does not exist!\n";}

    cout << "\n--- Unique ptr move demo ---\n";
    unique_ptr<Document> doc2 = make_unique<Document>("Draft");
    unique_ptr<Document> doc3 = move(doc2);
    cout << "Original unique_ptr is now empty (moved).\nMoved-to unique_ptr: [" << doc3 -> getTitle() << "]: (empty)\n";

    cout << "\n[Destructors firing automatically...]\n";

    return 0;
}
