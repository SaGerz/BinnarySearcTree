#include <iostream>
#include <malloc.h>

using namespace std;

struct Node {
	struct Node *Left;
	int INFO;
	struct Node *Right;
};

typedef struct Node Simpul;
Simpul *P, *Q, *Root;

void inialisasi(){
	Root = NULL;
	P = NULL;
}

void BuatSimpul(int x){
	P = (Simpul*) malloc(sizeof(Simpul));
	if(P != NULL){
		P->INFO = x;
		P->Left = NULL;
		P->Right = NULL;
	} else {
		cout <<"Memory head full" << endl;
	}
}

void BuatSimpulAkar (){
	if(Root == NULL){
		if(P != NULL){
			Root = P;
			Root->Left = NULL;
			Root->Right = NULL;
		} else {
			cout << "Simpul Belum ada" << endl;
		}
	} else {
		cout << "Pohon sudah ada" << endl;
	}
}

void insert(int x, Simpul *Akar){
	Simpul *Q;
	if(Akar != NULL){
		int Flag = 0;
		Q = Akar;
		while(Flag == 0){
			if(x == Q->INFO){
				cout << "\nDuplicate " << x << endl;
				Flag = 1;
			} else {
				if(x < Q->INFO){
					if(Q->Left == NULL){
						Q->Left = P;
						Flag = 1;
					} else {
						Q = Q->Left;
					}
				} else {
					if(Q->Right == NULL){
						Q->Right = P;
						Flag = 1;
					} else {
						Q = Q->Right;
					}
				}
			}
		}
	} else {
		cout << "Akar Belum ada" << endl;
	}
}

void BacaInOrder(Simpul *T){
	if(T != NULL){
		BacaInOrder(T->Left);
		cout << T->INFO << " ";
		BacaInOrder(T->Right);
	}
}

int main(){
	int x;
	int A[7] = {60,75,66,44,20,84,55};
	int i = 0;
	x = A[i];
	inialisasi();
	BuatSimpul(x);
	BuatSimpulAkar();
	
	for(i=1; i<=6; i++){
		x=A[i];
		BuatSimpul(x);
		insert(x, Root);
	}
	
	cout << " ";
	BacaInOrder(Root);
	return 0;
		
}


