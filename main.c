#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct yigin
{
    char data;
    struct yigin *next;
};
struct yigin *ilk=NULL,*son=NULL;


struct order_struct
{
    int order_data;
    int serial_number;
    struct order_struct *next;
};
struct order_struct *ilk_2=NULL,*son_2=NULL;


void sonaEkle(char a)
{
    struct yigin *yeni = (struct yigin*)malloc(sizeof(struct yigin));

    yeni->data=a;
    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=NULL;
    }
    else
    {
        son->next=yeni;
        son=yeni;
        son->next=NULL;
    }
}

int counter=0;
int main_trigger=0;

void ord_sonaEkle(int a)
{
    struct order_struct *yeni = (struct order_struct*)malloc(sizeof(struct order_struct));

    yeni->order_data=a;
    yeni->serial_number=counter;

    if(ilk_2==NULL)
    {
        ilk_2=yeni;
        son_2=yeni;
        son_2->next=NULL;
    }
    else
    {
        son_2->next=yeni;
        son_2=yeni;
        son_2->next=NULL;
    }


    if(ilk_2==1)
    {
        main_trigger=1;
    }



    counter++;
}

void Listele()
{
    struct yigin *liste=ilk;
    while(liste != NULL)
    {
        printf("%c",liste->data);
        liste=liste->next;
    }
}

void order_Listele()
{
    struct order_struct *liste=ilk_2;
    while(liste != NULL)
    {
        printf("CODE:%d\t\t",liste->order_data);
        printf("NUMBER:%d\n",liste->serial_number);
        liste=liste->next;
    }
}


void coder(int size)
{
    struct yigin *aranan=ilk;
    int control=0;

    while(aranan!=NULL)
    {
        if(control < size-3 && aranan->data=='m' && aranan->next->data=='a' && aranan->next->next->data=='i' && aranan->next->next->next->data=='n')
        {
            ord_sonaEkle(1);
            printf("\tmain\t--->1\n");
            aranan=aranan->next->next->next;
        }
        if(control < size-2 &&aranan->data=='f' && aranan->next->data=='o' && aranan->next->next->data=='r')
        {
            ord_sonaEkle(2);
            printf("\tfor\t--->2\n");
            aranan=aranan->next->next;
        }
        if(control < size-4 &&aranan->data=='w' && aranan->next->data=='h' && aranan->next->next->data=='i'&& aranan->next->next->next->data=='l'&& aranan->next->next->next->next->data=='e')
        {
            ord_sonaEkle(3);
            printf("\twhile\t--->3\n");
            aranan=aranan->next->next->next->next;
        }
        if(control < size-5 && aranan->data=='s' && aranan->next->data=='w' && aranan->next->next->data=='i'&& aranan->next->next->next->data=='t'&& aranan->next->next->next->next->data=='c' && aranan->next->next->next->next->next->data=='h')
        {
            ord_sonaEkle(4);
            printf("\tswitch\t--->4\n");
            aranan=aranan->next->next->next->next->next;
        }
        if(control < size-5 && aranan->data == 'e' && aranan->next->data == 'l' && aranan->next->next->data == 's' && aranan->next->next->next->data == 'e'&& aranan->next->next->next->next->data == 'i'&& aranan->next->next->next->next->next->data == 'f')
        {
            ord_sonaEkle(7);
            printf("\t else if\t--->5\n");
            aranan=aranan->next->next->next->next->next;
        }
        if(control < size-1 && aranan->data=='i' && aranan->next->data=='f')
        {
            ord_sonaEkle(5);
            printf("\tif\t--->5\n");
            aranan=aranan->next;
        }
        if(control < size-3 && aranan->data == 'e' && aranan->next->data == 'l' && aranan->next->next->data == 's' && aranan->next->next->next->data == 'e')
        {
            ord_sonaEkle(6);
            printf("\telse if\t--->7\n");
            aranan=aranan->next->next->next;
        }
        if(control < size-3 && aranan->data == 'c' && aranan->next->data == 'a' && aranan->next->next->data == 's' && aranan->next->next->next->data == 'e')
        {
            ord_sonaEkle(8);
            printf("\tcase \t--->8\n");
            aranan=aranan->next->next->next;
        }
        if(control < size-2 &&aranan->data == 'd' && aranan->next->data == 'o'  && aranan->next->next->data == '{')
        {
            ord_sonaEkle(9);
            printf("\tdo \t--->9\n");
            aranan=aranan->next;
        }
        if(aranan->data=='{')
        {
            ord_sonaEkle(10);
            printf("\t   {\t--->10\n\n");
        }
        if(aranan->data=='}')
        {
            ord_sonaEkle(11);
            printf("\t   }\t--->11\n\n");
        }
        control++;
        aranan=aranan->next;
    }
}

char string_num[]= {'0','1','2','3','4','5','6','7','8','9'};

int char_to_int(char ch)//CHAR OLAN SAYIYI INT DEGERINI DONDURUR+++
{
    int i=0;
    for(i=0; i<10; i++)
    {
        if(ch==string_num[i])
        {

            return i;
            break;
        }
    }
    if(i==10)
        return 'char';
}

int digit_trigger=0;
int digit_temp;

int digit(int num)
{
    if(digit_trigger==0)
    {
        digit_temp=(digit_temp+num);
        digit_trigger++;
        return digit_temp;
    }
    else
    {
        digit_temp=(10*digit_temp)+num;
        return digit_temp;
    }
}

int memory=0;
int memory_num_of_1=0;
int memory_num_of_2=0;

void memory_finder(struct yigin *liste,int byte)
{
    int num;
    int num_2;
    int num_3;//MATRIKSIN IKINCI BOYUTUNU TUTAR

    while(liste != NULL)
    {
        if(liste->data != '[' && liste->data != ';' && liste->data != ',' && liste->data != '(')
        {
            printf("%c",liste->data);
        }
        if(liste->data == '[')//INT DEGISKENIN BOYUTUNU MEMORY'E EKLER
        {
            if(liste->data=='[' && liste->next->data==']' && liste->next->next->data=='['&& liste->next->next->next->data==']')
            {
                printf("->ICI BOS IKI BOYUTLU MATRIKS n^2 byte\n",byte);
                memory_num_of_2=memory_num_of_2+byte;
            }
            else if(liste->data=='[' && liste->next->data==']')
            {
                printf("-->ICI BOS BIR BOYUTLU DIZI n byte\n",byte);
                memory_num_of_1=memory_num_of_1+byte;
            }
            else if(liste->data=='['&& liste->next->data!=']')
            {
                liste=liste->next;
                num=char_to_int(liste->data);

                if(num != 'char')
                {
                    num_2=digit(num);
                    liste=liste->next;

                    while(liste->data != ']' && char_to_int(liste->data) != 'char')
                    {
                        num=char_to_int(liste->data);
                        num_2=digit(num);
                        liste=liste->next;
                    }

                    if(liste->data==']' && liste->next->data !='[')//BIR BOYUTLU DIZI
                    {
                        printf("->BIR BOYUTLU DIZI %d byte\n",byte*num_2);
                        memory=(byte*num_2)+memory;
                    }
                    else if(liste->data==']' && liste->next->data =='[')//IKI BOYUTLU DIZI
                    {
                        liste=liste->next;
                        liste=liste->next;

                        while(liste->data != ']')
                        {
                            num=char_to_int(liste->data);
                            if(num != 'char')
                            {
                                digit_temp=0;
                                digit_trigger=0;
                                num_3=digit(num);
                                liste=liste->next;

                                while(liste->data != ']' && char_to_int(liste->data) != 'char')
                                {
                                    num=char_to_int(liste->data);
                                    num_3=digit(num);
                                    liste=liste->next;
                                }
                                printf("->IKI BOYUTLU DIZI %d byte\n",byte*num_2*num_3);
                                memory=memory+(byte*num_2*num_3);
                                break;
                            }
                            else if(num == 'char')
                            {
                                printf("->IKI BOYUTLU DIZI n byte\n");
                                memory_num_of_1=memory_num_of_1+byte;
                                break;
                            }
                            liste=liste->next;
                        }
                    }
                }
                else if(num == 'char')
                {
                    while(liste->data!=']')
                    {
                        liste=liste->next;
                    }
                    liste=liste->next;

                    if(liste->data == '[')
                    {
                        liste=liste->next;
                        num=char_to_int(liste->data);
                        if(num != 'char')
                        {
                            printf("->IKI BOYUTLU DIZI n byte\n");
                            memory_num_of_1=memory_num_of_1+byte;
                        }
                        else if(num == 'char')
                        {
                            printf("->IKI BOYUTLU DIZI n^2 byte\n");
                            memory_num_of_2=memory_num_of_2+byte;
                        }
                    }
                    else if(liste->data != '[')
                    {
                        printf("->BIR BOYUTLU DIZI n byte\n");
                        memory_num_of_1=memory_num_of_1+byte;
                    }
                }
            }
            break;
        }
        if(liste->data == ';')//INT DEGISKENIN BOYUTUNU MEMORY'E EKLER
        {
            printf("->DEGISKEN %d byte\n",byte);
            memory=(memory+byte);
            liste=liste->next;
            break;
        }
        else if(liste->data == ',')
        {
            printf("->DEGISKEN %d byte\n",byte);

            memory=(memory+byte);

            if(variable_type(liste->next)==0)
            {

            }
            else
                break;
        }
        else if(liste->data == ')')
        {
            printf("->DEGISKEN %d byte\n",byte);
            liste=liste->next;
            memory=(memory+byte);
            break;
        }
        else if(liste->data == '(')//FONKSIYONLAR
        {
            printf("->FONKSIYON / PRINTF\n",byte);
            break;
        }
        liste=liste->next;

    }
    printf("\n");
    digit_temp=0;
    digit_trigger=0;
}

void variable_fun()
{
    struct yigin *liste=ilk;

    while(liste != NULL)
    {
        if(variable_type(liste)==1)//CHAR
        {
            printf("char ");
            liste=liste->next->next->next->next;
            memory_finder(liste,1);
        }
        else if(variable_type(liste)==2)//INT //KONTROL BOLGESI
        {
            printf("int ");
            liste=liste->next->next->next;
            memory_finder(liste,4);
        }
        else if(variable_type(liste)==3)//FLOAT
        {
            printf("float ");

            liste=liste->next->next->next->next->next;
            memory_finder(liste,4);
        }
        else if(variable_type(liste)==4)//LONG
        {
            printf("long ");
            liste=liste->next->next->next->next;
            memory_finder(liste,8);
        }
        else if(variable_type(liste)==5)//SHORT
        {
            printf("short ");
            liste=liste->next->next->next->next;
            memory_finder(liste,2);
        }
        else if(variable_type(liste)==6)//DOUBLE
        {
            printf("double ");
            liste=liste->next->next->next->next->next->next;
            memory_finder(liste,8);
        }
        else if(variable_type(liste)==7)//RETURN
        {
            printf("return->");
            liste=liste->next->next->next->next->next->next;
                memory=memory+4;
        }
        liste=liste->next;
    }
}

int variable_type(struct yigin *liste)
{
    if(liste->data=='c' && liste->next->data=='h' && liste->next->next->data=='a'&& liste->next->next->next->data=='r')
    {
        return 1;
    }
    else if(liste->data=='i' && liste->next->data=='n' && liste->next->next->data=='t')
    {
        return 2;
    }
    else if(liste->data=='f' && liste->next->data=='l' && liste->next->next->data=='o'&& liste->next->next->next->data=='a'&& liste->next->next->next->next->data=='t')
    {
        return 3;
    }
    else if(liste->data=='l' && liste->next->data=='o' && liste->next->next->data=='n'&& liste->next->next->next->data=='g')
    {
        return 4;
    }
    else if(liste->data=='s' && liste->next->data=='h' && liste->next->next->data=='o'&& liste->next->next->next->data=='r'&& liste->next->next->next->next->data=='t')
    {
        return 5;
    }
    else if(liste->data=='d' && liste->next->data=='o' && liste->next->next->data=='u'&& liste->next->next->next->data=='b'&& liste->next->next->next->next->data=='l' && liste->next->next->next->next->next->data=='e')
    {
        return 6;
    }
    else if(liste->data=='r' && liste->next->data=='e' && liste->next->next->data=='t'&& liste->next->next->next->data=='u'&& liste->next->next->next->next->data=='r' && liste->next->next->next->next->next->data=='n')
    {
        return 7;
    }
    else
        return 0;

}

int type_bigO()
{
    struct yigin *liste=ilk;

    while(liste != NULL)
    {
        if(liste->data=='f' && liste->next->data=='o' && liste->next->next->data=='r')
        {
            for_fun(liste);
        }
        else if(liste->data=='w' && liste->next->data=='h' && liste->next->next->data=='i'&& liste->next->next->next->data=='l'&& liste->next->next->next->next->data=='e')
        {
            while_fun(liste);
        }
        else if(liste->data == 'r' && liste->next->data=='i' && liste->next->next->data=='n' && liste->next->next->next->data=='t')
        {
            liste=liste->next->next->next->next;
        }
        else if(liste->data=='i' && liste->next->data=='n' && liste->next->next->data=='t')
        {
            recursive_fun(liste);
        }
        liste=liste->next;
    }
}

char sequence_array[50];
int  sequence_counter=0;

void operation_sequence(int number)
{
    switch(number)
    {
        case 1://TOPLAM
        {
            sequence_array[sequence_counter]='+';
            sequence_counter++;
            break;
        }
        case 2://CARPMA
        {
            sequence_array[sequence_counter]='*';
            sequence_counter++;
            break;
        }
    }
}

int bigO_all[50][2];
int bigO_all_counter=0;

int teta=0;

void bigO_analyzer(int number,int magnitude)
{
    switch(number)
    {
    case 1:
    {
        bigO_all[bigO_all_counter][0]=1;
        bigO_all[bigO_all_counter][1]=magnitude;
        bigO_all_counter++;
        break;
    }
    case 2:
    {
        bigO_all[bigO_all_counter][0]=2;
        bigO_all[bigO_all_counter][1]=magnitude;
        bigO_all_counter++;
        break;
    }
    case 3:
    {
        bigO_all[bigO_all_counter][0]=3;
        bigO_all[bigO_all_counter][1]=magnitude;
        bigO_all_counter++;
        break;
    }
    }
}

void Theta_printer()
{
    printf("Theta (T()) exact bound of the complexity:\n");
    for(int i=0; i<bigO_all_counter; i++)
    {
        if(bigO_all[i][0]==1)
        {
            printf("%d ",bigO_all[i][1]);
        }
        else if(bigO_all[i][0]==2)
        {
            if(bigO_all[i][1]>0)
            {
                if(bigO_all[i][1]==1)
                {
                    printf("n ");
                }
                else
                    printf("%d*n ",bigO_all[i][1]);
            }
            else if(bigO_all[i][1]==0)
            {
                printf("n^2 ");
            }
            else
                printf("n/%d ",-bigO_all[i][1]);
        }
        else if(bigO_all[i][0]==3)
        {
            printf("log%d n ",bigO_all[i][1]);
        }
        printf("%c ",sequence_array[i]);
    }
    printf("\n");
}

int bigO_all_2[50][2];
int bigO_all_2_counter=0;

void bigO_all_analyzer_2_n(int upper,int log_n_control)
{
    bigO_all_2[bigO_all_2_counter][0]=upper;
    bigO_all_2[bigO_all_2_counter][1]=log_n_control;
    bigO_all_2_counter++;
}


void bigO_all_2_n_printer()
{
    for(int i=0; i<bigO_all_2_counter; i++)
    {
        printf("n^%d +", bigO_all_2[i][0]);
    }
}

void bigO()
{
    int max[1][2];
    max[0][0]=bigO_all_2[0][0];
    max[0][1]=bigO_all_2[0][1];
    for(int i=1; i<bigO_all_2_counter; i++)
    {
        if(max[0][0]<bigO_all_2[i][0])
        {
            max[0][0]=bigO_all_2[i][0];
            max[0][1]=bigO_all_2[i][1];
        }
        else if(max[0][0]==bigO_all_2[i][0])
        {
            if(max[0][1]<bigO_all_2[i][1])
            {
                max[0][1]=bigO_all_2[i][1];
            }
        }
    }
    printf("\nTIME COMPLEXITY BIGO\n");

    if(max[0][0] != 0 && max[0][1] != 0)
    {
        printf("O(n^%d*logn)\n",max[0][0]);
    }
    else if(max[0][0] == 0 && max[0][1] == 0)
    {
        printf("O(1)\n");
    }
    else if(max[0][0] == 0 && max[0][1] != 0)
    {
        printf("O(logn)\n");
    }
    else
    {
        printf("O(n^%d)\n",max[0][0]);
    }
}

void bigO_all_mult()
{
    int trigger=0;
    int trigger_2=0;
    for(int i=0; i<bigO_all_counter; i++)
    {
start:
        if(sequence_array[i]=='*')
        {
            if(bigO_all[i][0]==1)
            {
                i++;
                goto start;
            }
            else if(bigO_all[i][0]==2)
            {
                if(bigO_all[i][1]==0)
                {
                    trigger=trigger+2;
                }
                else
                {
                    trigger++;
                }
                i++;
                goto start;
            }
            else if(bigO_all[i][0]==3)
            {
                trigger_2++;
                i++;
                goto start;
            }
        }
        else if(sequence_array[i]=='+')
        {

            if(bigO_all[i][0]==2)
            {
                if(bigO_all[i][1]==0)
                {
                    trigger=trigger+2;
                }
                else
                {
                    trigger++;
                }
            }
            else if(bigO_all[i][0]==3)
            {
                trigger_2++;
            }

            bigO_all_analyzer_2_n(trigger,trigger_2);
            trigger=0;
            trigger_2=0;
        }
    }
}


char name[50];
int name_counter_1=0;

void fun_name_array(char ch)
{
    name[name_counter_1]=ch;
    name_counter_1++;
}

int que_to_array(char ch)
{
    return ch;
}

void recursive_fun(struct yigin *list)
{
    char fun_name[50];
    char temp_char;

    list=list->next->next->next;

    while(list->data != '(' && list->data != ';' && list->data != ')'&& list->data != '[')
    {
        fun_name_array(list->data);
        list=list->next;
    }
    if(list->data==';')
    {
        name_counter_1=0;
    }
    else if(list->data=='[')
    {
        name_counter_1=0;
    }
    else if(list->data=='(')
    {
        while(list!=NULL)
        {
            if(list->data == '{')
            {
                list=list->next;

                while(list != NULL && list->data != '}')
                {
                    if(que_to_array(list->data) == name[0])
                    {
                        list=list->next;

                        for(int i=1; i<name_counter_1; i++)
                        {
                            if(que_to_array(list->data) == name[i])
                            {
                                printf("%c",list->data);
                                list=list->next;
                            }
                            else
                            {
                                break;
                            }
                            if(i+1==name_counter_1)
                            {
                                list=list->next;
                                memory_num_of_1=memory_num_of_1+1;
                                memory=memory-4;

                                printf("%c",list->data);

                                if(char_to_int(list->data) == 'char')
                                {
                                    bigO_analyzer(2,1);
                                    operation_sequence(1);
                                }
                                break;
                            }
                        }
                    }
                    list=list->next;
                }
                break;
            }
            list=list->next;
        }
        name_counter_1=0;
    }
    else if(list->data==')')
    {
        name_counter_1=0;
    }
    list=list->next;
}


void while_fun(struct yigin *list)
{
    int num=0;
    int num_2=0;
    int temp_num=0;

    list=list->next->next->next->next->next->next;

    while(list != NULL &&list->data !=')')
    {
        if((list->data=='<'&& list->next->data!='=') || (list->data=='>'&& list->next->data!='='))
        {
            list=list->next;

            while(list->data !=')')
            {
                if(char_to_int(list->data) != 'char')
                {
                    num=char_to_int(list->data);
                    num_2=digit(num);
                }
                else if(char_to_int(list->data) == 'char')
                {
                    while(list->data !=')')
                    {
                        if(list->data=='*')
                        {
                            list=list->next;
                            if(char_to_int(list->data) != 'char')
                            {
                                while(list != NULL && list->data != ')')
                                {
                                    num=char_to_int(list->data);
                                    temp_num=digit(num);
                                    list=list->next;
                                }
                                bigO_analyzer(2,temp_num);
                            }
                            else if(char_to_int(list->data) == 'char')
                            {
                                bigO_analyzer(2,0);
                            }
                            break;
                        }
                        else if(list->data=='/')
                        {
                            list=list->next;
                            if(char_to_int(list->data) != 'char')
                            {
                                while(list != NULL && list->data != ')')
                                {
                                    num=char_to_int(list->data);
                                    temp_num=digit(num);
                                    list=list->next;
                                }
                                bigO_analyzer(2,-temp_num);
                            }
                            break;
                        }
                        else if(list->next->data==')')
                        {
                            bigO_analyzer(2,1);
                        }
                        list=list->next;
                    }
                    break;
                }
                list=list->next;
            }
            break;
        }
        else if((list->data=='<'&& list->next->data=='=') || (list->data=='>'&& list->next->data=='='))
        {
            list=list->next;
            list=list->next;

            while(list->data !=')')
            {
                if(char_to_int(list->data) != 'char')
                {
                    num=char_to_int(list->data);
                    num_2=digit(num);
                }
                else if(char_to_int(list->data) == 'char')
                {
                    while(list->data !=')')
                    {
                        if(list->data=='*')
                        {
                            list=list->next;
                            if(char_to_int(list->data) != 'char')
                            {
                                while(list != NULL && list->data != ')')
                                {
                                    num=char_to_int(list->data);
                                    temp_num=digit(num);
                                    list=list->next;
                                }
                                bigO_analyzer(2,temp_num);
                            }
                            else if(char_to_int(list->data) == 'char')
                            {
                                bigO_analyzer(2,0);
                            }
                            break;
                        }
                        else if(list->data=='/')
                        {
                            list=list->next;
                            if(char_to_int(list->data) != 'char')
                            {
                                while(list != NULL && list->data != ')')
                                {
                                    num=char_to_int(list->data);
                                    temp_num=digit(num);
                                    list=list->next;
                                }
                                bigO_analyzer(2,-temp_num);
                            }
                            break;
                        }
                        else if(list->next->data==')')
                        {
                            bigO_analyzer(2,1);

                        }
                        list=list->next;
                    }
                    break;
                }
                list=list->next;
            }
            break;
        }
        list=list->next;
    }
    if(num_2 !=0)
    {
        bigO_analyzer(1,num_2);
        teta=teta+num_2;
    }
    num_2=0;
    digit_temp=0;
    digit_trigger=0;
    list=list->next;
}


char thirdBase[255];
int thirdBaseCounter=0;

void for_array(char ch)
{
    thirdBase[thirdBaseCounter]=ch;
    thirdBaseCounter++;
}

void for_fun(struct yigin *requir)
{
    int start_int_trigger=0;
    int limit_int_trigger=0;

    requir=requir->next->next->next->next;

    while(requir!=NULL && requir->data!=')')
    {
        if(requir->data=='=')
        {
            requir=requir->next;
             if(char_to_int(requir->data) != 'char')
                {
                    start_int_trigger++;
                }
            while(requir->data !=';')
            {
                requir=requir->next;
            }

            requir=requir->next;

            while(requir->data !=';')
            {
                if((requir->data=='<'&& requir->next->data!='=') || (requir->data=='>'&& requir->next->data!='='))
                {
                    requir=requir->next;
                        if(char_to_int(requir->data) != 'char')
                        {
                            limit_int_trigger++;
                        }
                    while(requir->data !=';')
                    {
                        requir=requir->next;
                    }
                    requir=requir->next;

                    while(requir->data !=')')
                    {
                        for_array(requir->data);
                        requir=requir->next;
                    }

                    if(start_int_trigger == 0 && limit_int_trigger ==0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger != 0 && limit_int_trigger ==0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger == 0 && limit_int_trigger !=0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger != 0 && limit_int_trigger !=0)
                    {
                        thirdPart(1);
                    }
                    break;
                }
                else if((requir->data=='<'&& requir->next->data=='=') || (requir->data=='>'&& requir->next->data=='='))
                {
                    requir=requir->next->next;

                     if(char_to_int(requir->data) != 'char')
                        {
                            limit_int_trigger++;
                        }
                    while(requir->data !=';')
                    {
                        requir=requir->next;
                    }

                    requir=requir->next;

                    while(requir->data !=')')
                    {
                        for_array(requir->data);
                        requir=requir->next;
                    }

                    if(start_int_trigger == 0 && limit_int_trigger ==0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger != 0 && limit_int_trigger ==0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger == 0 && limit_int_trigger !=0)
                    {
                        thirdPart(2);
                    }
                    if(start_int_trigger != 0 && limit_int_trigger !=0)
                    {
                        thirdPart(1);
                    }
                    break;
                }
                requir=requir->next;
            }
            break;
        }
        requir=requir->next;
    }
    thirdBaseCounter=0;
    requir=requir->next;
    digit_temp=0;
    digit_trigger=0;
}

int thirdPart(int number)
{
    int i=0;
    int num=0;
    int num_2=0;
    digit_temp=0;
    digit_trigger=0;

    if(strstr(thirdBase,"++")!=NULL)
    {
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else
            bigO_analyzer(2,1);

    }
    else if(strstr(thirdBase,"--")!=NULL)
    {
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else
            bigO_analyzer(2,1);

    }
    else if(strstr(thirdBase,"+=")!=NULL)
    {
        for(i; i<thirdBaseCounter; i++)
        {
            if(thirdBase[i]=='+'&& thirdBase[i+1]=='=')
            {
                i=i+2;
                for(i; i<thirdBaseCounter; i++)
                {
                    num=char_to_int(thirdBase[i]);
                    num_2=digit(num);
                }
            }
        }
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else if(num_2==1)
        {
            bigO_analyzer(2,1);
        }
        else
            bigO_analyzer(2,-num_2);
    }
    else if(strstr(thirdBase,"-=")!=NULL)
    {
        for(i; i<thirdBaseCounter; i++)
        {
            if(thirdBase[i]=='-'&& thirdBase[i+1]=='=')
            {
                i=i+2;
                for(i; i<thirdBaseCounter; i++)
                {
                    num=char_to_int(thirdBase[i]);
                    num_2=digit(num);
                }
            }
        }
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else if(num_2==1)
        {
            bigO_analyzer(2,1);
        }
        else
            bigO_analyzer(2,-num_2);

    }
    else if(strstr(thirdBase,"*=")!=NULL)
    {
        for(i; i<thirdBaseCounter; i++)
        {
            if(thirdBase[i]=='*'&& thirdBase[i+1]=='=')
            {
                i=i+2;
                for(i; i<thirdBaseCounter; i++)
                {
                    num=char_to_int(thirdBase[i]);
                    num_2=digit(num);
                }
            }
        }
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else
            bigO_analyzer(3,num_2);

    }
    else if(strstr(thirdBase,"/=")!=NULL)
    {
        for(i; i<thirdBaseCounter; i++)
        {
            if(thirdBase[i]=='/'&& thirdBase[i+1]=='=')
            {
                i=i+2;
                for(i; i<thirdBaseCounter; i++)
                {
                    num=char_to_int(thirdBase[i]);
                    num_2=digit(num);
                }
            }
        }
        if(number==1)
        {
            bigO_analyzer(1,1);
        }
        else
            bigO_analyzer(3,num_2);
    }
    else if(strstr(thirdBase,"=")!=NULL)
    {
        for(i; i<thirdBaseCounter; i++)
        {
            if(thirdBase[i]=='=')
            {
                i=i+1;
                for(i; i<thirdBaseCounter; i++)
                {
                    if(thirdBase[i]=='+')
                    {
                        i++;
                        for(i; i<thirdBaseCounter; i++)
                        {
                            num=char_to_int(thirdBase[i]);
                            num_2=digit(num);
                        }
                        if(number==1)
                        {
                            bigO_analyzer(1,1);
                        }
                        else if(num_2==1)
                        {
                            bigO_analyzer(2,1);
                        }
                        else
                            bigO_analyzer(2,-num_2);

                    }
                    else if(thirdBase[i]=='-')
                    {
                        i++;
                        for(i; i<thirdBaseCounter; i++)
                        {
                            num=char_to_int(thirdBase[i]);
                            num_2=digit(num);
                        }
                        if(number==1)
                        {
                            bigO_analyzer(1,1);
                        }
                        else if(num_2==1)
                        {
                            bigO_analyzer(2,1);
                        }
                        else
                            bigO_analyzer(2,-num_2);

                    }
                    else if(thirdBase[i]=='*')
                    {
                        i++;
                        for(i; i<thirdBaseCounter; i++)
                        {
                            num=char_to_int(thirdBase[i]);
                            num_2=digit(num);
                        }
                        if(number==1)
                        {
                            bigO_analyzer(1,1);
                        }
                        else
                            bigO_analyzer(3,-num_2);
                    }
                    else if(thirdBase[i]=='/')
                    {
                        i++;
                        for(i; i<thirdBaseCounter; i++)
                        {
                            num=char_to_int(thirdBase[i]);
                            num_2=digit(num);
                        }
                        if(number==1)
                        {
                            bigO_analyzer(1,1);
                        }
                        else
                            bigO_analyzer(3,-num_2);
                    }
                }
            }
        }
    }
}

void identifier()
{
    struct order_struct *liste=ilk_2;
    int trigger=0;

    while(liste != NULL)
    {

        if(liste->order_data == 2 || liste->order_data == 3)
        {
            liste=liste->next;
            trigger++;
            start:
                if(liste->order_data == 2 || liste->order_data == 3)
                {
                    trigger++;
                    liste=liste->next;
                    goto start;
                }
                else if(liste->order_data == 10 && liste->next->order_data == 11)
                {
                    liste=liste->next;
                }
                else if(liste->order_data == 10 && liste->next->order_data != 11)
                {
                    liste=liste->next;
                    goto start;
                }
                else if(liste->order_data == 5 || liste->order_data == 6 || liste->order_data == 7)
                {
                    liste=liste->next;

                    if(liste->order_data == 10 && liste->next->order_data == 11)
                    {
                        liste=liste->next;
                    }
                    else if(liste->order_data == 10 && liste->next->order_data != 11)
                    {
                        liste=liste->next;
                        goto start;
                    }
                    else if(liste->order_data != 10)
                    {
                        goto start;
                    }
                }
                else if(liste->order_data == 4 || liste->order_data ==8)
                {
                    liste=liste->next;

                    if(liste->order_data == 10 && liste->next->order_data == 11)
                    {
                        liste=liste->next;
                    }
                    else if(liste->order_data == 10 && liste->next->order_data != 11)
                    {
                        liste=liste->next;
                        goto start;
                    }
                }
        }
        if(trigger==1)
        {
            operation_sequence(1);
        }
        else if(trigger>1)
        {
            for(int i=0;i<trigger-1;i++)
            {
                operation_sequence(2);
            }
            operation_sequence(1);
        }
        trigger=0;
        liste=liste->next;
    }

}

void space_comp_printer()
{
    printf("\nSPACE COMPLEXITY\n");

    if(memory_num_of_2 !=0)
    {
        printf("%dn^2 + ",memory_num_of_2);
    }

    if(memory_num_of_1 !=0)
    {
        printf("%dn + ",memory_num_of_1);
    }

    if(memory !=0)
    {
        printf("%d",memory);
    }

    printf("\nSPACE COMPLEXITY BIGO\n");
    if(memory_num_of_2 !=0)
    {
        printf("O(n^2)\n");
    }
    else if(memory_num_of_1 !=0)
    {
        printf("O(n)\n");
    }
    else
    {
        printf("O(1)\n");
    }
}

void zaman()
{
    printf("\n\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
    system("cp kod.txt 200202030.cbp"); //("cb txt adý kodun bulunduðu klasörün adý.c/cbp")
    system("gcc 200202030.cbp -o kod");// ("gcc kodun bulunduðu klasörün adý.c/cbp -o txt adý")

    printf("\n\nDERLEME TAMAMLANDI. \n" ) ;

    clock_t begin = clock();

    system("./200202030"); // ("./kodun bulunduðu klasörün adý")

    clock_t end = clock ();

    double time_spent = (double) (end-begin)/CLOCKS_PER_SEC;

    printf("Calisma zamani: %f\n", time_spent);
    printf("TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");

    return 0;
}

int main()
{
    FILE *file;
    file=fopen("kod.txt","r");
    int i=0;

    int size_que=0;

    for (int c = getc(file); c != EOF; c = getc(file))
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            continue;
        }
        else
        {
            sonaEkle(c);
            size_que++;
        }
    }

    printf("LISTELE:\n");
    Listele();
    printf("\n\n");

    coder(size_que);
    printf("\n\n");

    printf("CODER QUEUE:\n");
    order_Listele();
    printf("\n\n");

    variable_fun();
    printf("\n\n");

if(main_trigger==0)
{
     type_bigO();
     identifier();
}
else
{
     identifier();
     type_bigO();
}

    space_comp_printer();

    Theta_printer();

    bigO_all_mult();

    bigO_all_2_n_printer();

    bigO();

    zaman();
    fclose(file);
    return 0;
}
