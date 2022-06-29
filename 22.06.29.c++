#include<iostream>
#include<math.h>
#include<string.h>
#define Max 101
#define M 170001
using namespace std;
int count_prime[M];
int input[Max];
int prime_input[Max][M];
bool Prime[1000001];
int real_Prime[M];
int answer = 1;
int answer_count = 0;
int N;    int cnt = 1;

void getPrime() {
    memset(Prime, true, sizeof(Prime)); // 모든 값을 true로 설정

    for (int i = 2; i < sqrt(1000000); i++) {
        if (Prime[i] == false)continue;
        for (int j = i * i; j < 1000000; j += i) {
            Prime[j] = false;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (Prime[i]) {
            real_Prime[cnt] = i;
            cnt++;
        }
    }
}


int main() {
    //소수 구하기
    getPrime();
    //카운트 배열 초기화
    memset(count_prime, 0, sizeof(count_prime));
    //값 입력받기
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }

    //소수 값 세기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < cnt; j++) {
            while (input[i] % real_Prime[j] == 0) {
                prime_input[i][j]++;
                input[i] /= real_Prime[j];
                count_prime[j]++;
            }
        }

    }

    //존재하는 모든 소수의 개수를 N으로 나누어 주기
    for (int i = 1; i < cnt; i++) {
        count_prime[i] /= N;
    }

    for (int i = 1; i < cnt; i++) {
        if (count_prime[i] > 0) {
            for (int j = 0; j < count_prime[i]; j++) {
                answer *= real_Prime[i];
            }
        }
    }

    //나눈 이후에도 값이 1이상이면 값을 하나씩 빼주면서
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i < cnt; i++) {
            if (count_prime[i] > 0 && prime_input[j][i] < count_prime[i]) {
                answer_count+= count_prime[i] - prime_input[j][i];
            }
        }
    }





   cout << answer <<" "<< answer_count;

}