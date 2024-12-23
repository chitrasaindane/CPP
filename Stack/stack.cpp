#include<iostream>
using namespace std;

#define n 10 

class stack{

    int * a;
    int top;

    public:
    stack()
    {
        a= new int [n];
        top =-1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"stack full"<<endl;
            return;
        }

        else{
            top++;
            a[top]=x;
        }
    }

    int pop(){
        if(top == -1){
            cout<<"no element to pop"<<endl;  
        }
        else{
            cout<<a[top] << " element is POP"<<endl;
            top--;
        }

    }

    int Top(){
        if(top == -1){
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return a[top];
    }

    bool isempty(){
        return (top == -1);
    }

    bool isFull(){
        return (top == n-1);
    }

    int peek(int pos){
         int x=-1;
         if(top-pos+1  < 0){
          cout<<"invalid position"<<endl;
         }

         return a[top-pos+1];
    }
};


int main()
{
    stack st;
    st.push(6);
    st.push(8);
    st.push(11);

    cout<<"top element= " <<st.Top()<<endl;
    st.pop();
    cout<< "index 2 element=  "<<st.peek(2)<<endl;
    cout<< "is stack empty= "<<st.isempty()<<endl;

    return 0;
}