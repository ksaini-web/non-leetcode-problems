#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int>&arr,int st,int mid,int end){

    vector<int> temp;
    int i=st,j=mid+1;

    

  int   countInv=0;

    while(i<=mid && j<=end){

        if(arr[i]<=arr[j]){

           temp.push_back(arr[i]);
           i++;
            
        }

        else{
              temp.push_back(arr[j]);
           j++;
           countInv += (mid - i + 1);;
        }

    }

    while(i<=mid){

       temp.push_back(arr[i]);
      i++;
    }
    
    while(j<=end){

        temp.push_back(arr[j]);
        j++;
        
    }

    for(int k=0;k<temp.size();k++){

        arr[st+k]=temp[k];
    }
    return countInv;



}

int sortmerge(vector<int>&arr,int st,int end){

   if(st>=end){
    return 0;
   }

    int mid=st+(end-st)/2;
   int  invcount=0;

    //Call for left half

     invcount+=sortmerge(arr,st,mid);

    //Call for right half

    invcount+= sortmerge(arr,mid+1,end);

    invcount += merge(arr, st, mid, end);

   return invcount;



}

int main() {
    vector<int> arr = {6,3,5,2,7};

    cout << "Inversion Count = "
         << sortmerge(arr, 0, arr.size() - 1);

    return 0;
}
