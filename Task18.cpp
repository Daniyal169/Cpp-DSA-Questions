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
            return T(); // Return default value
        }
        return arr[--current_size];
    }

    T top()
    {
        if (current_size == 0)
        {
            cout << "Stack is empty!" << endl;
            return T(); // Return default value
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
        return (ch >= '0' && ch <= '9'); // Check if the character is a digit
    }

    string reverseString(string str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
        return str;
    }

    string infixToPrefix(string infix)
    {
        // Step 1: Reverse the infix expression
        infix = reverseString(infix);

        // Step 2: Swap '(' with ')' and vice versa
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '(')
                infix[i] = ')';
            else if (infix[i] == ')')
                infix[i] = '(';
        }

        // Step 3: Convert to postfix
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
                pop(); // Remove '('
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

        // Step 4: Reverse postfix to get prefix
        return reverseString(postfix);
    }

    int evaluatePrefix(string prefix)
    {
        stack<int> evalStack(prefix.length());
        for (int i = prefix.length() - 1; i >= 0; i--) // Traverse prefix from right to left
        {
            char ch = prefix[i];
            if (isOperand(ch))            // If operand
                evalStack.push(ch - '0'); // Convert char to int
            else                          // Operator
            {
                int a = evalStack.pop();
                int b = evalStack.pop();
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
    string infix = "(1-2)*5"; // Replace with your own infix expression
    stack<char> s(infix.length());

    // Convert infix to prefix
    string prefix = s.infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    // Evaluate the prefix expression
    stack<int> evalStack(prefix.length());
    int result = evalStack.evaluatePrefix(prefix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
