int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while(true){
        getline(cin, s);
        if(s.empty() == true)  break;
        if(s[0] == '.') break;
        stack<char> st;
        bool isResult = true;
        for(int i = 0; i<s.length(); i++){
            if( s[i] == '[' || s[i] == '(' ){
                st.push(s[i]);
            }
            else if( s[i] == ')'){
                if(st.empty() == false && st.top() == '('){
                    st.pop();
                    continue;
                }
                isResult = false;
                break;
            }
            else if( s[i] == ']'){
                if(st.empty() == false && st.top() == '['){
                    st.pop();
                    continue;
                }
                isResult = false;
                break;
            }
        }
        if(st.empty() == false) isResult = false;
        cout << (isResult == true ? "yes" : "no") << '\n';
    }
}
