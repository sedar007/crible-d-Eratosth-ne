#include <iostream>
using namespace std;
struct Element{
    int val;
    Element *next;
};

Element *initListe(){ // creation de ma tete de liste
    Element *tete = new Element;
    tete = nullptr;
    return tete;
}

void CreateListeN(Element **tete,int nombreElemnets){ // creation de la liste de N nombres en commencant par 1
    Element *ptr = new Element;

    int i;
    for(i=0; i<nombreElemnets - 1; i++ ){
        ptr->val = i+1;

        if(*tete == nullptr){
            *tete = ptr;
        }
        ptr->next = new Element;
        ptr = ptr->next;
    }
    ptr->val = i+1;
    ptr->next = nullptr;

}


void affichage(Element *tete){ // Afficher ma liste
    Element *ptr = tete;
	while(ptr!= nullptr){
		cout<<ptr->val<<" ";
		ptr = ptr->next;
	}	
}

void supprimerVal(Element *tete){ // Supprimer les nombres premiers
    int val = tete->val;

    Element *prec = tete;
    Element *ptr = tete->next;
    int i = 2;
    while(ptr !=nullptr){
        int res = val * i;

        if ( res == ptr->val){ // si i* val == ptr->val on suprime
            prec->next = ptr->next;
            i++;
        }

        else{
            if (res < ptr->val){ // si i* val < ptr->val on incremente, car on a deja suprimer  (i* val == ptr->val)
                i++;
            }    
            prec = ptr;
        }
        ptr = ptr->next;
        
    }
}

void MAJ(Element **liste, int *cpt){ // permet de mettre a jour et supprimer ts les valeurs
    *liste = (*liste)->next;
    Element *ptr = *liste;
    while(ptr != nullptr){
        supprimerVal(ptr);
        ptr = ptr->next;
        (*cpt)++;
    }
}
int main(){
    Element *liste = initListe();

    int nb;
    int cpt = 0;
    cout<<"Nombres Premiers inferieur a N!"<<endl;
    cout<<"Entrer un N? ";
    cin>> nb;
    CreateListeN(&liste, nb);
    
    MAJ(&liste, &cpt);
    
    cout<<"Les "<<cpt<<" nombres premiers inferieurs a "<<nb<<" sont: ";
    affichage(liste);
 
    
}