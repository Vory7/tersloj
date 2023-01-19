#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int W, K, curW = 0, curP = 0, bestP = 0, lostP = 0, MaxP = 0, N = 0;


void metodvg(int j, int *p, int *w, int *x, int *y) {
if (j == N) {
if (bestP < curP && curW <= W) {
for (int i = 0; i < N; ++i) y[i] = x[i];
bestP = curP;
}
return;
}
lostP += p[j];

if(bestP <= MaxP - lostP) metodvg(j + 1, p, w, x, y);
lostP -= p[j];
curW += w[j];
curP += p[j];

if(curW <= W) {
x[j] = 1;
metodvg(j + 1, p, w, x, y);
x[j] = 0;
}
curW -= w[j];
curP -= p[j];
}


int main(){
setlocale(LC_ALL, "Russian");
cout<<"Введите W - грузоподъемность рюкзака = ";
//cin>>W;
cout<<"Введите k - количество предметов = ";
//cin>>K1;
W = 24;
K = 3;

string *s1 = new string[K];
int *p1 = new int[K];
int *w1 = new int[K];
int *n1 = new int[K];
for(int i = 0; i < K; ++i) cin >> s1[i] >> w1[i] >> p1[i];

for(int i = 0; i < K; ++i) {
n1[i] = W / w1[i];
N += n1[i];
}

string *s = new string[N];
int *p = new int[N];
int *w = new int[N];
int c = 0;
for(int i = 0; i < K; ++i) {
for (int j = 0; j < n1[i]; ++j) {
p[c] = p1[i];
w[c] = w1[i];
s[c] = s1[i];
++c;
}
}

int *x = new int[N];
int *y = new int[N];

for(int i = 0; i < N; ++i) {
x[i] = 0;
y[i] = 0;
}

for(int i = 0; i < N; ++i) cout << "s[" << i << "] = " << s[i] << ", w[" << i << "] = " << w[i] << ", p[" << i << "] = " << p[i] << endl;

for(int i = 0; i < N; i++) MaxP += p[i];
metodvg(0, p, w, x, y);

for(int i = 0; i < N; ++i)
if(y[i]) cout << s[i] << endl;

cout << endl;
cout << "Сумма стоимости в лучшем наборе = " << bestP << endl;
}