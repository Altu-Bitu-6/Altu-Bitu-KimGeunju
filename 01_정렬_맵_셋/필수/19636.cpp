#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //input
    int W0,L0,T; // 체중, 에너지섭취량=기초대사량, 역치
    cin >> W0 >> L0 >> T;
    int D,L,A; // 다이어트 기간, 에너지 섭취량, 활동 대사량
    cin >> D >> L >> A;

    // 일일 에너지 소비량 = 일일 기초 대사량(l) + 일일 활동 대사량(A)
    int unchange_energy = L0+A; 
    int change_energy = L0+A;

    // 일일 기초대사량 변화
    int change_L = L0;

    int unchange_w = W0; // 기초대사량미변화몸무게
    int change_w = W0; // 기초대사량변화몸무게

    for (int i=0;i<D;i++){
        // 기초 대사량 미 변화
        unchange_w = unchange_w+(L-unchange_energy);

        // 기초 대사량 변화
        change_w = change_w+(L-change_energy);
        if(abs(L-(change_energy))>T){
            change_L = change_L+floor((L-change_energy)/2.0);
            change_energy = change_L+A;
        }
    }

    if(unchange_w<=0){
        cout<<"Danger Diet\n";
    } else {
        cout<<unchange_w<<" "<<L0<<"\n";
    }

    if(change_w<=0 || change_L<=0){
        cout<<"Danger Diet\n";
    } else {
        cout<<change_w<<" " << change_L<<" ";
        // YOYO 확인 : 기초대사량이 증가했으면 YOYO X
        if(L0-change_L>0){
            cout<<"YOYO";
        } else {
            cout<<"NO";
        }
    }
    return 0;
}