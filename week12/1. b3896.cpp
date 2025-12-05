#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAX 1300000
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N=0;
    cin>>N;

    vector<int> A(MAX,1); //vector A 1로 채우기 -> 소수점만 남기기 에라토스테네스의 체이용
    A[0]=A[1]=0; //0과 1은 소수가 아니므로 0으로 제외

    vector<int> B(N); // 입력값을 저장할 vector B
    for(int i=0;i<N;i++){
        cin>>B[i];
    } 

    vector<int> C;
    // vector A에서 소수에 해당하는 수만 저장해 놓을 vector C 
   
  
  for(int i=2;i<1300000;i++){ // 각각 배수들을 다 날리므로서 없에기
        if(A[i]==1){
            for(int j=i*i;j<=MAX;j+=i){
                A[j]=0;
            }
        }
    } // 에라토스테네스의 방식으로 소수들만 남은 A[]안에서 이들을 뽑아 C안에 저장
    for(int i=0;i<A.size();i++){
        if(A[i]==1){
            C.push_back(i);
        }
    } // A에서 소수만 C에 복사 한다!
    
    for(int i=0;i<N;i++){
        if(A[B[i]]==1){ // 내가 입력한 값이 소수이면 0 출력하고
            cout<<"0"<<'\n';
        } 
        else{
            int idx=lower_bound(C.begin(),C.end(),B[i])-c.begin();
            cout<<C[idx]-C[idx-1]<<'\n';
        }
        // 입력값이 소수가 아니면 구간의 크기 출력해라
    }
}
