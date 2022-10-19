// Postfix Evaluation
#include<iostream>
#include<stack>
using namespace std;

class PostfixEvaluator{
    
    string expression;
    bool isOperator(char c){
        if(c == '+' || c == '-' || c == '*' || c == '/')
            return true;
        return false;
    }

    bool isNumericDigit(char c){
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }

    int performOperation(int operand1, int operand2, char operation){
        switch(operation){
            case '+': return operand1+operand2;
            case '-': return operand1-operand2;
            case '*': return operand1*operand2;
            case '/':return operand1/operand2;
            default: return -1;
        }
    }   

public:
    PostfixEvaluator(string expression){
        this->expression = expression;
    }
    
    void evaluate(){
        int operand1;
        int operand2;
        stack<int> s;
        for(int i=0;i<expression.length();++i){
            if(expression[i] == ' ' || expression[i] == ',') continue;
            
            else if(isOperator(expression[i])){
                operand2 = s.top(); s.pop();
                operand1 = s.top(); s.pop();
                int result = performOperation(operand1,operand2,expression[i]);
                s.push(result);
            }

            else if(isNumericDigit(expression[i])){
                int operand = 0;
                while(i<expression.length() && isNumericDigit(expression[i])){
                    operand = (operand*10) + (expression[i] - '0');
                    i++;
                }
                --i;
                s.push(operand);
            }
        }

        cout<<"Output: "<<s.top()<<endl;
    }


};

int main(){
    string expression;
    cout<<"Enter the postfix expression: ";
    getline(cin,expression);
    PostfixEvaluator* evaluator = new PostfixEvaluator(expression); 
    evaluator->evaluate();
    delete evaluator;
    return 0;
}