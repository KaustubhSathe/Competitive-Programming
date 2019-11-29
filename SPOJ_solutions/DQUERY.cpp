#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int block_size;
int n,cnt;
int arr[30000+5];
int freq[1000000+5];
void get_rid(int idx){	
	freq[arr[idx]]--;
	if(freq[arr[idx]] == 0)
		cnt--;
} // remove value at idx from data structure
void add(int idx){
	freq[arr[idx]]++;
	if(freq[arr[idx]] == 1)
		cnt++;
} // add value at idx to the data structure
int get_answer(){
	return cnt;
} // extract the current answer of the data structure



struct Query{
	int l,r,idx;
	bool operator<(const Query& other) const{
		return make_pair(l/block_size,r) < make_pair(other.l/block_size,other.r);
	}
};

vector<int> mo_s_algorithm(vector<Query> queries){
	vector<int> answers(queries.size());
	sort(queries.begin(),queries.end());
	cnt = 0;
	int cur_l = 0,cur_r = -1;
	for(auto q : queries){
		while(cur_l > q.l){
			cur_l--;
			add(cur_l);
		}
		while(cur_r < q.r){
			cur_r++;
			add(cur_r);
		}
		while(cur_l < q.l){
			get_rid(cur_l);
			cur_l++;
		}
		while(cur_r>q.r){
			get_rid(cur_r);
			cur_r--;
		}
		answers[q.idx] = get_answer();
	}

	return answers;
}


int main(){
	scanf("%d",&n);
	block_size = (int)sqrt(n+0.0) + 1;
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	int q;
	scanf("%d",&q);
	vector<Query> queries;
	for(int i = 0;i<q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		l--;r--;
		Query temp;
		temp.l = l;
		temp.r = r;
		temp.idx = i;
		queries.push_back(temp);
	}
	vector<int> answers = mo_s_algorithm(queries);
	for(auto x : answers)
		printf("%d\n",x);

}