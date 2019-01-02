#include <utils.hpp>


struct node {
    node *nx[2];
    int depth;
    int flag;
};

node *root;

LL total = 0;

node *create() {
    node *tmp = new node();
    tmp->nx[0] = tmp->nx[1] = NULL;
    tmp->depth = 0;
    tmp->flag = 0;
    return tmp;
}

string s;
int n,p;

void insert() {
    node *curr = root;
    for(int i = 0;i < s.size();i++) {
        int nx = s[i] - 'B';
        if(nx != 0) nx = 1;
        if(curr->nx[nx] == NULL) {
            curr->nx[nx] = create();
            curr->nx[nx]->depth = i + 1;
        }
        curr = curr->nx[nx];
    }
    curr->flag = 1;
}

void traverse(node *curr) {
    if(curr == NULL) return ;
    if(curr->flag) return ;
    if(curr->nx[0] == NULL) {
        int x = curr->depth;
        total += (1LL<<(n - x));
    }
    if(curr->nx[1] == NULL) {
        int x = curr->depth;
        total += (1LL<<(n - x));    
    }
    if(curr->nx[1]) traverse(curr->nx[1]);
    if(curr->nx[0]) traverse(curr->nx[0]);
}

void clear(node *curr) {
    if(curr->nx[0]) clear(curr->nx[0]);
    if(curr->nx[1]) clear(curr->nx[1]);
    delete(curr);
}