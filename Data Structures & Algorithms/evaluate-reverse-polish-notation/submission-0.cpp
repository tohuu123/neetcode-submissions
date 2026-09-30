class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int ans = 0;
        for (string x: tokens) {
            if (x == "+") { 
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                ans = op1 + op2; 
                st.push(ans);
            }
            else if (x == "-") { 
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                ans = op2 - op1; 
                st.push(ans);
            }
            else if (x == "*") { 
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                ans = op1 * op2; 
                st.push(ans);
            }
            else if (x == "/") { 
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                ans = op2 / op1; 
                st.push(ans);
            }
            else { 
                st.push(stoi(x));
            }
        }

        while (!st.empty()) {  
            ans = st.top();
            st.pop();
        }
        return ans; 
    }
};
