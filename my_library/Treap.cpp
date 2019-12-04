#include<bits/stdc++.h>
using namespace std;

//Treap : BST by key value, and max-heap by priority
struct item{
    int key,prior,cnt;
    item *l,*r;
    item(){}
    item(int key,int prior) : key(key),prior(prior),l(nullptr),r(nullptr){}
};
// cnt can be used to find the k-th largest element in logN
int cnt(item* t) {
    return t ? t->cnt : 0;
}
void upd_cnt(item* t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

// Split(T,X) : Seperates tree T in two subtrees L and R trees(which are the return value of split and stored in l and r
// pointers),so that L contains all the elements with key < X and R contains all elements with key > X. This operation has
// O(logN) complexity. 
void split(item* t,int key,item*& l,item*& r){
    if(!t)
        l = r = nullptr;
    else if(key < t->key)
        split(t->l,key,l,t->l),r = t;
    else
        split(t->r,key,t->r,r),l = t;

    upd_cnt(t);
}

// Insert (X,Y) : While inserting we descend the tree X as in a regular binary search tree in O(logN),and then stop at the 
// first node which has priority greater than the priority of Y node. Now that we have found the node of insertion, we first
// split it into two parts L and R by calling the split function, and use the L and R as the left and right subtrees of Y
// and insert it at the found position.
void insert(item*& t,item* it){
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t,it->key,it->l,it->r),t = it;
    else
        insert(it->key < t->key ? t->l : t->r,it);
}

// Merge(T1,T2) : Combines two subtrees T1 and T2 and returns a new tree in O(logN) complexity. It works under the assumption
// that T1 and T2 are ordered,i.e all keys in T1 are smaller than keys in T2. Thus we need to combine these two trees
// without violating the order of priorities Y. To do this we choose as the root the tree which has a higher priority Y in
// the root node, and recursively call merge for the other tree and the corresponding subtree of the selected root node.
void merge(item*& t,item* l,item* r){
    if(!l || !r)
        t = l ? l : r;
    else if(l->prior > r->prior)
        merge(l->r,l->r,r),t = l;
    else
        merge(r->l,l,r->l),t = r;

    upd_cnt(t);
}

// Erase(X) :  First we descend in the tree (as in a regular binary search tree by X), looking for the element we want 
// to delete. Once the node is found, we call Merge on it children and put the return value of the operation in the place
// of the element we're deleting.
void erase(item*& t,int key){
    if(t->key == key)
        merge(t,t->l,t->r);
    else
        erase(key < t->key ? t->l : t->r,key);

    upd_cnt(t);
}

// Union(T1,T2) : It has a theoretical complexity O(Mlog(N/M)), but in practice it works very well, probably with a very 
// small hidden constant. Without loss of generality, assume that T1->prior > T2->prior i.e root of T1 will be the root of 
// their union. To get the result we need to merge the trees T1->L and T1->R into one tree and then merge this tree with 
// T2 in two trees which could be the left and right children of root T1. To do this, we call split(T2,T1->key), i.e split
// T2 with T1->key and get two trees L and R, which we then recursively combine with children of T1: Union(T1->L,L) and
// Union(T1->R,R) thus getting left and right subtrees of the result.
item* unite(item* l,item* r){
    if(!l || !r)return l ? l : r;
    if(l->prior < r->prior)swap(l,r);
    item *tl,*tr;
    split(r,l->key,tl,tr);
    l->l = unite(l->l,tl);
    l->r = unite(l->r,tr);
    return l;
}

/*---------------------------------------------------IMPLICIT TREAPS---------------------------------------------------*/

// Implicit treap can support operation in O(logN)(but with a large constant factor) like insert element,delete element,
// cut an array, merge two different array, maintain one objective function and query over an arbitary interval of the array
// addition/painting on intervals,reversing elements on an arbitary interval
// Implicit key : The implicit key for some node T is the number of vertices cnt(T->L) in the left subtree of this node 
// plus similar values cnt(P->L) + 1 for each ancestor of node T if T lies in the right subtree of P.

struct Node{
    int prior,sz,val,sum,lazy;
    //sz - subtree size
    //val - value of node
    //sum - sum of the interval
    //lazy - lazy value
    Node *l,*r;
};

int sz(Node* t){
    return t ? t->sz : 0;
}
void upd_sz(Node* t){
    if(t)
        t->sz = 1 + sz(t->l) + sz(t->r);
}
void lazy(Node* t){
    if(!t || !t->lazy)return;
    t->val += t->lazy;
    t->sum += t->lazy*sz(t);
    if(t->l)t->l->lazy += t->lazy; // propagate lazy to left
    if(t->r)t->r->lazy += t->lazy; // propagate lazy to right
    t->lazy = 0;
}
void reset(Node* t){
    if(t)
        t->sum = t->val; // lazy already propagated
}
void combine(Node*& t,Node* l,Node* r){
    if(!l || !r){
        t = l ? l : r;
        return;
    }
    t->sum = l->sum + r->sum;
}
void operation(Node* t){
    if(!t)return;
    reset(t);
    lazy(t->l);lazy(t->r);
    combine(t,t->l,t);combine(t,t,t->r);
}
void split(Node* t,Node* &l,Node* &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    lazy(t);int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to "l"
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else    
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);operation(t);
}
void merge(Node* &t,Node* l,Node* r){//result/left/right array
    lazy(l);lazy(r);
    if(!l || !r) 
        t = l?l:r;
    else if(l->prior>r->prior)
        merge(l->r,l->r,r),t=l;
    else    
        merge(r->l,l,r->l),t=r;
    upd_sz(t);operation(t);
}
int range_query(Node* t,int l,int r){
    Node* tl,*tm,*tr;
    split(t,tl,tm,l-1);
    split(tm,t,tr,r-l);
    int ans = t->sum;
    merge(tm,tl,t);
    merge(t,tm,tr);
    return ans;
}
void range_update(Node* t,int l,int r,int val){
    Node *tl,*tm,*tr;
    split(t,tl,tm,l-1);
    split(tm,t,tr,r-l);
    t->lazy += val;
    merge(tm,tl,t);
    merge(t,tm,tr);
}












int main(){
    item* treap = nullptr;
    for(int i = 1;i<=10;i++){
        insert(treap,new item(i,rand()));
    }

    
}
