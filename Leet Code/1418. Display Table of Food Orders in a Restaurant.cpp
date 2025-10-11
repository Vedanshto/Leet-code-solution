#include <bits/stdc++.h>
using namespace std;
#define rep(x, n) for (int x = 0; x < (n); ++x)
#define ll long long
#define el cout << endl;
#define min_heap priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    class Solution {
    public:
        vector<vector<string>> displayTable(vector<vector<string>>& orders) {
            int n = orders.size();
            map<pair<string,string>,int>mp; // table no and dishes 
            set<string>ds;
            set<int>table;
            int num = 1 , t_no = 1;


            for(int x = 0 ; x < orders.size() ; x++)   
            {
                int tableno = stoi(orders[x][1]); // change to int because of string  lexographical order suks 
                string t = orders[x][1];
                string dishes =  orders[x][2];

                pair<string,string>temp = {t,dishes};
                mp[temp]++;
                if(ds.count(dishes) == 0)
                {
                    ds.insert(dishes);
                }
                if(table.count(tableno) == 0)
                {
                    table.insert(tableno);
                }
            }
            vector<vector<string>>ans(table.size()+1,vector<string>(ds.size()+1 , "0"));

            vector<string>r1;

            r1.push_back("Table");

        // map the table

        unordered_map<string,int>tap;

        // map the dishes
        unordered_map<string,int>dish;

        int x = 1;

        for(auto p : ds)
        {
         r1.push_back(p);
         dish[p] = x;
         x++;
        }
            ans[0] = r1;

            int c = 1;

            for(auto it : table)
            {
                ans[c][0] = to_string(it);
                tap[to_string(it)]=c;
                c++;
            }

            for( auto it : mp )
            {
                int x = tap[it.first.first] ;
                int y = dish[it.first.second] ;
                string count = to_string(it.second);
                ans[x][y] = count;
            }


            return ans;
        }
    }obj;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<string>> orders = {
        {"David", "3", "Ceviche"},
        {"Corina", "10", "Beef Burrito"},
        {"David", "3", "Fried Chicken"},
        {"Carla", "5", "Water"},
        {"Carla", "5", "Ceviche"},
        {"Rous", "3", "Ceviche"}};

    vector<vector<string>>ans = obj.displayTable(orders);


    for(int x = 0 ; x < ans.size() ; x++ )
    {
        for(int i = 0 ; i < ans[x].size() ; i++)
        {
            cout<<ans[x][i]<<" ";
        }
        el
    }

    return 0;
}