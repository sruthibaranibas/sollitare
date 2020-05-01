#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct node
{
    char color,suit,no,status;
    node *link;
};
class solitaire
{
    public:
    node *top,*start,*ptr;
    int n,count,ch;
    solitaire()
    {
        ptr=NULL;
        start=NULL;
        n=13;
        count=0;
        top=NULL;
    }
        int insert(char,char,char,char);
        void put(char,char,char,char);
        void disp();
        struct node* transfer(int pos);
        int check(char,char,char,char);
        struct node* remove();
        int move(char,char,char,char);
};
struct node* solitaire::transfer(int  pos)
{
    struct node *ptr;
    int x=0;
    ptr=start;
    while((x<pos)&&(ptr->link!=NULL))
    {
        x++;
        ptr=ptr->link;
    }
    if(ptr->status=='D')
    {
        cout<<"You cannot take that card"<<endl;
        return NULL;
    }
    else
    return ptr;
}
struct node *solitaire::remove()
{
        cout<<"card"<<ptr->color<<ptr->suit<<ptr->no<<ptr->status<<endl;
        cout<<"Do you want to take this card?"<<endl;
        cin>>ch;
        return ptr;
}
void solitaire::put(char a,char b,char c,char d)
{
    int y;
    struct node* temp;
    temp=new node;
    temp->color=a;
    temp->suit=b;
    temp->no=c;
    temp->status=d;
    temp->link=start;
    start=temp;
    //start->status='U';
    ptr=start;

}
int solitaire::move(char a,char b,char c,char d)
{
    int m=0,x=0,y=0,r;
    struct node* temp;
    temp=new node;
    if(c=='J')
    m=10;
    else if(c=='Q')
    m=11;
    else if(c=='K')
    m=12;
    if(start->no=='J')
    x=10;
    else if(start->no=='Q')
    x=11;
    else if(start->no=='K')
    x=12;
    if(a!=start->color)
    {
        r=x-c+48;
        if(((x-m)==1)||((start->no-c)==1)||(r==1))
        {
        temp->color=a;
        temp->suit=b;
        temp->no=c;
        temp->status=d;
        temp->link=start;
        //start=temp;
        //ptr=start;
        return 1;
        }
        else
        return 0;
    }
    else
    {
    cout<<"Invalid move!You cannot place same color card"<<endl;
    return 0;
    }
}
int solitaire::check(char a,char b,char c,char d)
{
    struct node *temp;
    temp=new node;
    int x=0,m=0,p=0,count[10],y,r;
    if(c=='J')
    m=10;
    else if(c=='Q')
    m=11;
    else if(c=='K')
    m=12;
    if(start->no=='J')
    x=10;
    else if(start->no=='Q')
    x=11;
    else if(start->no=='K')
    x=12;
    if(a!=start->color)
    {
        r=x-c+48;
        if(((x-m)==1)||((start->no-c)==1)||(r==1))
    {
    temp->color=a;
    temp->suit=b;
    temp->no=c;
    temp->status=d;
    temp->link=start;
    start=temp;
    return 1;
    }
        else
        {
        cout<<"Invalid move!The cards follow no order"<<endl;
        return 0;
        }
    }
    else
    {cout<<"Invalid move!You cannot place a same color card"<<endl;
    return 0;
    }
}
void solitaire::disp()
{

    cout<<"\t"<<endl<<endl;
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    cout<<"***Empty***"<<endl;
    while(ptr!=NULL)
    {
        if(ptr->status=='U')
        cout<<"card"<<ptr->color<<ptr->suit<<ptr->no<<ptr->status<<"\t";
        else
        cout<<"****"<<"\t";
        ptr=ptr->link;
    }
}
int solitaire::insert(char a,char b,char c,char d)
    {
        int y;
        node *temp;
        temp=new node;
        if(count==0)
        {
            if(c=='A')
            {
            count++;
            temp->color=a;
            temp->suit=b;
            temp->no=c;
            temp->link=top;
            temp->status=d;
            top=temp;
            cout<<"Insertsed successful 1"<<endl;
            return 1;
            }
            else
            {
            cout<<"Invalid move!"<<endl;
            return 0;
            }
        }
        else if(count!=n)
        {
                if((c>='0')&&(c<='10')&&(c!='J')&&(c!='Q')&&(c!='K'))
                {
                    if((top->no=='A')&&(c=='1'))
                    {
                        count++;
                        temp->color=a;
                        temp->suit=b;
                        temp->no=c;
                        temp->link=top;
                        top=temp;
                        cout<<"Inserted successfull "<<count<<endl;
                        return 1;
                    }
                    else if((c-top->no)==1)
                    {
                        cout<<"top"<<top->no<<endl;
                        count++;
                        temp->color=a;
                        temp->suit=b;
                        temp->no=c;
                        temp->link=top;
                        top=temp;
                        cout<<"Inserted successfull"<<count<<endl;
                        return 1;
                    }
                    else
                        {cout<<"Wrong move"<<endl;
                        return 0;
                        }
                }
            else
            {
                if(count==10)
                {
                    if(c=='J')
                    {
                        count++;
                        temp->color=a;
                        temp->suit=b;
                        temp->no=c;
                        temp->link=top;
                        top=temp;
                        cout<<"Inserted successfull";
                        return 1;
                    }
                    else
                    {cout<<"Wrong move"<<endl;
                    return 0;
                    }
                }
             else if(count==11)
                {
                    if(c=='Q')
                    {
                        count++;
                        temp->color=a;
                        temp->suit=b;
                        temp->no=c;
                        temp->link=top;
                        top=temp;
                        cout<<"Inserted successfull";
                        return 1;
                    }
                    else
                    {cout<<"Wrong movement"<<endl;
                    return 0;
                    }
                }
                else if(count==12)
                {
                    if(c=='K')
                    {
                        count++;
                        temp->color=a;
                        temp->suit=b;
                        temp->no=c;
                        temp->link=top;
                        top=temp;
                        cout<<"Inserted successfull";
                        return 1;
                    }
                    else
                    {
                    cout<<"Wrong move!"<<endl;
                    return 0;
                    }
                }
            }
        }
        else
        cout<<"full";
}
int main()
{
    solitaire t,s,h,d,c;
    solitaire b[7];
    char tring[52],rString[52],color;
    int mess[52]={0},game[7]={0};
    int m,j=0,count=0,z=0,p=0,i=0,counting=0;
	for(i=0;i<4;i++)
	rString[i]='2';
    for(i=i;i<8;i++)
	rString[i]='8';
	for(i=i;i<12;i++)
	rString[i]='A';
	for(i=i;i<16;i++)
	rString[i]='3';
    for(i=i;i<20;i++)
	rString[i]='6';
	for(i=i;i<24;i++)
	rString[i]='J';
	for(i=i;i<28;i++)
	rString[i]='4';
	for(i=i;i<32;i++)
	rString[i]='7';
	for(i=i;i<36;i++)
	rString[i]='1';
	for(i=i;i<40;i++)
	rString[i]='9';
	for(i=i;i<44;i++)
	rString[i]='5';
	for(i=i;i<48;i++)
	rString[i]='Q';
	for(i=i;i<52;i++)
	rString[i]='K';

	for(i=0;i<13;i++)
	tring[i]='H';
    for(i=i;i<26;i++)
	tring[i]='C';
	for(i=i;i<39;i++)
	tring[i]='S';
	for(i=i;i<52;i++)
	tring[i]='D';
	i=0,j=0;
     srand (time(0));
    while(i<51)
    {
        count=0;
        m=rand()%51;
        for(int j=0;j<i;j++)
        {
            if(mess[j]==m)
            count++;
        }
        if(count==0)
        {
            mess[i]=m;
            i++;
        if(tring[m]=='S')
            color='B';
        else if(tring[m]=='D')
            color='R';
        else if(tring[m]=='H')
            color='R';
        else if(tring[m]=='C')
            color='B';
            if(counting>27)
        {t.put(color,tring[m],rString[m],'U');
            counting++;
        }
            else if(counting<28)
            {
            if(game[z]<=z)
            {
                counting++;
                b[z].put(color,tring[m],rString[m],'D');
                game[z]+=1;
            }
            else
            z++;
            }
            }
        }
    int help;
    cout<<"\t\t\t****WELCOME****\t\t\t"<<endl;
    cout<<"\t\t\t*****SOLITAIRE*****\t\t\t"<<endl;
    cout<<"1.Play game"<<endl;
    cout<<"2.Help"<<endl;
    cin>>help;
    if(help==1)
    {
    struct node *pt,*pt1,*pt2;
    char input[13],p,store1[30],store2[30],store3[30];
    int choice,k=0,st,pk,end,j=-1,hk,num,number,x,v,y,g,q=0,cm,o,ct=0,inc[10];
    for(int i=0;i<7;i++)
    {
    b[i].start->status='U';
    b[i].disp();
    }
    while(1)
    {
    we:cout<<endl<<"Want to continue?"<<endl<<"Press any number in the range 1 to 10 to go"<<endl<<"Press any other number to quit"<<endl;
    cin>>choice;
    if((choice>=1)&&(choice<=10))
    {
        cout<<"What move you want to do?"<<endl;
        cout<<"Enter 1.for moving from board to board"<<endl<<"2.for moving from board to foundation"<<endl<<"3.for moving from top"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
            {
                cout<<"enter the starting list and ending list"<<endl;
                cin>>st>>end;
                cout<<"Enter the position of starting card"<<endl;
                cin>>num;
                number=num;
                ct=0;
                o=0;
                inc[10]={0};
                while(num!=-1)
                {
                    pt=b[st].transfer(num);
                    if(pt!=NULL)
                    {
                    x=b[end].check(pt->color,pt->suit,pt->no,pt->status);
                    if(x==1)
                    {inc[o]=1;
                    o++;
                    }
                    num--;
                    }
                    else
                    break;
                }
                    for(int f=0;f<o;f++)
                    {
                        if(inc[f]==1)
                        ct++;
                    }
                    for(int f=-1;f<number;f++)
                    {
                    if(ct==o)
                    {
                        if(ct!=0&&o!=0)
                        {
                    while((b[st].start!=NULL)&&(cm<number))
                    {
                        cm++;
                        b[st].start=b[st].start->link;
                    }
                    if((b[st].start->link!=NULL)&&(b[st].start!=NULL))
                    {
                    b[st].start=b[st].start->link;
                    b[st].start->status='U';
                    }
                    else if(b[st].start->link==NULL)
                    b[st].start=NULL;
                        }
                    }
                    else
                    cout<<"Invalid move!"<<endl;
                    }
                for(int f=0;f<7;f++)
                b[f].disp();
            }break;
            case 2:
            {
                int up,gh,ht,down,mc,dec[10],ret;
                cout<<"Enter the board list number:"<<endl;
                cin>>v;
                cout<<"Enter the position of the starting card you want to move:"<<endl;
                cin>>ht;
                gh=ht;
                dec[10]={0};
                mc=0;
                up=0;
                down=0;
                while(ht!=-1)
                {
                    pt=b[v].transfer(ht);
                    if(pt->suit=='S')
                ret=s.insert(pt->color,pt->suit,pt->no,pt->status);
                else if(pt->suit=='H')
                ret=h.insert(pt->color,pt->suit,pt->no,pt->status);
                else if(pt->suit=='C')
                ret=c.insert(pt->color,pt->suit,pt->no,pt->status);
                else if(pt->suit=='D')
                ret=d.insert(pt->color,pt->suit,pt->no,pt->status);
                    if(ret==1)
                    {
                    dec[up]=1;
                    up++;
                    }
                    ht--;
                }
                for(int f=0;f<up;f++)
                    {
                        if(dec[f]==1)
                        down++;
                    }
                 for(int f=-1;f<gh;f++)
                    {
                    if(up==down)
                    {if(up!=0&&down!=0)
                        {
                    while((b[v].start!=NULL)&&(mc<gh))
                    {
                        mc++;
                        b[v].start=b[v].start->link;
                    }
                    if((b[v].start->link!=NULL)&&(b[v].start!=NULL))
                    {b[v].start=b[v].start->link;
                    b[v].start->status='U';
                    }
                    else if(b[v].start->link==NULL)
                    b[v].start=NULL;
                        }
                    }
                    }
                for(int f=0;f<7;f++)
                b[f].disp();
            }break;
            case 3:
            {
                int opt;
                static int i=0,q=0;
                int u=0;
                if(t.ptr==NULL)
                {
                    t.start=NULL;
                    for(int i=0;i<q;i++)
                    t.put(store1[i],store2[i],store3[i],'U');
                    store1[30]='\0';
                    store2[30]='\0';
                    store3[30]='\0';
                }
                  pt1=t.remove();
                  if(t.ch==1)
                  {
                 cout<<"Enter your option 1.top to board 2.top to foundation"<<endl;
                cin>>opt;
                 if(opt==1)
                 {
                cout<<"Enter the board number you want to move"<<endl;
                cin>>y;
                g=b[y].move(pt1->color,pt1->suit,pt1->no,pt1->status);
                if(g==0)
                {
                    store1[i]=pt1->color;
                    store2[i]=pt1->suit;
                    store3[i]=pt1->no;
                    i++;
                    q++;
                    cout<<"Your card was not inserted properly due to invalid movement"<<endl;
                }
                else
                 {
                     t.ptr=t.ptr->link;
                     pt1->link=b[y].start;
                     b[y].start=pt1;
                 }
                 }
                else if(opt==2)
                {
                pt2=t.remove();
                if(t.ch==1)
                {
                cout<<"Card taken"<<pt2->color<<pt2->suit<<pt2->no<<pt2->status<<endl;
                cout<<"enter the suit to insert the taken card"<<endl;
                cin>>p;
                if(pt2->suit==p)
                {
                switch(p)
                {
                    case 'S':u=s.insert(pt2->color,pt2->suit,pt2->no,pt2->status);break;
                    case 'H':u=h.insert(pt2->color,pt2->suit,pt2->no,pt2->status);break;
                    case 'C':u=c.insert(pt2->color,pt2->suit,pt2->no,pt2->status);break;
                    case 'D':u=d.insert(pt2->color,pt2->suit,pt2->no,pt2->status);break;
                }
                if(u==0)
                {
                    store1[i]=pt2->color;
                    store2[i]=pt2->suit;
                    store3[i]=pt2->no;
                    i++;
                    q++;
                }
                else
                    t.ptr=t.ptr->link;
                }
                else
                cout<<"Not valid suit"<<endl;
                }
                else
                {
                    store1[i]=pt2->color;
                    store2[i]=pt2->suit;
                    store3[i]=pt2->no;
                    i++;
                    q++;
                    t.ptr=t.ptr->link;
                }
                }
                  }
                  else
                {
                    store1[i]=pt1->color;
                    store2[i]=pt1->suit;
                    store3[i]=pt1->no;
                    i++;
                    q++;
                    t.ptr=t.ptr->link;
                }
                for(int f=0;f<7;f++)
                b[f].disp();
            }break;
        }
    }
    else
    {
     cout<<"Are you sure to quit the current game"<<endl;
     cout<<"Your progress will not be saved"<<endl;
     cout<<"Enter 3. if you are sure to quit 4.if not"<<endl;
     cin>>pk;
     if(pk==3)
     break;
     else if(pk==4)
     goto we;
    }
    }
}
else if(help==2)
{
    cout<<"The seven lists on the table are called as board lists"<<endl;
    cout<<"In board lists you should arrange the cards in descending order as well as the colors should be alternate"<<endl;
    cout<<"If  there is no movement possible,you can take cards from top"<<endl;
    cout<<"The game gets over,when all the suits are arranged in ascending order"<<endl;
    cout<<"Violation of any of the rule results in an invalid move!!"<<endl;
    cout<<"\t\t\t******HAPPY PLAYING*****\t\t\t"<<endl;
}
}

