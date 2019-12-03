#include<bits/stdc++.h>
using namespace std;

//Modifying stack to find the smallest element in the stack in O(1).

stack<pair<int,int>> st;// where first value of pair stores the value of the element and second stores the minimum in the 
// stack starting from this element and below it.

// Adding new element
// int new_min = st.empty() ? new_val : min(new_val,new_min);
// st.push({new_elem, new_min});


//Modifying queue 
