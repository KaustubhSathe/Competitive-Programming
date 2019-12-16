#include<bits/stdc++.h>
using namespace std;

/*********************************************************************** INTERVIEW DSA PROBLEMS *************************************************************************
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
*********************************************************************** INTERVIEW DSA PROBLEMS *************************************************************************/

/****************************************************************** DATA STRUCTURES IMPLEMENTATIONS ***************************************************************

template<class T> struct Heap{
    vector<T> table;
    Heap(){}
    Heap(vector<T> input){
        for(auto x : input){
            insert(x);
        }
    }
    void insert(T x){
        table.push_back(x);
        for(int i = table.size()-1;i != 0 && table[(i-1)/2] > table[i];){
            swap(table[(i-1)/2],table[i]);
            i = (i-1)/2;
        }
    }
    T extractMin(){
        if(table.size() == 0)
            return 0;
        

        T ret = table.front();
        swap(table[table.size() - 1],table[0]);
        table.erase(table.begin() + table.size() - 1);
        Heapify(0);
        return ret;
    }

    T getMin(){
        return table.front();
    }

    void Heapify(int id){
        int left = 2*id + 1;
        int right = 2*id + 2;
        int smallest = id;
        if(left < table.size() && table[left] < table[smallest])
            smallest = left;

        if(right < table.size() && table[right] < table[smallest])
            smallest = right;

        if(smallest != id){
            swap(table[smallest],table[id]);
            Heapify(smallest);
        }
    }
};

****************************************************************** DATA STRUCTURES IMPLEMENTATIONS ***************************************************************/

/************************************************************************* INTERFACES *****************************************************************************
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
 - Since all data fields are public static final in an interface it must be initialized then and there itself.
 - Methods and data fields can have one of the four access specifiers private,default(when nothing in specified),protected,public. 
   But classes and interface can have only two access specifier public and default. But nested classes/interfaces can have all four.
 - Comparator interface :
    class cmp implements Comparator<Obj> 
    { 
        // Used for sorting in ascending order of 
        // roll number 
        public int compare(Obj a,Obj b) 
        { 
            return custom logic; 
        } 
    } 
 - When we define the method of the interface in a class implementing the interface, we have to give it public access as child can't assign the weaker access to methods

************************************************************************* Interfaces ******************************************************************************/

/****************************************************************** Abstract Classes ******************************************************************************
 - Using keyword abstract a class can be made abstract in Java
 - An instance of abstract class cannot be made, but we can have reference of abstract class type though.
 - An abstract class can have constructor, and a constructor of abstract class is called when an instance of a inherited class is created.
 - We can have an abstract class without any abstract method, this allows us to only create classes that can only be inherited and not instantiated.
 -                                                      Difference between abstract class and interface
                        Interface                                                                   Abstract Class
    --> Interface can only have abstract methods                            | --> Abstract class can have both abstract and non-abstract methods
    --> Variables declared in interface are final by default.               | --> Abstract class can contain non-final variables
    --> Interface only has static and final variables.                      | --> Abstract class can have final,non-final,static,non-static variables
    --> Interface is inherited using implements keyword.                    | --> Abstract class is inherited using extends keyword
    --> Interface can inherit interface only(Using extend keyword)          | --> Whereas abstract class can inherit both class and interface
    --> Interface members are public,static and final                       | --> Abstract class members can have any access type

 - 
                                                                            
****************************************************************** Abstract Classes ******************************************************************************/


/*********************************************************************** IMPORTANT STL ****************************************************************************
Policy Based Data Structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
order_of_key (val): returns the no. of values less than val
find_by_order (k): returns the iterator to kth largest element.(0-based)

Writing custom comparators for built-in data structures like set,multiset,priority_queue,map,multimap
struct cmp{
    !!!Always use const while defining custom comparators,otherwise such errors happen std::pair<int, int>&’ to ‘const std::pair<int, int>
    bool operator()(const T& a,const T& b){
        return custom logic;
    }
};
Useage : priority_queue<T,vector<T>,cmp>, set<T,cmp>, multiset<T,cmp>, map<T,T,cmp>, multimap<T,T,cmp>

Functions : 
1. empty() : common to all containers
2. size() : commmon to all containers
3. top() : priority_queue,stack
4. push() : priority_queue,stack
5. emplace()/emplace_back()/emplace_front(): all containers except list back() and front() to be used according to data structure
6. pop() : priority_queue/stack
7. [] random access : deque,vector
8. front() : queue,list,
9. back() : queue,list


List related functions(important for linked list problems)
front() : returns reference to front element
back() : returns reference to back element
emplace_front(),push_front(),pop_front()
emplace_back(),push_back(),pop_back()

Erase : http://www.cplusplus.com/reference/list/list/erase/ 

Splice : entire list (1) void splice (iterator position, list& x); pq.spl
         single element (2) void splice (iterator position, list& x, iterator i);
         element range (3) void splice (iterator position, list& x, iterator first, iterator last);

reverse : http://www.cplusplus.com/reference/list/list/reverse/
sort : http://www.cplusplus.com/reference/list/list/sort/
merge : http://www.cplusplus.com/reference/list/list/merge/
remove : http://www.cplusplus.com/reference/list/list/remove/
*********************************************************************** IMPORTANT STL ****************************************************************************/

/*********************************************************************** CPU SCHEDULING ****************************************************************************
 - Process is program in excecution
 - Attributes of a process (also called context of a process)
    - Process Id : A unique identifier assigned by the operating system
    - Process State : Ready,runnable,blocked etc.
    - CPU Registers : Like the program counter 
    - I/O status info : For example devices allocated to the process.
    - CPU Scheduling info : for example priority associated with the process 
    - Every process has its own PCB(process control block)

 - States of process : new,ready,running,wait,complete,suspended ready,suspended block
 - Context Switching : Process of saving the context of one prorcess and loading the context of another process is known as context switching.

 - PCB (Process Control Block) is used to track the process excecution status. Each block of memory contains information about the process state, program counter,
   stack pointer, status of opened files, scheduling algorithms, etc. All these information is required and must be saved when the process is switched from 
   one state to another. When the process made transitions from one state to another, the operating system must update information in the process’s PCB.
 - Process Table is an array of PCBs that means logically contains a PCB for all the current running process in the system.
 - PCB stores the following properties of a process : 
    --> Pointer : It is a stack pointer which is required to be saved when the process is switched from one state to another to retain the current position of the process.
    --> Process state – It stores the respective state of the process.
    --> Process number – Every process is assigned with a unique id known as process ID or PID which stores the process identifier.
    --> Program counter – It stores the counter which contains the address of the next instruction that is to be executed for the process.
    --> Register – These are the CPU registers which includes: accumulator, base, registers and general purpose registers.
    --> Memory limits – This field contains the information about memory management system used by operating system. 
        This may include the page tables, segment tables etc.
    --> Open files list – This information includes the list of files opened for a process.
    --> The process control block stores the register content also known as execution content of the processor when it was blocked from running.
        This execution content architecture enables the operating system to restore a process’s execution context when the process returns to the running state. 
        When the process made transitions from one state to another, the operating system update its information in the process’s PCB. 
        The operating system maintains pointers to each process’s PCB in a process table so that it can access the PCB quickly.

 - Long Term or job scheduler It brings the new process to the ‘Ready State’. It controls Degree of Multi-programming, i.e., number of process present in ready 
   state at any point of time.It is important that the long-term scheduler make a careful selection of both IO and CPU bound process.
 - Short term or CPU scheduler: It is responsible for selecting one process from ready state for scheduling it on the running state. Note: Short-term scheduler only selects the process to schedule it doesn’t load the process on running.
   Dispatcher is responsible for loading the process selected by Short-term scheduler on the CPU (Ready to Running State) Context switching is done by dispatcher only. A dispatcher does the following: Switching context.Switching to user mode.Jumping to the proper location in the newly loaded program.
 - Medium-term scheduler It is responsible for suspending and resuming the process. It mainly does swapping (moving processes from main memory to disk and
   vice versa). Swapping may be necessary to improve the process mix or because a change in memory requirements has overcommitted available memory,requiring memory to be freed up.

 - Arrival Time: Time at which the process arrives in the ready queue.
 - Completion Time: Time at which process completes its execution.
 - Burst Time: Time required by a process for CPU execution.
 - Turn Around Time: Time Difference between completion time and arrival time.
 - Turn Around Time = Completion Time – Arrival Time
 - Waiting Time(W.T): Time Difference between turn around time and burst time.
 - Waiting Time = Turn Around Time – Burst Time

 - Job Scheduling Algorithms : 
    --> FCFS (First Come First Served) : Simplest scheduling algorithm that schedules according to arrival times of processes.
    First come first serve scheduling algorithm states that the process that requests the CPU first is allocated the CPU first.
    --> SJF (Shortest Job First) : Process which have the shortest burst time are scheduled first.If two processes have the same bust time then FCFS is used to break the tie. It is a non-preemptive scheduling algorithm.
    --> LJF (Longest Job First) : It is similar to SJF scheduling algorithm. But, in this scheduling algorithm, we give priority to the process having the longest burst time.
    --> Shortest Remaining Time First (SRTF): It is preemptive mode of SJF algorithm in which jobs are schedule according to shortest remaining time.
    --> Longest Remaining Time First (LRTF): It is preemptive mode of LJF algorithm in which we give priority to the process having largest burst time remaining.
    --> Round Robin Scheduling: Each process is assigned a fixed time(Time Quantum/Time Slice) in cyclic way.It is designed especially for the time-sharing system. The ready queue is treated as a circular queue. The CPU scheduler goes around the ready queue, allocating the CPU to each process for a time interval of up to 1-time quantum.
    --> Priority Based scheduling (Non-Preemptive): In this scheduling, processes are scheduled according to their priorities, i.e., highest priority process is scheduled first. If priorities of two processes match, then schedule according to arrival time. Here starvation of process is possible.
    --> Highest Response Ratio Next (HRRN): In this scheduling, processes with highest response ratio is scheduled. This algorithm avoids starvation.
 
 
 - A Context switch is the time spent between two processes (i.e., bringing a waiting process into execution and sending an executing process into waiting state). This happens in multitasking.The operating system must bring the state information if waiting process into memory and save the state information of the currently running process.
 - Convoy Effect : Convoy Effect is phenomenon associated with the First Come First Serve (FCFS) algorithm, in which the whole Operating System slows down due to few slow processes.


 - Belady Anomaly in Page Replacement Algorihtms
 - In Operating System, process data is loaded in fixed sized chunks and each chunk is referred to as a page. 
   The processor loads these pages in the fixed sized chunks of memory called frames. Typically the size of each page 
   is always equal to the frame size.
 - A page fault occurs when a page is not found in the memory, and needs to be loaded from the disk. 
   If a page fault occurs and all memory frames have been already allocated, then replacement of a page in memory is 
   required on the request of a new page. This is referred to as demand-paging. The choice of which page to replace is 
   specified by a page replacement algorithms. The commonly used page replacement algorithms are FIFO, LRU, optimal page 
   replacement algorithms etc.
 - Generally, on increasing the number of frames to a process’ virtual memory, its execution becomes faster as less number
   of page faults occur. Sometimes the reverse happens, i.e. more number of page faults occur when more frames are 
   allocated to a process. This most unexpected result is termed as Belady’s Anomaly.
 - Bélády’s anomaly is the name given to the phenomenon where increasing the number of page frames results in an increase 
   in the number of page faults for a given memory access pattern.
*********************************************************************** CPU SCHEDULING ***************************************************************************/

/*********************************************************************** PROCESS SYNCHRONIZATION ***************************************************************************
 - Race Condition : When more than one processes are executing the same code or accessing the same memory or any shared variable in that condition there is a
   possibility that the output or the value of the shared variable is wrong so for that all the processes doing race to say that my output is correct this condition 
   known as race condition. 
 - Critical Section Problem : Critical section is a code segment that can be accessed by only one process at a time. Critical section contains shared variables which need to be synchronized to maintain consistency of data variables.
 - Any solution to the critical section problem must satisfy three requirements: Mutual exclusion,progress and bounded waiting.
 - Processes can communicate with each other using two ways : shared memory, message passing
 - Communication between processes using shared memory requires processes to share some variable and it completely depends on how programmer will implement it.
 - https://www.geeksforgeeks.org/inter-process-communication-ipc/
 - Methods in IPC : 
    --> Pipes : This allows flow of data in one direction only. Analogous to simplex systems (Keyboard). Data from the output is usually buffered until input process receives it which must have a common origin.
    --> Names Pipes : This is a pipe with a specific name it can be used in processes that don’t have a shared common process origin. E.g. is FIFO where the details written to a pipe is first named.
    --> Message Queuing : This allows messages to be passed between processes using either a single queue or several message queue. This is managed by system kernel these messages are coordinated using an API.
    --> Semaphores : This is used in solving problems associated with synchronization and to avoid race condition. These are integer values which are greater than or equal to 0.
    --> Shared Memory : This allows the interchange of data through a defined area of memory. Semaphore values have to be obtained before data can get access to shared memory.
    --> Sockets : This method is mostly used to communicate over a network between a client and a server. It allows for a standard connection which is computer and OS independent.


 1. IPC through shared memory https://www.geeksforgeeks.org/ipc-shared-memory/ : IPC through shared memory is a concept where two or more process can access the common memory. And communication is done via this shared memory where changes made by one process can be viewed by another process.
    The problem with pipes, fifo and message queue – is that for two process to exchange information. The information has to go through the kernel.
 2. IPC using message queue https://www.geeksforgeeks.org/ipc-using-message-queues/ : A message queue is a linked list of messages stored within the kernel and identified by a message queue identifier. A new queue is created or an existing queue opened by msgget(). 
    
    Semaphores in operating system : Semaphore is simply a variable which is non-negative and shared between threads. This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment.
    Binary Semaphore – This is also known as mutex lock. It can have only two values – 0 and 1. Its value is initialized to 1. It is used to implement the solution of critical section problem with multiple processes.
    Counting Semaphore – Its value can range over an unrestricted domain. It is used to control access to a resource that has multiple instances.

    https://www.geeksforgeeks.org/mutex-vs-semaphore/



*********************************************************************** PROCESS SYNCHRONIZATION ***************************************************************************/








/********************************************************************** CODE - HERE ******************************************************************************/

int main(){
    // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    list<int> pq1,pq2;
    for(int i = 0;i<10;i++){
        pq1.emplace_back(i);
        pq2.emplace_back(i*i);
    }
    for(auto it = pq1.begin();it != pq1.end();it++){
        if(*it == 0){
            it = pq1.erase(it);
        }
    }
    cout<<pq1.front()<<endl;
    
    return 0;
}


