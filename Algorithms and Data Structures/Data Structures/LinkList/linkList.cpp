#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
//创建链表
void createList(ListNode* linklist,int n){
    ListNode *p = linklist;
    for (int i = 0; i < n;i++){
        ListNode *newNode = new ListNode;
        newNode->val = i;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return;
}
//输出链表
void outputList(ListNode* linklist){
    if(linklist==NULL||linklist->next==NULL){
        cout << "链表为空" << endl;
        return;
    }else{
        cout << "链表元素为：";
        ListNode *p = linklist;
        while(p->next!=NULL){
            p = p->next;
            cout << p->val << " ";
        }
        cout << endl;
        return;
    }
}
//输出链表长度
int lengthOfList(ListNode* linklist){
    if(linklist==NULL||linklist->next==NULL){
        return 0;
    }else{
        ListNode *p = linklist;
        if(p!=NULL){
            int count = 0;
            while(p->next!=NULL){
                p = p->next;
                count++;
            }
            return count;
        }
    }
    return -1;
}

//获取目标位置的值
int getValue(ListNode* linklist,int index){
    if(index<=lengthOfList(linklist)){
        ListNode *p = linklist;
        for(int i = 0; i < index;i++){
            p = p->next;
        }
        return p->val;
    }
    return -1;
}
//在目标位置插入节点
void insert(ListNode* linklist,int index,int value){
    if(index<=lengthOfList(linklist)){
        ListNode *p = linklist;
        while(index--){
            p = p->next;
        }
        ListNode *temp = new ListNode;
        temp->val = value;
        temp->next = p->next;
        p->next = temp;
        cout << "插入元素完成" << endl;
        return;
    }
    cout << "插入元素失败" << endl;
    return;
}


//删除目标位置的节点
void deleteL(ListNode* linklist,int index){
    if(index<=lengthOfList(linklist)){
        ListNode *p = linklist;
        while(index--){
            p = p->next;
        }
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        cout << "删除元素成功" << endl;
        return;
    }
    cout << "删除元素失败" << endl;
    return;
}

//删除整个链表
void deleteList(ListNode* linklist){
    ListNode *p = linklist->next;
    while(p!=NULL){
        ListNode *temp = p;
        p = p->next;
        delete temp;
    }
    linklist->next = NULL;
    cout << "删除链表成功" << endl;
    return;
}

int main(){
    ListNode *list = new ListNode;
    list->next = NULL;
    int n;
    cout << "输入链表长度：";
    cin >> n;
    //创建链表
    createList(list, n);

    //输出链表
    outputList(list);

    //链表长度
    int length = lengthOfList(list);
    cout << "链表长度为：" << length << endl;

    //获取指定节点的值
    cout << "输入要获取第几个链表的值：";
    int index;
    cin >> index;
    int valueIndex = getValue(list, index);
    cout << "第" << index << "个元素的值为：" << valueIndex << endl;

    //在指定位置插入元素
    cout << "输入插入元素的位置：";
    int indexInsert;
    cin >> indexInsert;
    cout << "输入插入元素的值：";
    int valueInsert;
    cin >> valueInsert;
    insert(list, indexInsert, valueInsert);
    cout << "插入元素后链表如下：";
    outputList(list);

    //删除指定位置链表元素
    cout << "请输出删除元素位置：";
    int indexDelete;
    cin >> indexDelete;
    deleteL(list,indexDelete );
    cout << "删除元素后的链表为：" << endl;
    outputList(list);

    //删除指定链表
    cout << "是否要删除链表,输入(0:不删除/1:删除)：";
    int ifDelte;
    cin >> ifDelte;
    while(ifDelte!=0&&ifDelte!=1){
        cout << "输入错误，请重新输入:";
        cin >> ifDelte;
    }
    if(ifDelte==0){
        cout << "结束" << endl;
    }else{
        deleteList(list);
        outputList(list);
    }

    delete list;
    return 0;
}