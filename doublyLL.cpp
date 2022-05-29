#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;

    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next  = NULL;
        }
        cout<<"Memory free for the node with data "<<val<<endl;
    }
};
void insertAtHead(Node* &head, Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;

    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;

    }
    
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;

    }
    else{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {
    //insert at Start
    if(position == 1) {
        insertAtHead(head,tail, d); 
        return;
    }

    Node* temp  = head;
    int count = 1;

    while(count < position-1) {
        temp = temp->next;
        count++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next ->prev  = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* & head, Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next =NULL;
        delete temp;
    }
    else
    { 
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next == NULL){
            tail = prev;
            curr->prev = NULL;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

    }
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    insertAtHead(head,tail,12);
    print(head);

    insertAtTail(head,tail,16);
    print(head);

    insertAtPosition(tail,head,3,23);
    print(head);

    insertAtPosition(tail,head,2,33);
    print(head);

    insertAtPosition(tail,head,1,43);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(1,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(4,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


}