#include <iostream>
#include <string>
using namespace std;

class MyBigNumber {
public:
    string sum(string stn1, string stn2) {
        string result = "";
        int carry = 0;
        //Kiểm soát việc loop qua 2 strings
        int i = stn1.length() - 1;
        int j = stn2.length() - 1;
        int step = 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? stn1[i] - '0' : 0;
            int digit2 = (j >= 0) ? stn2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
            
            cout << "Step " << step << ": " << digit1 << " + " << digit2 << " + carry " << carry 
                 << " = " << sum << ", next carry = " << carry << endl;
            
            i--;
            j--;
            step++;
        }
        
        return result;
    }
};

int main() {
    MyBigNumber myBigNumber;
    string result = myBigNumber.sum("12379703808537930790", "9874387");
    cout << "Result: " << result << endl;
    return 0;
}