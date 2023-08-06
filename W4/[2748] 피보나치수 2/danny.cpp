// 1초, 128MB 피보나치 수 2
// n <= 90
// fi[0] = 0 fi[1] = 1 (n>=2)

long fi[91];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stack<int> s;
    int n;
    cin >> n;
    fill(fi, fi+91, -1);
    fi[0] = 0; fi[1] = 1;
    s.push(n);
    while(!s.empty()){ // s.pop();
        int t = s.top();
        if(t < 2 || fi[t] != -1){
            s.pop();
            continue;
        }
        if(fi[t-1] == -1){
            s.push(t-1);
            continue;
        }
        if(fi[t-2] == -1){
            s.push(t-2);
            continue;
        }
        fi[t] = fi[t-1] + fi[t-2];
        s.pop();
    }
    cout << fi[n];

    return 0;
}
