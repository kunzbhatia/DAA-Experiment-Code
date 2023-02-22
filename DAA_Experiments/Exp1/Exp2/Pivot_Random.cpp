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

int swaps = 0;
//FILE READING FUNCTIONS FROM HERE
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

//MERGE SORT FUNCTIONS FROM HERE
void Merge(int *arr,int low,int high,int mid)
{
	int left_size = mid-low+1;
	int right_size = high-mid;
	int *left_arr = new int[left_size];
	int *right_arr = new int[right_size];
	for(int i=0;i<left_size;i++)
		left_arr[i] = arr[low+i];
	for(int i=0;i<right_size;i++)
		right_arr[i] = arr[mid+i+1];
	int i=0,j=0;
	int k=low;	
	while(i<left_size && j<right_size){
		if(left_arr[i] < right_arr[j]){
			arr[k] = left_arr[i];
			i++;
		}else{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
}
	while(i<left_size){
		arr[k] = left_arr[i];
		i++;
		k++;
}
	while(j<right_size){
		arr[k] = right_arr[j];
		j++;
		k++;
}
	delete[] left_arr;
	delete[] right_arr;
	return;
}

void MergeSort(int *arr,int low,int high)
{
	if(low < high){
		int mid = (low+high)/2;
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,high,mid);
}
	return;
}

//QUICK SORT for random pivot FUNCTIONS FROM HERE

void swap(int *arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr,int low,int high){
    int i = low-1;
    int j = low;
    int pivot = arr[high];

    for(;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr,j,i);
			swaps++;
        }
    }
    i++;
    swap(arr,i,high);
    return i;
}

int partition_r(int *arr,int low,int high){
    int r = low + rand() % (high - low);
    swap(arr,high,r);

    return partition(arr,low,high);
}



void QuickSort(int *arr,int low,int high){
	if(low < high){
		int pivot = partition_r(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
	return;
}
 
//PRINTING FUNCTION
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//MAIN FUNCTION
int main()
{
  int i;
  int stop,limit;
  int arr[100000];
  clock_t start,end;
  double time_taken=0;
  getInput();
  readfile(arr);
  printf("The data:\n");
  printArray(arr,100000);
  printf("\nFunction:\n1.Merge Sort\n2.Quick Sort\n");
  printf("\nEnter your choice:");
   int ch;
   scanf("%d", &ch);
   if(ch==1)
   {   
       time_taken=0;
       i=1;
       stop=100;
       while(i<=1000)
       {
       start=clock();
       MergeSort(arr,0,stop);
       end=clock();
       time_taken=(double(end-start)/double(CLOCKS_PER_SEC));
       cout<<"Time taken by program is:"<<fixed<<time_taken<<setprecision(5);
       cout<<"sec"<<endl;
       stop=stop+100;
       i++;
       }
       return 0;
   }
   else if(ch==2)
   { 
       time_taken=0;
       i=1;
       stop=100;
       while(i<=1000)
       {
       start=clock();
       QuickSort(arr,0,stop);
       end=clock();
       time_taken=(double(end-start)/double(CLOCKS_PER_SEC));
       cout<<""<<fixed<<time_taken<<setprecision(5);
       cout<<""<<endl;
       printf("\n%d",swaps);
       stop=stop+100;
       i++;
       }
       return 0;
   }
   else 
   {
       cout<<"Entered wrong choice"<<endl;
   }
  return 0;
}