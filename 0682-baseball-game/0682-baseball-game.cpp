
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                st.pop();
            }
            else if (ops[i] == "+") {
                int temp1 = st.top();
                st.pop();

                int temp2 = st.top();
                st.pop();

                int temp3 = temp1 + temp2;

                st.push(temp2);
                st.push(temp1);
                st.push(temp3);
            }
            else if (ops[i] == "D") {
                st.push(2 * st.top());
            }
            else {
                st.push(stoi(ops[i]));
            }
        }

        int sum = 0;

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
