/* code by saka015*/

/*I 'm the best ever. I' m the most brutal and vicious and most ruthless champion there 's ever been, there' s no one can stop me. I 'm Alexander. I 'm the best ever. There' s never been anybody as ruthless.There 's no one like.There 's no one that can match me. */

#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1'000'000'007;
const int N = 3e5, M = N;

/* BRUTE FORCE
int longestSubarraySumK(vector<int> arr, int k)
{
    int n = arr.size();
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}
*/

/*int longestSubarraySumK(vector<int> arr, int k)
{

    map<int, int> mp;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }

        if (mp.find(sum) == mp.end())
        {

            mp[sum] = i;
        }
    }

    return maxLen;
}*/
int longestSubarraySumK(vector<int> arr, int k)
{

    int i = 0,j = 0;

    int sum = arr[0];
    int maxlen = 0;
    int n=arr.size();

    while(j<n){

        while(i<=j && sum>k){
            sum -= arr[i];
            i++;
        }
        if(sum==k)
        {
            maxlen = max(maxlen, j - i + 1);
        }
        j++;

        if(j<n)
        {
            sum += arr[j];
        }
    }

    return maxlen;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int ans = longestSubarraySumK(arr, k);
    cout << ans << endl;
    return 0;
}