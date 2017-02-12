#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    
    int n, counter, counter_b, ii, temp;
    fstream input;
    ofstream output;
    
    ii=0;
    temp=0;
    counter=0;
    counter_b=0;
    input.open("sch.in");
    input >> n;
    
    if(n<3 || n>100000){
    	return 0;
	}
	
	
    int list[n], d[n], num[n];
    
    while(input.eof() == false && counter<n)
    {
   	 input >> list[counter];
   	 if(list[counter]<1 || list[counter]>10000){
   	 	return 0;
		}
   	 counter++;
    }
    input.close();

    
    qsort(list, n, sizeof(int), compare);
    
    
    counter=0;
    while(counter<n){
   	 d[ii]=1;
   	 while(list[counter]==list[counter+1]){
   		 d[ii]++;
   		 num[ii]=list[counter];
   		 counter++;
   	 }
   	 num[ii]=list[counter];
   	 ii++;
   	 counter++;
    }


    for (counter = 0; counter < ii; counter++){
   	 counter_b = counter;
   	 
   	 while (counter_b > 0 && d[counter_b] > d[counter_b-1]){
   		   temp = d[counter_b];
   		   d[counter_b] = d[counter_b-1];
   		   d[counter_b-1] = temp;
   		   temp = num[counter_b];
   		   num[counter_b] = num[counter_b-1];
   		   num[counter_b-1] = temp;
   		   counter_b--;
   		   }
   	 }
    
    
    output.open("sch.out");
    output<<num[0]<<" ";
    output<<num[1]<<" ";
    output<<num[2];
    output.close();
    
    return 0;
}

