#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int L,count=0;
int i,j,fb,period;
int *poly,*init_st,*arr;
cout<<"Enter the length of LFSR: ";
cin>>L;
poly=new int[L];
init_st=new int[L];
arr=new int[L];
cout<<endl<<"Enter the feedback polynomial of LFSR :";
for(i=0;i<L;i++)
 {
     cin>>poly[i];
  }
cout<<endl<<"Enter the initial state of LFSR at t=0 :";
for(i=L-1;i>=0;i--)
 {
     cin>>init_st[i];
     arr[i]=init_st[i];
}
     int max_period=(1<<L)-1;
     j=0;
    while(1)
 {
       j++;
      fb=0;
      for(i=0;i<L;i++)
      fb^=(poly[i]*arr[L-i-1]);
      for(i=0;i<L;i++)
      arr[i]=arr[i+1];
      arr[L-1]=fb;
      cout<<endl<<j<<":\t";
      for(i=0;i<L;i++)
      cout<<arr[L-i-1]<<" ";
      count=0;
      for(i=0;i<L;i++)
         {
              if((init_st[i]==arr[i]))
              count++;
          }
	     if(count==L)
	     break;
    }
       period=j;
      cout<<endl<<endl<<"The period of the lfsr is:"<<period<<endl;
      cout<<"Maximum period of the lfsr is:"<<max_period<<endl;
      delete[] poly;
      delete[] arr;
      delete[] init_st;
      return 0;
}

