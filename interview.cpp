#include<bits/stdc++.h>
using namespace std;

// Given arrival and departure times of all trains that reach a railway station.
// Your task is to find the minimum number of platforms required for the railway station so that no train waits.
// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// Solution : O(1) range update used here https://wcipeg.com/wiki/Prefix_sum_array_and_difference_array https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
// int n,a[1000+5],d[1000+5],dp[2500];
// int main(){
// 	int tc;
// 	cin>>tc;
// 	while(tc--){
// 	   cin>>n;
// 	   for(int i = 0;i<n;i++){
// 	       cin>>a[i];
// 	   }
// 	   for(int i = 0;i<n;i++){
// 	       cin>>d[i];
// 	   }
// 	   memset(dp,0,sizeof(dp));
// 	   for(int i = 0;i<n;i++){
// 	       dp[a[i]]++;
// 	       dp[d[i]+1]--;
// 	   }
// 	   int ans = 0;
// 	   for(int i =1;i<2500;i++){
// 	       dp[i] += dp[i-1];
// 	       ans = max(ans,dp[i]);
// 	   }	   
// 	   cout<<ans<<endl;
// 	}
// 	return 0;
// }

// Minimum number of bracket reversals needed to make an expression balanced
// https://practice.geeksforgeeks.org/problems/count-the-reversals/0
//https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
// int main(){
//     int tc;
//     cin>>tc;
//     while(tc--){
//         string s;cin>>s;
//         if(s.length()%2 == 1){
//             cout<<-1<<endl;
//             continue;
//         }
//         stack<char> pq;
//         for(auto x : s){
//             if(pq.empty()){
//                 pq.push(x);
//             }else{
//                 if(pq.top() == '{' && x == '}'){
//                     pq.pop();
//                 }else{
//                     pq.push(x);
//                 }
//             }
//         }
//         int cnt1 = 0,cnt2 = 0;
//         if(cnt1 != cnt2){
//             cout<<-1<<endl;
//             continue;
//         }
//         while(!pq.empty()){
//             cnt1 += (pq.top() == '{');
//             cnt2 += (pq.top() == '}');
//             pq.pop();
//         }
        
//         int ans = (int)ceil(cnt1/2.0) + (int)ceil(cnt2/2.0);
//         cout<<ans<<endl;
//     }
//     return 0;
// }

// merge (initer1 beg1, initer1 end1,initer2 beg2, initer2 end2,outiter res, Compare comp)
// Use back_inserter merge(temp1.begin(),temp1.end(),temp2.begin(),temp2.end(),back_inserter(temp3))

// /********************Min-Heap********************/
// template<class T> struct Heap{
//     vector<T> table;
//     /**********Constructors**********/
//     Heap(){}
//     Heap(vector<T> input){
//         for(auto x : input){
//             insert(x);
//         }
//     }

//     /**********Methods**********/
//     void insert(T x){
//         table.push_back(x);
//         for(int i = table.size()-1;i != 0 && table[(i-1)/2] > table[i];){
//             swap(table[(i-1)/2],table[i]);
//             i = (i-1)/2;
//         }
//     }

//     T extractMin(){
//         if(table.size() == 0)
//             return 0;
        

//         T ret = table.front();
//         swap(table[table.size() - 1],table[0]);
//         table.erase(table.begin() + table.size() - 1);
//         Heapify(0);
//         return ret;
//     }

//     T getMin(){
//         return table.front();
//     }

//     void Heapify(int id){
//         int left = 2*id + 1;
//         int right = 2*id + 2;
//         int smallest = id;
//         if(left < table.size() && table[left] < table[smallest])
//             smallest = left;

//         if(right < table.size() && table[right] < table[smallest])
//             smallest = right;

//         if(smallest != id){
//             swap(table[smallest],table[id]);
//             Heapify(smallest);
//         }
//     }
// };

// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

// https://leetcode.com/problems/lru-cache/
// class LRUCache {
// public:
//     int capacity;
//     unordered_map<int,list<pair<int,int>>::iterator> keys;
//     list<pair<int,int>> pq;
//     LRUCache(int cap) {
//         capacity = cap;  
//         pq.clear();
//         keys.clear();
//     }
    
//     int get(int key) {
//         if(keys.find(key) == keys.end())
//             return -1;
            
//         int value = keys[key]->second;
//         pq.erase(keys[key]);
//         keys.erase(key);
//         pq.emplace_front(make_pair(key,value));
//         keys[key] = pq.begin();
//         return value;
//     }
    
//     void put(int key, int value) {
//         if(keys.find(key) != keys.end()){
//             pq.erase(keys[key]);
//             keys.erase(key);
//             pq.emplace_front(make_pair(key,value));
//             keys[key] = pq.begin();    
//             return;
//         }
//         if(pq.size() == capacity){
//             pair<int,int> last = pq.back();
//             keys.erase(last.first);
//             pq.pop_back();
//         }
//         pq.emplace_front(make_pair(key,value));
//         keys[key] = pq.begin();
//     }
// };

/************************************************************************* Interfaces *****************************************************************************
Interface : Like a class, an interface can have methods and variables, but the methods declared in an interface are by default abstract.
 - Interfaces specify what a class must do and not how. It is the blueprint of the class.
 - If a class implements an interface and does not provide method bodies for all functions specified in the interface, then the class must be declared abstract.0
    interface <interface_name> {    
        // declare constant fields
        // declare methods that abstract 
        // by default.
    }
 - all the methods in an interface are declared with an empty body and are public and all fields are public, static and final by default.
 - A class that implement interface must implement all the methods declared in the interface. To implement interface use implements keyword.
 
 - Why do we use interface : It is used to achieve total abstraction., Since java does not support multiple inheritance in case of class, but by using interface it can achieve multiple inheritance, It is also used to achieve loose coupling.

 - Interfaces are used to implement abstraction. So the question arises why use interfaces when we have abstract classes?
 The reason is, abstract classes may contain non-final variables, whereas variables in interface are final, public and static.
 - JDK 8 onwards interfaces also support default implementation
 - interface In1 
    { 
        final int a = 10; 
        default void display() 
        { 
            System.out.println("hello"); 
        } 
    }

 - Static methods are also added JDK 8 onwards
    // An example to show that interfaces can 
    // have methods from JDK 1.8 onwards 
    interface In1 
    { 
	    final int a = 10; 
	    static void display() 
	    { 
		    System.out.println("hello"); 
	    } 
    } 

    // A class that implements the interface. 
    class TestClass implements In1 
    { 
        // Driver Code 
        public static void main (String[] args) 
        { 
            In1.display(); 
        } 
    } 

 - We can’t create instance(interface can’t be instantiated) of interface but we can make reference of it that refers to the Object of its implementing class.
 - A class can implement more than one interface.
 - An interface can extends another interface or interfaces (more than one interface) .
 - A class that implements interface must implements all the methods in interface.
 - All the methods are public and abstract. And all the fields are public, static, and final.
 - It is used to achieve multiple inheritance.
 - It is used to achieve loose coupling.

 
************************************************************************* Interfaces ******************************************************************************/



