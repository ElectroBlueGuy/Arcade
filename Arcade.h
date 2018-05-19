#ifndef ARCADE_H_INCLUDED
#define ARCADE_H_INCLUDED

FILE *fp;

void pac(){Sleep(500);
    system("pause");
            system("cls");}
void err(){pac();
printf("Il comando inserito non esiste!\n");
pac();
printf("Turno saltato!\n");
pac();}
void loader() {
    int i;
    system("cls");
    char str[] = "                                        ";
    for(i = 0 ; i <= 40 ; i++) {
        printf("\r[%s]", str);
        str[i] = '|';
      Sleep(150);
    }

}
void tutorial(){
    system("cls");
        printf("l'obbiettivo del gioco e' far arrivare la vita dell'avversario a 0\n");
        pac();
        printf("Puoi fare attaccandolo(1)\n");
        pac();
        printf("Se la tua vita scende a zero, hai perso\n");
        pac();
        printf("Gli MP servono per usare gli incantesimi\n");
        pac();
        printf("Premendo 2 apri il menu degli incantesimi\nVengono dati gli incantesimi, una descrizone, ed il costo\n");
        pac();
        printf("Piu vinci, Piu il nemico diventa forte!\n");
        pac();
        printf("Ma anche tu diventi piu' forte!\n");
        pac();
        printf("Buona Fortuna!\n");
        pac();

}
int hp, mp, ehp, r, scelta, attacco, eattacco, magia, cura, usmagic, stmagic, x, protection, fchance, rage, adamage, restart,
lifesteal, fireball, meter,c=0, stun, modifier, lastchance, powervita=0, powermp=0, dvita=30, dmp=10, taunt, score, chars, count, space, cc, colpocaricato= 10;
int enattacco;
int attack[] = {2,3,4,5,6}, magic[]={4,5,6,7}, heal[]={8,9,10}, umagic[]={1,2,3}, eattack[]={3,4,5,6},
smagic[]={2,3}, fdamage[]={8,9,10}, lastdamage[]={0,0,0,1,2,3,0,0,0};
char name[1000], taunts[][50]={"Sono Invincibile!","Cosa sei, nervoso?","Sono Alessandro Il Grande!","Cabron!","Mi stai facendo arrabbiare!","La mia difesa e' inespugnabile!","Il mio stile e' impetuoso!"};
void nomp(){ mp=0;
printf("Stai combattendo contro Nemico #%d\nNon hai abbastanza MP per lanciare l'incantesimo!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
pac();
}

#endif // ARCADE_H_INCLUDED
