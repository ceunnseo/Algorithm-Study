
    // N : 명령어 수 1 <= N <= 10000
    // 1 <= 정수 <= 100000
    // push X 정수 X 큐 삽입
    // pop 큐 가장 앞 빼고 수 출력, 없으면 -1
    // size 정수 개수 출력
    // empty 비어있으면 1 아니면 0
    // front : 앞 정수 출력, 비어있으면 -1
    // back : 뒤 정수 출력, 비어있으면 -1
int n;

typedef struct _queue{
    int x[10005];
    int head = 0, tail = 0;
    void push(int dat){
        x[tail++] = dat;
    }
    int pop(){
        if(empty() == 1)
            return -1;
        return x[head++];
    }
    int size(){
        if(empty() == 1)
            return 0;
        return tail - head;
    }
    int empty(){
        if(head == tail)   return 1;
        return 0;
    }
    int front(){
        if(empty() == 1)
            return -1;
        return x[head];
    }
    int back(){
        if(empty() == 1)
            return -1;
        return x[tail-1];
    }
}Queue;

Queue _s;
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
        }else if(cmd == "front"){
            cout << _s.front() << '\n';
        }else if(cmd == "back"){
            cout << _s.back() << '\n';
        }else if(cmd == "size"){
            cout << _s.size() << '\n';
        }else if(cmd == "empty"){
            cout << _s.empty() << '\n';
        }
    }
}
