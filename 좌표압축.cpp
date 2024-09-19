int a[N]; //원본 배열
vector<int>v;
for (int i=0; i<N; i++) {
    v.push_back(a[i]);
}
sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end()); //중복 제거
for (int i=0; i<N; i++) {
    a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin(); // 원본 배열 수정
}


/*
원본 배열을 바로 수정하지 않고 함수형태로 만들어서 사용 가능
int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
*/
