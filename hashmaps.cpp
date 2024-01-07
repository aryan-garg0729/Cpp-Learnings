#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<string>
//see inbuilt fxn in notes
vector<int> removeDuplicates(int*a,int size){
    vector<int> output;
    unordered_map<int , bool> seen;

    for(int i = 0;i<size;i++){

        if(seen.count(a[i])>0){
            continue;            //if key exists continue
        }

        seen[a[i]] = true;     //if key don't exist create it and set as true and push that 
        output.push_back(a[i]);//element into output

    }
    return output;
}

int highestFrequency(int arr[], int n) {
    unordered_map<int,int>freq;
    
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;      //counting freq of each element
    }
    
    int max = freq[arr[0]];
    int mf = arr[0];    //max freq element
    
    for(int i = 0;i<n;i++){
        if(freq[arr[i]]>max){    //finding max freq and element corresponding to it 
            max = freq[arr[i]];
            mf = arr[i];
        }
    }
    
    return mf;
    
}

string uniqueChar(string str) {
    unordered_map<char , bool> seen;

    for(int i = 0;i<str.length();i++){
        if(seen.count(str[i])>0){
            continue;            //if key exists continue
        }

        seen[str[i]] = true; //if key don't exist create it and set as true
    }
    
    string ans;
    for(int i = 0;i<str.length();i++){
        if(seen.count(str[i])>0){  //if key exists append it to ans and erase that key
            ans+=str[i];
            seen.erase(str[i]);
        }
    }
    
    return ans;
}

int pairSum(int *arr, int n) {
	unordered_map<int ,int> freq;
  
    int count = 0;

    for(int i = 0;i<n;i++){
        count+=freq[-1*arr[i]];
        freq[arr[i]]++; 
    }

    return count;
}

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int ,int> freq;
    for(int i = 0;i<n;i++){
        freq[arr1[i]]++;
    }
    for(int i = 0;i<m;i++){
        if(freq[arr2[i]]!=0){
            cout<<arr2[i]<<endl;
            freq[arr2[i]]--;
        }
    }
}

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int>sums;
    int sum = 0;
    sums[sum] = -1;
    int max = -1;

    for(int i = 0;i<n;i++){
        int ans = 0;
        sum+=arr[i];

        if(sums.count(sum)==0){
            sums[sum] = i; 
        }
        else{
            ans = i-sums[sum];
            if(ans>max){
                max = ans;
            }
        }
        
    }
    return max;
}

int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> kno;
    int ans = 0;
    for(int i = 0;i<n;i++){
        kno[arr[i]]++;
    }
    if(k==0){
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            if(kno[arr[i]]==0){
            	continue;
        	}
            ans+= (kno[arr[i]]*(kno[arr[i]]-1))/2;
            kno[arr[i]] = 0;
        }
        return ans;
    }
    for(int i = 0;i<n;i++){
        if(kno[arr[i]]==0){
            continue;
        }
        if(kno.count(arr[i]+k)>0){
            ans+=kno[arr[i]+k] * kno[arr[i]];
            
        }
        if(kno.count(arr[i]-k)>0){
            ans+=kno[arr[i]-k] * kno[arr[i]];
            
        }
        kno[arr[i]] = 0;
    }
    return ans;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    vector<int> ans;
    unordered_map<int ,bool> nos;   //store number and bool value
    for(int i = 0;i<n;i++){
        nos[arr[i]] = true;
    }
    unordered_map<int ,int> ind;  //stores numbers and their indexes
    for(int i = 0;i<n;i++){
        ind[arr[i]] =i;
    }
    int start,end,max = INT16_MIN;
    for(int i = 0;i<n;i++){
        if(!nos[arr[i]]){
            continue;    //if the num is already used in some seq then continue
        }
        int s = arr[i],e = arr[i];  //initialising temp start and end
        
        int size = 1;  //size of seq
        for(int j = arr[i]+1;;j++){   //searching for continous nums greater than arr[i]
            if(nos[j]){
                size++;
                nos[j] = false;
                e = j;
            }
            else{
                break;
            }
        }
        
        for(int j = arr[i]-1;;j--){  //searching for continous nums smaller than arr[i]
            if(nos[j]){
                size++;
                nos[j] = false;
                s = j;
            }
            else{
                break;
            }
        }
        
        if(max<size ||(max==size && ind[start]>ind[s])){  //storing final results
            max = size;
            start = s;
            end = e;
        }
        
    }
    
    ans.push_back(start);
    ans.push_back(end);
    return ans;
    
}

                        //separate chaining technique(building hashmap)
template <typename V>
class MapNode {
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};
template <typename V>
class ourmap {
	MapNode<V>** buckets;
	int count;
	int numBuckets;

	public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

	void rehash(){
		MapNode<V> **temp = buckets;				// To store the old bucket
		buckets = new MapNode<V> *[2 * numBuckets]; // reinitialising & doubling the size
		
		for (int i = 0; i < 2 * numBuckets; i++){
			buckets[i] = NULL; // initialising each head pointer to NULL
		}

		int oldBucketCount = numBuckets;  //storing old bucket count
		numBuckets *= 2; // updating new size
		count = 0;  //reintialising count to 0

		for (int i = 0; i < oldBucketCount; i++){
			MapNode<V> *head = temp[i];
			while (head != NULL){
				string key = head->key;
				V value = head->value;
				insert(key, value); // inserting each value of old bucket
				// into the new one
				head = head->next;
			}
		}
		// deleting the old bucket
		for (int i = 0; i < oldBucketCount; i++){  //going to each bucket and deleting LL
			MapNode<V> *head = temp[i];
			delete head;
		}
		delete[] temp;  //deleting bucket array
	}

	public:
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;
		double loadFactor = (1.0*count)/numBuckets;
		if(loadFactor>0.7){
			rehash();
		}

	}

	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key) {
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}

};

int main() {
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;

	unordered_map<string, int>::iterator it;  //creating iterator
    it = ourmap.begin();                     //initialising iterator

	while (it != ourmap.end()) {
		cout << "Key : " << (*it).first << " Value: " << it->second << endl;
		it++;
	}

	// find
	unordered_map<string, int>::iterator it2 = ourmap.find("abc");
	// ourmap.erase(it2,it2+4);
	

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end()) {
		cout << *it1 << endl;
		it1++;
	}

}

