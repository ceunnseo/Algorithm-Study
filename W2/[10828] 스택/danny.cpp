
    // N : 명령어 수 1 <= N <= 10000
    // 1 <= 정수 <= 100000
    // push X 정수 X 스택 삽입
    // pop 탑 정수 빼고 출력 없으면 -1
    // size 정수 개수 출력
    // empty 스택 비어있으면 1 아니면 0
    // top : 스택 가장 위 정수 출력 없으면 -1
int n;

typedef struct _stack{
    int x[10005];
    int pos = 0;
    void push(int dat){
        x[pos++] = dat;
    }
    int pop(){
        if(empty() == 1)
            return -1;
        return x[--pos];
    }
    int size(){
        return pos;
    }
    int empty(){
        if(pos <= 0)   return 1;
        return 0;
    }
    int top(){
        if(empty() == 1)
            return -1;
        return x[pos-1];
    }
}Stack;

Stack _s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string cmd;
    int dat;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if(cmd == "push"){
            cin >> dat;
            _s.push(dat);
        }else if(cmd == "pop"){
            cout << _s.pop() << '\n';
        }else if(cmd == "top"){
            cout << _s.top() << '\n';
        }else if(cmd == "size"){
            cout << _s.size() << '\n';
        }else if(cmd == "empty"){
            cout << _s.empty() << '\n';
        }
    }
}
