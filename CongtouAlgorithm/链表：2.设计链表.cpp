/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    ListNode* head;
    int length;
public:
    MyLinkedList() {
        head = new ListNode();
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index > length - 1) return -1;
        ListNode* temp = head;
        for(int i = 0; i <= index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* p = new ListNode(val, head->next);
        head->next = p;
        length++;
    }

    void addAtTail(int val) {
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(val);
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        ListNode* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(val, temp->next);
        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > length - 1) return;
        ListNode* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete(del);
        length--;
    }
};