#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int hp, m, ehp, r, scelta, attacco, eattacco, magia, cura, usmagic, stmagic, x, crit, protection, rage, rattacco;
int enattacco;
int attack[4], magic[3], heal[2], umagic[2], eattack[3], smagic[1];
int main()
{
    protection=0;
    rage=0;
    hp=30;
    ehp=45;
    r=clock();
    attack[0]=2;
    attack[1]=3;
    attack[2]=4;
    attack[3]=5;
    attack[4]=6;
    magic[0]=4;
    magic[1]=5;
    magic[2]=6;
    magic[3]=7;
    heal[0]=6;
    heal[1]=7;
    heal[2]=8;
    umagic[0]=1;
    umagic[1]=2;
    umagic[2]=3;
    eattack[0]=3;
    eattack[1]=4;
    eattack[2]=5;
    eattack[3]=6;
    smagic[0]=2;
    smagic[1]=3;
    m=10;
    while(ehp>0)
    {
        system ("pause");
        printf("\e[1;1H\e[2J");
        printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\n1: Attacca 2: Incantesimi\n\n", hp, m, ehp);
        scanf("%d", &scelta);
        if(scelta==1)
        {
            printf("\e[1;1H\e[2J");
            srand(time(0));
            attacco=( rand() % 4 );
            srand(time(0));
            x=( rand() % 99);
            if(x<=6)
            {
              crit=attack[attacco];
              crit=crit*3;
              ehp=ehp-crit;
              printf("Attacchi l'avversario togliendogli %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",crit, hp, m, ehp);
            }
            else
            {
                srand(time(0));
                x=( rand() % 99);
                if(x>=90)
                {
                    printf("Il tuo attacco manca l'avversario!\n\nCOLPO MANCATO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
                }
                else
                {
                    if(rage!=0)
                    {

                rage--;
                rattacco=attack[attacco]+4;
                ehp=ehp-rattacco;
                printf("Attacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",rattacco, hp, m, ehp);
                    }
                    else
                    {
                     ehp=ehp-attack[attacco];
                     printf("Attacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",attack[attacco], hp, m, ehp);
                }
            }
            system ("pause");
            printf("\e[1;1H\e[2J");
        }
        }
        else
        {
        if(scelta==2)
                {
                    printf("\e[1;1H\e[2J");
                    printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\nScegli che incantesimo usare usare:\n1)Heal: Ti curi aggiungendo qualcosa alla tua vita(costo: 2 MP)\n2)Concentration: Aggiunge qualche punto ai tuoi MP(Costo: 0 MP)\n3)Protection: per 3 turni il danno subito sara' minore(costo: 5 MP)\n4)Rage: Farai piu' danni per 3 turni(Costo: 10 MP)\n", hp, m, ehp);
                    scanf("%d",&scelta);
                    if(scelta==1)
                    {
                    printf("\e[1;1H\e[2J");
                    srand(time(0));
                    cura=( rand() % 2 );
                    hp=hp+heal[cura];
                    m=m-2;
                    printf("Usando 2 di magia, aggiungi %d alla tua vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",heal[cura], hp, m, ehp);
                    system ("pause");
                    printf("\e[1;1H\e[2J");
                    }
                    else
                    {
                        if(scelta==2)
                        {
                                printf("\e[1;1H\e[2J");
                                srand(time(0));
                                magia=( rand() % 3 );
                                m=m+magic[magia];
                                printf("Aggiungi %d alla tua magia!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",magic[magia], hp, m, ehp);
                                system ("pause");
                                printf("\e[1;1H\e[2J");
                        }
                        else
                        {
                            if(scelta==3)
                            {
                                printf("\e[1;1H\e[2J");
                                protection=protection+3;
                                m=m-5;
                                printf("Usi 5 MP Per ridurre il danno che subisci per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
                                system ("pause");
                                printf("\e[1;1H\e[2J");
                            }
                            else
                            {
                                if(scelta==4)
                                {
                                    printf("\e[1;1H\e[2J");
                                rage=rage+3;
                                m=m-10;
                                printf("Usi 10 MP Per aumentare il danno che fai per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
                                system ("pause");
                                printf("\e[1;1H\e[2J");
                                }
                            }
                        }

                    }
                }



                }

            srand(time(0));
            eattacco=( rand() % 3 );
            enattacco=eattack[eattacco];
            if(protection!=0)
            {
                protection--;
                enattacco=eattack[eattacco]-3;
            }

            hp=hp-enattacco;
            printf("L'avversario ti colpisce togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",enattacco, hp, m, ehp);
            system ("pause");
            printf("\e[1;1H\e[2J");
            if((m < 0) || (hp <= 0))
            {
                printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, m, ehp);
                system ("pause");
                return 0;
            }

        }
                printf("Hai Vinto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nComplimenti!\n\n", hp, m, ehp);
               system ("pause");
               return 0;
}






