#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// #define ARR_SIZE 1e10
const int ARR_SIZE = 2e5;
// const int ARR_SIZE = 10;

void min_max(int i,int j,double*arr,double*min,double*max);
void min_max_pos(int i,int j,double*arr,int*min,int*max);
void min_max_sort(double*arr);
void bubble_sort(double*arr);
void merge_sort(double*arr,int size);
void merge_sort(double*a,double*b,int left,int right);

void min_max(int i,int j,double*arr,double*min,double*max) {
    int mid;
    double  lmin, lmax, rmin, rmax;
    if (i == j) {
        *min = *(arr+i);
        *max = *(arr+j);
    } else if (j == i + 1) {
        if (*(arr+i)>*(arr+j)) {
            *min = *(arr+j);
            *max = *(arr+i);
        } else {
            *min = *(arr+i);
            *max = *(arr+j);
        }
    } else {
        mid = (i + j) / 2;
        min_max(i, mid,arr, &lmin, &lmax);
        min_max(mid + 1, j,arr, &rmin, &rmax);
        
        *min = lmin<rmin ? lmin : rmin;
        *max = lmax>rmax ? lmax : rmax;
    }
}

void min_max_pos(int i,int j,double*arr,int*min,int*max) {
    int mid;
    int  lmin, lmax, rmin, rmax;
    if (i == j) {
        *min = i;
        *max = j;
    } else if (j == i + 1) {
        if (*(arr+i)>*(arr+j)) {
            *min = j;
            *max = i;
        } else {
            *min = i;
            *max = j;
        }
    } else {
        mid = (i + j) / 2;
        min_max_pos(i, mid,arr, &lmin, &lmax);
        min_max_pos(mid + 1, j,arr, &rmin, &rmax);
        
        *min = *(arr+lmin)<*(arr+rmin) ? lmin : rmin;
        *max = *(arr+lmax)>*(arr+rmax) ? lmax : rmax;
    }
}

void min_max_sort(double*arr){
    int midpt = ARR_SIZE/2 ;
    int min,max;
    int n = ARR_SIZE-1;
    double temp;
    for(int i = 0;i<midpt;i++){
        min_max_pos(i,n-i,arr,&min,&max);
        // if(min!=i){
            temp = arr[i];
            *(arr+i) = *(arr+min);
            *(arr+min) = temp;
        // }
        // if(max!=n-i){
            temp = arr[n-i];
            *(arr+n-i) = *(arr+max);
            *(arr+max) = temp;
        // }
    }
}

void bubble_sort(double*arr){
    bool done = false;
    double temp;
    for(int k = 1;k<ARR_SIZE-1;k++){
        done = true;
        for(int i=0;i<ARR_SIZE-k;i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i+1];
                *(arr+i+1) = *(arr+i);
                *(arr+i) = temp;
                done = false;
            }
        }
        if (done)break;
    }
}

void merge_sort(double*arr,int size){
    double*b = new double[size];
    merge_sort(b,arr,0,size);
}

void merge_sort(double*a,double*b,int left,int right){
    if(left+1==right)
        return;
    int mid = (left+right)/2;
    merge_sort(b,a,left,mid);
    merge_sort(b,a,mid,right);
    for (int i=left,j=mid,pos=left; pos < right; ++pos)
    {
        if(j>=right || (i<mid && a[i]<a[j]))
            b[pos]=a[i++];
        else
            b[pos]=a[j++];
    }
}

int main(){
    
    double*arr = new double[ARR_SIZE];
    
    high_resolution_clock::time_point t1,t2;
    
    t1 = high_resolution_clock::now();
    {
        const long double stddev =100;

        random_device rd;

        mt19937 e2(rd());

        normal_distribution<double> dist(0,stddev);
        
        double r;
        for(int i = 0; i<ARR_SIZE;i++){
            r = dist(e2);
            *(arr+i) = r;
        }
        // double temp;
        // for(int i=0;i<ARR_SIZE;i++){
        //     cin >> temp;
        //     arr[i] = temp;
        // }
        // cout << endl;
    }
    t2 = high_resolution_clock::now();

    auto generation_duration = duration_cast<milliseconds>( t2 - t1 ).count();
    
    cout << "Generatoin Duration : "<< generation_duration << endl;
    
    cout << endl << endl;
    
    // t1 = high_resolution_clock::now();
    // {
    //     double min_max_arr[ARR_SIZE];
    //     for(int i=0;i<ARR_SIZE;i++){
    //         min_max_arr[i] = *(arr+i);
    //     }
    //     min_max_sort(&min_max_arr[0]);
    //     cout << endl << endl;
    // }
    // t2 = high_resolution_clock::now();

    // auto min_max_sort_duration = duration_cast<milliseconds>( t2 - t1 ).count();
    
    // cout << "Min-Max Sort Duration : "<< min_max_sort_duration << endl;
    
    // cout << endl << endl;
    
    
    // t1 = high_resolution_clock::now();
    // {
    //     double bubble_arr[ARR_SIZE];
    //     for(int i=0;i<ARR_SIZE;i++){
    //         bubble_arr[i] = *(arr+i);
    //     }
    //     cout << endl;
    //     bubble_sort(&bubble_arr[0]);
    //     cout << endl << endl;
    // }
    // t2 = high_resolution_clock::now();

    // auto bubble_sort_duration = duration_cast<milliseconds>( t2 - t1 ).count();

    // cout << "Bubble Sort Duration : "<< bubble_sort_duration << endl;
    
    // cout << endl << endl;


    t1 = high_resolution_clock::now();
    {
        double merge_arr[ARR_SIZE];
        for(int i=0;i<ARR_SIZE;i++){
            merge_arr[i] = *(arr+i);
        }
        cout << endl;
        merge_sort(&merge_arr[0],ARR_SIZE);
        cout << endl << endl;
    }
    t2 = high_resolution_clock::now();

    auto merge_sort_duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << "Merge Sort Duration : "<< merge_sort_duration << endl;
    
    cout << endl << endl;
    
    return 0;
}