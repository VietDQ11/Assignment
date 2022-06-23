#include <iostream>
#include <string>
    using namespace std;

        template <class T>
        class Stack
        {
        public:
            Stack();
            void push(T i);
            T pop();
        private:
            int top;
        T st[100];
        };

        template <class T>
        Stack<T>::Stack()
        {
            top = -1;
        }

        template <class T>
        void Stack<T>::push(T i)
        {
            st[++top] = i;
        }

        template <class T>
        T Stack<T>::pop()
        {
            return st[top--];
        }

        int main ()
        {
            Stack<int> int_stack;
            Stack<string> str_stack;
            int_stack.push(99);
            int_stack.push(9999);
            str_stack.push("Soft");
            str_stack.push("F");
            cout << int_stack.pop() << endl;
            cout << int_stack.pop() << endl;
            cout << str_stack.pop() << endl;
            cout << str_stack.pop() << endl;
            return 0;
        }