char st[10000];
int top=-1;
class Solution {
public:
    inline static char bracket_open(char c){
        switch (c){
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
        }
        return 0;// never reach
    }
    static bool isValid(string& s) { 
        top=-1;// reset the st 
        if (s.size()&1) return 0;
        for (char c: s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    st[++top]=c;
                    break;
                case ')': 
                case '}':
                case ']':
                    if (top==-1 || st[top]!=bracket_open(c))
                        return 0;
                    else st[top--];
                    break;
            }
        }
        return top==-1;
    }
};