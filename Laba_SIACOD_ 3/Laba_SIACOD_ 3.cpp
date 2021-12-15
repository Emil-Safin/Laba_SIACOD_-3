#include <iostream>
#include <time.h>
int N = 0;
class Node;
class tree {
private:
    class Node {
    public:
        int data;
        Node* NextL;
        Node* NextR;
        Node(int data = 0, Node* NextL = nullptr, Node* NextR = nullptr ) {
            this->data = data;
            this->NextL = NextL;
            this->NextR = NextR;

        }
    };
        int sizel;
        int sizer;
        Node* head;
public:
    tree();
    ~tree();
    Node* add_in(Node* t, int n) {
        Node* r = new Node;
        int nl, nr;
        if (n == 0) { head = NULL; return head; }
        nl = n / 2;
        nr = n - nl - 1;    
            N++;
            r->data = (rand() % 900) + 100;
            std::cout << r->data << " ";
            r->NextL = add_in(r->NextL, nl);
            r->NextR = add_in(r->NextR, nr);
            head = r;
            return head;

        
    }
    void NLR_in(Node* head);
    void LNR_in(Node* head);
    void LRN_in(Node* head);
    void LRN_for_delete(Node* head);
    void print_in(Node* t, int size);
    void NLR() {
        //Node* tmp = head;
        NLR_in(head);
    }
    void LNR() {
        LNR_in(head);
    }
    void LRN() {
        //Node* tmp = head;
        LRN_in(head);
    }
    void print() {
        print_in(head, 3);
    }
    void add(int i) {
        add_in(head, i);
    }
   
};
tree::tree() {
    sizel = 0;
    sizer = 0;
    head = nullptr;
}
// Node* tadd_in(Node* head, const int n=11) {
//     Node* r = new Node;
//     int nl, nr;
//     if (n == 0) { head = NULL; return head; }
//     nl = n / 2;
//     nr = n - nl - 1;
//     std::cin >> r->data;
//     r->left = add_in(r->left, nl);
//     r->right = add_in(r->right, nr);
//     head = r;
//     return head;
//
//    //if (head == nullptr)
//    //{
//    //    head = new Node(data);
//    //}
//    //else {
//
//    //    Node* current = this->head;
//    //    Node* tmp = new Node(data);
//    //  //  std::cout << tmp->data;
//    //    while (current->NextL != nullptr && current->NextR != nullptr) {     
//    //        if ((sizel - sizer) == 1)
//    //            current = current->NextR;
//    //        else
//    //            current = current->NextL;
//    //    }
//    //    if (current->NextL == nullptr) {
//    //        current->NextL = tmp;
//    //        sizel++;
//    //    }
//    //    else {
//    //        current->NextR = tmp;
//    //        sizer++;
//    //    }        
//    //}
//}

//int cnt;
void tree::NLR_in(Node* head)
{
    if (head == nullptr)
        return;
    std::cout << head->data << " ";
  //  cnt++;
    NLR_in(head->NextL);
    NLR_in(head->NextR);
}

void tree::LNR_in(Node* head)
{
    if (!head)
        return;
    LNR_in(head->NextL);
    std::cout << head->data << " ";
    LNR_in(head->NextR);
}

void tree::LRN_in(Node* head)
{
    if (!head)
        return;
    LRN_in(head->NextL);
    LRN_in(head->NextR);
    std::cout << head->data << " ";
}

void tree::LRN_for_delete(Node* head)
{
    if (!head)
        return;
    LRN_for_delete(head->NextL);
    LRN_for_delete(head->NextR);
    delete head;
}

//
void tree::print_in(Node* t, const int level = 0)
{
    if (t->NextL)
        print_in(t->NextL, level + 1);
    for (int i = 0; i < level; i++)
        std::cout << "     ";
    std::cout << t->data << std::endl;
    if (t->NextR)
        print_in(t->NextR, level + 1);
}

tree::~tree()
{
    LRN_for_delete(head);
}

int main()
{
    tree a;
    srand(time(NULL));
    a.add(10);
    std::cout << std::endl << "NLR: ";
    a.NLR();
    std::cout << std::endl;
    std::cout << "LNR: ";
    a.LNR();
    std::cout << std::endl;
    std::cout << "LRN: ";
    a.LRN();
    std::cout << std::endl << std::endl;
    a.print();
}
