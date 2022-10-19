// Infix To Postfix Convertion
#include<iostream>
#include<stack>
using namespace std;

class PostfixConverter{
    string infix;
    string postfix;
    
    bool isOperand(char C){
        if(C >= '0' && C <= '9') return true;
        if(C >= 'a' && C <= 'z') return true;
        if(C >= 'A' && C <= 'Z') return true;
        return false;
    }

    bool IsOperator(char C){
        if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
            return true;
        return false;
    }

    int getOperatorWeight(char c){
        int weight = -1;
        switch(c)
        {
            case '+': weight = 1;
                      break;
            case '-': weight = 1;
                      break;
            case '*': weight = 2;
                      break;
            case '/': weight = 2;
                      break;
            case '$': weight = 3;
                      break;
        }
        return weight;
    }

    bool hasLowerOrEqualPrecedence(char op1, char op2){
        int op1Weight = getOperatorWeight(op1);
        int op2Weight = getOperatorWeight(op2);
        if(op1Weight <= op2Weight){
            return true;
        }
        else
            return false;
    }

    bool isOpeningParanthesis(char c){
        if(c == '(' || c == '{' || c == '[')
            return true;
        return false;
    }

    bool isSpaceProvider(char c){
        if(c == ' ' || c == ',')
            return true;
        return false;
    }

    bool isClosingParanthesis(char c){
        if(c == ')' || c == '}' || c == ']')
            return true;
        return false;
    }

    void displayPostfix(){
        cout<<"The equivalent postfix expression is: "<<postfix<<endl;
    }
    bool isMatchingParanthesis(char closing, char opening){
        if(opening == '{' && closing == '}') return true;
        if(opening == '(' && closing == ')') return true;
        if(opening == '[' && closing == ']') return true;
        return false;
    }

    bool isParanthesisBalanced(){
        stack<char> s;
        for(int i=0;i<infix.length();++i){
            if(isSpaceProvider(infix[i])) continue;
            else if(isOpeningParanthesis(infix[i]))
                s.push(infix[i]);
            else if(isClosingParanthesis(infix[i])){
                if(s.empty() || !isMatchingParanthesis(infix[i],s.top()))
                    return false;
                s.pop();
            }
        }
        if(s.empty())
            return true;
        return false;
    }

public:
    PostfixConverter(string infix){
        this->infix = infix;
        postfix = "";
    }

    void convert(){
        if(!isParanthesisBalanced()){
            cout<<"Typo! Paranthesis is not balanced in the infix expression"<<endl;
            return;
        }
        stack<char> s;
        for(int i=0;i<infix.length();++i){
            if(isSpaceProvider(infix[i])) continue;
            else if(IsOperator(infix[i])){
                while(!s.empty() &&  !isOpeningParanthesis(s.top()) && hasLowerOrEqualPrecedence(infix[i],s.top())){
                    postfix+= s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if(isOperand(infix[i]))
                postfix+=infix[i];
            else if(isOpeningParanthesis(infix[i]))
                s.push(infix[i]);
            else if(isClosingParanthesis(infix[i])){
                while(!isOpeningParanthesis(s.top())){
                    postfix+= s.top();
                    s.pop();
                }
                s.pop();
            }
        }
        while(!s.empty()){
            postfix+=s.top(); 
            s.pop();
        }
        displayPostfix();
    }
};

int main(){
    string expression;
    cout<<"Enter the infix expression: ";
    getline(cin,expression);
    PostfixConverter* postfixConverter = new PostfixConverter(expression);
    postfixConverter->convert();
    return 0;
}
@04luna
