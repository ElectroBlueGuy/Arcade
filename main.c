#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "arcade.h"

int main()
{
    printf("Inserisci il tuo nome(senza spazi): ");
    scanf("%s", name);
    while(name[count]!='\0')
    {
        count++;
        chars++;
    }
    space=12-chars;
    system("cls");
    printf("Benvenuto, %s\n", name);
    pac();
    MENU:printf("Fai la tua scelta:\n\n 1: Tutorial\n 2: Gioca\n 3: Punteggi\n 4: Esci\n");
    scanf("%d", &scelta);
    switch(scelta){
case 1:
    {
        tutorial();
    }
    goto MENU;
case 2:
    {
restart=1;

while(restart==1){
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
mp=dmp+powermp;
        loader();
        system("cls");
    while(ehp>0)///finchè la vita del nemico è superiore a 0 il gioco non si ferma
    {
    system("cls");
    printf("Stai combattendo contro Nemico #%d\nSeleziona la tua prossima mossa!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n1: Attacca 2: Incantesimi\n\n",c, hp, mp, ehp); /// schermata iniziale
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
        printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, mp, ehp);
        }
        else
        {
        x=( rand() % 99);
            if(x<=6) /// prova a rollare per un attacco critico
            {
            adamage=adamage*2;
            ehp=ehp-adamage;
            printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, mp, ehp);

            }
        else
        {
            if(x>=90) /// prova a rollare per un attacco missato
            {
            printf("Stai combattendo contro Nemico #%d\nIl tuo attacco manca l'avversario!\n\nCOLPO MANCATO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
            }
            else
            {
            ehp=ehp-adamage;
             printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, mp, ehp);
            }
        }
        }
            pac();
        }
        break;

        case 2: ///se scegli incantesimi
        {
        system("cls");
        printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\nScegli che incantesimo usare:\n1)Heal: Ti curi aggiungendo qualcosa alla tua vita(costo: 2 MP)\n2)Concentration: Aggiunge qualche punto ai tuoi MP(Costo: 0 MP)\n3)Protection: per 3 turni il danno subito sara' minore(costo: 5 MP)\n4)Rage: Farai piu' danni per 3 turni(Costo: 10 MP)\n5)Stun: Stordisci l'avversario impedendogli di attaccare per 2 turni(Costo: 7 MP)\n", hp, mp, ehp);
        scanf("%d",&scelta); /// va nel menù incantesimi
        switch(scelta){
    case 1:
        {
            system("cls");
            srand(time(0));
            cura=( rand() % 2 );
            mp=mp-2;
            if(mp<0)
            {
                nomp();
            }
            else
            {
            hp=hp+heal[cura];
            printf("Stai combattendo contro Nemico #%d\nUsando 2 di magia, aggiungi %d alla tua vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,heal[cura], hp, mp, ehp);
            pac();
            }
        }
        break;
    case 2:
    {
        system("cls");
        srand(time(0));
        magia=( rand() % 3 );
        mp=mp+magic[magia];
        printf("Stai combattendo contro Nemico #%d\nAggiungi %d alla tua magia!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,magic[magia], hp, mp, ehp);
        pac();
    }
    break;
    case 3:
        {
            system("cls");
            mp=mp-5;
              if(mp<0)
            {
                nomp();
            }
            else{
            protection=protection+3;
            printf("Stai combattendo contro Nemico #%d\nUsi 5 MP Per ridurre il danno che subisci per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
            pac();
            }
        }
        break;
    case 4:
        {
            system("cls");
            mp=mp-10;
               if(mp<0)
            {
                nomp();
            }
            else{
            rage=rage+3;
            printf("Stai combattendo contro Nemico #%d\nUsi 10 MP Per aumentare il danno che fai per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
            pac();
            }
        }
        break;
    case 5:
        {
            system("cls");
            mp=mp-7;
               if(mp<0)
            {
                nomp();
            }
            else
            {
            stun=stun+2;
            printf("Stai combattendo contro Nemico #%d\nUsi 7 MP Per bloccare il nemico per 2 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
            pac();
            }
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
if(ehp>0)
{
if(stun>0)
{
   stun=stun-1;
   printf("Stai combattendo contro Nemico #%d\nL'avversario non riesce a muoversi\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
   meter=0;
}
else{
if(meter==-666)
{
    enattacco=15;
    hp=hp-enattacco;
    meter=0;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con un colpo caricato, togliendoti %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, mp, ehp);
}
else
{
if(meter>=30)
{
    meter=-666;
    taunt=(rand() % 6);
    printf("Stai combattendo contro Nemico #%d\nIl Nemico dice: %s\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,taunts[taunt], hp, mp, ehp);
    pac();
    printf("Stai combattendo contro Nemico #%d\nIl Nemico sembra star caricando un colpo potente...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
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
        printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con una palla di fuoco, togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, mp, ehp);
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
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti ruba %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, mp, ehp);
    meter=meter+enattacco;
    }
    else
    {
    hp=hp-enattacco;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, mp, ehp);
    meter=meter+enattacco;
    }
    }
}
}
    }
    pac();
}

    if(hp <= 0) /// controlla se ci sono endgame variabili
    {
    printf("Stai combattendo contro Nemico #%d\nCrolli a terra, senza energie...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
    pac();
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, mp, ehp);
    pac();
    printf("Vuoi salvare il tuo punteggio?\n1=Si\n");
    scanf("%d", &scelta);
if(scelta==1)
    {
    fp = fopen("score.txt", "a+");
    score=c-1;
    fprintf(fp, "%s", name);
    for(;space!=0;space--)
    {
      fprintf(fp, "%s", " ");
    }
    fprintf(fp, "%s %s %s %d", "|", " ", " ", score);
    fprintf(fp, "%s", "\n");
    fclose(fp);
    }
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
    printf("Stai combattendo contro Nemico #%d\nCon le sue ultime energie il nemico ti attacca togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,lastdamage[lastchance], hp, mp, ehp);
    pac();
    if(hp <= 0) /// controlla se ci sono endgame variabili
    {
     printf("Stai combattendo contro Nemico #%d\nCrolli a terra, senza energie...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
    pac();
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, mp, ehp);
    pac();
    printf("Vuoi salvare il tuo punteggio?\n1=Si\n");
    scanf("%d", &scelta);
    if(scelta==1)
    {
    fp = fopen("score.txt", "a+");
    score=c-1;
    fprintf(fp, "%s", name);
    for(;space!=0;space--)
    {
      fprintf(fp, "%s", " ");
    }
    fprintf(fp, "%s %s %s %d", "|", " ", " ", score);
    fprintf(fp, "%s", "\n");
    fclose(fp);
    }
     system("pause");
     return 0;
    }
}
printf("Stai combattendo contro Nemico #%d\nIl nemico crolla a terra, sconfitto...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, mp, ehp);
printf("Hai Vinto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nComplimenti!\n\n", hp, mp, ehp);
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
case 3:
    {
system ("cls");
fp = fopen("score.txt", "r");
if (fp) {
    while ((cc = getc(fp)) != EOF)
        putchar(cc);
    fclose(fp);
    pac();
 goto MENU;
    }
    }
 break;
case 4:
    {
return 0;
    }
    break;
default:
    {
        return 0;
    }
    break;
    }
return 0;
}

