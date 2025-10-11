// 3306. Count of Substrings Containing Every Vowel and K Consonants II

// You are given a string word and a non-negative integer k.

// Return the total number of substrings of word that contain every vowel
//('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.


#include<bits/stdc++.h>
using namespace std;
bool isvowel(char x)
{
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ;
}

long long count_substring_with_k_consonents(string w , int k) // using sliding window for atleast k 
{
    long long ans = 0;
    int n = w.size(),low = 0 ,cons = 0;
    unordered_map<char,int>mp;

    for(int x = 0 ; x < n ; x++ )
    {
        if(isvowel(w[x]))
        {
            mp[w[x]]++;
        }
        else 
        {
            cons++;
        }


        while (mp.size()==5 && cons >= k)   
        {
            ans += n-x;
            if(isvowel(w[low]))
            {
                mp[w[low]]--;
                if(mp[w[low]] == 0 )
                {
                    mp.erase(w[low]);
                }
            }
            else 
            {
                cons--; 
            }
            low++;

        }
    }
    return ans;
}

long long countOfSubstrings(string word, int k)//atlest k - atleast k+1 = exect k;
{   
    return count_substring_with_k_consonents(word,k) - count_substring_with_k_consonents(word,k+1);
}
int main()
{
    string temp;
    cin>>temp;
    int k ;
    cin>>k;
    cout << countOfSubstrings(temp,k);
    
 return 0;
}