#include <iostream>
class tree {
public:
    tree();
    ~tree();
    void add(int data);
private:
    class Node {
    public:
        int data;
        Node* NextL;
        Node* NextR;
        Node(int data, Node* NextL = nullptr, Node* NextR = nullptr ) {
            this->data = data;
            this->NextL = NextL;
            this->NextR = NextR;

        }
        int getData() { return data; }
    };
        int sizel;
        int sizer;
        Node* head;
   
};
tree::tree() {
    sizel = 0;
    sizer = 0;
    head = nullptr;
}

void tree::add(int data) {
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else {

        Node* current = this->head;
        Node* tmp = new Node(data);
      //  std::cout << tmp->data;
        while (current->NextL != nullptr && current->NextR != nullptr)
        {
            if(tmp->data > current->data)
                current = current->NextL;
            else
                current = current->NextR;
        }
        if (tmp->data > current->data) {
            if (current->NextL == nullptr) {
                current->NextL = tmp;
                sizel++;
            }
            else {
                current = current->NextL;
                if (tmp->data > current->data) {
                    current->NextL = tmp;
                    sizel++;
                }
                else {
                    current->NextR = tmp;
                    sizer++;
                }
            }
        }
        else {
            if (current->NextR == nullptr) {
                current->NextR = tmp;
                sizer++;
            }
            else {
                current = current->NextR;
                if (tmp->data > current->data) {
                    current->NextL = tmp;
                    sizel++;
                }
                else {
                    current->NextR = tmp;
                sizer++;
                }
            }
        }
    }
}



tree::~tree()
{
}



int main()
{
    tree a;
    a.add(2);
    a.add(1);
    a.add(3);
}
