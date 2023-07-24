// 1초, 256mb
// 긴 쇠막대기 위에만 짧은 쇠막대기 놓을 수 있음
// 쇠막대기 위 쇠막대기 놓는 경우 포함되도록 놓고 끝점은 겹치지 않게
// 쇠막대기 자르는 레이저 하나 이상 존재
// 레이저는 어떤 쇠막대기 양 끝점과도 겹치지 않음
// () : 레이저
// ( : 쇠막대기 왼쪽 끝
// ) : 쇠막대기 오른쪽 끝
// 잘려진 쇠막대기 조각 총 개수
// 괄호 문자 <= 100,000


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin, s);
    stack<char> _s;
    int total = 0, cnt = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){ // 막대 시작
            _s.push(s[i]); // 스택 추가
            continue;
        }
        
        if(s[i-1] == '('){ // 레이저
            _s.pop(); // 레이저 빼주기
            total += _s.size();
            continue;
        }
        // 막대 끝
        _s.pop(); // 막대 빼주기
        total++; // 막대 절단 상황과 동일 (힌트 참고내용**) 
        // 조각을 나타내는것이므로 안잘렸어도 잘렸어도
        // 이제 더이상 뒤에서 셀수 없음 그러므로 지금 추가해놓음
    }
    cout << total;
}
