#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct intervalo{
    double a;
    double b;
    int index;

    bool operator < (intervalo x) const {
        return a < x.a;
    }
};

double A,B,maxx;    
int n, it, best;
vector<int> cover;
bool possible;

int main(){
	int n,l;
	double r,w,x;
	while (cin >> n >> l >> w){
		intervalo intervalos[n];
		for (int i=0;i<n;i++){
			cin >> x >> r; 
			if (r >= w/2){
				double p = sqrt(r*r -w*w/4);
				intervalos[i].a = x - p;
				intervalos[i].b = x + p;
				intervalos[i].index = i;
			}
			else {
				intervalos[i].a = -1;
				intervalos[i].b = -1;
				intervalos[i].index = i;
			}
		}
		A = 0;
		B = l;

        sort(intervalos,intervalos+n); 
        it = 0;
        cover.clear();
        possible = true;
        
        while (intervalos[it].b < A){
            it++;
            if (it == n){
                possible = false;
                break;
            }
        }
        if (A == B && possible){
            if (intervalos[it].a <= A && intervalos[it].b >= A)
                cover.push_back(intervalos[it].index);
            else possible = false;
        }
        while (A < B && possible){
            if (it == n){
                possible = false;
                break;
            }
            maxx = -1;
            best = -1;
            while (intervalos[it].a <= A){
                if (intervalos[it].b - A > maxx){
                    maxx = intervalos[it].b - A;
                    best = it;
                }
                it++;
                if (it == n) break;
            }
            if (best == -1){
                possible = false;
                break;
            }
            cover.push_back(intervalos[best].index);
            A = intervalos[best].b;
        }
        if (!possible)
            cout << "-1" << endl;
        else
            cout << cover.size() << endl;
	}
    return 0;
}