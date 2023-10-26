#include <cstdio>

long long segTree[4000004];
long long arrLL[1000001];

long long make_SegmentTree(int start, int end, int node)
{
    if(start == end){
        segTree[node] = arrLL[start];
        return segTree[node];
    }
    long long mid = (start + end) >> 1;
    long long left = make_SegmentTree(start, mid, node*2);
    long long right = make_SegmentTree(mid+1, end, node*2+1);
    segTree[node] = left + right;
    return segTree[node];
}

void update(int start, int end, int node, int pos, long long diff)
{
    if(pos < start || pos > end)
        return;
    segTree[node] = segTree[node] + diff;
    
    if(start != end){
        int mid = (start + end) >> 1;
        update(start, mid, node * 2, pos, diff);
        update(mid+1, end, node*2+1, pos, diff);
    }
}

long long rangeSum(int start, int end, int node, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segTree[node];
    
    int mid = (start + end)/2;
    long long left_sum = rangeSum(start, mid, node*2, left, right);
    long long right_sum = rangeSum(mid+1, end, node*2+1, left, right);
    
    return left_sum + right_sum ;
}


int main(void){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=1; i<=N; i++){
        scanf("%lld", &arrLL[i]);
    }
    
    make_SegmentTree(1, N, 1);
    
    long long aLL, bLL, cLL;
    for(int i=0; i<M+K; i++){
        scanf("%lld %lld %lld", &aLL, &bLL, &cLL);
        
        if(aLL==1){
            long long diff = cLL - arrLL[bLL];
            arrLL[bLL] = cLL;
            update(1, N, 1, static_cast<int>(bLL), diff);

        }
        else if(aLL==2){
            printf("%lld\n", rangeSum(1, N, 1, static_cast<int>(bLL), static_cast<int>(cLL)));
        }
        else{
            printf(" ERROR \n");
        }
    }  


    return 0;
}