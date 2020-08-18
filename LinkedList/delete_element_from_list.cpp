/** author: geds
 *  date  : 2020-08-18
 *  link  : https://blog.nowcoder.net/n/7326bb130504437facc0ac1b9a76af8b[NowCoder]
 * */
#include <iostream>
#include <string>
#include <sstream>
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};

class MyList{
public:
    ListNode* header;
    int size;

    MyList(){
        header = new ListNode();
        size = 0;
    }

    void insertAfter(int key_e, int e){
        ListNode *p = new ListNode(), *ptr = header->m_pNext;
        p->m_nKey = e;
        int n = size;
        if(size == 0){
            ptr = header;
        }else{
            for(int i=0; i<size; i++){
                if(ptr->m_nKey == key_e)
                    break;
                else
                    ptr = ptr->m_pNext;
            }
        }
        p->m_pNext = ptr->m_pNext;
        ptr->m_pNext = p;
        size++;
    }

    void remove(int e){
        ListNode *p = header, *ptr = header->m_pNext;
        for(int i=0; i<size; i++){
            if(ptr->m_nKey == e)
                break;
            ptr = ptr->m_pNext;
            p = p->m_pNext;
        }
        p->m_pNext = ptr->m_pNext;
        delete ptr;
        size--;
    }

    void clear(){
        ListNode *p0 = header;
        while(size--){
            ListNode*p1 = header->m_pNext;
            p0->m_pNext = p1->m_pNext;
            delete p1;
        }
        size = 0;
    }
};

int main()
{
    MyList list;
    int node_num;
    int e, key_e;
    while(std::cin >> node_num >> e){
        list.insertAfter(0, e);
        for(int i=0; i<node_num-1; i++){
            std::cin >> e >> key_e;
            list.insertAfter(key_e, e);
        }
        int del_e;
        std::cin >> del_e;
        list.remove(del_e);
        ListNode* p = list.header->m_pNext;
        for(int i = 0; i < list.size; i++){
            std::cout << p->m_nKey << " ";
            p = p->m_pNext;
        }
        list.clear();
        std::cout << std::endl;
    }
    return 0;
}
