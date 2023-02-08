
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<string.h> 
#include<chrono>
#include<numeric>
#include<iomanip>
using namespace std;

void getInput()
{
  ofstream fp;
  fp.open("input.text");
  for(int i=0;i<100000;i++)
  fp<< rand()%100000 << endl;
  fp.close();
}

void readfile(int arr[])
{
  int i=0;
  ifstream fp;
  fp.open("input.text");
  while(fp.good())
  {
    fp >> arr[i];
    i++;
  }
  fp.close();
}
void insertionsort(int arr[],int i)
{
    int temp=i;
    if(i==100000)
    return;
    int curr=arr[i];
    temp--;
    while(temp>=0 && arr[temp]>curr)
    {
      arr[temp+1]=arr[temp];
      temp--;
    }
    arr[temp+1]=curr;
    insertionsort(arr,i+1);
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void selectionsort(int arr[],int i)
{
  if(i==100000)
  return;
  for(int j=i;j<100000;j++)
  {
    if(arr[j]<arr[i])
    swap(arr[j],arr[i]);
  }
}

int main()
{
  int arr[100000];
  clock_t start,end;
  double time_taken;
  getInput();
  readfile(arr);
  printf("The data:\n");
  printArray(arr,100000);
  printf("\nFunction:\n1.Insertion Sort\n2.Selection Sort\n");
  printf("\nEnter your choice:");
   int ch;
   scanf("%d", &ch);
   if(ch==1)
   {
      start=clock();
      insertionsort(arr,0);
      end=clock();
      time_taken=double(end-start)/double(CLOCKS_PER_SEC);
      cout<<"Time taken by program is:"<<fixed<<time_taken<<setprecision(5);
      cout<<"sec"<<endl;
      return 0;
   }
   else if(ch==2)
   {
       start=clock();
       selectionsort(arr,0);
       end=clock();
       time_taken=double(end-start)/double(CLOCKS_PER_SEC);
       cout<<"Time taken by program is:"<<fixed<<time_taken<<setprecision(5);
       cout<<"sec"<<endl;
       return 0;
   }
   else 
   {
       cout<<"Entered wrong choice"<<endl;
   }
  return 0;
}