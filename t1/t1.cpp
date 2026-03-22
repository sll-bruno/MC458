#include <iostream>

using namespace std;

int is_present(int x, int* set, int* pos, int n){
    if (pos[x] >= 0 && pos[x] < n && set[pos[x]] == x){
        return 1;
    }
    return 0;
}

int main(){
    int q, N, x, i = 0, n = 0;
    int i_removed, last;
    char c;
    
    cin >> N >> q;

    int *set = new int[N];
    int *pos = new int[N];

    while (i++ < q){
        cin >> c;

        switch (c) {
            case 'p': // verifica se x pertence a S
                cin >> x;
                cout << is_present(x, set, pos, n) << endl;
                break;
            case 'i': // insere x em S
                cin >> x;

                if (is_present(x, set, pos, n)) break;

                set[n] = x;
                pos[x] = n;
                n += 1;
                break;
            case 'r': // remove x de S
                cin >> x;

                if (!is_present(x, set, pos, n)) break;

                i_removed = pos[x];
                last  = set[n-1];

                set[i_removed] = last;
                pos[last] = i_removed;
                n -= 1;

                break;
            case 'l': // reinicializa S
                n = 0;
                break;
        }

    }
    
    delete[] set;
    delete[] pos;

    return 0;
}
