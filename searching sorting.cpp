// void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
// {
//     int ind1 = 0, ind2 = 0;
    
//     for(int i = 0;i<size1+size2;i++){
//         if(ind1<size1&&ind2<size2){
//         	if(arr1[ind1]>arr2[ind2]){
//             	ans[i] = arr2[ind2];
//             	ind2++;
//         	}
//         	else{
//             	ans[i] = arr1[ind1];
//             	ind1++;
//         	}
//         }
//         else if(ind1==size1){
//             ans[i] = arr2[ind2];
//             ind2++;
//         }
//         else{
//             ans[i] = arr1[ind1];
//             ind1++;
//         }
//     }
// }

// void mergeSort(int input[], int size){
	
//     if(size==1||size==0){
//         return;
//     }
//     int mid = (size-1)/2;
//     mergeSort(input,mid+1);
//     mergeSort(input+(mid+1),size-mid-1);
//     int arr[size];
//     merge(input,mid+1,input+(mid+1),size-mid-1,arr);
//     for(int i = 0;i<size;i++){
//         input[i]= arr[i];
//     }
//         return;
// }

                            //binary search: array must be sorted
// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int n, int x) {
// 	int start = 0, end = n - 1;
// 	while(start <= end) {
// 		int mid = (start + end) / 2;
// 		if(arr[mid] == x) {
// 			return mid;
// 		}
// 		else if(x < arr[mid]) {
// 			end = mid - 1;
// 		}
// 		else {             // x > arr[mid]
// 			start = mid + 1;
// 		}
// 	}

// 	return -1;      // if that element is not present
// }

// int main() {
// 	// Take array input from the user
// 	int n;
// 	cin >> n;

// 	int input[100];
	
// 	for(int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}

// 	int x;
// 	cin >> x;

// 	cout << binarySearch(input, n, x) << endl; 	

// }
//                             //selection sort
// #include <iostream>
// using namespace std;

// void selectionSort(int input[], int n) {
	// for(int i = 0; i < n-1; i++ ) {        // we need to run n-1 rounds
	// // Find min element in the array
	// int min = input[i], minIndex = i;
	// for(int j = i+1; j < n; j++) {
	// 	if(input[j] < min) {
	// 		min = input[j];
	// 		minIndex = j;
	// 	}
	// }
	// // Swap
	// int temp = input[i];
	// input[i] = input[minIndex];
	// input[minIndex] = temp;
	// }
// }

// int main() {
// 	int input[] = {3, 1, 6, 9, 0, 4};
// 	selectionSort(input, 6);
// 	for(int i = 0; i < 6; i++) {
// 		cout << input[i] << " ";
			 
// 	}
// 	cout << endl;
// }

                //bubble sort
// #include <iostream>
// using namespace std;

// void printArray(int input[], int n) {
// 	for(int i = 0; i < n; i++) {
// 		cout << input[i] << " " ;
// 	}
// 	cout << endl;
// }

// void bubbleSort(int arr[], int n) {
// 	for(int j = 0; j < n - 1; j++) {
// 		for(int i = 0; i < n - 1 - j; i++) {
// 			if(arr[i] > arr[i+1]) {
// 				int temp = arr[i];
// 				arr[i] = arr[i+1];
// 				arr[i+1] = temp;
// 			}
// 		}
// 	}
// }

// int main() {
// 	// Take array input from the user
// 	int n;
// 	cin >> n;

// 	int input[100];
	
// 	for(int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}
	
// 	bubbleSort(input, n);

// 	printArray(input, n);
	
// }
                        // insertion sort
// #include <iostream>
// using namespace std;

// void insertionSort(int arr[], int n) {
// 	for(int i = 1; i < n; i++) {
// 		int current = arr[i];
// 		int j;
// 		for(j = i - 1; j >= 0; j--) {
// 			if(current < arr[j]) {
// 				arr[j+1] = arr[j];
// 			}
// 			else {
// 				break;
// 			}
// 		}
// 		arr[j+1] = current;
// 	}

// }

// void printArray(int input[], int n) {
// 	for(int i = 0; i < n; i++) {
// 		cout << input[i] << " " ;
// 	}
// 	cout << endl;
// }

// int main() {
// 	// Take array input from the user
// 	int n;
// 	cin >> n;

// 	int input[100];
	
// 	for(int i = 0; i < n; i++) {
// 		cin >> input[i];
// 	}
	
// 	insertionSort(input, n);

// 	printArray(input, n);
	
// }