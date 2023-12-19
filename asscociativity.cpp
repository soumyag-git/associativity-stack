#include <iostream>

using namespace std;

struct node{
    char data;
    node *next;
}*top=NULL;

void push(char c){
    node *t=new node;
    if(t==NULL){
        cout<<"Stack overflow ";
    }

    else{
        t->data=c;
        t->next=top;
        top=t;
    }

}


char pop(){
    char c=-1;
    if(top==NULL){
        cout<<"stack underflow";
    }
    else{
        node *t;
        t=top;
        c=t->data;
        top=top->next;
        free(t);
    }
    return c;
}

int isoperand(char &x){
    if(x=='('||x==')'||x=='+'||x=='-'||x=='*'||x=='/'|| x=='^'){
        return 0;
    }
    else{
        return 1;
    }
}

int prece(char & x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 5;
    }

    else if(x=='('){
        return 6;
    }

    else {
        return 0;
    }
    

}

int preceinstack(char x){
    if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 4;
    }

    else if(x=='('){
        return 0;
    }
    return 0;
}


char *intopos(char *infix){
    int i=0,j=0;
    char *postfix= new char[strlen(infix)+2];

    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(prece(infix[i])>preceinstack(top->data) ){
                push(infix[i++]);
            }
            else if(prece(infix[i])==preceinstack(top->data)){
               pop();
                i++;
            }

            else{
                postfix[j++]=pop();
            }

        }
    }
    while(top){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    push('@');
    char *c="((a+b)*c)-d^e^f";
    char *postfix;
    postfix= intopos(c);
    cout<<postfix;
}
