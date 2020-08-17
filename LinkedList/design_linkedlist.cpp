/** author: geds
 *  date  : 2020-08-17
 *  link  : https://leetcode-cn.com/problems/design-linked-list/
 * */
#include <iostream>

class MyNode{
public:
    int val;
    MyNode* next;
    MyNode();
    MyNode* insertAfter(int e);
};

MyNode::MyNode(){
    next = NULL;
}

MyNode* MyNode::insertAfter(int e){
    MyNode* node_ptr = new MyNode();
    node_ptr->val = e;
    node_ptr->next = next;
    next = node_ptr;
    return node_ptr;
}

class MyLinkedList {
public:
    MyNode* header;
    int size;

    /** Initialize your data structure here. */
    MyLinkedList() {
        header = new MyNode();
        size = 0;
    }

    ~MyLinkedList(){
        while (0 < size){
            header->next = header->next->next;
            delete header->next;
            size--;
        }
        delete header;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        MyNode* p = header->next;
        while(index--)
            p = p->next;
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        header->insertAfter(val);
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyNode* p = header;
        int n = size;
        while(n--)
            p = p->next;
        p->insertAfter(val);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyNode* p = header;
        while(index--)
            p = p->next;
        p->insertAfter(val);
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < size){
            MyNode* p0 = header;
            MyNode* p1 = header->next;
            while(index--){
                p0 = p0->next;
                p1 = p1->next;
            }
            p0->next = p1->next;
            delete p1;
            size--;
        }
    }

};

int main()
{
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    std::cout << linkedList->get(0) << ", " << linkedList->get(1) << ", " << linkedList->get(2) << "\n";            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    std::cout << linkedList->get(0) << ", " << linkedList->get(1) << "\n";            //返回3
    return 0;
}
