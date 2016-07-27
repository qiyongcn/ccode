/* Accepted 1279 C++ 00:00.00 840K */
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cout << "COWCULATIONS OUTPUT" << endl;
    
    while(N--)
    {
        char a[8], b[8], d[8], op;
        char alen = 0, blen = 0, dlen = 0;
        
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(d, 0, sizeof(d));
        
        string s;
        
        cin >> s;
        {
            int i = 0;
            while(s[i] == 'V')
                i++;
            int p = 0;
            while(i < 5)
                a[p++] = s[i++];
            alen = p;
        }
        for(int i = 0; i < alen / 2; i++)
            swap(a[i], a[alen - i - 1]);
        for(int i = 0; i < alen; i++)
            switch(a[i])
            {
                case 'V' : a[i] = 0; break;
                case 'U' : a[i] = 1; break;
                case 'C' : a[i] = 2; break;
                case 'D' : a[i] = 3; break;
            }
        
        cin >> s;
        {
            int i = 0;
            while(s[i] == 'V')
                i++;
            int p = 0;
            while(i < 5)
                b[p++] = s[i++];
            blen = p;
        }
        for(int i = 0; i < blen / 2; i++)
            swap(b[i], b[blen - i - 1]);
        for(int i = 0; i < blen; i++)
            switch(b[i])
            {
                case 'V' : b[i] = 0; break;
                case 'U' : b[i] = 1; break;
                case 'C' : b[i] = 2; break;
                case 'D' : b[i] = 3; break;
            }
        
        //compute
        for(int k = 0; k < 3; k++)
        {
            cin >> op;
            if(op == 'A')
            {
                char c[6], clen;
                memset(c, 0, sizeof(c));
                
                clen = max(alen, blen);
                for(int i = 0; i < clen; i++)
                    c[i] = a[i] + b[i];
                for(int i = 0; i < clen; i++)
                    c[i + 1] += c[i] / 4, c[i] %= 4;
                
                if(c[clen])
                    clen++;
                
                blen = clen;
                memcpy(b, c, sizeof(c));
            }
            if(op == 'L')
            {
                for(int i = blen; i >= 1; i--)
                    b[i] = b[i - 1];
                b[0] = 0;
                blen++;
            }
            if(op == 'R')
            {
                for(int i = 0; i < blen - 1; i++)
                    b[i] = b[i + 1];
                b[blen - 1] = 0;
                blen--;
            }
        }
        
        cin >> s;
        {
            int i = 0;
            while(s[i] == 'V')
                i++;
            int p = 0;
            while(i < 8)
                d[p++] = s[i++];
            dlen = p;
        }
        for(int i = 0; i < dlen / 2; i++)
            swap(d[i], d[dlen - i - 1]);
        for(int i = 0; i < dlen; i++)
            switch(d[i])
            {
                case 'V' : d[i] = 0; break;
                case 'U' : d[i] = 1; break;
                case 'C' : d[i] = 2; break;
                case 'D' : d[i] = 3; break;
            }
        
        if(blen == dlen)
        {
            int i;
            for(i = 0; i < blen; i++)
                if(b[i] != d[i])
                {
                    cout << "NO" << endl; break;
                }
            if(i == blen)
                cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    
    cout << "END OF OUTPUT" << endl;
    
    return 0;
}
