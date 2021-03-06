 struct Position {
       int cases_joueur[10]; // chaque case contient un nombre de
                                       // pions
       int cases_ordi[10];
       bool ordi_joue; // boolean vrai si c'est � l'ordi de jouer et faux sinon
       int pions_pris_joueur; // pions pris par le joueur
       int pions_pris_ordi; // pions pris par l'ordi
 };
 
 int main(int argc, char*[] args){
	
	if(argc == 1){
		
	} else if(argc > 1){
		// Erreur 
		return 1;
	}
	
	
 }

 int valeurMinMax(Position* pos_courante, ordi_joue, prof, profMax){
       // ordi_joue est un booleen qui est vrai si l'ordi joue
       int tab_valeurs[10];
       Position pos_next; // En C on cr�e dans la pile = TRES rapide

       if (positionFinale(pos_courante, ordi_joue,prof)){
               // code � �crire
               // on retourne VALMAX (=48) si l'ordi gagne et -48 si l'ordi perd  et 0 si nul
       }
       if (prof == profMax) {
               return evaluation(pos_courante, ordi_joue,prof);
               // dans un premier temps l'�valuation sera la
               // diff�rence du nb de pions pris
       }
       for(int i=0;i<6;i++){
               // on joue le coup i
               // ecrire la fn coupValide(pos_courante,ordi_joue,i)
               // elle teste si on peut prendre les pions dans la
               // case i et les jouer (si pas de pion alors elle retourne invalide). La position de d�part
               // est pos_courante
               if (coupValide(pos_courante,ordi_joue,i)){
                       // ecrire la fn :
			 jouerCoup(&pos_next,pos_courante, ordi_joue-i)
                       // on joue le coup i a partir de la position
                       // pos_courante et on met le r�sultat
                       // dans pos_next
                       jouerCoup(&pos_next,pos_courante,ordi_joue,i);
 			// pos_next devient la position courante, et on change le joueur
                       tab_valeurs[i]=valeurMinMax(&pos_next, !ordi_joue,prof+1,profMax);
               } else {
			if (joueur==0) tab_valeurs[i]=-100.
			else tab_valeurs[i]=+100;
               }
       }
       int res;
       if (ordi_joue){
               // ecrire le code: res contient le MAX de
               // tab_valeurs
       } else {
               // ecrire le code : res contient le MIN de
               // tab_valeurs
       }
       return res;
}
