#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";

        stack<pair<char,int>>st; // the character and the index;

        for(int x = 0 ; x < s.size() ; x++ )
        {
            if(s[x] == ')' &&  !st.empty() && st.top().first == '(' )
            {
                st.pop();
                continue;
            }
            else if(s[x] == '(' || s[x] == ')' )
            {
                st.push({s[x],x});
            }
        }

        while(!st.empty())
        {
            auto it = st.top() ; st.pop();

            s[it.second] = '*';
        }

        for(int x = 0 ; x < s.size() ; x++ )
        {
            if(s[x] != '*') ans+=s[x];
        }


        return ans;
    }
}obj;
int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

string temp; cin>>temp;

cout<<obj.minRemoveToMakeValid(temp);

return 0;
}