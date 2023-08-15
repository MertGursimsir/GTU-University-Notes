int findMax(int B[], int n){
	int max=B[0];
	
	for (int i=1; i<n; i++){
		if (B[i]>max)
			max=B[i];
	}
	return max;
}


//********************************************
int findMin(int B[], int n){
		int min=B[0];
	
	for (int i=1; i<n; i++){
		if (B[i]<min)
			min=B[i];
	}
	return min;
}


//********************************************
int findAverage(int B[], int n){
	int total=0;
	for (int i=0; i<n; i++){
		total = total+B[i];
	}
	return total/n;
	
}
