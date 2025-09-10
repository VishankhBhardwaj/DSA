//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
    
    cout << "-" << "\n";

    return 0;
}
//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> stack1;
    for(int i=0;i<len;i++){
        char ch=S[i];
        stack1.push(ch);
        
    }
    string ans="";
    while(!stack1.empty()){
        char ch=stack1.top();
        ans.push_back(ch);
        stack1.pop();
    }
    char* result = new char[ans.length() + 1]; // Allocate memory
    strcpy(result, ans.c_str()); // Copy string content
    return result;
}