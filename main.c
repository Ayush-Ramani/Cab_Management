#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Num_Of_Registration = 0;
struct Registration
{
    int d_id,d_pass;
    long d_phone;
    char d_name[20],d_email[30];
}d;
void Reg()
{
    struct Registration *de;
    de = &d;
    FILE *fp;
    fp = fopen("record-delear.txt","a");
        printf("\n Enter Delear Id :");
        scanf("%d",&de->d_id);
        printf("\n Enter Delear name :");
        scanf("%s",de->d_name);
        printf("\n Enter Delear Email :");
        scanf("%s",de->d_email);
        printf("\n Enter Delear password :");
        scanf("%d",&de->d_pass);
        printf("\n Enter Delear phone number :");
        scanf("%ld",&de->d_phone);
    fwrite(&d,sizeof(d),1,fp);
    fclose(fp);
}
void display()
{
    struct Registration *de;
    de = &d;
    FILE * fp1;
    fp1 = fopen("record-delear.txt","r");
    printf("Id\tName\tEmail\tpassword\tphone no\n");
    while(fread(&d,sizeof(d),1,fp1))
    {
        printf("%d\t%s\t%s\t\t%d\t%ld",de->d_id,de->d_name,de->d_email,de->d_pass,de->d_phone);
        printf("\n");
    }
    fclose(fp1);
}
struct cab
{
    int c_id,c_model,sm;
    char c_name[20],c_type[20],c_from[20],c_to[20];
}cabs;
void Addcab()
{
    struct cab *c;
    c = &cabs;
   FILE * fp3;
   fp3 = fopen("cab-record.txt","a");
                        
                            printf("\n Enter Cab Id :");
                            scanf("%d",&c->c_id);
                            printf("\n Enter Cab Name :");
                            scanf("%s",c->c_name);
                            printf("\n Enter Cab Type :");
                            scanf("%s",c->c_type);
                            printf("\n Enter Cab Model :");
                            scanf("%d",&c->c_model);
                            printf("\n Enter A Pick Up Place :");
                            scanf("%s",c->c_from);
                            printf("\n Enter A Destination Place :");
                            scanf("%s",c->c_to);
                            printf("\n Enter The Service Ammount :");
                            scanf("%d",&c->sm);
                        printf("\n*****Cab Added Successfully*****\n");
    fwrite(&cabs,sizeof(cabs),1,fp3);
    fclose(fp3);
}
int get_Num_of_Registration()
{
    FILE * fp;
    fp = fopen("cab-record.txt","r");
    Num_Of_Registration = 0;
    while(fread(&cabs,sizeof(cabs),1,fp))
    {
        Num_Of_Registration  =  Num_Of_Registration + 1;
    }
    fclose(fp);
    return  Num_Of_Registration;
}
void displayCab()
{
    struct cab *c;
    c = &cabs;
    FILE * fp4;
    fp4 = fopen("cab-record.txt","r");
    printf("Id\tName\tType\tModel\tFrom\tTo\tAmmount\n");
    while(fread(&cabs,sizeof(cabs),1,fp4))
    {
        printf("%d\t%s\t%s\t%d\t%s\t%s\t%d",c->c_id,c->c_name,c->c_type,c->c_model,c->c_from,c->c_to,c->sm);
        printf("\n");
    }
    fclose(fp4);
}
int availableCabId(int id)
{
    struct cab *c;
    c = &cabs;
    FILE * fp3;
    fp3 = fopen("cab-record.txt","r");
    while(!feof(fp3))
    {
        fread(&cabs,sizeof(cabs),1,fp3);
        if(id == c->c_id)
        {
            fclose(fp3);
            return 1;
        }
    }
    fclose(fp3);
    return 0;
}
void updateCab()
{
    struct cab *c;
    c = &cabs;
    FILE * fp5;
    FILE * fp6;
    int available,upid,s,ch=1,choice;
    printf("\n Enter The Id You Want To Update :");
    scanf("%d",&upid);
    available = availableCabId(upid);
    if(available == 0)
    {
        printf("\nCab Id %d is not Available",upid);
    }
    else
    {
        fp5 = fopen("cab-record.txt","r");
        fp6 = fopen("update.txt","w");
        while(fread(&cabs,sizeof(cabs),1,fp5))
        {
            s = c->c_id;
            if(s!=upid)
            {
                fwrite(&cabs,sizeof(cabs),1,fp6);
            }
            else
            {
                while(ch!=0)
                {
                    printf("\n0.Exist This Process.");
                    printf("\n1. Update  Name of Id %d ",upid);
                    printf("\n2. Update Type of Id %d ",upid);
                    printf("\n3. Update Model of Id %d ",upid);
                    printf("\n4. Update From Destination  of Id %d ",upid);
                    printf("\n5. Update To Destination of Id %d ",upid);
                    printf("\n6. Update Ammount of Id %d ",upid);
                    printf("\n Enter Your Choice :");
                    scanf("%d",&choice);
                    if(choice == 0)
                    {
                        break;
                    }
                    else if(choice == 1)
                    {
                        printf("\n Enter Cab Name :");
                        scanf("%s",c->c_name);
                    }
                    else if(choice == 2)
                    {
                        printf("\n Enter Cab Type :");
                        scanf("%s",c->c_type);
                    }
                    else if(choice == 3)
                    {
                        printf("\n Enter Cab Model :");
                        scanf("%d",&c->c_model);
                    }
                    else if(choice == 4)
                    {
                        printf("\n Enter A Pick Up Place :");
                        scanf("%s",c->c_from);
                    }
                    else if(choice == 5)
                    {
                        printf("\n Enter A Destination Place :");
                        scanf("%s",c->c_to);
                    }
                    else if(choice == 6)
                    {
                        printf("\n Enter The Service Ammount :");
                        scanf("%d",&c->sm);
                    }
                    else
                    {
                        printf("\n Please Enter Valid Choice.");
                    }
                }
                fwrite(&cabs,sizeof(cabs),1,fp6);
            }
        }
        fclose(fp5);
        fclose(fp6);
        fp5 = fopen("cab-record.txt","w");
        fp6 = fopen("update.txt","r");
        while(fread(&cabs,sizeof(cabs),1,fp6))
        {
            fwrite(&cabs,sizeof(cabs),1,fp5);
        }
        fclose(fp5);
        fclose(fp6);
        printf("\n Cab Record Updated Successfully.");
    }
}
void deleteCab()
{
    struct cab *c;
    c = &cabs;
    FILE * fp5;
    FILE * fp6;
    int delete_id,s,available;
    printf("\n Enter The Id You Want To Delete :");
    scanf("%d",&delete_id);
    available = availableCabId(delete_id);
    if(available == 0)
    {
        printf("\nCab Id %d is not Available",delete_id);
    }
    else
    {
        fp5 = fopen("cab-record.txt","r");
        fp6 = fopen("update.txt","w");
        while(fread(&cabs,sizeof(cabs),1,fp5))
        {
            s = c->c_id;
            if(s!=delete_id)
            {
                fwrite(&cabs,sizeof(cabs),1,fp6);
            }
        }
        fclose(fp5);
        fclose(fp6);
        fp5 = fopen("cab-record.txt","w");
        fp6 = fopen("update.txt","r");
        while(fread(&cabs,sizeof(cabs),1,fp6))
        {
            fwrite(&cabs,sizeof(cabs),1,fp5);
        }
        fclose(fp5);
        fclose(fp6);
        printf("\n Cab Record Deleted Successfully.");

    }
}
void login()
{
    struct Registration *de;
    de = &d;
    FILE * fp2;
    fp2 = fopen("record-delear.txt","r");
    char Lname[20];
    int Lpass,z,ch=1;
    printf("\n Enter Delear name :");
    scanf("%s",Lname);
    printf("\n Enter Delear password :");
    scanf("%d",&Lpass);
    while(fread(&d,sizeof(d),1,fp2)){
    if(strcmp(Lname,de->d_name) == 0)
    {
        if(Lpass == de->d_pass)
        {
           printf("login sucessfully!! Now You Can Add , view , Update And Delete Your Cabs");
               while(ch!=0)
               {
                    printf("\n Press 1 For Add A New Cab .");
                    printf("\n Press 2 For veiw All your Cabs .");
                    printf("\n Press 3 For Update Any Information About Cab .");
                    printf("\n press 4 For Delete A Cab From Your List .");
                    printf("\n press 0 For Log Out .");
                    printf("\n Enter Your Choice :");
                    scanf("%d",&z);
                    if(z == 0)
                    {
                        printf("\n Thank You.Have a Nice Day");
                        break;
                    }
                    else if(z == 1)
                    {
                        Addcab();
                    }
                    else if(z == 2)
                    {
                        displayCab();
                    }
                    else if(z == 3)
                    {
                        updateCab();
                    }
                    else if(z == 4)
                    {
                        deleteCab();
                    }
                    else
                    {
                        printf("\n Please Enter Valid Choice.");
                    }
               }
        }
        
    }
    
    }
    fclose(fp2);
}
struct user_Registration
{
    char uname[20],uemail[20];
    int upass,uid;
    long uphone;
}uReg;
void userReg()
{
    struct user_Registration *u;
    u = &uReg;
   FILE * fp7;
   fp7 = fopen("user-record.txt","a");
        printf("\n Enter User Id : ");
        scanf("%d",&u->uid);
        printf("\n Enter User Name : ");
        scanf("%s",u->uname);
        printf("\n Enter User Password : ");
        scanf("%d",&u->upass);
        printf("\n Enter User Email Address : ");
        scanf("%s",u->uemail);
        printf("\n Enter User Phone Number : ");
        scanf("%ld",&u->uphone);
    fwrite(&uReg,sizeof(uReg),1,fp7);
    fclose(fp7);
    printf("\n *****User Added Successfully*****\n");
}
void displayUser()
{
    struct user_Registration *u;
    u = &uReg;
    FILE * fp8;
    fp8 = fopen("user-record.txt","r");
    printf("Id\tName\tpassword\tEmail\tphone\n");
    while(fread(&uReg,sizeof(uReg),1,fp8))
    {
        printf("%d\t%s\t%d\t%s\t%ld",u->uid,u->uname,u->upass,u->uemail,u->uphone);
        printf("\n");
    }
    fclose(fp8);
}
int availableUserId(int usid)
{
    struct user_Registration *u;
    u = &uReg;
    FILE * fp12;
    fp12 = fopen("user-record.txt","r");
    while(!feof(fp12))
    {
        fread(&uReg,sizeof(uReg),1,fp12);
        if(usid == u->uid)
        {
            fclose(fp12);
            return 1;
        }
    }
    fclose(fp12);
    return 0;
}
void updateUser()
{
    struct user_Registration *u;
    u = &uReg;
    FILE * fp10;
    FILE * fp11;
    int available,User_id,s,ch=1,choice;
    printf("\n Enter The User Id You Want To Update :");
    scanf("%d",&User_id);
    available = availableUserId(User_id);
    if(available == 0)
    {
        printf("\n User Id %d is not Available",User_id);
    }
    else
    {
        fp10 = fopen("user-record.txt","r");
        fp11 = fopen("userUpdate.txt","w");
        while(fread(&uReg,sizeof(uReg),1,fp10))
        {
            s = u->uid;
            if(s!=User_id)
            {
                fwrite(&uReg,sizeof(uReg),1,fp11);
            }
            else 
            {
                while(ch!=0)
                {
                    printf("\n 0. Exist This Process.");
                    printf("\n 1. Update Name Of User Id %d ",User_id);
                    printf("\n 2. Update Password Of User Id %d ",User_id);
                    printf("\n 3. Update Email Address Of User Id %d ",User_id);
                    printf("\n 4. Update Phone Number Of User Id %d ",User_id);
                    printf("\n Enter Your Choice :");
                    scanf("%d",&choice);
                    if(choice == 0)
                    {
                        break;
                    }
                    else if(choice == 1)
                    {
                         printf("\n Enter User Name :");
                        scanf("%s",u->uname);
                    }
                    else if(choice == 2)
                    {
                        printf("\n Enter user Password :");
                        scanf("%d",&u->upass);
                    }
                    else if(choice == 3)
                    {
                        printf("\n Enter User Email Address :");
                        scanf("%s",u->uemail);
                                    
                    }
                    else if(choice == 4)
                    {
                        printf("\n Enter User Phone Number :");
                        scanf("%ld",&u->uphone);               
                    }
                    else
                    {
                        printf("\n Please Enter Valid Choice.");
                    }
                }
                fwrite(&uReg,sizeof(uReg),1,fp11);
            }
        }
        fclose(fp10);
        fclose(fp11);
        fp10 = fopen("user-record.txt","w");
        fp11 = fopen("userUpdate.txt","r");
        while(fread(&uReg,sizeof(uReg),1,fp11))
        {
            fwrite(&uReg,sizeof(uReg),1,fp10);
        }
        fclose(fp10);
        fclose(fp11);
        printf("\n*****User Information Updated Successfully*****\n");
    }
}
void sort()
{
    int i,j;
    int size = get_Num_of_Registration();
    struct cab *p,temp;
    p = (struct cab *) calloc(size,sizeof(struct cab));
    FILE * fp12;
    fp12 = fopen("cab-record.txt","r");
    for(i=0;i<size;i++)
    {
        fread(p+i,sizeof(cabs),1,fp12);
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if((p+i)->sm > (p+j)->sm)
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
       printf("%d\t%s\t%s\t%d\t%s\t%s\t%d",(p+i)->c_id,(p+i)->c_name,(p+i)->c_type,(p+i)->c_model,(p+i)->c_from,(p+i)->c_to,(p+i)->sm);
        printf("\n");
    }
    fclose(fp12);
}
void searchCabPrice()
{
    struct cab *c;
    c = &cabs;
    FILE *fp16;
    int lower,higher,m=0;
    printf("\n Enter Lower Lmit Of Price :");
    scanf("%d",&lower);
    printf("\n Enter Higher Lmit Of Price :");
    scanf("%d",&higher);
    fp16 = fopen("cab-record.txt","r");
    printf("Id\tName\tType\tModel\tFrom\tTo\tAmmount\n");
        while(fread(&cabs,sizeof(cabs),1,fp16))
        {
            if(c->sm >= lower && c->sm <= higher)
            {
                printf("%d\t%s\t%s\t%d\t%s\t%s\t%d",c->c_id,c->c_name,c->c_type,c->c_model,c->c_from,c->c_to,c->sm);
                printf("\n");
                m++;
            }
        }
        if(m == 0)
        {
            printf("\n No Records Found With Price.");
        }
        else
        {
            printf("\n %d Record Found\n ",m);
        }
    
    fclose(fp16);
}
void SearchcabId()
{
    struct cab *c;
    c = &cabs;
    FILE *fp17;
    int i,available,m;
    printf("\n Enter The Cab Id You Want To Search :");
    scanf("%d",&i);
    available = availableCabId(i);
    if(available == 0)
    {
        printf("\n Cab Id %d Is Not Available In This File.\n",i);
    }
    else
    {
        fp17 = fopen("cab-record.txt","r");
        printf("Id\tName\tType\tModel\tFrom\tTo\tAmmount\n");
        while(fread(&cabs,sizeof(cabs),1,fp17))
        {
            m = c->c_id;
            if(m == i)
            {
                printf("%d\t%s\t%s\t%d\t%s\t%s\t%d",c->c_id,c->c_name,c->c_type,c->c_model,c->c_from,c->c_to,c->sm);
                printf("\n");
            }
        }
       
    }
    fclose(fp17);
}
void searchCab()
{
    struct cab *c;
    c = &cabs;
    FILE * fp13;
    char name[20];
    int p=0;
    printf("\n Enter Cab Name You Want To Search :");
    scanf("%s",name);
    fp13 = fopen("cab-record.txt","r");
    while(fread(&cabs,sizeof(cabs),1,fp13))
    {
        if(strcmp(name,c->c_name) == 0)
        {
            printf("Id\tName\tType\tModel\tFrom\tTo\tAmmount\n");
            printf("%d\t%s\t%s\t%d\t%s\t%s\t%d",c->c_id,c->c_name,c->c_type,c->c_model,c->c_from,c->c_to,c->sm);
            printf("\n");
            p++;
        }
    }
    if(p == 0)
    {
        printf("\n No Records Found With Name %s ",name);
    }
    else
    {
        printf("\n %d Record Found\n ",p);
    }
    fclose(fp13);
}
void userlogin()
{
    struct user_Registration *u;
    u = &uReg;
     struct cab *c;
    c = &cabs;
    FILE * fp9;
    fp9 = fopen("user-record.txt","r");
    int Upass,z,ch=1;
    char Uname[20];
    printf("\n Enter User name :");
    scanf("%s",Uname);
    printf("\n Enter User password :");
    scanf("%d",&Upass);
    while(fread(&uReg,sizeof(uReg),1,fp9))
    {
        if(strcmp(Uname,u->uname) == 0)
        {
            if(Upass == u->upass)
            {
                printf("Login Sucessfully!!");
                while(ch!=0)
                {
                printf("\n Press 1 For Show Present Cab : ");
                printf("\n Press 2 For Change Profile : ");
                printf("\n Press 3 For Show Sort Wise Cab Details :");
                printf("\n Press 4 For Search :");
                printf("\n Press 0 For Logout : ");
                printf("\n Enter Your Choice :");
                scanf("%d",&z);
                if(z == 0)
                {
                        printf("Thank You.For Visiting.");
                        break;
                }
                else if(z == 1)
                {
                    displayCab();
                }
                else if(z == 2)
                {
                    updateUser();
                }
                else if(z == 3)
                {
                    sort();
                }
                else if(z == 4)
                {
                    int k=1,v;
                    while(k!=0)
                    {
                        printf("\n 1. Search By Cab Charges :");
                        printf("\n 2. Search By Cab Name :");
                        printf("\n 3. Search by Cab Id :");
                        printf("\n 0. Exit.");
                        printf("\n Enter Your Choice = ");
                        scanf("%d",&v);
                        if(v == 0)
                        {
                            break;
                        }
                        else if(v == 1)
                        {
                            searchCabPrice();
                        }
                        else if(v == 2)
                        {
                            searchCab();
                        }
                        else if(v == 3)
                        {
                            SearchcabId();
                        }
                        else
                        {
                            printf("\n Please Enter Valid Choice.\n");
                        }
                    }
                }
                else
                {
                    printf("\n Please Enter Valid Choice.");
                }
                    
                
                }
            }
        }
    }
}
int emptyfile()
{
    struct Registration *de;
    de = &d;
    int k=0;
    FILE * fp14;
    fp14 = fopen("record-delear.txt","r");
    while(fread(&d,sizeof(d),1,fp14))
    {
        k=1;
    }
    fclose(fp14);
    return k;
}
int emptyfile1()
{
    struct user_Registration *u;
    u = &uReg;
    int x=0;
    FILE * fp15;
    fp15 = fopen("user-record.txt","r");
    while(fread(&uReg,sizeof(uReg),1,fp15))
    {
        x=1;
    }
    fclose(fp15);
    return x;
}
int main()
{
    int ch=1,z,c;
    while(ch!=0)
    {
        printf("\n 1. Delear Registration");
        printf("\n 2. Display All Delear");
        printf("\n 3. Delear Login");
        printf("\n 4. User Registration");
        printf("\n 5. Display All User");
        printf("\n 6. User login");
        printf("\n 0. Exist.");
        printf("\n Enter Your Choice :");
        scanf("%d",&z);
        if(z == 0)
        {
            printf("\n Thank You. For Visiting.");
            break;
        }
        else if(z == 1)
        {
            Reg();
        }
        else if(z == 2)
        {
            c = emptyfile();
            if(c == 0)
            {
                printf("\n Your File Is Blank.\n");
            }
            else
            {
                display();
            }
        }
        else if(z == 3)
        {
            login();
        }
        else if(z == 4)
        {
            userReg();
        }
        else if(z == 5)
        {
            c = emptyfile1();
            if(c == 0)
            {
                printf("\n Your File Is Blank.\n");
            }
            else
            {
                displayUser();
            }
        }
        else if(z == 6)
        {
            userlogin();
        }
        else
        {
            printf("\n Please Enter Valid Choice.");
        }
    }
    return 0;
}