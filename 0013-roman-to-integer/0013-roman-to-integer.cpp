class Solution {
public:
    int romanToInt(string s) {
        int result{0};
        size_t length = s.length();


        for (int i = 0; i<length - 1; ++i) {
            unsigned int currentValue = value(s[i]);
            unsigned int nextValue = value(s[i+1]);

            if(currentValue<nextValue) {
                result -= currentValue;
            } else {
                result += currentValue;
            }
        }

        return result + value(s[length - 1]);
    }
private:
    int value(char c)
    {
        switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
    }
};