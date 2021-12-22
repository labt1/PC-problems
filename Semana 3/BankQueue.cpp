#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

struct Person{
    int money;
    int time;
    
    Person(int m, int w){
        money = m;
        time = w;
    }
};

bool compareMoney(const Person &a, const Person &b){
        return a.money >= b.money;
}

void queuePerson(vector<int> &v, Person c){
    int i = c.time;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.money;
            return;
        }  
        i--; 
    }
}

int main(){ 

    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    cin>>N>>T;    
   
    vector<int> bQueue(T);
    vector<Person> money;
    
    for(int i = 0; i < N; i++){
        cin>>ci>>ti;
        Person c(ci, ti);
        money.push_back(c); 
    }    
	
    sort(money.begin(), money.end(), compareMoney);    
    while(i < money.size()){
        queuePerson(bQueue, money[i]);
        i++;
    }    
    
    for(int i = 0; i < bQueue.size(); i++)
        sum += bQueue[i];
    
    cout<<sum; 
    return 0;
}