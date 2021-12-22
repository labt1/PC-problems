#include <iostream>

using namespace std;

#define max 100001

int sa[max], height[max];
int _rank[max], t1[max], t2[max], c[max];
string s;

bool cmp(int* r, int a, int b, int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}

void get_sa(int str[], int n, int m){
    n++; int i, j, p, *x = t1, *y = t2;
    for (i = 0; i < m; i++)
        c[i] = 0;
    for (i = 0; i < n; i++){
        x[i] = str[i];
        c[x[i]]++;
    }
    for (i = 1; i < m; i++)
        c[i] += c[i-1];
    for (i = n-1; i >=0; i--)
        sa[--c[x[i]]] = i;

    for (j = 1; j <= n; j<<=1){
        p = 0;
        for (i = n-j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i]-j;
        for (i = 0; i < m; i++)
            c[i] = 0;
        for (i = 0; i < n; i++)
            c[x[y[i]]]++;
        for (i = 1; i < m; i++)
            c[i] += c[i-1];
        for (i = n-1; i >= 0; i--)
            sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for (i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1:p++;
        if (p >= n) 
            break; 
        m = p;
    }

    int k = 0;
    n--;
    for (i = 0; i <= n; i++)
        _rank[sa[i]] = i;
    for (i = 0; i < n; i++){
        if (k) k--;
        j = sa[_rank[i]-1];
        while (str[i+k] == str[j+k]) 
            k++;
        height[_rank[i]] = k;
    }
}

int T, n, a[max];

int main(){
    cin>>T;
    while (T--){
        cin>>s;
        n=0; int len = s.size();
        for (int i = 0; i < len; i++)
            a[n++] = s[i];
        a[n] = 0;
        get_sa(a,n,333);
        int res = 0, min_ = 0, max_ = 0;
        for (int i = 2; i <= n; i++){
            if (height[i] > max_)
                max_ = height[i];
            else{
                res += max_ - min_;
                min_ = max_ = height[i];
            } 
        }
        res += max_ - min_;
        cout<<res<<endl;
    }
}