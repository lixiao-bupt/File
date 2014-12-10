#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct student{
      int number;
	  char name[10];
	  float elective;
	  float experiment;
	  float required;
	  float sum;

}stu[100];
char name[]="data.txt";//文件名字
void show(){
     FILE*fp;
	 int i,m=0;
	 if((fp=fopen(name,"ab+"))==NULL){
	     printf("faill\n");
		  return;
	 }
	  while(!feof(fp)){
		 if(fread(&stu[m],sizeof(struct student),1,fp)==1){
		    m++;
		 }
	 }
	      printf("number  name     elective   experiment  required  sum\n");
	  for(i=0;i<m;i++){
		  printf("%6d  %6s  %8.1f  %10.1f   %8.1f  %3.1f\n",stu[i].number,stu[i].name,stu[i].elective,stu[i].experiment,stu[i].required,stu[i].sum);
	  }
	  fclose(fp);
}
void menu(){
    system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|........STUDENT..........|\n");
	printf("\t\t|\t 0.exit                |\n");
	printf("\t\t|\t 1. input record       |\n");
	printf("\t\t|\t 2. search record      |\n");
	printf("\t\t|\t 3. delete record      |\n");
	printf("\t\t|\t 4. modify record      |\n");
	printf("\t\t|\t 5. insert record      |\n");
	printf("\t\t|\t 6. order              |\n");
	printf("\t\t|\t 7. number             |\n");
	printf("\t\t|...................      |\n\n");
	printf("\t\t\tchoose(0-7):");
}
//添加学生信息
void in(){
     int i,m=0;
	 char ch[2];
	 float lelec,lexpe,lrequ;
	 FILE*fp;
	 if((fp=fopen(name,"ab+"))==NULL){
	     printf("can not open\n");
		 return;
	 }
	 while(!feof(fp)){
		 if(fread(&stu[m],sizeof(struct student),1,fp)==1){
		    m++;
		 }
	 }
	 fclose(fp);
	 if(m==0)
		 printf("No record\n");
	 else{
	      system("cls");
		  show();
	 }
	 if((fp=fopen(name,"ab+"))==NULL){
	     printf("can not open\n");
		 return;
	 }
	 
	 printf("please input (y/n):");
	 scanf("%s",ch);
	 if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0){
	     printf("please input per centum:");
		 printf("\nelective:");
		 scanf("%f",&lelec);
		 printf("\nexperiment:");
		 scanf("%f",&lexpe);
		 printf("\nrequired course:");
		 scanf("%f",&lrequ);
	 }
	 while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0){
	      printf("number:");
		  scanf("%d",&stu[m].number);
		  for(i=0;i<m;i++){
			  if(stu[i].number==stu[m].number){
			     printf("the number is existing,press any to continue");
				 getch();
				 fclose(fp);
				 return;
			  }
		  }
		  printf("name:");
		  scanf("%s",&stu[m].name);
		  printf("elective:");
		  scanf("%f",&stu[m].elective);
		  printf("experiment:");
		  scanf("%f",&stu[m].experiment);
		  printf("required course:");
		  scanf("%f",&stu[m].required);
		  stu[m].sum=stu[m].elective*lelec+stu[m].experiment*lexpe+stu[m].required*lrequ;
		  if(fwrite(&stu[m],sizeof(struct student),1,fp)!=1){
		     printf("can not save!");
			 getch();
		  }
		  else{
			  printf("%s saved!\n",stu[m].name);
			  m++;
		  }
		  printf("continue?(y/n):");
		  scanf("%s",ch);

	 }
	 fclose(fp);
	 printf("OK!\n");
}
//查询学生成绩信息
void search()
{
	FILE*fp;
	int snum,i,m=0;
	char ch[2];
	if((fp=fopen(name,"ab+"))==NULL)
	{
	    printf("can not open file\n");
		return;
	}
	while(!feof(fp))
    {
	      if(fread(&stu[m],sizeof(struct student),1,fp)==1)
			  m++;
		  fclose(fp);
		  if(m==0)
		  {
			  printf("no record\n");
		      return;
		  }
		  printf("please input the number\n");
		  scanf("%d",&snum);
		  for(i=0;i<=m;i++)
		  {
			  if(snum==stu[i].number)
			  {
			       printf("find the student,show?(y/n)");
				   scanf("%s",ch);
				   if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				   {
				        printf("number  name     elective   experiment  required  sum\n");
						printf("%6d  %6s  %8.1f  %10.1f   %8.1f  %3.1f\n",stu[i].number,stu[i].name,stu[i].elective,stu[i].experiment,stu[i].required,stu[i].sum);
						break;
				   }
					
			  }
			  if(i==m)
				  printf("can not find the student\n");
		  }
	}

}
//删除学生信息
void del()
{
    FILE*fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen(name,"ab+"))==NULL)
	{
	   printf("can not open file\n");
	   return;
	}
	while(!feof(fp))
	{
	      if(fread(&stu[m],sizeof(struct student),1,fp)==1)
		  {
			  m++;
		  }
	}
		  fclose(fp);
		  if(m==0)
		  {
			  printf("no record\n");
		      return;
		  }
		 
	 printf("please input the number\n");
	 scanf("%d",&snum);
     for(i=0;i<m;i++)
	{
		if(snum==stu[i].number)
		{  
			 

			printf("find the student,delete?(y/n)");
			scanf("%s",&ch);
			if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
			{	  
				for(j=i;j<m;j++)
				{
						  stu[j]=stu[j+1];
				}
				m--;
				if((fp=fopen(name,"wb"))==NULL)
				{
						   printf("can not open\n");
						   return;
				}
				for(j=0;j<m;j++)
				{
					 if(fwrite(&stu[j],sizeof(struct student),1,fp)!=1)
					{
							  printf("can not save\n");
							  return;
					}
				}
					fclose(fp);
					printf("delete successfully\n");
				
		       }
			   break;
		   }
	}
	

}
//修改学生信息
void modify()
{
     FILE*fp;
	 int i,j,snum,m=0;
	 char ch[2];
	 float lelec,lexpe,lrequ;
	 if((fp=fopen(name,"ab+"))==NULL)
	 {
	     printf("can not open\n");
		 return;
	 }
	 while(!feof(fp))
	 {
	     if(fread(&stu[m],sizeof(struct student),1,fp)==1)
		 {
		       m++;
		 }
	 }
	 fclose(fp);
	 if(m==0)
	 {
	     printf("no record\n");
		 return;
	 }
	 printf("please input the student's number:\n");
	 scanf("%d",&snum);
	 for(i=0;i<m;i++)
	 {
		 if(snum==stu[i].number)
		 {
		      printf("find the student,you can modify\n");
			  printf("please input per centum:");
			  printf("\nelective:");
			  scanf("%f",&lelec);
			  printf("\nexperiment:");
			  scanf("%f",&lexpe);
			  printf("\nrequired course:");
			  scanf("%f",&lrequ);
			  printf("name:");
			  scanf("%s",&stu[i].name);
			  printf("elective:");
			  scanf("%f",&stu[i].elective);
			  printf("experiment:");
			  scanf("%f",&stu[i].experiment);
			  printf("required course:");
			  scanf("%f",&stu[i].required);
			  stu[i].sum=stu[m].elective*lelec+stu[m].experiment*lexpe+stu[m].required*lrequ;
			  if((fp=fopen(name,"wb"))==NULL)
			  {
			       printf("can not open\n");
				   return;
			  }
			  for(j=0;j<m;j++)
			  {
			      if(fwrite(&stu[j],sizeof(struct student),1,fp)!=1)
				  {
				     printf("can not save\n");
					 return;
				  }
			  }
			  fclose(fp);
			  printf("修改完成\n");
			  break;
		 }
		 else if(i==m-1)

		 {
		    printf("can not find the student\n");
			getchar();
			return;
		 }
	 }
	
}
void main(){
     int n;
	 menu();
	 scanf("%d",&n);
	 while(n)
	 {	 switch(n){
		 case 1:
			 in();
			 break;
		 case 2:
			 search();
			 break;
		 case 3:
			 del();
			 break;
		 
		 case 4:
			 modify();
			 break;
		 default:break;
		 }
	     printf("请按任意键继续\n");
		 getch();
		 menu();
		 scanf("%d",&n);
	 }
}


