#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> //isdigit

using namespace std;

bool cmpSn(const string& sn1, const string& sn2){
    //1. 길이 비교
    if(sn1.length() != sn2.length()){
        return sn1.length()<sn2.length();
    }
    //2. 숫자 합 비교
    int sn1_sum = 0, sn2_sum = 0;
    for(int i=0;i<sn1.length();i++){
        if(isdigit(sn1[i])){
            sn1_sum += sn1[i]-'0';
        }
        if(isdigit(sn2[i])){
            sn2_sum += sn2[i]-'0';
        }
    }
    if(sn1_sum != sn2_sum){
        return sn1_sum < sn2_sum;
    }

    //3. 사전 순 비교(숫자-알파벳 순)
    return sn1 < sn2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //input
    int N;
    cin>>N;
    
    vector<string> serial_number(N);
    for(int i=0;i<N;i++){
        cin>>serial_number[i];
    }

    //sort
    sort(serial_number.begin(),serial_number.end(), cmpSn);

    //output
    for(int i=0;i<serial_number.size();i++){
        cout<<serial_number[i]<<'\n';
    }

    return 0;
}
