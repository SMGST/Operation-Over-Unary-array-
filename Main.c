/*          AUTHOR
        Mohammad Tamim Sarker
            CSE Student 
        Faridpur Engineering College    */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct array
{
    int *A;
    int size;
    int length;
}Array;

void display(Array);              //--------------O(n)
void scan(Array*);                //--------------O(n)
void declare(Array*);             //--------------O(1)
void declare_and_scan(Array*);    //--------------O(n)
void swap(int *,int *);           //--------------O(1)

void exclude_include(Array *);        //----------O(n^3)
void execute_append(Array *);     //--------------O(n)
void append(Array*,int);          //--------------O(1)
void execute_insert(Array *);     //--------------O(n^2)
void insert(Array*,int,int);      //--------------O(n)
void execute_insert_into_sorted(Array *); //------O(n^2)
void insert_into_sorted(Array *,int);       //----O(n)
void execute_delete(Array *);     //--------------O(n^2)
int Delete(Array *,int);          //--------------O(n)
void execute_replace(Array *);    //--------------O(n)
void replace(Array *,int ,int );  //--------------O(1)
void execute_Get(Array);          //--------------O(n)
int Get(Array ,int);              //--------------O(1)

int is_sorted(Array );
void rearrange_positive_negitive(Array *);

void search(Array *);                 //----------O(n^2)
void execute_binary_search(Array *);  //----------O(nLog(n))
int binary_search(Array * ,int);      //----------O(Log(n))
void execute_linear_search(Array *);  //----------O(n^2)
int linear_search2(Array *,int);      //----------O(n)
int linear_search(Array *,int);       //----------O(n)

void Order_braking(Array *);
void execute_Left_sift(Array *);
void execute_Right_sift(Array *);
void execute_Left_rotate(Array *);
void execute_Right_rotate(Array *);
void reverse(Array *);
void reverse2(Array *);
void Left_sift(Array *);
void Left_rotate(Array *);
void Right_sift(Array *);
void Right_rotate(Array *);

void mathOP(Array *);               //----------O(n)
int Max(Array );                    //----------O(1)
int Min(Array );                    //----------O(1)
int Sum(Array );                    //----------O(1)
double Avg(Array );                 //----------O(1)

void copy(Array* ,Array*);
void reverse_copy(Array* ,Array*);

void main()
{
    system("cls && color 0a");
    Array arr;
    declare_and_scan(&arr);
    int op;
    while(1)
    {
        system("cls");
        display(arr);
        printf("Which Operation you want to Operate ?\n\n");
        printf("\t(Give Option Number)\n");
        printf("\t(Wrong Option Number not accepted)\n\n");

        printf("1.search\n");
        printf("2.excluding & including\n");
        printf("3.Mathematical Operation\n");
        printf("4.Change Order\n");
        printf("0.Exit\n");

        scanf("%d",&op);
        if(op > 4) {printf("Wrong option\n");}

        else if(op == 1) search(&arr);
        else if(op == 2) exclude_include(&arr);
        else if(op == 3) mathOP(&arr);
        else if(op == 4) Order_braking(&arr);
        else if(op == 0) break;
        printf("\n\n");
    }
    free(arr.A);
    system("Pause");
}
void Order_braking(Array *arr)
{
    int op;
    while(1)
    {
        system("cls");
        display(*arr);
        printf("Which Operation you want to Operate ?\n\n");
        printf("\t(Give Option Number)\n");
        printf("\t(Wrong Option Number not accepted)\n\n");

        printf("1.Right Sift\n");
        printf("2.Left Sift\n");
        printf("3.Right rotate\n");
        printf("4.Left rotate\n");
        printf("5.Reverse\n");
        printf("0.Back\n");

        scanf("%d",&op);
        if(op > 5) {printf("Wrong option\n");}

        else if(op == 1) execute_Right_sift(arr);
        else if(op == 2) execute_Left_sift(arr);
        else if(op == 3) execute_Right_rotate(arr);
        else if(op == 4) execute_Left_rotate(arr);
        else if(op == 5) {
            system("cls");
            reverse(arr);
            printf("\n\nFinally After Reversing ");
            display(*arr);
            system("pause");
        }
        else if(op == 0) break;
        printf("\n\n");
    }
    system("Pause");
}
void mathOP(Array *arr)
{
    int value,op;
    double valuef;
    system("cls");
    while(1)
    {

        printf("Which Operation you want to Operate ?\n\n");
        printf("\t(Give Option Number)\n");
        printf("\t(Wrong Option Number not accepted)\n\n");
        printf("1.Find Maximum\n");
        printf("2.Find Minimum\n");
        printf("3.Summation of all ELEMENTS\n");
        printf("4.Average of all ELEMENTS\n");
        printf("0.Back\n");

        scanf("%d",&op);
        if(op > 4) {printf("Wrong option\n");break;}

        if(op == 1)
        {
            value = Max(*arr);
            printf("maximum of array : %d\n",value);
        }
        else if(op == 2)
        {
            value = Min(*arr);
            printf("minimum of array : %d\n",value);
        }
        else if(op == 3)
        {
            value = Sum(*arr);
            printf("Summetion of all elemen of array : %d\n",value);
        }
        else if(op == 4)
        {
            valuef = Avg(*arr);
            printf("Average of all elemen of array : %.3lf\n",valuef);
        }
        else if(op == 0) break;
        printf("\n\n");
    }
    system("Pause");
}
void exclude_include(Array *arr)
{
    int op;
    system("cls");
    while(1)
    {
        printf("Which Operation you want to Operate ?\n\n");
        printf("\t(Give Option Number)\n");
        printf("\t(Wrong Option Number not accepted)\n\n");

        printf("1.Delete Element with index\n");
        printf("2.Get Value of any index\n");
        printf("3.Append Element\n");
        printf("4.Insert Element at fix INDEX\n");
        printf("5.Replace(Set) Element at fix INDEX\n");
        printf("6.Insert Element into sorted Array");
        printf("(If Array is Sorted)\n");
        printf("0.Back\n");

        scanf("%d",&op);
        if(op > 6) {printf("Wrong option\n");}

        else if(op == 1) execute_delete(arr);
        else if(op == 2) execute_Get(*arr);
        else if(op == 3) execute_append(arr);
        else if(op == 4) execute_insert(arr);
        else if(op == 5) execute_replace(arr);
        else if(op == 6) execute_insert_into_sorted(arr);
        else if(op == 0) break;
        printf("\n\n");
    }
    system("Pause");
}
void search(Array *arr)
{
    system("cls");
    printf("Which Search you want to Operate ?\n\n");
    printf("\t(Give Option Number)\n");
    printf("\t(Wrong Option Number not accepted)\n\n");
    printf("1.Linear Search\n");
    printf("2.Binary Search");
    printf("(If Array is Sorted)\n");

    int op;
    scanf("%d",&op);
    if(op != 1 || op != 2) printf("Wrong option\n");

    if(op == 1) execute_linear_search(arr);
    else if(op == 2) execute_binary_search(arr);
    printf("\n\n");
    system("Pause");
}
void execute_Left_sift(Array * arr)
{
    system("cls");
    int n,i;
    display(*arr);

    printf("Enter number of time do you want to Left sift :");
    scanf("%d",&n);
    for (i=0;i<n;i++) Left_sift(arr);

    printf("\n\nFinally After Left_sifting ");
    display(*arr);
    system("Pause");
}
void execute_Right_sift(Array * arr)
{
    system("cls");
    int n,i;
    display(*arr);

    printf("Enter number of time do you want to Right sift :");
    scanf("%d",&n);
    for (i=0;i<n;i++) Right_sift(arr);

    printf("\n\nFinally After Right_sifting ");
    display(*arr);
    system("Pause");
}
void execute_Left_rotate(Array * arr)
{
    system("cls");
    int n,i;
    display(*arr);

    printf("Enter number of time do you want to Left rotate :");
    scanf("%d",&n);
    for (i=0;i<n;i++) Left_rotate(arr);

    printf("\n\nFinally After Left_rotating ");
    display(*arr);
    system("Pause");
}
void execute_Right_rotate(Array * arr)
{
    system("cls");
    int n,i;
    display(*arr);

    printf("Enter number of time do you want to Right rotate :");
    scanf("%d",&n);
    for (i=0;i<n;i++) Right_rotate(arr);

    printf("\n\nFinally After Right_rotating ");
    display(*arr);
    system("Pause");
}
void execute_Get(Array arr)
{
    system("cls");
    int n,i,index,ele;
    display(arr);

    printf("Enter number of Time do you want to GET value from array:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {

        printf("\nCase %d:\n",i+1);
        printf("Enter index :");
        scanf("%d",&index);

        ele = Get(arr,index);
        printf("Value of INDEX %d is %d\n",index,ele);
    }
    system("Pause");
}
void execute_replace(Array * arr)
{
    system("cls");
    int n,i,ele,index;
    display(*arr);

    printf("Enter number of Time do you want to REPLACE :");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {

        printf("\nCase %d:\n",i+1);
        printf("Enter index :");
        scanf("%d",&index);
        printf("Enter Number :");
        scanf("%d",&ele);

        replace(arr,index,ele);
        printf("%d is replaced for old value of Index %d\n",ele,index);
        printf("After replacing %d, ARRAY ",ele);
        display(*arr);
    }
    printf("\n\nFinally After replacing ALL given Number ");
    display(*arr);
    system("Pause");

}
void execute_insert(Array * arr)
{
    system("cls");
    int n,i,count = arr->length,ele,index;
    display(*arr);

    printf("Enter number of Time do you want to INSERT at fix index :");
    scanf("%d",&n);
    for (i=0;i<n;i++,count++)
    {
        if(count >= arr->size)
        {
            printf("Not enough mamory is available for more element \n");
            break ;
        }
        printf("\nCase %d:\n",i+1);
        printf("Enter index :");
        scanf("%d",&index);
        printf("Enter element :");
        scanf("%d",&ele);

        insert(arr,index,ele);
        printf("%d is Inserted to %d Index\n",ele,index);
        printf("After Inserting %d, ARRAY ",ele);
        display(*arr);
    }
    printf("\n\nFinally After Appending ALL given elements ");
    display(*arr);
    system("Pause");

}
void execute_insert_into_sorted(Array * arr)
{
    system("cls");
    int n,i,count = arr->length,num;
    display(*arr);

    printf("Enter number of Time do you want to INSERT into Sorted array :");
    scanf("%d",&n);
    for (i=0;i<n;i++,count++)
    {
        if(count >= arr->size)
        {
            printf("Not enough mamory is available for more element \n");
            break ;
        }
        printf("\nCase %d:\n",i+1);
        printf("Enter Element :");
        scanf("%d",&num);
        insert_into_sorted(arr,num);
        printf("%d is Inserted into Array\n",num);
        printf("After Inserting %d, ARRAY ",num);
        display(*arr);
    }
    printf("\n\nFinally After Appending ALL given elements ");
    display(*arr);
    system("Pause");
}
void execute_append(Array * arr)
{
    system("cls");
    int n,i,count = arr->length,num;
    display(*arr);

    printf("Enter number of Time do you want to APPEND :");
    scanf("%d",&n);
    for (i=0;i<n;i++,count++)
    {
        if(count >= arr->size)
        {
            printf("Not enough mamory is available for more element \n");
            break ;
        }
        printf("\nCase %d:\n",i+1);
        printf("Enter Element :");
        scanf("%d",&num);
        append(arr,num);
        printf("%d is appended into Array\n",num);
        printf("After appending %d, ARRAY ",num);
        display(*arr);
    }
    printf("\n\nFinally After Appending ALL given elements ");
    display(*arr);
    system("Pause");
}
void execute_delete(Array * arr)
{
    system("cls");
    int n,i,x,index;
    display(*arr);

    printf("Enter number of Time do you want to DELETE :");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("\nCase %d:\n",i+1);
        printf("\nEnter Index :");
        scanf("%d",&index);
        x = Delete(arr,index);
        printf("%d is deleted from index %d\n",x,index);
        printf("After deleting %d, ARRAY ",x);
        display(*arr);
    }
    printf("\n\nFinally After Deleting ALL Given Indexes ");
    display(*arr);
    system("Pause");
}
void execute_binary_search(Array * arr)
{
    system("cls");
    int i,n,index,num;
    display(*arr);
    printf("Enter number of Time do you want to Search :");
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        printf("\nCase %d:\n",i+1);
        printf("Enter Number :");
        scanf("%d",&num);
        index = binary_search(arr,num);
        if(index>=0) printf("%d is available in index %d\n",num,index);
        else printf("%d is not available at array\n",num);
    }
    display(*arr);
    printf("\n\n");
    system("Pause");
}
void execute_linear_search(Array * arr)
{
    system("cls");
    printf("Which linear Search you want to Operate ?");
    printf("\t(Give Option Number)\n");
    printf("\t(Wrong Option Number not accepted)\n\n");
    printf("1.Normal Linear Search\n");
    printf("2.AI Linear Search\n");

    int op;
    scanf("%d",&op);
    if(op != 1 || op != 2) printf("Wrong option\n");

    system("cls");
    int i,n,index,num;
    display(*arr);
    printf("Enter number of Time do you want to Search :");
    scanf("%d",&n);
    if(op == 1)
    {
        for (i=0;i<n;i++)
        {
            printf("\nCase %d:\n",i+1);
            printf("Enter Number :");
            scanf("%d",&num);
            index = linear_search(arr,num);
            if(index>=0) printf("%d is available in index %d\n",num,index);
            else printf("%d is not available at array\n",num);
        }
    }
    else if(op == 2)
    {
        for (i=0;i<n;i++)
        {
            printf("\nCase %d:\n",i+1);
            printf("Enter Number :");
            scanf("%d",&num);
            index = linear_search2(arr,num);
            if(index>=0) printf("%d is available in index %d\n",num,index);
            else printf("%d is not available at array\n",num);
        }
    }
    display(*arr);
    printf("\n\n");
    system("Pause");
}
void rearrange_positive_negitive(Array *X)
{
    int i = 0,j = X->length-1;
    while(i<j)
    {
        while(X->A[i]<0) i++;
        while(X->A[j]>=0) j--;
        if(i<j) swap(&X->A[i],&X->A[j]);
    }
}
int is_sorted(Array arr)
{
    int i,l = arr.length-1;
    for(i=0;i<l;i++)
    {
        if(arr.A[i] > arr.A[i+1]) return 0;
    }
    return 1;
}
void Left_sift(Array *X)
{
    int i,l = X->length-1;
    for(i=0;i<l;i++)
    {
        X->A[i] = X->A[i+1];
    }
    X->A[i] = 0;

}
void Left_rotate(Array *X)
{
    int i,temp = X->A[0],l = X->length-1;
    for(i=0;i<l;i++)
    {
        X->A[i] = X->A[i+1];
    }
    X->A[i] = temp;

}
void Right_sift(Array *X)
{
    int i,l = X->length-1;
    for(i=l;i>0;i--)
    {
        X->A[i] = X->A[i-1];
    }
    X->A[i] = 0;

}
void Right_rotate(Array *X)
{
    int i,temp,l = X->length-1;
    temp = X->A[l];
    for(i=l;i>0;i--)
    {
        X->A[i] = X->A[i-1];
    }
    X->A[i] = temp;

}
void reverse2(Array *X)
{
    int i,j;
    for(i=0,j=X->length-1;i<=j;i++,j--)
    {
        swap(&X->A[i],&X->A[j]);
    }
}
void reverse(Array *X)
{
    Array Y;
    Y.A = (int *) malloc(X->length*sizeof(int));
    if(Y.A == NULL)
    {
        printf("Unable to allocate mamory of secend array for reversing");
        return;
    }
    Y.length = X->length;
    copy(X,&Y);
    reverse_copy(&Y,X);
    free(Y.A);
}
void copy(Array* from,Array* to)
{
    int i;
    for (i=0;i<from->length;i++)
    {
        to->A[i] = from->A[i];
    }
}
void reverse_copy(Array* from,Array* to)
{
    int i,j;
    for (i=0,j=from->length-1;i<from->length;i++,j--)
    {
        to->A[i] = from->A[j];
    }
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int Get(Array arr,int index)
{
    if(index>=0 && index<arr.length)return arr.A[index];
    return -1;
}
void replace(Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length) arr->A[index] = x;
}
int Max(Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}
int Min(Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
}
int Sum(Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++) s+=arr.A[i];
    return s;
}
double Avg(Array arr)
{
    return (double)Sum(arr)/arr.length;
}
int binary_search(Array* arr,int num)
{
    int low = 0,mid,high = arr->length-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(num==arr->A[mid]) return mid;
        else if(num<arr->A[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int linear_search2(Array* arr,int num)
{
    int i,tm;
    for(i=0;i<arr->length;i++)
    {
        if(num==arr->A[i])
        {
            if(i>0)
            {
                tm  = arr->A[i];
                arr->A[i] = arr->A[i-1];
                arr->A[i-1] = tm;
                return i-1;
            }
            else return i;
        }
    }
    return -1;
}
int linear_search(Array* arr,int num)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(num==arr->A[i]) return i;
    }
    return -1;
}
int Delete(Array* arr,int index)
{
    int x = 0 ,i,l = arr->length-1;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];

        for(i=index;i<l;i++) arr->A[i] = arr->A[i+1];

        arr->length--;
        return x;
    }
    else if(index>=arr->length && index<arr->size)
    {
        arr->length--;
        return arr->A[index];
    }
    return 0;
}
void insert_into_sorted(Array *arr,int x)
{
    int i = arr->length-1;
    /*
    if(is_sorted(*arr))
    {
        arr->A[arr->length] = x;
        arr->length++;
        return;
    }
    */
    if(arr->length == arr->size)
    {
        printf("Array is full\n");
        return;
    }
    while(i>=0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
void insert(Array* arr,int index,int x)
{
    int i;
    if(index>=0 && index < arr->size)
    {
        if(index < arr->length)
        {
            for(i=arr->length;i>index;i--) arr->A[i]=arr->A[i-1];

            arr->A[index]=x;
            arr->length++;
            return;
        }
        if(index>=arr->length)
        {
            arr->A[index] = x;
            arr->length = index + 1;
        }
    }
    else printf("invalid index \n");
}
void append(Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
    else
        printf("Not enough memory is available for this element \n");
}
void declare_and_scan(Array* a)
{
    declare(a);
    scan(a);
}
void declare(Array* a)
{
    printf("Enter size of array :");
    scanf("%d",&a->size);

    a->A = (int *) malloc(a->size*sizeof(int));
    a->length = 0;
}
void scan(Array* arr)
{
    int i,n;
    printf("Enter number of Time do you Want to input initially:");
    scanf("%d",&n);

    printf("Enter %d element :",n);
    arr->length = n;
    for(i=0;i<n;i++) scanf("%d",&arr->A[i]);
}
void display(Array arr)
{
    int i;
    printf("\n\tARRAY Elements are\n\t");
    for(i=0;i<arr.length;i++) printf("%d ",arr.A[i]);
    printf("\n\n");
}
