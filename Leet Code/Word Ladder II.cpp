#include<bits/stdc++.h>
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
using namespace std;
class Solution {
    public:
    string b  ;
    unordered_map<string,int>mp; // int for lvl
    vector<vector<string>>ans;
    vector<vector<string>> findLadders(string bg,  string en, vector<string>& wL) {

        int n = wL.size();
        
        unordered_set<string>st(wL.begin(),wL.end());
        queue<pair<string,int>>q;
        q.push({bg,1});
        mp[bg] = 1;
        st.erase(bg);
        b = bg;

        while(!q.empty())
        {

            auto it = q.front(); q.pop();
            string str = it.first; 
            int count = it.second;
            if(str == en )
            {
                break;                
            }
            for(int x = 0 ; x < str.size() ; x++ )
            {
                for(char ch = 'a' ; ch <= 'z' ; ch++ )
                {
                    string temp = str;
                    temp[x] = ch;
                    if(st.find(temp) != st.end() )
                    {
                        q.push({temp,count+1});
                        mp[temp] = count+1;
                        st.erase(temp);
                    }
                }
            }
        }
        // cout<<mx;el
        // for(auto it : mp)
        // {
        //     cout<<it.first<<" -> "<<it.second;
        //     el
        // }

        
        if(mp.find(en)!=mp.end())
        {
         vector<string>parth;
         dfs(en,parth);
         return ans;
        }

        return {};
    }


    void dfs(  string word ,vector<string>&parth )
    {
        parth.push_back(word);

         if(b == word)
         {
        vector<string> temp = parth;
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        parth.pop_back(); 
        return;
        }
        
        int steps = mp[word];
        int sz = word.size();

        for(int x = 0 ; x < sz ; x++ )
        {
            char og = word[x];
            int lvl = mp[word];
            for(char ch = 'a' ; ch <= 'z' ; ch++ )
            {
                word[x] = ch;
                if(mp.find(word) != mp.end() && mp[word]+1 == lvl )
                {
                    dfs(word,parth);
                }
            }
            word[x] = og;
        }

        parth.pop_back();

    }

    // void pt()
    // {
    //     for(int x = 0 ;x < ans.size() ; x++ )
    //     {
    //         for(int i = 0 ; i < ans[x].size() ; i++)
    //         {
    //             cout<<ans[x][i]<<"->";
    //         }
    //         el;
    //     }
    // }


}obj;


int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
string bg , ed ; cin>>bg>>ed;

int n; cin>>n;
vector<string>str(n);

rep(x,n)
{
    cin>>str[x];
}

obj.findLadders(bg,ed,str);
obj.pt();

return 0;
}