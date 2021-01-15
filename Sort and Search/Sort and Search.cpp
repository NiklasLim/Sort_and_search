#include<stdio.h>
#include<time.h>
int n;
int count;
int num[100000];
int num2[100000];

FILE *in;
void file(){
	n=0;
	in=fopen("datatugas.txt","r");
	while(!feof(in)){
		fscanf(in,"%d ",&num[n]);
		n++;
	}
	fclose(in);
}
void print_file(){
	int flag=0;
	for(int i=0;i<n;i++){
		if(flag==0){
			printf("%d",num[i]);
			flag=1;
		}
		else if(flag==1){
			printf(" %d",num[i]);
		}
	}
	printf("\n");
}

void hitung_waktu(){
	clock_t start_t,end_t,total_t;
	
	start_t = clock();
	   printf("Starting of the program, start = %ld\n", start_t);
	    
	   printf("Going to scan a big loop, start = %ld\n", start_t);
	   for(int i=0; i< 100001; i++) {
	   }
	   end_t = clock();
	   printf("End of the big loop, end = %ld\n", end_t);
	   
	   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	   printf("Total time taken by CPU: %f\n", total_t  );
}

void bubble_sort(){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(num[j]<num[j-1]){
				temp=num[j-1];
				num[j-1]=num[j];
				num[j]=temp;
			}
		}
	}
}
void selection_sort(){
	int temp_1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(num[j]<num[i]){
			temp_1=num[i];
			num[i]=num[j];
			num[j]=temp_1;
			}
		}
	}
}
void insertion_sort(){
	int kunci,temp_3;
	for(int i=1;i<n;i++){
		kunci=num[i];
		temp_3=i-1;
		while(temp_3>=0&&num[temp_3]>kunci){
			num[temp_3+1]=num[temp_3];
			temp_3-=1;
		}
		num[temp_3+1]=kunci;
	}
}

void merge(int left,int mid,int right){
	int l,r,m;
	for(l=left,r=mid+1,m=left;l<=mid&&r<=right;m++){
		if(num[l]<=num[r]){
			num2[m]=num[l++];
		}
		else{
			num2[m]=num[r++];
		}
	}
	while(l<=mid){
		num2[m++]=num[l++];
	}
	while(r<=right){
		num2[m++]=num[r++];
	}
	for(m=left;m<=right;m++){
		num[m]=num2[m];
	}
}
void merge_sort(int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left,mid,right);
	}
	else{
		return;
	}
}

int partition_sort(int low,int high,int pivot){
	int temp_low,temp_right,temp_4,swap_3,temp_5;
	temp_low=low-1;
	temp_right=high;
	while(true){
		while(num[++temp_low]<pivot){
		}
		while(temp_right>0&&num[--temp_right]>pivot){
		}
		if(temp_low>=temp_right){
			break;
		}
		else{
			temp_4=num[temp_low];
			num[temp_low]=num[temp_right];
			num[temp_right]=temp_4;
			count++;
		}
	}
	temp_5=num[temp_low];
	num[temp_low]=num[high];
	num[high]=temp_5;
	return temp_low;
}
void quick_sort(int low,int high){
	int pivot,temp_6;
	if(high-low<=0){
		return;
	}
	else{
		pivot=num[high];
		temp_6=partition_sort(low,high,pivot);
		quick_sort(low,temp_6-1);
		quick_sort(temp_6+1,high);
	}
}

void linear_search(int x){
	int temp_7,flag,compare;
	flag=0;
	for(int i=0;i<n;i++){
		if(num[i]==x){
			temp_7=i;
			flag=1;
			compare++;
		}
		else{
			compare++;
		}
	}
	if(flag==1){
		printf("Data yang anda cari ada pada urutan ke-%d\n",temp_7+1);
	}
	else if(flag==0){
		printf("Data Not Found !!\n");
	}
	printf("Total Perbandingan : %d\n",compare);
}
void binary_search(int y){
	int a=0;
	int b=n-1;
	int c=-1;
	int flag_3=-1;
	int compare=0;
	while(a<=b){
		compare++;
		c=a+(b-a)/2;
		if(num[c]==y){
			flag_3=c;
			break;
		}
		else{
			if(num[c]<y){
				a=c+1;
			}
			else{
				b=c-1;
			}
		}
	}
	if(flag_3!=-1){
		printf("Data yang anda cari ada di urutan ke-%d\n",flag_3+1);
	}
	else{
		printf("Data Not Found !!\n");
	}
	printf("Total Perbandingan : %d\n",compare);
}
void interpolation_search(int z){
	int low_2=0;
	int mid_2=-1;
	int high_2=n-1;
	int compare=0;
	int flag_2=-1;
	while(low_2<=high_2){
		compare++;
		mid_2=low_2+(((double)(high_2-low_2)/(num[high_2]-num[low_2]))*(z-num[low_2]));
		if(num[mid_2]==z){
			flag_2=mid_2;
			break;
		}
		else{
			if(num[mid_2]<z){
				low_2=mid_2+1;
			}
			else{
				high_2=mid_2-1;
			}
		}
	}
	if(flag_2!=-1){
		printf("Data yang anda cari ada di urutan ke-%d\n",flag_2+1);
	}
	else{
		printf("Data Not Found !!\n");
	}
	printf("Total Perbandingan : %d\n",compare);
}
int main(){

    int input_1,input_2,input_3;
	
	file();
	printf("Daftar Data	: ");
	print_file();
	printf("\n");
	
	file();
	bubble_sort();
	printf("Hasil Bubble sort	: ");
	print_file();
	hitung_waktu();
	printf("\n");
	
	file();
	selection_sort();
	printf("Hasil Selection sort	: ");
	print_file();
	hitung_waktu();
	printf("\n");
	
	insertion_sort();
	printf("Hasil Insertion sort	: ");
	print_file();
	hitung_waktu();
	printf("\n");
	
	file();
	merge_sort(0,n-1);
	printf("Hasil Merge sort	: ");
	print_file();
	hitung_waktu();
	printf("\n");
	
	file();
	quick_sort(0,n-1);
	printf("Hasil Quick sort	: ");
	print_file();
	hitung_waktu();
	printf("\n");
	
	printf("Angka yang ingin di cari : ");
	scanf("%d",&input_1);getchar();
	linear_search(input_1);
	printf("\n");
	
	printf("Angka yang ingin di cari : ");
	scanf("%d",&input_2);getchar();
	binary_search(input_2);
	printf("\n");

	printf("Angka yang ingin di cari : ");
	scanf("%d",&input_3);getchar();
	interpolation_search(input_3);
	printf("\n");	
	
	return 0;
}








