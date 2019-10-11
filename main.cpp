#include <iostream>
using namespace std;

void sorter(int arr[], int start,int end)
	{
		int start_of_left_array = start;
		int end_of_left_array = (start+end)/2;

		int start_of_right_array = ((start+end)/2)+1;
		int end_of_right_array = end;

		int temp_array[end+1];

		int index_of_left_array=start_of_left_array;	
        int index_of_right_array=start_of_right_array;
		int index_of_temp_array = 0 ;
		while(index_of_left_array<= end_of_left_array && index_of_right_array<= end_of_right_array)
		{
			if(arr[index_of_left_array] <= arr[index_of_right_array])
				{temp_array[index_of_temp_array]=arr[index_of_left_array];	index_of_left_array++;	}
			else
				{temp_array[index_of_temp_array] = arr[index_of_right_array];	index_of_right_array++;	}

			index_of_temp_array++;
		}

		while(index_of_left_array <= end_of_left_array )
		{
			temp_array[index_of_temp_array]=arr[index_of_left_array];	index_of_left_array++;		index_of_temp_array++;
		}

		while(index_of_right_array<= end_of_right_array)
		{
			temp_array[index_of_temp_array] = arr[index_of_right_array];	index_of_right_array++;	index_of_temp_array++;
		}

		////////////////////////////////// Returning elements to Original Array ///////////////////////////////////

		int i=0;
		for(int x = start_of_left_array ; x <= end_of_left_array ; x++)
		{
			arr[x] = temp_array[i];
            i++;
		}
        
		for(int x = start_of_right_array ; x <= end_of_right_array ; x++)
		{
			arr[x] = temp_array[i];
            i++;
		}



	}


void merge(int arr[], int start,int end)
	{
		if(start<end){
			merge(arr,start,(start+end)/2);
			//cout<<"Left "<<start<<" "<<end<<endl;
			merge(arr,((start+end)/2)+1,end);
			//cout<<"Right "<<start<<" "<<end<<endl;
			sorter(arr, start, end);
		}



	}



#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int my_array[] = {10,9,8,5,4,6,7,1,3,2};
	for(int i=0; i<10; i++)
	{
		cout<<my_array[i]<<endl;
	}
	cout<<"\n \n "; 
	merge(my_array, 0, 9);

	for(int i=0; i<10; i++)
	{
		cout<<my_array[i]<<endl;
	}


	cout<<"Done;";






	return 0;
}
