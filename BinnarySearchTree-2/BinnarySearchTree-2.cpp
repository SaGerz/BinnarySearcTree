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
	Simpul *Q, *R;
	int NotDuplicate = 1;
	if(Akar != NULL){
		R = Akar;
		while(R != NULL && NotDuplicate){
			Q = R;
			if(x == Q->INFO){
				cout << "\nDuplicate " << x << endl;
				NotDuplicate = 0; 
			} else {
				if(x < Q->INFO){
					R = Q->Left;
				} else {
					R = Q->Right;
				}
			}
		}
		
		if(NotDuplicate){
			if(x < Q->INFO){
				Q->Left = P;
			} else {
				Q->Right = P;
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
