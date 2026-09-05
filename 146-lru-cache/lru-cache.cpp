class LRUCache {
private:
    struct Node{
        int key,value;
        Node *prev, *next;
        Node(int k, int v) : key(k),value(v),prev(nullptr),next(nullptr){}
    };
    int cap;
    unordered_map<int,Node*>m;
    Node *head=new Node(-1,-1), *tail=new Node(-1,-1);

public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* node=m[key];
            int res = node->value;
            m.erase(key);
            deleteNode(node);
            addNode(node);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            deleteNode(node);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */