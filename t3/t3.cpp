#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

struct Seq{
    string seq;
    int ordem;
    

    Seq(string s){
        this->seq = s;
        this->ordem = calcula_ordem(s, s.size());
    }

    int calcula_ordem(string s, int n){
    int o = 0;
    for (int i = 1; i < n; i++){
        char key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j] > key){
            s[j+1] = s[j];
            j = j - 1;
            o += 1;
        }
        s[j+1] = key;
    }
    return o;
}
};

void insertion_sort(vector<Seq>& a){
    int n = a.size();

    for (int i = 1; i < n; i++){
        Seq key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].ordem > key.ordem){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}

int main(){
    int M, n,m;
    string d;
    cin >> M;
    getline(cin,d);

    for (int i = 0; i < M; i++){
        
        cin >> n >> m;
        vector<Seq> v;
        
        for (int j = 0; j < m; j++){
            string s;
            cin >> s;
            v.push_back(Seq(s));
        } 

        insertion_sort(v);

        for (int j = 0; j < m; j++){
            cout << v[j].seq << endl;
        }

        if (i < M - 1){
            cout << endl;
        }
    }

    return 0;
}