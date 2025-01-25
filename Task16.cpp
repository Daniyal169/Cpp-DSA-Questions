#include <iostream>
#include <string>
using namespace std;

template <class T>
class stack
{
private:
    T *arr;
    int current_size;
    int max_size;

public:
    stack(int size)
    {
        current_size = 0;
        max_size = size;
        arr = new T[max_size];
    }

    ~stack()
    {
        delete[] arr;
    }

    void push(T value)
    {
        if (current_size == max_size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[current_size++] = value;
    }

    T pop()
    {
        if (current_size == 0)
        {
            cout << "Stack underflow!" << endl;
            return T();
        }
        return arr[--current_size];
    }

    T top()
    {
        if (current_size == 0)
        {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return arr[current_size - 1];
    }

    bool isEmpty()
    {
        return current_size == 0;
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    bool isOperand(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }

    string infixToPostfix(string infix)
    {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];
            if (isOperand(ch))
                postfix += ch;
            else if (ch == '(')
                push(ch);
            else if (ch == ')')
            {
                while (!isEmpty() && top() != '(')
                    postfix += pop();
                pop();
            }
            else
            {
                while (!isEmpty() && precedence(top()) >= precedence(ch))
                    postfix += pop();
                push(ch);
            }
        }
        while (!isEmpty())
            postfix += pop();
        return postfix;
    }

    int evaluatePostfix(string postfix)
    {
        stack<int> evalStack(postfix.length());
        for (int i = 0; i < postfix.length(); i++)
        {
            char ch = postfix[i];
            if (isOperand(ch))
                evalStack.push(ch - '0');
            else
            {
                int b = evalStack.pop();
                int a = evalStack.pop();
                switch (ch)
                {
                case '+':
                    evalStack.push(a + b);
                    break;
                case '-':
                    evalStack.push(a - b);
                    break;
                case '*':
                    evalStack.push(a * b);
                    break;
                case '/':
                    evalStack.push(a / b);
                    break;
                }
            }
        }
        return evalStack.pop();
    }
};

int main()
{
    string infix = "(1-2)*5";
    stack<char> s(infix.length());

    string postfix = s.infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    stack<int> evalStack(postfix.length());
    int result = evalStack.evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
