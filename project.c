#include<stdio.h>

int n=5;
int a[6]={2,3,5,7,11};

void Traversing(a);
void INSERT(a,k,item);
void search(a);
void Deleting(a,i);
void sort_ascensing(a);
void sort_descensing(a);
void Find_loc(a,item);

int main()
{
    int choice,value,i,item;;

        printf("\n0. Exit.");
        printf("\n1. View all element.");
        printf("\n2. Insert new element.");
        printf("\n3. Search an element.");
        printf("\n4. Delete an element.");
        printf("\n5. Sort elements in ascending order.");
        printf("\n6. Sort elements in descending order.");
        printf("\n7. Find memory location of an element.");


    while(1)
    {

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
             Traversing(a);
             break;
        case 2:
            printf("\nWhich index you can insert the number.");
            scanf("%d",&i);
            printf("\nWhat is the number?");
            scanf("%d",&item);
            INSERT(a,i,item);
            break;
        case 3:
           search(a);
            break;
        case 4:
           printf("\nFrom Which index you can delete the number.");
           scanf("%d",&i);
           Deleting(a,i);
            break;
        case 5:
              sort_ascensing(a);
            break;
        case 6:
            sort_descensing(a);
            break;
        case 7:
             printf("\nWhat is the number?");
            scanf("%d",&item);
             Find_loc(a,item);
            break;

        default:
            printf("Invalid chioce.");

        }
    }
}
void Traversing(int a[])
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
void INSERT(int a[],int k,int item)
{
    k--;
    int j;
    j=n;
    while(j>=k)
    {
        a[j+1]= a[j];
        j--;
    }
    a[k]=item;
    n++;
}

void search(int a[])
{
    int i;

   int start,end,mid,key;
    start=0;
    end=n-1;
    printf("Enter searched number: ");
    scanf("%d",&key);

    do{
        mid=(int)((start+end)/2);
        if(a[mid]==key){
            printf("find at :%d\n",mid+1);
            break;
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    while(start<=end);
    if(start>end){
        printf("Failed\n");
    }

}
void Deleting(int a[],int k)
{
    k = k-1;
    int j;
    for(j=k; j<n; j++)
    {
        a[j] = a[j+1];
    }
    n = n-1;
}
void sort_ascensing(int a[])
{
   // int arr[5]={8,3,1,6,2};
    int i,j,k,temp,n;


    for(i=0;i<4;i++){
    for(j=i+1;j<5;j++){
        if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
      }
    }
      for(i=0;i<5;i++){
        printf("%d ",a[i]);
      }

    return 0;
}

void sort_descensing(int a[])
{
   int i,j,k,temp,n;


    for(i=0;i<4;i++){
    for(j=i+1;j<5;j++){
        if(a[i]<a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
      }
    }
      for(i=0;i<5;i++){
        printf("%d ",a[i]);
      }

    return 0;
}

void Find_loc(int a[],int item)
{
    int i,ck=0;
    for(i=0; i<n; i++)
    {
        if(a[i]==item){
                ck=1;
            printf("Find element at index: %d",i+1);
        break;
        }
    }
    if(ck==0)
        printf("Element is not found.");
}
