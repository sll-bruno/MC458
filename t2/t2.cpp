#include <iostream>
#define NEG_INF -2147483648

using namespace std;

//Struct que representa um nó
struct Node{
    int value;
    Node* l;
    Node* r;

    //Constructor: Inicializa weight com value e os ponteiros l e r como nullptr
    Node(int value): value(value), l(nullptr), r(nullptr) {}
};

class BinaryTree{

    private:
    Node* root;
    int maior_caminho = NEG_INF;

    // left - right - root
    int percurso_pos_ordem(Node* node){
        if (node == nullptr) return 0;
        if (node->l == nullptr && node->r == nullptr) return max(node->value,0);

        int val_esq = percurso_pos_ordem(node->l);
        int val_dir = percurso_pos_ordem(node->r);

        val_esq = max(val_esq, 0);
        val_dir = max(val_dir, 0);

        int soma = max(node->value + val_esq + val_dir,0);

        if (soma > this->maior_caminho) this->maior_caminho = soma;

        if (this->root == node) {
            return maior_caminho;
        }
        else{
            return node->value + max(val_esq,val_dir);
        } 
    }

    public:
    BinaryTree(): root(nullptr) {}

    void read_tree(){
        this->root = read_tree_rec();
    }

    Node* read_tree_rec(){        
        int p;
        char flagE, flagD;

        cin >> p;
        Node* new_node = new Node(p);

        cin >> flagE;

        if (flagE == 'T') new_node->l=read_tree_rec();

        cin >> flagD;

        if (flagD == 'T') new_node->r=read_tree_rec();

        return new_node;
    }

    int get_maior_caminho(){
        return percurso_pos_ordem(this->root);
    }
};

int main(){

    BinaryTree t = BinaryTree();
    t.read_tree();

    cout << t.get_maior_caminho() << endl;

    return 0;
}