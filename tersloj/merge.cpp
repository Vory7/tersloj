#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void PrintDesk();
void BubbleSort();
void SelectSort();
void MergeSort();

const double pi = 3.14;

int main()
{
    MergeSort();
	
	return 0;
}

void PrintDesk()
{
		cout << "\t3 - MergeSort\n\n";
		
				
		cout << "\t0 - EXIT\n";
}

void BubbleSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int temp, M = 0, C = 0;
	for (int i = 0; i < n - 1; i++)
	{
	    for (int j = n - 1; j > i; j--) 
	    {
	      if (A[j - 1] > A[j]) 
	      {
	        temp = A[j - 1]; 
	        A[j - 1] = A[j];
	        A[j] = temp;
	        M+=3;
	      }
	      C++;	      
		}
	}
	cout << "\nC= " << C;
	cout << "\nM= " << M << "\n";	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nSum C + M = " << C+M << "\n";
}

void SelectSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int temp, min_i, M = 0, C = 0;
	for (int i = 0; i < n - 1; i++) 
	{	
        min_i = i;
    	for (int j = i + 1; j < n; j++) 
    	{
    		C++;
    		if (A[j] < A[min_i]) 
			    min_i = j;
		}	 
    	temp = A[i];
   		A[i] = A[min_i];
    	A[min_i] = temp;
    	M+=3;
	}
	cout << "\nS= " << C << "\n";
	cout << "\nP= " << M << "\n";	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nSum S + P = " << C+M << "\n";	
}

void MergeSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int M = 0, C = 0;
	
  	int step = 1;
  	int temp[n];
  	while (step < n)  
  	{
    	int index = 0;
    	int l = 0;
    	int m = l + step;
    	int r = l + step * 2;
    	
	    do
	    {
	    	if(m>n)
	    		m = n;
	    	if(r>n)
	    		r = n;
	    		
	    	int i1 = l, i2 = m; 
	    	while(i1<m && i2<r)
	    	{
	    		C++;
	    		if (A[i1] < A[i2]) 
				{ 
					temp[index++] = A[i1++]; 
					M++;
				}
	    		else 
				{ 
					temp[index++] = A[i2++]; 
					M++;
				}	
	    	}
	    	while (i1 < m)
			{
				
	    		 temp[index++] = A[i1++]; 
	    		M++;
			} 
	    	while (i2 < r) 
			{
				temp[index++] = A[i2++];
				M++;	
			}	    	
	    	l += step * 2; 
	    	m += step * 2;
	    	r += step * 2;
	    } 
		while (l < n);
    	for (int i = 0; i < n; i++)
		{
    		A[i] = temp[i];
		}	
    	step *= 2; 
    	
    	for(int i = 0; i < n; i++)
    	{
    		if(i%step==0 && i!=0)
    			cout << "|";
    		cout << A[i] << " ";
		}
		cout << "\n";	
	}
	cout << "\nC= " << C;
	cout << "\nM= " << M << "\n";	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nSum C + M = " << C+M << "\n";		
}