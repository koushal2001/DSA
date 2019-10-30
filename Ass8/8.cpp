/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
Operands and operator, both must be single character, Input Postfix expression must be in a desired format,
Only '+', '-', '*' and '/ ' operators are expected.
*/
#include<iostream>
#define MAX 100
using namespace std;
class stack{
    int top;
    char stackArray[MAX], infix[MAX], postfix[MAX];
public:
    stack();
    void push(char);
    char pop();
    bool isFull();
    bool isEmpty();

    void read();
    int whiteSpace(char);
    void infixToPostfix();
    int prior(char);
};

stack::stack(){
        top = -1;
}

void stack::push(char symbol){
    if(isFull())
        cout<<"\nStack overflow !";
    else
        stackArray[++top]==symbol;   
}

char stack::pop(){
    if (isEmpty())
        return '#';
    else
        return stackArray[top--];
}

bool stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;    
}

bool stack::isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void stack::read(){
    cout << "\nEnter an infix expression:";
    cin >> infix;
}

int stack::whiteSpace(char symbol){
    if (symbol == ' ' || symbol == '\t' || symbol == '\0')
        return 1;
    else
        return 0;
}

void stack::infixToPostfix(){

}

int stack::prior(char symbol){
    switch (symbol)
    {
    case '/':
        return (4);         //no break reqd as it returns the int value at that time only
    case '*':
        return (3);
    case '+':
        return (2);
    case '-':
        return (1);
    case '(':
        return (0);
    default:
        return (-1);
    }
}

int main()
{
    char choice;
    stack expr;
up:
        expr.read();
        expr.infixToPostfix();
        cout << "\n\nDo you want to continue ? (y/n): ";
        cin >> choice;
    if(choice=='y')
        goto up;
    else
        return 0;
}
/*
    void ConvertToPostfix()
    {
        int prev, p;
        char entry;
        p = 0;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            if (!white_space(infix[i]))
            {
                switch (infix[i])
                {
                case '(':
                    push(infix[i]);
                    break;
                case ')':
                    while ((entry = pop()) != '(')
                        postfix[p++] = entry;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    if (!empty())
                    {
                        prev = prior(infix[i]);
                        entry = pop();
                        while (prev <= prior(entry))
                        {
                            postfix[p++] = entry;
                            if (!empty())
                                entry = pop();
                            else
                                break;
                        }
                        if (prev > prior(entry))
                            push(entry);
                    }
                    push(infix[i]);
                    break;
                default:
                    postfix[p++] = infix[i];
                    break;
                }
            }
        }
        while (!empty()) //while stack is not empty
            postfix[p++] = pop();
        postfix[p] = '\0';
        cout << "\nThe postfix expression is: " << postfix << endl;
    }
    int prior(char symbol)
    {
        switch (symbol)
        {
        case '/':
            return (4);
        case '*':
            return (3);
        case '+':
            return (2);
        case '-':
            return (1);
        case '(':
            return (0);
        default:
            return (-1);
        }
    }
};
int main()
{
    char choice = 'y';
    stack expr;
    while (choice == 'y')
    {
        expr.read();
        expr.ConvertToPostfix();
        cout << "\n\nDo you want to continue ? (y/n): ";
        cin >> choice;
    }
    return 0;
}
*/