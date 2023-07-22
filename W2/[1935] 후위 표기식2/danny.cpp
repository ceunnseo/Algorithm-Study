// 2초, 128mb
// N : 피연산자 개수 1<= n <= 26
// 후위 표기식
// 피연산자 <= 100 자연수

int numbers[26] = {0,};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(int i = 0; i<n; i++){
        cin >> numbers[i];
    }
    stack<double> _s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] >='A' && s[i] <='Z'){
            _s.push(numbers[s[i]-'A']);
            // cout << numbers[s[i]-'A'] << s[i];
            continue;
        }
        double tar1, tar2, result = 0;
        tar2 = _s.top();
        _s.pop();
        tar1 = _s.top();
        _s.pop();
        if(s[i] == '+'){
            result = tar1 + tar2;
        } else if(s[i] == '-'){
            result = tar1 - tar2;
        } else if(s[i] == '*'){
            result = tar1 * tar2;
        } else if(s[i] == '/'){
            result = tar1 / tar2;
        }
        _s.push(result);
    }
    cout<<fixed; // 소수 둘째자리까지 출력
    cout.precision(2);
    cout << _s.top();
}
