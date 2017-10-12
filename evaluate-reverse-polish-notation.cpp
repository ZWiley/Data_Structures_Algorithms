/**
 *  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        for(auto token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
             {
                int a,b,res;
                b=numbers.top();numbers.pop();
                a=numbers.top();numbers.pop();
                if(token == "+")
                    res=a+b;
                else if(token == "-")
                    res=a-b;
                else if(token == "*")
                    res=a*b;
                else
                    res=a/b;
                numbers.push(res);
             }
            else
            {
                stringstream ss;
                ss<<token;
                int temp;
                ss>>temp;
                numbers.push(temp);
            }
        }
        return numbers.top();
    }
};