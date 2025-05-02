#include <iostream>
using namespace std;
/* 定義hash table由13個buckets(lists)所組成 */
#define b 13
/* 定義hash table 的空位為EMPTY, or INT_MIN */
#define EMPTY -32768
/*定義list_node型態是single linked list的節點 */
typedef struct node {
    int key;
    struct node* next;
}list_node;

/* 宣告hash table是由具有b個值的list_node 指標陣列所組成 */
list_node* ht[b];
/* 將hash table初始化 */
void initialize()
{
    for (int i = 0; i < b; i++) {
        ht[i] = new(list_node);//動態配置一個新的點作為此list的head
        ht[i]->key = EMPTY;
        ht[i]->next = NULL;
    }
}
/* 將key透過hash function轉成位址 */
int hash_fun(int key)
{
    return key % b;
}
/* 根據位址將key存在對應的串列*/
void insert(int key)
{
    int address;
    list_node* ptr, * tmp;
    ptr = new(list_node); /*配置記憶體空間給新節點*/
    ptr->key = key;             		    /*將key存放在新節點*/
    ptr->next = NULL;            	    /*令新節點指向NULL*/
    address = hash_fun(key);     	    /*將key透過hash function轉成位址*/
    tmp = ht[address];            /*根據位址令tmp指向該串列的開頭*/
    while (tmp->next != NULL)    /*令tmp指向該串列的尾端*/
        tmp = tmp->next;
    tmp->next = ptr;    	      /*令tmp指向新節點*/
}

// 在 hash table 中搜尋 key，找到回傳所在 bucket index，否則回傳 -1
int search(int key) {
    int address = hash_fun(key);
    list_node* tmp = ht[address]->next;  // 跳過 head 的 EMPTY 節點
    while (tmp != nullptr) {
        if (tmp->key == key)
            return address;
        tmp = tmp->next;
    }
    return -1;
}


/*依照各串列內容印出hash table的所有keys*/
void show()
{
    list_node* tmp;
    for (int i = 0; i < b; i++) {
        cout << "ht[" << i << "]" << "\t";
        tmp = ht[i];
        do {
            if (tmp->key != EMPTY) cout << tmp->key << "\t";
            if (tmp->next == NULL) break;
            tmp = tmp->next;
        } while (1);
        cout << endl;
    }
}
int main()
{
    int key;
    initialize();
    insert(13);   insert(14);  insert(26);
    insert(60);   insert(39);  insert(40);
    insert(86);   insert(15);  insert(25);
    show();
    while (cin >> key) {
        cout << "---------------------------------------" << endl;
        cout << "位置在:" << search(key) << endl;
    }
    return 0;
}
