/*
Problem Statement
You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:

The string has exactly N characters, each of which is either 'A' or 'B'.
The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
*/

#include <string>
using namespace std;

class AB
{
public:
    string createString(int N, int K)
    {
        int i = 0;
        bool found = false;
        while(!found)
        {
            if ((i + 1) * (N - i - 1) >= K)
                found = true;
            else
                i++;
            if (i >= N)
                break;
        }
        if (!found)
        {
            return "";
        }
        else
        {
            string ret = "";
            for (int j = 0; j < N; ++j)
            {
                ret += 'A';
            }
            if (K == 0)
            {
                return ret;
            }
            else
            {
                int mostPart = (N - i - 1) * i;
                int remaining = K - mostPart;
                ret[remaining] = 'B';
                for (int j = N - i; j < N; j++)
                {
                    ret[j] = 'B';
                }
                return ret;
            }
        }
    }
};
