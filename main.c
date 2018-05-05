#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
void pac(){system("pause");
            system("cls");}
void err(){pac();
printf("Il comando inserito non esiste!\n");
pac();
printf("Turno saltato!\n");
pac();}
void loader() {
    int i;
    char str[] = "                                        ";
    for(i = 0 ; i <= 40 ; i++) {
        printf("\r[%s]", str);
        str[i] = '|';
      Sleep(150);
    }

}
int hp, m, ehp, r, scelta, attacco, eattacco, magia, cura, usmagic, stmagic, x, protection, fchance, rage, adamage, restart,
lifesteal, fireball, meter,c=0, stun, modifier, lastchance, powervita=0, powermp=0, dvita=30, dmp=10, taunt;
int enattacco;
int attack[] = {2,3,4,5,6}, magic[]={4,5,6,7}, heal[]={8,9,10}, umagic[]={1,2,3}, eattack[]={3,4,5,6},
smagic[]={2,3}, fdamage[]={8,9,10}, lastdamage[]={0,0,0,1,2,3,0,0,0};
char taunts[][20]={"Sono Invincibile!","Nervoso?","Sono Alessandro Il Grande!","Cabron!","Mi stai facendo arrabbiare, Pendejo!","La mia difesa e' inespugnabile!","Il mio stile e' impetuoso!"};
int main()
{
    printf("Benvenuto\n");
    pac();
    printf("Fai la tua scelta:\n\n 1: Tutorial\n 2: Gioca\n 3: Esci\n");
    scanf("%d", &scelta);
    switch(scelta){
case 1:
    {
        system("cls");
        printf("l'obbiettivo del gioco e' far arrivare la vita dell'avversario a 0\n");
        pac();
        printf("Puoi fare attaccandolo(1)\n");
        pac();
        printf("Se la tua vita scende a zero, hai perso\n");
        pac();
        printf("Gli MP servono per usare gli incantesimi, se scendono sotto lo zero, hai perso\n");
        pac();
        printf("Premendo 2 apri il menu degli incantesimi\nVengono dati gli incantesimi, una descrizone, ed il costo\n");
        pac();
        printf("Piu vinci, Piu il nemico diventa forte!\n");
        pac();
        printf("Ma anche tu diventi piu' forte!\n");
        pac();
        printf("Buona Fortuna!\n");
        pac();
        printf("\n\n\n\n\n\nNe avrai bisogno...\n");
        Sleep(50);
        system("cls");
        loader();
        system("cls");
    }
case 2:
    {
restart=1;

while(restart=1){
c++;
dvita=dvita+powervita;
dmp=dmp+powermp;
meter=0;
modifier=modifier+10;
protection=0;
rage=0;
hp=dvita;
ehp=10+modifier;
r=clock();
m=dmp+powermp;
    while(ehp>0)///finchè la vita del nemico è superiore a 0 il gioco non si ferma
    {
    system("cls");
    printf("Stai combattendo contro Nemico #%d\nSeleziona la tua prossima mossa!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n1: Attacca 2: Incantesimi\n\n",c, hp, m, ehp); /// schermata iniziale
    scanf("%d", &scelta);
    switch(scelta)
    {
        case 1: /// se la prima scelta è di attaccare
        {
        system("cls");
        srand(time(0));
        attacco=( rand() % 4 );
        adamage=attack[attacco];
        if(rage>0)
        {
        rage--;
        adamage=adamage*2;
        ehp=ehp-adamage;
        printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);
        }
        else
        {
        x=( rand() % 99);
            if(x<=6) /// prova a rollare per un attacco critico
            {
            adamage=adamage*2;
            ehp=ehp-adamage;
            printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);

            }
        else
        {
            if(x>=90) /// prova a rollare per un attacco missato
            {
            printf("Stai combattendo contro Nemico #%d\nIl tuo attacco manca l'avversario!\n\nCOLPO MANCATO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            }
            else
            {
            ehp=ehp-adamage;
             printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);
            }
        }
        }
            pac();
        }
        break;

        case 2: ///se scegli incantesimi
        {
        system("cls");
        printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\nScegli che incantesimo usare:\n1)Heal: Ti curi aggiungendo qualcosa alla tua vita(costo: 2 MP)\n2)Concentration: Aggiunge qualche punto ai tuoi MP(Costo: 0 MP)\n3)Protection: per 3 turni il danno subito sara' minore(costo: 5 MP)\n4)Rage: Farai piu' danni per 3 turni(Costo: 10 MP)\n5)Stun: Stordisci l'avversario impedendogli di attaccare per 2 turni(Costo: 7 MP)\n", hp, m, ehp);
        scanf("%d",&scelta); /// va nel menù incantesimi
        switch(scelta){
    case 1:
        {
            system("cls");
            srand(time(0));
            cura=( rand() % 2 );
            hp=hp+heal[cura];
            m=m-2;
            printf("Stai combattendo contro Nemico #%d\nUsando 2 di magia, aggiungi %d alla tua vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,heal[cura], hp, m, ehp);
            pac();
        }
        break;
    case 2:
    {
        system("cls");
        srand(time(0));
        magia=( rand() % 3 );
        m=m+magic[magia];
        printf("Stai combattendo contro Nemico #%d\nAggiungi %d alla tua magia!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,magic[magia], hp, m, ehp);
        pac();
    }
    break;
    case 3:
        {
            system("cls");
            protection=protection+3;
            m=m-5;
            printf("Stai combattendo contro Nemico #%d\nUsi 5 MP Per ridurre il danno che subisci per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
        }
        break;
    case 4:
        {
            system("cls");
            rage=rage+3;
            m=m-10;
            printf("Stai combattendo contro Nemico #%d\nUsi 10 MP Per aumentare il danno che fai per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
        }
        break;
    case 5:
        {
            system("cls");
            stun=stun+2;
            m=m-7;
            printf("Stai combattendo contro Nemico #%d\nUsi 7 MP Per bloccare il nemico per 2 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
        }
        break;
    default:
        {
            err();
        }
        break;
        }
        }
        break;
    default:
        {
            err();
        }
        break;

    }
 ///turno dell'avversario
if(stun>0)
{
   stun=stun-1;
   printf("Stai combattendo contro Nemico #%d\nL'avversario non riesce a muoversi\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
   meter=0;
}
else{
if(meter==-666)
{
    enattacco=15;
    hp=hp-enattacco;
    meter=0;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con un colpo caricato, togliendoti %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
}
else
{
if(meter>=30)
{
    meter=-666;
    taunt=(rand() % 6);
    printf("Stai combattendo contro Nemico #%d\nIl Nemico dice: '%s'\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,taunts[taunt], hp, m, ehp);
    pac();
    printf("Stai combattendo contro Nemico #%d\nIl Nemico sembra star caricando un colpo potente...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
}
else
{
srand(time(0));
fchance=(rand() % 9);
        if(fchance>=8) /// rolla per tirare una fireball, più danno
        {
        if(protection>0)
        protection--;
        fireball=(rand() % 2);
        enattacco=fdamage[fireball];
        hp=hp-enattacco;
        printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con una palla di fuoco, togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
        meter=meter+enattacco;
        }
    else
{
    eattacco=( rand() % 3 );
    enattacco=eattack[eattacco];

        if(protection>0) /// controlla se c'è protezione
        {
        protection--;
        enattacco=eattack[eattacco]-3;
        }
        srand(time(0));
        fchance=(rand() % 99);
    if(fchance<10)/// rolla per un lifesteal
    {
    hp=hp-enattacco;
    ehp=ehp+enattacco;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti ruba %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
    meter=meter+enattacco;
    }
    else
    {
    hp=hp-enattacco;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
    meter=meter+enattacco;
    }
    }
}
}
    }
pac();
    if((m < 0) || (hp <= 0)) /// controlla se ci sono endgame variabili
    {
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, m, ehp);
     system("pause");
     return 0;
    }
    }
/// esce e vinci
srand(time(0));
lastchance=(rand() % 99);
if(lastchance>=50)
{
    lastchance=(rand() % 8);
    hp=hp-lastdamage[lastchance];
    printf("Stai combattendo contro Nemico #%d\nCon le sue ultime energie il nemico ti attacca togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,lastdamage[lastchance], hp, m, ehp);
    pac();
    if((m < 0) || (hp <= 0)) /// controlla se ci sono endgame variabili
    {
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, m, ehp);
     system("pause");
     return 0;
    }
}
printf("Hai Vinto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nComplimenti!\n\n", hp, m, ehp);
pac();
printf("\nVuoi ricominciare?\n\n1=Si   0=No\n");
scanf("%d",&restart);
switch(restart){
case 1:
{
    system("cls");
    printf("Hai abbastanza esperienza per potenziarti!\n");
    pac();
    printf("Scegli tra questi 3 potenziamenti:\n\n1)Vita: Aumenta la tua vita iniziale (Vita +5)\n2)MP: Aumenta il tuo MP iniziale(MP +10)\n3)Attacco: Aumenta il tuo attacco iniziale (Attacco +1)\n");
    scanf("%d", &scelta);
    switch(scelta){
case 1:
    {
        powervita=powervita+5;
        system("cls");
        printf("Hai potenziato la tua vita!\n");
        pac();
    }
    break;
case 2:
    {
        powermp=powermp+5;
        system("cls");
        printf("Hai potenziato i tuoi mp!\n");
        pac();
    }
    break;
case 3:
    {
        attack[0]=attack[0]+1;
        attack[1]=attack[1]+1;
        attack[2]=attack[2]+1;
        attack[3]=attack[3]+1;
        attack[4]=attack[4]+1;
        system("cls");
        printf("Hai potenziato il tuo attacco!\n");
        pac();
    }
    break;
default:
    {
        err();
    }
    break;
    }
}

}
}
    }
default:
    {
        return 0;
    }
    }
return 0;

}

