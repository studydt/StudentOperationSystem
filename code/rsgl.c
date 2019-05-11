#include "stdio.h"    /*��׼�������������*/
#include "stdlib.h"   /*��׼������*/
#include "string.h"   /*�ַ���������*/
#include <conio.h>    /*��Ļ����������*/
#define HEADER1 "      ----------------------------TEACHER---------------------------  \n"
#define HEADER2 "     |  NUMBER  |   NAME   |STATUS|  ZC  |  YFGZ  |  KKGZ  |  SFGZ  | \n"
#define HEADER3 "     |----------|----------|------|------|--------|--------|--------| \n"
#define FORMAT  "     |%-10s|%-10s|%6d|%6d|%8d|%8d|%8d|\n"
#define DATA  p->data.num,p->data.name,p->data.zc,p->data.status,p->data.yfgz,p->data.kkgz,p->data.sfgz
#define END     "      --------------------------------------------------------------  \n"

int saveflag=0;  /*�Ƿ���Ҫ���̵ı�־����*/
/*�������ʦ�����йص����ݽṹ*/
typedef struct teacher      /*���Ϊteacher*/
{
char num[10];  /*��ʦ���*/
char name[15]; /*��ʦ����*/
int zc;        /*ְ�ƣ�1Ϊ���̣�2Ϊ��ʦ��3Ϊ�����ڣ�4Ϊ����*/
int status;    /*״̬��1Ϊ��ְ��2Ϊ����*/
int yfgz;      /*Ӧ������*/
int kkgz;      /*������*/
int sfgz;      /*ʵ������*/
};

/*����ÿ����¼��������ݽṹ�����Ϊ��node*/
typedef struct node
{
struct teacher data;  /*������*/
struct node *next;    /*ָ����*/
}Node,*Link;   /*NodeΪnode���͵Ľṹ������*LinkΪnode���͵�ָ�����*/



void menu()  /*���˵�*/
{
system("cls");   /*����DOS�������.��clrscr()������ͬ*/
printf("                 The Teachers' RenShi Management System \n");
printf("     *************************Menu********************************\n");
printf("     *  1 input   record             2 delete record             *\n");
printf("     *  3 search  record             4 modify record             *\n");
printf("     *  5 insert  record             6 count  record             *\n");
printf("     *  7 sort    reord              8 save   record             *\n");
printf("     *  9 display record             0 quit   system             *\n");
printf("     *************************************************************\n");

}
void printheader() /*��ʽ�������ͷ*/
{
  printf(HEADER1);
  printf(HEADER2);
  printf(HEADER3);
}
void printdata(Node *pp) /*��ʽ�������������*/
{
 Node* p;
 p=pp;
 printf(FORMAT,DATA);

}

void Wrong()  /*�������������Ϣ*/
{
printf("\n\n\n\n\n***********Error:input has wrong! press any key to continue**********\n");
getchar();
}

void Nofind()  /*���δ���Ҵ˽�ʦ����Ϣ*/
{
printf("\n=====>Not find this teacher!\n");
}

void Disp(Link l)  /*��ʾ������l�д洢�Ľ�ʦ��¼������Ϊteacher�ṹ�ж��������*/
{
Node *p;
p=l->next; /*l�洢���ǵ�������ͷ����ָ�룬��ͷ���û�д洢��ʦ��Ϣ��ָ����ָ��ĺ�̽����н�ʦ��Ϣ*/

if(!p)  /*p==NULL,NUll��stdlib�ж���Ϊ0*/
{
  printf("\n=====>Not teacher record!\n");
  getchar();
  return;
}

printf("\n\n");
printheader(); /*������ͷ��*/

while(p)    /*������������д洢�Ľ�ʦ��Ϣ*/
{
  printdata(p);
  p=p->next;  /*�ƶ�ֱ��һ�����*/
  printf(HEADER3);
}
getchar();
}

/*************************************************************
���ã����ڶ�λ�����з���Ҫ��Ľڵ㣬������ָ��ýڵ��ָ��
������findmess[]����Ҫ���ҵľ�������; nameornum[]���水ʲô����;
      �ڵ�����l�в���;
**************************************************************/
Node* Locate(Link l,char findmess[],char nameornum[])
{
Node *r;
if(strcmp(nameornum,"num")==0) /*����Ų�ѯ*/
{
  r=l->next;
  while(r)
  {
   if(strcmp(r->data.num,findmess)==0) /*���ҵ�findmessֵ�ı��*/
    return r;
   r=r->next;
  }
}
else if(strcmp(nameornum,"name")==0)  /*��������ѯ*/
{
  r=l->next;
  while(r)
  {
   if(strcmp(r->data.name,findmess)==0)    /*���ҵ�findmessֵ�Ľ�ʦ����*/
    return r;
   r=r->next;
  }
}
return 0; /*��δ�ҵ�������һ����ָ��*/
}


/*�����ַ����������г�����֤(����<lens)*/
void stringinput(char *t,int lens,char *notice)
{
   char n[255];
   do{
      printf(notice);  /*��ʾ��ʾ��Ϣ*/
      scanf("%s",n);  /*�����ַ���*/
      if(strlen(n)>lens)printf("\n exceed the required length! \n"); /*���г���У�飬����lensֵ��������*/
     }while(strlen(n)>lens);
   strcpy(t,n); /*��������ַ����������ַ���t��*/
}


/*���ӽ�ʦ��¼*/
void Add(Link l)
{
Node *p,*r,*s;  /*ʵ����Ӳ�������ʱ�Ľṹ��ָ�����*/
char ch,flag=0,num[10];
r=l;
s=l->next;
system("cls");
Disp(l); /*�ȴ�ӡ�����еĽ�ʦ��Ϣ*/
while(r->next!=NULL)
  r=r->next; /*��ָ��������������ĩβ��׼����Ӽ�¼*/
while(1) /*һ�ο����������¼��ֱ��������Ϊ0�ļ�¼�����Ӳ���*/
{

 while(1) /*�����ţ���֤�ñ��û�б�ʹ�ã���������Ϊ0�����˳���Ӽ�¼����*/
 {
   stringinput(num,10,"input number(press '0'return menu):"); /*��ʽ�������Ų�����*/
   flag=0;
   if(strcmp(num,"0")==0) /*����Ϊ0�����˳���Ӳ���������������*/
   {return;}
    s=l->next;
    while(s) /*��ѯ�ñ���Ƿ��Ѿ����ڣ���������Ҫ����������һ��δ��ռ�õı��*/
    {
      if(strcmp(s->data.num,num)==0)
      {
       flag=1;
       break;
       }
     s=s->next;
    }

  if(flag==1) /*��ʾ�û��Ƿ���������*/

     {  getchar();
        printf("=====>The number %s is not existing,try again?(y/n):",num);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
         continue;
        else
          return;
      }
     else
      {break;}
  }
  
  p=(Node *)malloc(sizeof(Node)); /*�����ڴ�ռ�*/
  if(!p)
   {
      printf("\n allocate memory failure "); /*��û�����뵽����ӡ��ʾ��Ϣ*/
      return ;             /*����������*/
   }
  strcpy(p->data.num,num); /*���ַ���num������p->data.num��*/
  stringinput(p->data.name,15,"Name:");
  printf("Please input status[1,2]:");
  scanf("%d",&p->data.status);
  printf("Please input zc[1,2,3,4]:");
  scanf("%d",&p->data.zc);
  printf("Please input yfgz:");
  scanf("%d",&p->data.yfgz);
  printf("Please input kkgz:");
  scanf("%d",&p->data.kkgz);

  p->data.sfgz=(p->data.yfgz)-(p->data.kkgz); /*����ʵ������*/
  printf("sfgz:%d\n",p->data.sfgz);
  p->next=NULL; /*�������������β�����*/
  r->next=p;  /*���½��Ľ���������β����*/
  r=p;
  saveflag=1;

  }
     return ;
}

/*����Ż���������ѯ��ʦ��¼*/
void Qur(Link l)
{
int select; /*1:����Ų飬2���������飬���������������棨�˵���*/
char searchinput[20]; /*�����û�����Ĳ�ѯ����*/
Node *p;
if(!l->next) /*������Ϊ��*/
{
  system("cls");
  printf("\n=====>No teacher record!\n");
  getchar();
  return;

}
system("cls");
printf("\n     =====>1 Search by number  =====>2 Search by name\n");
printf("      please choice[1,2]:");
scanf("%d",&select);
if(select==1)   /*����Ų�ѯ*/
 {

  stringinput(searchinput,10,"input the existing teacher number:");
  p=Locate(l,searchinput,"num");/*��l�в��ұ��Ϊsearchinputֵ�Ľڵ㣬�����ؽڵ��ָ��*/
  if(p) /*��p!=NULL*/
  {
   printheader();
   printdata(p);
   printf(END);
   printf("press any key to return");
   getchar();
  }
  else
   Nofind();
   getchar();
}
else if(select==2) /*��������ѯ*/
{
  stringinput(searchinput,15,"input the existing teacher name:");
  p=Locate(l,searchinput,"name");
  if(p)
  {
   printheader();
   printdata(p);
   printf(END);
   printf("press any key to return");
   getchar();
  }
  else
   Nofind();
   getchar();
}
else
  Wrong();
  getchar();
  
}

/*ɾ����ʦ��¼�����ҵ�����ý�ʦ��¼�Ľڵ㣬Ȼ��ɾ���ýڵ�*/
void Del(Link l)
{
int sel;
Node *p,*r;
char findmess[20];
if(!l->next)
{ system("cls");
  printf("\n=====>No teacher record!\n");
  getchar();
  return;
}
system("cls");
Disp(l);
printf("\n        =====>1 Delete by Teacher Number   =====>2 Delete by Teacher Name\n");
printf("       please choice[1,2]:");
scanf("%d",&sel);
if(sel==1)
{

  stringinput(findmess,10,"input the existing teacher number:");
  p=Locate(l,findmess,"num");
  if(p)  /*p!=NULL*/
  {
   r=l;
   while(r->next!=p)
    r=r->next;
   r->next=p->next;/*��p��ָ�ڵ��������ȥ��*/
   free(p); /*�ͷ��ڴ�ռ�*/
   printf("\n=====>delete success!\n");
   getchar();
   saveflag=1;
  }
  else
   Nofind();
   getchar();
}
else if(sel==2) /*�Ȱ�������ѯ���ü�¼���ڵĽڵ�*/
{
  stringinput(findmess,15,"input the existing teacher name");
  p=Locate(l,findmess,"name");
  if(p)
  {
   r=l;
   while(r->next!=p)
    r=r->next;
   r->next=p->next;
   free(p);
   printf("\n=====>delete success!\n");
   getchar();
   saveflag=1;
  }
  else
   Nofind();
   getchar();
}
else
  Wrong();
  getchar();
}

/*�޸Ľ�ʦ��¼��ע�⣺�Ȱ�����ı�Ų�ѯ���ü�¼��Ȼ����ʾ�û��޸ı��֮���ֵ����Ų����޸�*/
void Modify(Link l)
{
Node *p;
char findmess[20];
if(!l->next)
{ system("cls");
  printf("\n=====>No teacher record!\n");
  getchar();
  return;
}
system("cls");
printf("modify teacher recorder");
Disp(l);


stringinput(findmess,10,"input the existing teacher number:"); /*���벢����ñ��*/
p=Locate(l,findmess,"num"); /*��ѯ���ýڵ�*/
if(p) /*��p!=NULL,�����Ѿ��ҵ��ýڵ�*/
{
  printf("number:%s\n",p->data.num);
  printf("name:%s\n",p->data.name);
  stringinput(p->data.name,15,"input new name:");
  /******************************************/
  printf("status:%d",p->data.status);
  printf("\nPlease input new status[1,2]:");scanf("%d",&p->data.status);
  /******************************************/
  printf("zc:%d",p->data.zc);
  printf("\nPlease input new zc[1,2,3,4]:");scanf("%d",&p->data.zc);
  /******************************************/
  printf("yfgz:%d",p->data.yfgz);
  printf("\nPlease input new yfgz:");scanf("%d",&p->data.yfgz);
  /******************************************/
  printf("kkgz:%d\n",p->data.kkgz);
  printf("Please input new kkgz:");scanf("%d",&p->data.kkgz);
  /******************************************/
  p->data.sfgz=p->data.yfgz-p->data.kkgz;/*����ʵ������*/
  printf("sfgz:%d",p->data.sfgz);
  /******************************************/
  printf("\n=====>modify success!\n");
  Disp(l);
  saveflag=1;
}
else
  Nofind();
  getchar();

}


/*�����¼:����Ų�ѯ��Ҫ����Ľڵ��λ�ã�Ȼ���ڸñ��֮�����һ���½ڵ㡣*/
void Insert(Link l)
{
   Link p,v,newinfo; /*pָ�����λ�ã�newinfoָ�²����¼*/
   char ch,num[10],s[10];  /*s[]��������λ��֮ǰ�ı��,num[]����������¼�¼�ı��*/
   int flag=0;
   v=l->next;
   system("cls");
   Disp(l);
   while(1)
   { stringinput(s,10,"please input insert location  after the Number:");
     flag=0;v=l->next;
     while(v) /*��ѯ�ñ���Ƿ���ڣ�flag=1��ʾ�ñ�Ŵ���*/
     {
      if(strcmp(v->data.num,s)==0)  {flag=1;break;}
          v=v->next;
     }
      if(flag==1)
        break; /*����Ŵ��ڣ�����в���֮ǰ���¼�¼���������*/
     else
     {  getchar();
        printf("\n=====>The number %s is not existing,try again?(y/n):",s);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
         {continue;}
        else
          {return;}
      }
   }
  /*�����¼�¼�����������Add()��ͬ*/
  stringinput(num,10,"input new teacher Number:");
  v=l->next;
  while(v)
  {
   if(strcmp(v->data.num,num)==0)
   {
    printf("=====>Sorry,the new number:'%s' is existing !\n",num);
    printheader();
    printdata(v);
    printf("\n");
    getchar();
    return;
   }
   v=v->next;
  }
  
  newinfo=(Node *)malloc(sizeof(Node));
  if(!newinfo)
   {
      printf("\n allocate memory failure "); /*��û�����뵽����ӡ��ʾ��Ϣ*/
      return ;             /*����������*/
   }
  strcpy(newinfo->data.num,num);
  stringinput(newinfo->data.name,15,"Name:");
  /******************************************/
  printf("Please input status[1,2]:");scanf("%d",&newinfo->data.status);
  /******************************************/
  printf("Please input zc[1,2,3,4]:");scanf("%d",&newinfo->data.zc);
  /******************************************/
  printf("Please input yfgz:");scanf("%d",&newinfo->data.yfgz);
  /******************************************/
  printf("Please input kkgz:");scanf("%d",&newinfo->data.kkgz);
  /******************************************/
  newinfo->data.sfgz=(newinfo->data.yfgz)-(newinfo->data.kkgz);/*����ʵ������*/
  /******************************************/
  newinfo->next=NULL;
  saveflag=1; /*��main()�жԸ�ȫ�ֱ������жϣ���Ϊ1,����д��̲���*/
  /*��ָ�븳ֵ��p,��Ϊl�е�ͷ�ڵ����һ���ڵ��ʵ�ʱ����Ž�ʦ�ļ�¼*/
  p=l->next;
  while(1)
   {
     if(strcmp(p->data.num,s)==0) /*�������в���һ���ڵ�*/
      {
        newinfo->next=p->next;
        p->next=newinfo;
        break;
       }
      p=p->next;
    }

   Disp(l);
   printf("\n\n");
   getchar();

}

/*ͳ����ְ������״̬������ͳ�Ƹ�ְ������*/
void Tongji(Link l)
{
Node *r=l->next;
int counts1=0,counts2=0; /*�ֱ𱣴���ְ������״̬����*/
int countz1=0,countz2=0,countz3=0,countz4=0; /*�ֱ𱣴����̡���ʦ�������ڡ����ڵ�����*/
if(!r)
{ system("cls");
  printf("\n=====>Not teacher record!\n");
  getchar();
  return ;
}
system("cls");
Disp(l);
while(r)
{
  if(r->data.status==1) counts1++;
  if(r->data.status==2) counts2++;
  if(r->data.zc==1) countz1++;
  if(r->data.zc==2) countz2++;
  if(r->data.zc==3) countz3++;
  if(r->data.zc==4) countz4++;
  r=r->next;
}
printf("\n------------------------------the TongJi result--------------------------------\n");
printf("Number of ZZ:%d (ren)\n",counts1);
printf("Number of TX:%d (ren)\n",counts2);
printf("-------------------------------------------------------------------------------\n");
printf("Number of ZJ:%d (ren)\n",countz1);
printf("Number of ZS:%d (ren)\n",countz2);
printf("Number of FG:%d (ren)\n",countz3);
printf("Number of ZG:%d (ren)\n",countz4);
printf("-------------------------------------------------------------------------------\n");
printf("\n\npress any key to return");
getchar();
}


/*���ò�������ʵ�ֵ�����İ�ʵ�����ʵĽ������򣬴Ӹߵ���*/
void Sort(Link l)
{
Link ll;
Node *p,*rr,*s;
int i=0;
if(l->next==NULL)
{ system("cls");
  printf("\n=====>Not teacher record!\n");
  getchar();
  return ;
}

ll=(Node*)malloc(sizeof(Node)); /*���ڴ����µĽڵ�*/
if(!ll)
   {
      printf("\n allocate memory failure "); /*��û�����뵽����ӡ��ʾ��Ϣ*/
      return ;             /*����������*/
   }
ll->next=NULL;
system("cls");
Disp(l);  /*��ʾ����ǰ�����н�ʦ��¼*/
p=l->next;
while(p) /*p!=NULL*/
{
  s=(Node*)malloc(sizeof(Node)); /*�½��ڵ����ڱ����ԭ������ȡ���Ľڵ���Ϣ*/
  if(!s) /*s==NULL*/
   {
      printf("\n allocate memory failure "); /*��û�����뵽����ӡ��ʾ��Ϣ*/
      return ;             /*����������*/
   }
  s->data=p->data; /*��������*/
  s->next=NULL;    /*ָ����Ϊ��*/
  rr=ll;
  /*rr�����ڴ洢���뵥���ڵ�󱣳����������ll����������ͷָ��,ÿ�δ�ͷ��ʼ���Ҳ���λ��*/

  while(rr->next!=NULL && rr->next->data.sfgz>=p->data.sfgz)
   {rr=rr->next;} /*ָ������ʵ�����ʱ�p��ָ�Ľڵ��ʵ������С�Ľڵ�λ��*/
  if(rr->next==NULL)/*��������ll�е����нڵ��ʵ������ֵ����p->data.total��ʱ���ͽ�p��ָ�ڵ��������β��*/
     rr->next=s;
  else /*���򽫸ýڵ��������һ��ʵ�������ֶα���С�Ľڵ��ǰ��*/
  {
   s->next=rr->next;
   rr->next=s;
  }
   p=p->next; /*ԭ�����е�ָ������һ���ڵ�*/
 }

   l->next=ll->next; /*ll�д洢�ǵ�������������ͷָ��*/
   p=l->next;           /*���ź����ͷָ�븳��p��׼����д����*/
   while(p!=NULL)  /*��p��Ϊ��ʱ���������в���*/
   {
      i++;       /*������*/
      p=p->next;   /*ָ�����*/

   }
Disp(l);
saveflag=1;
printf("\n    =====>sort complete!\n");

}

/*���ݴ���,���û�û��ר�Ž��д˲����Ҷ��������޸ģ����˳�ϵͳʱ�� ����ʾ�û�����*/
void Save(Link l)
{
FILE* fp;
Node *p;
int count=0;
fp=fopen("c:\\teacher","wb");/*��ֻд��ʽ�򿪶������ļ�*/
if(fp==NULL) /*���ļ�ʧ��*/
{
  printf("\n=====>open file error!\n");
  getchar();
  return ;
}
p=l->next;

while(p)
{
  if(fwrite(p,sizeof(Node),1,fp)==1)/*ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�*/
  { 
   p=p->next;
   count++;
  }
  else
  {
   break;
  }
}
if(count>0)
{
  getchar();
  printf("\n\n\n\n\n=====>save file complete,total saved's record number is:%d\n",count);
  getchar();
  saveflag=0;
}
else
{system("cls");
 printf("the current link is empty,no teacher record is saved!\n");
 getchar();
 }
fclose(fp); /*�رմ��ļ�*/
}

int  main()
{

  Link l;      /*��������*/
  FILE *fp;    /*�ļ�ָ��*/
  int select;     /*����ѡ��������*/
  char ch;     /*����(y,Y,n,N)*/
  int count=0; /*�����ļ��еļ�¼���������������*/
  Node *p,*r;   /*�����¼ָ�����*/


  l=(Node*)malloc(sizeof(Node));
  if(!l)
   {
      printf("\n allocate memory failure "); /*��û�����뵽����ӡ��ʾ��Ϣ*/
      return ;             /*����������*/
   }
  l->next=NULL;
  r=l;
  fp=fopen("teacher.dat","ab+"); /*��׷�ӷ�ʽ��һ���������ļ����ɶ���д�������ļ������ڣ��ᴴ�����ļ�*/
  if(fp==NULL)
  {
    printf("\n=====>can not open file!\n");
    exit(0);
  }

while(!feof(fp))
{
  p=(Node*)malloc(sizeof(Node));
  if(!p)
   {
      printf(" memory malloc failure!\n");    /*û�������ڴ�ɹ�*/
      exit(0);       /*�˳�*/
   }

  if(fread(p,sizeof(Node),1,fp)==1) /*һ�δ��ļ��ж�ȡһ����ʦ���¼�¼*/
  {
   p->next=NULL;
   r->next=p;
   r=p;                            /*rָ�������һ��λ��*/
   count++;
   }
}

fclose(fp); /*�ر��ļ�*/
printf("\n=====>open file sucess,the total records number is : %d.\n",count);
menu();
while(1)
{
   system("cls");
   menu();
   p=r;
   printf("\n              Please Enter your choice(0~9):");    /*��ʾ��ʾ��Ϣ*/
   scanf("%d",&select);

  if(select==0)
  {
   if(saveflag==1) /*����������������޸���δ���д��̲�������˱�־Ϊ1*/
   { getchar();
     printf("\n=====>Whether save the modified record to file?(y/n):");
     scanf("%c",&ch);
     if(ch=='y'||ch=='Y')
       Save(l);
   }
   printf("=====>thank you for useness!");
   getchar();
   break;
  }

  switch(select)
  {
  case 1:Add(l);break;           /*���ӽ�ʦ���¼�¼*/
  case 2:Del(l);break;           /*ɾ����ʦ���¼�¼*/
  case 3:Qur(l);break;           /*��ѯ��ʦ���¼�¼*/
  case 4:Modify(l);break;        /*�޸Ľ�ʦ���¼�¼*/
  case 5:Insert(l);break;        /*�����ʦ���¼�¼*/
  case 6:Tongji(l);break;        /*ͳ�ƽ�ʦ���¼�¼*/
  case 7:Sort(l);break;          /*�����ʦ���¼�¼*/
  case 8:Save(l);break;          /*�����ʦ���¼�¼*/
  case 9:system("cls");Disp(l);break;         /*��ʾ��ʦ��¼*/
  default: Wrong();getchar();break;        /*�������󣬱���Ϊ��ֵ0-9*/
  }
}
return 0;
}
