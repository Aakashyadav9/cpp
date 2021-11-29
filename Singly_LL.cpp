#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertion(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertion_head(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    display(head);
    insertion_head(head, 0);
    display(head);
    cout<<search(head, 4);
    return 0;
}
