#include<iostream>
#include<string.h>
#define MAX_NUMBER 2000010
 
struct Data{
    int num;
    int next;
    int before;
};
 
Data data[MAX_NUMBER];
int head = -1,tail = -1,cp = 0;
 
void insert(int x){
    data[cp].num = x;
    data[cp].next = head;
    data[cp].before = -1;
    if(head!=-1){
        data[head].before = cp;
    }else{
        tail = cp;
    }
    head = cp++;
}
 
void delete1(int x){
    int p = head;
    if(data[p].num == x){
        head = data[p].next;
        data[data[p].next].before = -1;
    }else{
        while(p != -1){
            int tmp = data[p].next;
            if(tmp == tail && data[tmp].num == x){
                data[p].next = -1;
                tail = p;
            }else if(data[tmp].num == x){
                data[p].next = data[tmp].next;
                data[data[tmp].next].before = p;
                return;
            }
            p = data[p].next;
        }
    }
}
             
 
void deleteFirst(){
    int tmp=data[head].next;
    if(tmp==-1){
        head=-1;
        tail=-1;
    }else{
        data[tmp].before = -1;
        head = tmp ;
    }
}
 
void deleteLast(){
    int tmp = data[tail].before;
    if(tmp==-1){
        head = -1;
        tail = -1;
    }else{
        data[tmp].next = -1;
        tail = tmp;
    }
}
 
int main(){
    int n,x;
    char command[20];
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> command ;
        if(strcmp(command,"insert")==0){
            std::cin >> x;
            insert(x);
        }else if(strcmp(command,"delete")==0){
            std::cin >> x;
            delete1(x);
        }else if(strcmp(command,"deleteFirst")==0){
            deleteFirst();
        }else if(strcmp(command,"deleteLast")==0){
            deleteLast();
        }
    }
    int p = head;
    if(p!=-1){
        std::cout << data[p].num ;
    }
    p = data[p].next;
    while(p!=-1){
        std::cout << ' ' << data[p].num ;
        p = data[p].next;
    }
    std::cout << '\n';
    return 0;
}
