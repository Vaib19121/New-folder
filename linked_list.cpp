#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    };
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Node succefully Deleted \n";
    }
};

void InsertAtHead(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail,int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next; 
}

void InsertAt(Node* &tail,Node* &head,int position, int data ){

    if(position == 1){
        InsertAtHead(head,data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        InsertAtTail(tail,data);
        return;
    }

    Node* nodetoInsert = new Node(data);

    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
    

}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count =1;
        while (count<position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}

void printData(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
}
int main()
{
    Node* a = new Node(5); //5

    Node* head = a;
    Node* tail = a;
    InsertAtHead(head, 8); // 8 5
    InsertAtHead(head, 9); // 9 8 5
    InsertAtTail(tail,7);  // 9 8 5 7
    InsertAtTail(tail,8);  // 9 8 5 7 8
    InsertAt(tail,head,2,7);   //  9 7 8 5 7 8
    deleteNode(head,6);
    printData(head);
    return 0;
}